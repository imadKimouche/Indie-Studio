/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Bomberman.hpp
*/

#pragma once

#ifndef BOMBERMAN_HPP_
	#define BOMBERMAN_HPP_
	#include "BombermanProtocol.hpp"
	#include "States/IState.hpp"
	#include "States/MainMenu.hpp"
	#include "States/SoloModeGameState.hpp"
	#include "Musician.hpp"
	#include <thread>
	#include <chrono>
class Bomberman : public BombermanProtocol, public Musician {
public:
	Bomberman();
	~Bomberman();
	void start();
	void intro();
	void changeState(IState *newState) final;
	void restart() final;
protected:
private:
	IState *_state;
};

#endif /* !BOMBERMAN_HPP_ */
