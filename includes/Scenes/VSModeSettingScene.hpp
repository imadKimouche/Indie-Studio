/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** 
*/

#ifndef VSMODESETTINGSCENE_HPP_
	#define VSMODESETTINGSCENE_HPP_
	#include "IScene.hpp"
	#include <iostream>
	#include <string>
	#include "States/VSModeGameState.hpp"
	#include "PlayerSetting.hpp"
	#include "Musician.hpp"

class VSModeSettingScene : public IScene, public Musician {
public:
	VSModeSettingScene(IStateProtocol *state);
	~VSModeSettingScene();
	void update() final;
	void start() final;
protected:
private:
	std::vector<PlayerSetting> _players;
};

#endif /* !VSMODESETTINGSCENE_HPP_ */
