//
// EPITECH PROJECT, 2018
// Indie Studio
// File description:
// Player Controller
//

#include "PlayerController.hpp"

PlayerController::PlayerController(std::shared_ptr<Character> player)
{
	for (int i = 0; i < 5; i++)
		_keys[i] = 0;
	_keys[ACTION_UP] = M_KEY_UP;
	_keys[ACTION_DOWN] =  M_KEY_DOWN;
	_keys[ACTION_RIGHT] =  M_KEY_RIGHT;
	_keys[ACTION_LEFT] =  M_KEY_LEFT;
	_keys[ACTION_1] =  M_KEY_A;
	_keys[ACTION_2] =  M_KEY_Z;
	_character = player;
}

void PlayerController::set_keys(int keys[TOTAL_KEY])
{
	for (int i = 0; i < TOTAL_KEY; i++)
		_keys[i] = keys[i];
}

bool PlayerController::checkKey(int key)
{
	if (_keys[key] < 100) {
		if (IrrlichtEngine::Instance().i_is_key(_keys[key]))
			return true;
	} else {
		if (IrrlichtEngine::Instance().i_is_joystick(_keys[key] / 100 - 1, _keys[key] % 100)) {
			std::cout << "/* message */" << '\n';
			return true;
		}
	}
	return false;
}

void PlayerController::update()
{
	_character->update();
	if (!_character)
		return;
	if (checkKey(ACTION_1))
		_character->poseBomb();
	if (checkKey(ACTION_2))
		_character->special();
	if (!_character->getMove())
		return;
	if (checkKey(ACTION_UP))
		_character->move({0, 1});
	else if (checkKey(ACTION_DOWN))
		_character->move({0, -1});
	else if (checkKey(ACTION_RIGHT))
		_character->move({1, 0});
	else if (checkKey(ACTION_LEFT))
		_character->move({-1, 0});
}

std::shared_ptr<Character> PlayerController::get_character()
{
	return _character;
}
