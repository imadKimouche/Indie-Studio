/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** VSModeGameScene.hpp
*/

#ifndef VSMODEGAMESCENE_HPP_
	#define VSMODEGAMESCENE_HPP_
	#include "IScene.hpp"
	#include <iostream>
	#include <string>
	#include "../MapObserver.hpp"
	#include "../IController.hpp"
	#include "../Wall.hpp"
	#include "../Bomb.hpp"
	#include "../Bomberman/GameObject/Floor.hpp"
	#include "../APowerUp.hpp"
	#include "../GameMode.hpp"
	#include "../States/VSModeSetting.hpp"

class VSModeGameScene : public IScene {
public:
	VSModeGameScene(IStateProtocol *state, VSModeSetting vsModeSetting);
	~VSModeGameScene();
	void update() final;
	void start() final;
protected:
private:
	GameMode _gameMode;
};

#endif /* !VSMODEGAMESCENE_HPP_ */
