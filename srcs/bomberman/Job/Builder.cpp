/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Builder
*/

#include "Bomberman/Job/Builder.hpp"


Builder::Builder(Coord2 spone, GameModeProtocol* gameModeProtocol  = NULL) : Player(spone,gameModeProtocol)
{
	_name = NAME_CLASS_BUILDER;
	_durationSpec = 10;
}

void Builder::special()
{
	Coord3 pos = getDir();

	if (!CheckTimeLeft(_durationSpec, _endSpec))
		return;
	if (_gameModeProtocol->isFreeInCase({pos.x, pos.z}) && _gameModeProtocol->addWall(pos)) {
		_startSpec = std::chrono::system_clock::now();
		_endSpec = std::chrono::system_clock::now();
	}
}

void Builder::update()
{
	return;
}
