/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SoloModeSettingScene.cpp
*/

#include "Scenes/SoloModeSettingScene.hpp"

SoloModeSettingScene::SoloModeSettingScene(IStateProtocol *state)
{
	this->_state = state;
}

SoloModeSettingScene::~SoloModeSettingScene()
{
}

void SoloModeSettingScene::update()
{
	_state->changeState(new SoloModeGameState(_state->getProtocol()));
}

void SoloModeSettingScene::start()
{
	
}
