/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SoloModeSettingScene
*/

#ifndef SOLOMODESETTINGSCENE_HPP_
	#define SOLOMODESETTINGSCENE_HPP_
	#include "IScene.hpp"
	#include <iostream>
	#include <string>
	#include "States/SoloModeGameState.hpp"

class SoloModeSettingScene : public IScene {
public:
	SoloModeSettingScene(IStateProtocol *state);
	~SoloModeSettingScene();
	void update() final;
	void start() final;
protected:
private:
};

#endif /* !SOLOMODESETTINGSCENE_HPP_ */