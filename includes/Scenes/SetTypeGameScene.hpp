/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Scene used for setting mode game
*/

#pragma once
#ifndef SETTYPEGAMESCENE_HPP_
	#define SETTYPEGAMESCENE_HPP_
	#include "IScene.hpp"
	#include "SoloModeSettingScene.hpp"
	#include "VSModeSettingScene.hpp"
	#include "../States/VSModeGameState.hpp"
	#include <iostream>
	#include "../AObject2D.hpp"

class SetTypeGameScene : public IScene, public Musician {
public:
	SetTypeGameScene(IStateProtocol *state);
	~SetTypeGameScene();
	void update() final;
	void start() final;
protected:
private:
	enum GameType {
		STORY,
		VSMODE
	};
	GameType _type;
	std::shared_ptr<Object2D> _background;
};

#endif /* !SETTYPEGAMESCENE_HPP_ */
