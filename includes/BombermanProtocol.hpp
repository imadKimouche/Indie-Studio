/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** BombermanProtocol.hpp
*/

#pragma once
#ifndef BOMBERMANPROTOCOL_HPP_
	#define BOMBERMANPROTOCOL_HPP_
	#include "States/IState.hpp"

class IState;
class BombermanProtocol {
public:
	~BombermanProtocol() {}
	virtual void changeState(IState *newState) = 0;
	virtual void restart() = 0;
protected:
private:
};

#endif /* !BOMBERMANPROTOCOL_HPP_ */