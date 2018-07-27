/*
** EPITECH PROJECT, 2018
** Indie Studio
** File description:
** Bomberman.cpp
*/

#include "Bomberman.hpp"

Bomberman::Bomberman()
{
	std::srand(std::time(nullptr));
	this->_state = new MainMenu(this);
}

Bomberman::~Bomberman()
{
}

void Bomberman::intro() 
{
	std::string sound = AUDIO_SOURCES;
	sound += "title1.wav";
	int track = IrrlichtEngine::Instance().s_add_sound(S_TRACKS, sound);
	if (track < 0)
		return;
	IrrlichtEngine::Instance().s_loop_tracks(track, true);
	IrrlichtEngine::Instance().s_volume_tracks(track, 10);
	IrrlichtEngine::Instance().s_play(S_TRACKS, track);
	int seconds = 0;
	IrrlichtEngine::Instance().g_add_object(std::make_shared<Object2D>(Coord2(0, 0), "./ressources/images/background/charging.png"));
	std::chrono::time_point<std::chrono::system_clock> _start = std::chrono::system_clock::now();
	while (seconds < 9) {
		IrrlichtEngine::Instance().update();
		if (IrrlichtEngine::Instance().i_is_key(M_KEY_ENTER)) {
			IrrlichtEngine::Instance().i_release_key(M_KEY_ENTER);
			break;
		}
		seconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - _start).count();
	}
	IrrlichtEngine::Instance().e_clear_scene();
	IrrlichtEngine::Instance().s_remove_all();
}

void Bomberman::start()
{
	IrrlichtEngine::Instance().g_set_window(Coord2(1024, 768));
	IrrlichtEngine::Instance().g_set_camera(Camera(Coord3(0,10,0), Coord3(5,0,5)));
	intro();
	IrrlichtEngine::Instance().g_add_object(std::make_shared<Object2D>(Coord2(0, 0), "./ressources/images/background/wallpaper1.jpg"));
	std::string sound = AUDIO_SOURCES;
	sound += "title2.wav";
	int track = IrrlichtEngine::Instance().s_add_sound(S_TRACKS, sound);
	if (track < 0)
		return;
	IrrlichtEngine::Instance().s_loop_tracks(track, true);
	IrrlichtEngine::Instance().s_volume_tracks(track, 10);
	IrrlichtEngine::Instance().s_play(S_TRACKS, track);
	while (IrrlichtEngine::Instance().running()) {
		IrrlichtEngine::Instance().update();
		if (IrrlichtEngine::Instance().i_is_key(M_KEY_ENTER)) {
			play("bomberman.wav");
			break;
		}
	}
	IrrlichtEngine::Instance().e_clear_scene();
	this->_state->start();
	while (IrrlichtEngine::Instance().running()) {
		IrrlichtEngine::Instance().update();
		this->_state->update();
	}
}

void Bomberman::changeState(IState *newState)
{
	IrrlichtEngine::Instance().e_clear_scene();
	delete _state;
	_state = newState;
	_state->start();
}

void Bomberman::restart()
{
	std::cout << "Restarting..." << std::endl;
	IrrlichtEngine::Instance().s_remove_all();
	delete _state;
	this->_state = new MainMenu(this);
	IrrlichtEngine::Instance().e_clear_scene();
	IrrlichtEngine::Instance().g_add_object(std::make_shared<Object2D>(Coord2(0, 0), "./ressources/images/background/wallpaper1.jpg"));
	std::string sound = AUDIO_SOURCES;
	sound += "title2.wav";
	int track = IrrlichtEngine::Instance().s_add_sound(S_TRACKS, sound);
	if (track < 0)
		return;
	IrrlichtEngine::Instance().s_loop_tracks(track, true);
	IrrlichtEngine::Instance().s_volume_tracks(track, 10);
	IrrlichtEngine::Instance().s_play(S_TRACKS, track);
	while (IrrlichtEngine::Instance().running()) {
		IrrlichtEngine::Instance().update();
		if (IrrlichtEngine::Instance().i_is_key(M_KEY_ENTER))
			break;
	}
	IrrlichtEngine::Instance().e_clear_scene();
	this->_state->start();
}