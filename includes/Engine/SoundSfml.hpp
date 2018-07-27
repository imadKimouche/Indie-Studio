/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SoundSfml header file
*/

#ifndef SOUNDSFML_HPP_
#define SOUNDSFML_HPP_

#include "ISound.hpp"
#include <SFML/Audio.hpp>
#include <utility>
#include <memory>
#include <vector>

class SoundSfml : public ISound {
public:
	SoundSfml();
	~SoundSfml();
	int add_sound(const char type, const std::string &path) override;
  	void play(const char type, const size_t index) override;
  	void pause_track(const size_t index) override;
  	void stop_track(const size_t index) override;
  	void loop_track(const size_t index, bool loop) override;
	void volume_track(const size_t index, int volume) override;
	void remove_all() override;
private:
	int addTrack(const std::string &path);
	int addChunk(const std::string &path);
	void remove_useless_sound();
	std::vector<std::unique_ptr<sf::Sound>> _chunks;
	std::vector<std::unique_ptr<sf::SoundBuffer>> _chunksbuffer;
	std::vector<std::unique_ptr<sf::Music>> _tracks;
};

#endif /* !SOUNDSFML_HPP_ */
