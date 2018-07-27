/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SoundSfml
*/

#include "Engine/SoundSfml.hpp"
#include <iostream>

SoundSfml::SoundSfml()
{
	sf::err().rdbuf(NULL);
}

SoundSfml::~SoundSfml()
{
	for (size_t i = 0; i < _tracks.size(); i++)
		_tracks[i]->stop();
}

int SoundSfml::add_sound(const char type, const std::string &path)
{
	if (path.empty())
	  return -1;
	if (type == S_TRACKS)
	  return addTrack(path);
	else if (type == S_SOUND)
		return addChunk(path);
	return -1;
}

void SoundSfml::remove_useless_sound()
{
	_chunks.erase(std::remove_if(
		_chunks.begin(), _chunks.end(),
		[](std::unique_ptr<sf::Sound> &sound) {
			return (sound->getStatus() != sf::SoundSource::Playing);
		}), _chunks.end());
}

void SoundSfml::play(const char type, const size_t index)
{
	if (type == S_TRACKS && index < _tracks.size())
		_tracks[index]->play();
	else if (type == S_SOUND && index < _chunksbuffer.size()) {
		remove_useless_sound();
		std::unique_ptr<sf::Sound> sound(new sf::Sound());
		sound->setBuffer(*(_chunksbuffer[index].get()));
		_chunks.push_back(std::move(sound));
		_chunks[_chunks.size()-1]->play();
	}
}

void SoundSfml::pause_track(const size_t index)
{
	if (index < _tracks.size())
		_tracks[index]->pause();
}

void SoundSfml::stop_track(const size_t index)
{
	if (index < _tracks.size())
		_tracks[index]->stop();
}

void SoundSfml::loop_track(const size_t index, bool loop)
{
	if (index < _tracks.size())
		_tracks[index]->setLoop(loop);
}

int SoundSfml::addTrack(const std::string &path)
{
	std::unique_ptr<sf::Music> music(new sf::Music);

	if (!music->openFromFile(path))
		return -1;
	_tracks.push_back(std::move(music));
	return _tracks.size() - 1;
}

int SoundSfml::addChunk(const std::string &path)
{
	std::unique_ptr<sf::SoundBuffer> buffer(new sf::SoundBuffer);
	if (!buffer->loadFromFile(path))
		return -1;
	_chunksbuffer.push_back(std::move(buffer));
	return _chunksbuffer.size() - 1;
}

void SoundSfml::volume_track(const size_t index, int volume)
{
	if (index < _tracks.size() && volume > 0 && volume <= 100)
		_tracks[index]->setVolume(volume);
}

void SoundSfml::remove_all()
{
	for (size_t i = 0; i < _tracks.size(); i++)
		_tracks[i]->stop();
	_chunks.clear();
	_chunksbuffer.clear();
	_tracks.clear();
}
