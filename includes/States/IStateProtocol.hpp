/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IStateProtocol.hpp (change scenes)
*/

#pragma once
#ifndef ISTATEPROTOCOL_HPP_
	#define ISTATEPROTOCOL_HPP_
	#include "../Scenes/IScene.hpp"
	#include "IState.hpp"
class IScene;
class IState;
class IStateProtocol {
public:
	~IStateProtocol() {}
	virtual void changeScene(IScene *newScene) = 0;
	virtual void changeState(IState *newState) = 0;
	virtual void restart() = 0;
	virtual BombermanProtocol *getProtocol() = 0;
protected:
private:
};

#endif /* !ISTATEPROTOCOL_HPP_ */