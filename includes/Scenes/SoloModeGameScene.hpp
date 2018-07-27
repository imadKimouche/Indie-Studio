/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** SoloModeGameScene
*/

#ifndef SOLOMODEGAMESCENE_HPP_
	#define SOLOMODEGAMESCENE_HPP_
	#include "IScene.hpp"
	#include <iostream>
	#include <string>
	#include "../MapObserver.hpp"
	#include "../PlayerController.hpp"
	#include "../Wall.hpp"
	#include "../Bomb.hpp"
	#include "../Bomberman/GameObject/Floor.hpp"
	#include "../APowerUp.hpp"
	#include "../GameMode.hpp"

class SoloModeGameScene : public IScene {
public:
	SoloModeGameScene(IStateProtocol *state);
	~SoloModeGameScene();
	void update() override;
	void start() final;
protected:
private:
	GameMode *_gameMode;
};
#endif /* !SOLOMODEGAMESCENE_HPP_ */
