/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** SoloModeGameState.hpp
*/

#ifndef SOLOMODEGAMESTATE_HPP_
	#define SOLOMODEGAMESTATE_HPP_
	#include "../BombermanProtocol.hpp"
	#include "IState.hpp"
	#include "../Scenes/SoloModeGameScene.hpp"

class SoloModeGameState : public IState, public IStateProtocol{
public:
	SoloModeGameState(BombermanProtocol *);
	~SoloModeGameState();
	void start() final;
	void update() final;
	void changeState(IState *newState) final;
	void changeScene(IScene *newScene) final;
	BombermanProtocol* getProtocol() final;
	void restart() final;
protected:
private:
};

#endif /* !SOLOMODEGAMESTATE_HPP_ */
