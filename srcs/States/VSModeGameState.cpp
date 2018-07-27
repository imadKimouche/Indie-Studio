/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** 
*/

#include "States/VSModeGameState.hpp"

VSModeGameState::VSModeGameState(BombermanProtocol *bomberman, VSModeSetting vsModeSetting)
{
	this->_bomberman = bomberman;
	this->_actualScene = new VSModeGameScene(this, vsModeSetting);
}

VSModeGameState::~VSModeGameState()
{
}

void VSModeGameState::start()
{
	_actualScene->start();
}

void VSModeGameState::update()
{
	_actualScene->update();
}

void VSModeGameState::changeScene(IScene *newScene)
{
	//delete _actualScene;
	this->_actualScene = newScene;
}

void VSModeGameState::changeState(IState *newState)
{
	_bomberman->changeState(newState);
}

BombermanProtocol *VSModeGameState::getProtocol()
{
	return this->_bomberman;
}

void VSModeGameState::restart()
{
	_bomberman->restart();
}