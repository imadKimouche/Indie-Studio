/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** 
*/

#include "Scenes/VSModeGameScene.hpp"

VSModeGameScene::VSModeGameScene(IStateProtocol *state, VSModeSetting vsModeSetting) : _gameMode(vsModeSetting._mapSize, vsModeSetting._characters, vsModeSetting._iAs)
{
	this->_state = state;
}

VSModeGameScene::~VSModeGameScene()
{
}

void VSModeGameScene::update()
{
	if (IrrlichtEngine::Instance().i_is_key(M_KEY_ESC))
		_state->restart();
	if (!_gameMode.update()) {
	}
}

void VSModeGameScene::start()
{
	std::cout << "VSModeGameScene starting" << std::endl;
	_gameMode.start();
	//IrrlichtEngine::Instance().g_set_camera(Camera(Coord3(4, 10, 4), Coord3(4, 0, 4)));
}