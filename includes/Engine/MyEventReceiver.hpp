/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MyEventReceiver header file
*/

#ifndef MYEVENTRECEIVER_HPP_
#define MYEVENTRECEIVER_HPP_

class MyEventReceiver;
#include <irr/irrlicht.h>
#include "Irrlicht.hpp"

class MyEventReceiver : public irr::IEventReceiver
{
public:
	MyEventReceiver(Irrlicht *data) : _data(data) {}
	~MyEventReceiver() = default;
	virtual bool OnEvent(const irr::SEvent& event);
	void compute_joy(int joy, const irr::SEvent::SJoystickEvent &event);
	virtual void release_joystick();
private:
	Irrlicht *_data;
};

#endif
