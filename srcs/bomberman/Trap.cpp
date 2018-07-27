/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Trap
*/

#include "Bomberman/GameObject/Trap.hpp"

Trap::Trap(int delay, Coord3 pos) : APowerUp()
{
	_delay = delay;
	this->setPosition3D(pos);
	this->_pos2D.x = pos.x;
	this->_pos2D.y = pos.z;
    	_mesh = MESH_TRAP;
	_texture = TEXTURE_TRAP;
	_inUse = false;
	_passed = false;
	//setScale(Coord3f(0.6f, 0.6f, 0.6f));
}

bool Trap::affect(std::shared_ptr<Character> ch)
{
	if (ch.get() == NULL || ch == nullptr)
        	return false;
	if (!_passed && !_inUse) {
		ch.get()->setMove(false);
		_start = std::chrono::system_clock::now();
		_passed = true;
	}
	if (_inUse)
		ch.get()->setMove(true);
    	return _inUse;
}

void Trap::update()
{
	std::chrono::time_point<std::chrono::system_clock> now;
	int seconds = 0;

	now = std::chrono::system_clock::now();
	seconds =  std::chrono::duration_cast<std::chrono::seconds>(now - _start).count();
	if (_passed && seconds >= _delay)
		_inUse = true;
}