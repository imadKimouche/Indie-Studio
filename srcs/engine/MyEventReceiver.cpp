/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MyEventReceiver
*/

#include "Engine/MyEventReceiver.hpp"

bool MyEventReceiver::OnEvent(const irr::SEvent& event)
{
	if (!_data)
		return false;
	switch (event.EventType) {
	case irr::EET_KEY_INPUT_EVENT:
		if (event.KeyInput.PressedDown)
			_data->push_key(_data->_irrkey[event.KeyInput.Key]);
		else
			_data->release_key(_data->_irrkey[event.KeyInput.Key]);
		break;
	case irr::EET_LOG_TEXT_EVENT:
		break;
	case irr::EET_JOYSTICK_INPUT_EVENT:
		if (event.JoystickEvent.Joystick < MAX_JOYSTICK)
			compute_joy(event.JoystickEvent.Joystick, event.JoystickEvent);
		break;
	default:
		return false;
		break;
	}
	return true;
}

void MyEventReceiver::compute_joy(int joy, const irr::SEvent::SJoystickEvent &event)
{
	float moveHorizontal = event.Axis[irr::SEvent::SJoystickEvent::AXIS_X] / 32767.f;
	float moveVertical = event.Axis[irr::SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
	release_joystick();
	if(std::fabs(moveHorizontal) > 0.5f) {
		int key = (moveHorizontal > 0) ? M_JOYSTICK_LEFT : M_JOYSTICK_RIGHT ;
		_data->push_joystick(joy, key);
	}
	if(std::fabs(moveVertical) > 0.5f) {
		int key = (moveVertical > 0) ? M_JOYSTICK_TOP : M_JOYSTICK_DOWN ;
		_data->push_joystick(joy, key);
	}
	if (event.IsButtonPressed(M_JOYSTICK_A))
		_data->push_joystick(joy, M_JOYSTICK_A);
	if (event.IsButtonPressed(M_JOYSTICK_B))
		_data->push_joystick(joy, M_JOYSTICK_B);
	if (event.IsButtonPressed(M_JOYSTICK_X))
		_data->push_joystick(joy, M_JOYSTICK_X);
	if (event.IsButtonPressed(M_JOYSTICK_Y))
		_data->push_joystick(joy, M_JOYSTICK_Y);
	if (event.IsButtonPressed(M_JOYSTICK_L1))
		_data->push_joystick(joy, M_JOYSTICK_L1);
	if (event.IsButtonPressed(M_JOYSTICK_R1))
		_data->push_joystick(joy, M_JOYSTICK_R1);
	if (event.IsButtonPressed(M_JOYSTICK_SELECT))
		_data->push_joystick(joy, M_JOYSTICK_SELECT);
	if (event.IsButtonPressed(M_JOYSTICK_START))
		_data->push_joystick(joy, M_JOYSTICK_START);
	if (event.IsButtonPressed(M_JOYSTICK_XBOX))
		_data->push_joystick(joy, M_JOYSTICK_XBOX);
	if (event.IsButtonPressed(M_JOYSTICK_L3))
		_data->push_joystick(joy, M_JOYSTICK_L3);
	if (event.IsButtonPressed(M_JOYSTICK_R3))
		_data->push_joystick(joy, M_JOYSTICK_R3);
}

void MyEventReceiver::release_joystick()
{
	for (int i = 0; i < MAX_JOYSTICK; i++) {
		for (int j = 0; j < M_JOYSTICK_END; j++) {
			_data->release_joystick(i, j);
		}
	}
}
