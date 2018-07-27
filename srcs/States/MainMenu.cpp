/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MainMenu.cpp
*/

#include "States/MainMenu.hpp"

MainMenu::MainMenu(BombermanProtocol *bomberman)
{
	this->_bomberman = bomberman;
	this->_actualScene = new SetTypeGameScene(this);
}

MainMenu::~MainMenu()
{
	//delete _actualScene;
}

void MainMenu::start()
{
	this->_actualScene->start();
}

void MainMenu::update()
{
	_actualScene->update();
}

void MainMenu::changeScene(IScene *newScene)
{
	//delete _actualScene;
	IrrlichtEngine::Instance().e_clear_scene();
	this->_actualScene = newScene;
	this->_actualScene->start();
}

void MainMenu::changeState(IState *newState)
{
	_bomberman->changeState(newState);
}

BombermanProtocol *MainMenu::getProtocol()
{
	return this->_bomberman;
}

void MainMenu::restart()
{
	_bomberman->restart();
}