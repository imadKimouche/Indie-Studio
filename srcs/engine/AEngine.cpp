/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** AEngine
*/

#include "Engine/AEngine.hpp"

void AEngine::e_clear_scene()
{
	_input->release_all();
	_gui->clear_scene();
}

void AEngine::e_close_window()
{
	_gui->close_window();
}

void AEngine::g_add_object(std::shared_ptr<IObject> object)
{
	_gui->add_object(object);
}

void AEngine::g_remove_object(std::shared_ptr<IObject> object)
{
	_gui->remove_object(object);
}

void AEngine::g_set_window(const Coord2& size)
{
	_gui->set_window(size);
}

void AEngine::g_set_camera(Camera camera)
{
	_camera = camera;
}

Camera &AEngine::g_get_camera()
{
	return _camera;
}

bool AEngine::i_is_key(int mask) const
{
	return _input->is_key(mask);
}

void AEngine::i_push_key(int mask)
{
	_input->push_key(mask);
}

void AEngine::i_release_key(int mask)
{
	_input->release_key(mask);
}

bool AEngine::i_is_joystick(int index, char key)
{
	return _input->is_joystick(index, key);
}

void AEngine::i_push_joystick(int index, char key)
{
	_input->push_joystick(index, key);
}

void AEngine::i_release_joystick(int index, char key)
{
	_input->release_joystick(index, key);
}

void AEngine::i_release_all()
{
	_input->release_all();
}

std::vector<int> AEngine::i_get_keys() const
{
	return _input->get_keys();
}

std::string AEngine::i_translate_key(int index) const
{
	return _input->translate_key(index);
}

int AEngine::s_add_sound(char mask, const std::string &file)
{
	return _sound->add_sound(mask, file);
}

void AEngine::s_stop_tracks(size_t index)
{
	_sound->stop_track(index);
}

void AEngine::s_pause_tracks(size_t index)
{
	_sound->pause_track(index);
}

void AEngine::s_play(char mask, size_t index)
{
	_sound->play(mask, index);
}

void AEngine::s_loop_tracks(size_t index, bool loop)
{
	_sound->loop_track(index, loop);
}

void AEngine::s_volume_tracks(size_t index, int volume)
{
	_sound->volume_track(index, volume);
}

void AEngine::s_remove_all()
{
	_sound->remove_all();
}

bool AEngine::running()
{
	return _gui->run();
}
