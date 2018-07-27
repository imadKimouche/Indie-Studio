/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MenuInGame.hpp
*/

#ifndef MENUINGAMESCENE_HPP_
	#define MENUINGAMESCENE_HPP_
	#include "IScene.hpp"
	#include <iostream>

class MenuInGameScene : public IScene {
public:
	MenuInGameScene(IStateProtocol *state, IScene *gameScene);
	~MenuInGameScene();
	void update() override;
	void start() override;
	void returnInGame();
	void returnToMainMenu();
protected:
private:
	IScene *_gameScene;
};

#endif /* !MENUINGAMESCENE_HPP_ */
