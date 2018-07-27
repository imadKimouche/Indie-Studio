/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** AEngine
*/

#ifndef AENGINE_HPP_
#define AENGINE_HPP_

#include "IEngine.hpp"
#include <memory>

class AEngine : public IEngine {
public:
	~AEngine() = default;
	virtual void e_clear_scene() override;
	virtual void e_close_window() override;
	virtual void g_add_object(std::shared_ptr<IObject> object) override;
	virtual void g_remove_object(std::shared_ptr<IObject> object) override;
	virtual void g_set_window(const Coord2& size) override;
	virtual void g_set_camera(Camera camera) override;
	virtual Camera &g_get_camera() override;
	virtual bool i_is_key(int mask) const override;
	virtual void i_push_key(int mask) override;
	virtual void i_release_key(int mask) override;
	virtual bool i_is_joystick(int index, char key) override;
	virtual void i_push_joystick(int index, char key) override;
	virtual void i_release_joystick(int index, char key) override;
	virtual void i_release_all() override;
	virtual std::vector<int> i_get_keys() const override;
	virtual std::string i_translate_key(int index) const override;
	virtual int s_add_sound(char mask, const std::string &file) override;
	virtual void s_remove_all() override;
	virtual void s_stop_tracks(size_t index) override;
	virtual void s_pause_tracks(size_t index) override;
	virtual void s_play(char mask, size_t index) override;
	virtual void s_loop_tracks(size_t index, bool loop) override;
	virtual void s_volume_tracks(size_t index, int volume) override;
	virtual bool running() override;
protected:
	Camera _camera;
	std::shared_ptr<IGui> _gui;
	std::shared_ptr<IInput> _input;
	std::shared_ptr<ISound> _sound;
};

#endif
