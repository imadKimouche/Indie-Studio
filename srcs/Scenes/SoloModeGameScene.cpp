/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SoloModeGameScene.cpp
*/

#include "Scenes/SoloModeGameScene.hpp"

SoloModeGameScene::SoloModeGameScene(IStateProtocol *state)
{
	std::vector<std::shared_ptr<PlayerController>> characters;
	std::vector<std::shared_ptr<IAController>> iAs;
	std::shared_ptr<IAController> ia;
	Coord2 coor(10, 10);
	if (coor.x % 2 == 0) {
		coor.x++;
	}
	if (coor.y % 2 == 0) {
		coor.y++;
	}
	characters.push_back(std::make_shared<PlayerController>(std::make_shared<Illusioniste>(Coord2(0, 0), nullptr)));
	ia = std::make_shared<IAController>(std::make_shared<Illusioniste>(Coord2(0, 0), nullptr), coor);
	iAs.push_back(ia);
	this->_gameMode = new GameMode(coor, characters, iAs);
	this->_state = state;
}

SoloModeGameScene::~SoloModeGameScene()
{
}

void SoloModeGameScene::update()
{
	if (IrrlichtEngine::Instance().i_is_key(M_KEY_ESC))
		_state->restart();
	if (!_gameMode->update()) {
		//_state->restart();
	}
}

void SoloModeGameScene::start()
{
	_gameMode->start();
	//IrrlichtEngine::Instance().g_set_camera(Camera(Coord3(4, 10, 4), Coord3(4, 0, 4)));
}
