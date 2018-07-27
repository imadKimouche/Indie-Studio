/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Setting mode game scene
*/

#include "Scenes/SetTypeGameScene.hpp"

SetTypeGameScene::SetTypeGameScene(IStateProtocol *state)
{
	this->_state = state;
	_type = STORY;
}

SetTypeGameScene::~SetTypeGameScene()
{
}

void SetTypeGameScene::update()
{
	if (IrrlichtEngine::Instance().i_is_key(M_KEY_ESC)) {
		_state->restart();
	}
	if (IrrlichtEngine::Instance().i_is_key(M_KEY_UP) || IrrlichtEngine::Instance().i_is_key(M_KEY_DOWN)) {
		if (_type == VSMODE) {
			_type = STORY;
			IrrlichtEngine::Instance().g_remove_object(_background);
			_background = std::make_shared<Object2D>(Coord2(0, 0), "./ressources/images/background/StoryModeSelected.jpg");
			IrrlichtEngine::Instance().g_add_object(_background);
		} else {
			_type = VSMODE;
			IrrlichtEngine::Instance().g_remove_object(_background);
			_background = std::make_shared<Object2D>(Coord2(0, 0), "./ressources/images/background/VSModeSelected.jpg");
			IrrlichtEngine::Instance().g_add_object(_background);			
		}
		play("cmd_set.wav");
		IrrlichtEngine::Instance().i_release_key(M_KEY_UP);
		IrrlichtEngine::Instance().i_release_key(M_KEY_DOWN);
	}
	if (IrrlichtEngine::Instance().i_is_key(M_KEY_ENTER)) {
		if (_type == STORY)
			this->_state->changeScene(new SoloModeSettingScene(this->_state));
		else
			this->_state->changeScene(new VSModeSettingScene(this->_state));
	}
}

void SetTypeGameScene::start()
{
	_background = std::make_shared<Object2D>(Coord2(0, 0), std::string(IMG_DIR) + "background/StoryModeSelected.jpg");
	IrrlichtEngine::Instance().g_add_object(_background);
}