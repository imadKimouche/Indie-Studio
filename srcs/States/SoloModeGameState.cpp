/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SoloModeGameState.cpp
*/

#include "States/SoloModeGameState.hpp"

SoloModeGameState::SoloModeGameState(BombermanProtocol *bomberman)
{
	this->_bomberman = bomberman;
	this->_actualScene = new SoloModeGameScene(this);
}

SoloModeGameState::~SoloModeGameState()
{
}

void SoloModeGameState::start()
{
	_actualScene->start();
}

void SoloModeGameState::update()
{
	_actualScene->update();
}

void SoloModeGameState::changeScene(IScene *newScene)
{
	//delete _actualScene;
	this->_actualScene = newScene;
}

void SoloModeGameState::changeState(IState *newState)
{
	_bomberman->changeState(newState);
}

BombermanProtocol *SoloModeGameState::getProtocol()
{
	return this->_bomberman;
}

void SoloModeGameState::restart()
{
	_bomberman->restart();
}
