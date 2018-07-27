/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** interface for sound gestion
*/

#ifndef ISOUND_HPP_
#define ISOUND_HPP_

#include <string>

#define S_TRACKS 1
#define S_SOUND 2
#define AUDIO_SOURCES "ressources/audio/"

class ISound {
public:
	virtual ~ISound() {};
	virtual int add_sound(const char type, const std::string &path) = 0;
	virtual void play(const char type, const size_t index) = 0;
	virtual void pause_track(const size_t index) = 0;
	virtual void stop_track(const size_t index) = 0;
	virtual void loop_track(const size_t index, bool loop) = 0;
	virtual void volume_track(const size_t index, int volume) = 0;
	virtual void remove_all() = 0;
};

#endif /* !ISOUND_HPP_ */
