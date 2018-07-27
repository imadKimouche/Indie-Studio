/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** VSModeSettingTouchs.hpp
*/

#ifndef VSMODESETTINGTOUCHSCENE_HPP_
	#define VSMODESETTINGTOUCHSCENE_HPP_
	#include "IScene.hpp"
	#include <iostream>
	#include <string>
	#include "States/VSModeGameState.hpp"
VSModeSettingTouchs
class VSModeSettingTouchScene : public IScene {
public:
	VSModeSettingTouchScene(IStateProtocol *state);
	~VSModeSettingTouchScene();
	void update() final;
	void start() final;

protected:
private:
};

#endif /* !VSMODESETTINGTOUCHSCENE_HPP_ */
