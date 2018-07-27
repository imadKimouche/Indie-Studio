/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Illusioniste
*/
#include "Bomberman/Job/Illusioniste.hpp"

Illusioniste::Illusioniste(Coord2 spone, GameModeProtocol* gameModeProtocol  = NULL) : Player(spone,gameModeProtocol)
{
	_name = NAME_CLASS_ILLUSIONISTE;
	_durationSpec = 10;
	_teleporting = 0;
	_animation._start = 0;
	_animation._end = 0;
	_animation._frame = 0;
}

void Illusioniste::special()
{
	if (_inUse && CheckTimeLeft(2, _startSpec)) {
		teleportation();
		return;
	}
	if (_inUse)
		return;
	if (!_inUse && !CheckTimeLeft(TIMETOREUSEPOWER, _endSpec))
		return;
	_inUse = true;
	_portail = this->getPosition2D();
	_startSpec = std::chrono::system_clock::now();
}

void Illusioniste::update()
{
	std::chrono::time_point<std::chrono::system_clock> end;
	int seconds = 0;

	if (_animation._moving && _animation._end != 13) {
		_animation.frameSpeed(0, 13, 30);
	} else if (!_animation._moving && _animation._end != 205)
		_animation.frameSpeed(184, 205, 7);
	if (getAnimation()._teleport)
		getAnimation()._teleport = false;
	end = std::chrono::system_clock::now();
	seconds =  std::chrono::duration_cast<std::chrono::seconds>(end - _startSpec).count();
	if ((_inUse && seconds < _durationSpec) || !_inUse)
		return;
	teleportation();
}

void Illusioniste::teleportation()
{
	std::chrono::time_point<std::chrono::system_clock> end;

	end = std::chrono::system_clock::now();
	if (_gameModeProtocol->isFreeInCase(_portail)) {
		play("illusioniste.wav");
		_portail.x = _portail.x - getPosition2D().x;
		_portail.y = _portail.y - getPosition2D().y;
		getAnimation()._teleport = true;
		this->move(_portail);
	}
	_endSpec = end;
	_inUse = false;
}
