/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MainMenu.hpp
*/

#pragma once
#ifndef MAINMENU_HPP_
	#define MAINMENU_HPP_
	#include "../BombermanProtocol.hpp"
	#include "IState.hpp"
	#include "../Scenes/SetTypeGameScene.hpp"

class MainMenu : public IState, public IStateProtocol {
public:
	MainMenu(BombermanProtocol *);
	~MainMenu();
	void start() final;
	void update() final;
	void changeState(IState *newState) final;
	BombermanProtocol *getProtocol() override;
	void changeScene(IScene *newScene) final;
	void restart() final;
protected:
private:
};

#endif /* !MAINMENU_HPP_ */
