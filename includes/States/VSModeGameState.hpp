/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** 
*/

#ifndef VSMODEGAMESTATE_HPP_
	#define VSMODEGAMESTATE_HPP_
	#include "../BombermanProtocol.hpp"
	#include "IState.hpp"
	#include "../Scenes/VSModeGameScene.hpp"
	#include "VSModeSetting.hpp"
	#include <vector>
	#include <memory>
	#include "../IController.hpp"

class VSModeGameState : public IState, public IStateProtocol {
public:
	VSModeGameState(BombermanProtocol *bomberman, VSModeSetting vsModeSetting);
	~VSModeGameState();
	void start() final;
	void update() final;
	void changeState(IState *newState) final;
	void changeScene(IScene *newScene) final;
	BombermanProtocol* getProtocol() final;
	void restart() final;

protected:
private:
};

#endif /* !VSMODEGAMESTATE_HPP_ */