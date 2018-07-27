/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IEngine
*/

#ifndef IENGINE_HPP_
#define IENGINE_HPP_

#include "IGui.hpp"
#include "ISound.hpp"
#include "IInput.hpp"
#include "ICamera.hpp"
#include <iostream>

class IEngine {
public:
	virtual ~IEngine() {}
	virtual void e_clear_scene() = 0;
	virtual void e_close_window() = 0;
	virtual void g_add_object(std::shared_ptr<IObject> ) = 0;
	virtual void g_remove_object(std::shared_ptr<IObject>) = 0;
	virtual void g_set_window(const Coord2&) = 0;
	virtual void g_set_camera(Camera camera) = 0;
	virtual Camera &g_get_camera() = 0;
	virtual bool i_is_key(int mak) const = 0;
	virtual bool i_is_joystick(int index, char key) = 0;
	virtual void i_push_key(int mask) = 0;
	virtual void i_release_key(int mask) = 0;
	virtual void i_push_joystick(int index, char key) = 0;
	virtual void i_release_joystick(int index, char key) = 0;
	virtual void i_release_all() = 0;
	virtual std::vector<int> i_get_keys() const = 0;
	virtual std::string i_translate_key(int index) const = 0;
	virtual int s_add_sound(char mask, const std::string &) = 0;
	virtual void s_remove_all() = 0;
	virtual void s_stop_tracks(size_t index) = 0;
	virtual void s_pause_tracks(size_t index) = 0;
	virtual void s_play(char mask, size_t index) = 0;
	virtual void s_loop_tracks(size_t index, bool loop) = 0;
	virtual void s_volume_tracks(size_t index, int volume) = 0;
	virtual bool running() = 0;
	virtual void update() = 0;
};

#endif
