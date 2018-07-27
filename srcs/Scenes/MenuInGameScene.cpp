/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MenuIngameScene.cpp
*/

#include "Scenes/MenuInGameScene.hpp"

MenuInGameScene::MenuInGameScene(IStateProtocol *state)
{
	this->_state = state;
}

MenuInGameScene::~MenuInGameScene()
{
}

void MenuInGameScene::update()
{
}

void MenuInGameScene::returnInGame()
{
	_state->changeScene(_gameScene);
}

void MenuInGameScene::returnToMainMenu()
{
	_state->changeState();
}

void MenuInGameScene::start()
{
	
}