/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** State.hpp
*/

#pragma once
#ifndef ISTATE_HPP_
	#define ISTATE_HPP_
class BombermanProtocol;
class IScene;
class IState {
public:
	virtual ~IState() {};
	virtual void start() = 0;
	virtual void update() = 0;
protected:
	BombermanProtocol *_bomberman;
	IScene *_actualScene;
private:
};

#endif /* !ISTATE_HPP_ */
