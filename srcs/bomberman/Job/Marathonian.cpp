/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Marathonian
*/

#include "Bomberman/Job/Marathonian.hpp"

Marathonian::Marathonian(Coord2 spone, GameModeProtocol* gameModeProtocol  = NULL) : Player(spone,gameModeProtocol)
{
	_name = NAME_CLASS_MARATHONIAN;
	_normalSpeed = getSpeed();
}

void Marathonian::special()
{
	if (_inUse || (!_inUse && !CheckTimeLeft(TIMETOREUSEPOWER, _endSpec)))
		return;
	_inUse = true;
	_normalSpeed = getSpeed();
	setSpeed(getSpeed() - SPEEDMOVEMARATHONIAN);
	_startSpec = std::chrono::system_clock::now();
}

void Marathonian::update()
{
	std::chrono::time_point<std::chrono::system_clock> end;
	int seconds = 0;
	
	end = std::chrono::system_clock::now();
	seconds =  std::chrono::duration_cast<std::chrono::seconds>(end - _startSpec).count();
	if (_inUse  && seconds >= _durationSpec) {
		setSpeed(_normalSpeed);
		_endSpec = end;
		_inUse = false;
	}
}

