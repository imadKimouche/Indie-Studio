/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Hunter
*/

#include "Bomberman/Job/Hunter.hpp"

Hunter::Hunter(Coord2 spone, GameModeProtocol* gameModeProtocol  = NULL) : Player(spone,gameModeProtocol)
{
	_name = NAME_CLASS_HUNTER;
	_durationSpec = INITIAL_DELAY_HUNTER;
}

void Hunter::special()
{
	std::shared_ptr<Trap> trap;
	Coord3 pos = getDir();

	if (!CheckTimeLeft(HUNTERCOOLDOWN, _endSpec))
		return;
	trap =  std::make_shared<Trap>(_durationSpec, pos);
	if (_gameModeProtocol->isFreeInCase(trap.get()->getPosition2D())) {
		_gameModeProtocol->putPowerUp(trap);
		_startSpec = std::chrono::system_clock::now();
		_endSpec = std::chrono::system_clock::now();
	}
}

void Hunter::update()
{
	return;
}
