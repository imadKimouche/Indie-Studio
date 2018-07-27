/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IScene.hpp
*/

#pragma once
#ifndef ISCENE_HPP_
	#define ISCENE_HPP_
	#include "../States/IStateProtocol.hpp"
	#include "../Engine/IrrlichtEngine.hpp"
class IScene {
public:
	~IScene() = default;
	virtual void update() = 0;
	virtual void start() = 0;
protected:
	IStateProtocol *_state;
private:
};

#endif /* !ISCENE_HPP_ */
