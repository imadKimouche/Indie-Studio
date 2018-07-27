/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** VSModeSettingScene.hpp
*/

#include "Scenes/VSModeSettingScene.hpp"

VSModeSettingScene::VSModeSettingScene(IStateProtocol *state)
{
	this->_state = state;
}

VSModeSettingScene::~VSModeSettingScene()
{
}

void VSModeSettingScene::update()
{
	if (IrrlichtEngine::Instance().i_is_key(M_KEY_ESC)) {
		_state->restart();
	}
	if (IrrlichtEngine::Instance().i_is_key(M_KEY_ENTER)) {
		IrrlichtEngine::Instance().i_release_key(M_KEY_ENTER);
		if (_players.size() < 2) {
			std::cerr << "Not enough player" << std::endl;
			play("error.wav");
		} else {
			std::vector<std::shared_ptr<PlayerController>> characters;
			for (auto &player : _players) {
				if (player.getPlayerController() == 0) {
					std::cerr << "Can't create this type of player" << std::endl;
					play("error.wav");
					return ;
				} else {
					characters.push_back(player.getPlayerController());
				}
			}
			this->_state->changeState(new VSModeGameState(this->_state->getProtocol(), VSModeSetting(Coord2(12, 12), characters,
						std::vector<std::shared_ptr<IAController>>())));
		}
	} else if (IrrlichtEngine::Instance().i_is_key(M_KEY_SPACE)) {
		IrrlichtEngine::Instance().i_release_key(M_KEY_SPACE);
		if (_players.size() < 4) {
			play("new_challenger.wav");
			_players.push_back(PlayerSetting(_players.size()));
		} else {
			std::cerr << "You can't create more players" << std::endl;
			play("error.wav");
		}
	} else if (IrrlichtEngine::Instance().i_is_key(M_KEY_REMOVE)) {
		IrrlichtEngine::Instance().i_release_key(M_KEY_REMOVE);
		if (_players.size() > 0) {
			_players.back().destroy();
			_players.pop_back();
			play("error.wav");
		}
	}
	for (auto &player : _players) {
		player.update();
	}
}

void VSModeSettingScene::start()
{
	IrrlichtEngine::Instance().g_add_object(std::make_shared<Object2D>(Coord2(0, 0), std::string(IMG_DIR) + "background/VSMode.jpg"));
}
