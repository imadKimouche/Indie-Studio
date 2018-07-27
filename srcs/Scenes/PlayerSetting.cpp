/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** PlayerSetting.cpp
*/

#include "Scenes/PlayerSetting.hpp"

static Coord2 _cursorEmplacements[5] = {Coord2(59, 486), Coord2(264, 486), Coord2(475, 486), Coord2(682, 486), Coord2(890, 486)};
static Coord2 _touchEmplacement[6] = {Coord2(250, 300), Coord2(60, 428), Coord2(401, 428), Coord2(235, 561), Coord2(620, 495), Coord2(795, 495)};

PlayerSetting::PlayerSetting(int id) : _id(id),  _selectionned(id)
{
	Coord2 coor;

	switch (id) {
	case 0: _cursorName = "./ressources/images/cursors/cursor1.png";
		coor = Coord2(16, 173);
		break;
	case 1: _cursorName = "./ressources/images/cursors/cursor2.png";
		coor = Coord2(268, 173);
		break;
	case 2: _cursorName = "./ressources/images/cursors/cursor3.png";
		coor = Coord2(516, 173);
		break;
	case 3: _cursorName = "./ressources/images/cursors/cursor4.png";
		coor = Coord2(764, 173);
		break;
	default:
		break;
	}
	_cursor = std::make_shared<Object2D>(_cursorEmplacements[_selectionned], _cursorName);
	_character = std::make_shared<Object2D>(coor, "./ressources/images/characters/bombermanPlayer.png");
	IrrlichtEngine::Instance().g_add_object(_cursor);
	IrrlichtEngine::Instance().g_add_object(_character);
	setUpTouch();
}

PlayerSetting::~PlayerSetting()
{
}

void PlayerSetting::destroy()
{
	IrrlichtEngine::Instance().g_remove_object(_cursor);
	IrrlichtEngine::Instance().g_remove_object(_character);
}

void PlayerSetting::changeCursor()
{
	IrrlichtEngine::Instance().g_remove_object(_cursor);
	_cursor = std::make_shared<Object2D>(_cursorEmplacements[_selectionned], _cursorName);
	IrrlichtEngine::Instance().g_add_object(_cursor);
}

void PlayerSetting::update()
{
	if (_keys[ACTION_RIGHT] > M_KEY_LAST) {
		if (IrrlichtEngine::Instance().i_is_joystick(_keys[ACTION_RIGHT] / 100 - 1, _keys[ACTION_RIGHT] % 100)) {
			IrrlichtEngine::Instance().i_release_joystick(_keys[ACTION_RIGHT] / 100 - 1, _keys[ACTION_RIGHT] % 100);
			if (_selectionned < 4) {
				_selectionned++;
				changeCursor();
			} else {
				play("Nope.wav");
			}
		} else if (IrrlichtEngine::Instance().i_is_joystick(_keys[ACTION_LEFT] / 100 - 1, _keys[ACTION_LEFT] % 100)) {
			IrrlichtEngine::Instance().i_release_joystick(_keys[ACTION_LEFT] / 100 - 1, _keys[ACTION_LEFT] % 100);
			if (_selectionned > 0) {
				_selectionned--;
				changeCursor();
			} else {
				play("Nope.wav");
			}
		}
		return ;
	}
	if (IrrlichtEngine::Instance().i_is_key(_keys[ACTION_RIGHT])) {
		IrrlichtEngine::Instance().i_release_key(_keys[ACTION_RIGHT]);
		if (_selectionned < 4) {
			_selectionned++;
			changeCursor();
		} else {
			play("Nope.wav");
		}
	} else if (IrrlichtEngine::Instance().i_is_key(_keys[ACTION_LEFT])) {
		IrrlichtEngine::Instance().i_release_key(_keys[ACTION_LEFT]);
		if (_selectionned > 0) {
			_selectionned--;
			changeCursor();
		} else {
			play("Nope.wav");
		}
	}
}

std::shared_ptr<PlayerController> PlayerSetting::getPlayerController()
{
	std::shared_ptr<PlayerController> playerController = 0;

	switch (_selectionned) {
	/*case 0: playerController = std::make_shared<PlayerController>(std::make_shared<Thief>(Coord(0,0), nullptr));
		playerController->set_keys(_keys);
		break;*/
	case 1: playerController = std::make_shared<PlayerController>(std::make_shared<Marathonian>(Coord2(0,0), nullptr));
		playerController->set_keys(_keys);
		break;
	case 2: playerController = std::make_shared<PlayerController>(std::make_shared<Builder>(Coord2(0,0), nullptr));
		playerController->set_keys(_keys);
		break;
	case 3: playerController = std::make_shared<PlayerController>(std::make_shared<Illusioniste>(Coord2(0,0), nullptr));
		playerController->set_keys(_keys);
		break;
	case 4: playerController = std::make_shared<PlayerController>(std::make_shared<Hunter>(Coord2(0,0), nullptr));
		playerController->set_keys(_keys);
		break;
	default:
		return 0;
	}
	return playerController;
}

void PlayerSetting::refresh(std::shared_ptr<IObject> &img, int i, std::vector<std::shared_ptr<ObjectText>> inputs)
{
	(void) inputs;
	std::string s = IMAGES_DIR;
	s += std::to_string(i + 1);
	s += ".png";
	IrrlichtEngine::Instance().g_remove_object(img);
	img = std::make_shared<Object2D>(Coord2(0, 0), s);
	IrrlichtEngine::Instance().g_add_object(img);
}

bool PlayerSetting::checkTouch(int touch, int i)
{
	for (int j = 0 ; j < i ; j++) {
		if (touch == _keys[j] || touch == M_KEY_REMOVE || touch == M_KEY_ENTER || touch == M_KEY_ESC)
			return false;
	}
	return true;
}

int StringToWString(std::wstring &ws, const std::string &s)
{
    std::wstring wsTmp(s.begin(), s.end());

    ws = wsTmp;

    return 0;
}

void PlayerSetting::addTextTouch(std::vector<std::shared_ptr<ObjectText>> &text, std::string str, int i)
{
	std::wstring ws(str.begin(), str.end());
	std::wcout << ws << std::endl;
	text.push_back(std::make_shared<ObjectText>(_touchEmplacement[i], L"OK", "fonttest.png", Color(255, 0, 0, 0)));
}

void PlayerSetting::setUpTouch()
{
	int i = 0;
	std::string s = IMAGES_DIR;
	s += "1.png";
	std::shared_ptr<IObject> img = std::make_shared<Object2D>(Coord2(0, 0), s);
	std::vector<std::shared_ptr<ObjectText>> text;
	int touch = 0;

	for (int i = 0; i < TOTAL_KEY; i++)
		_keys[i] = 0;
	IrrlichtEngine::Instance().g_add_object(img);
	while (i < 7 && IrrlichtEngine::Instance().running()) {
		IrrlichtEngine::Instance().update();
		if (IrrlichtEngine::Instance().i_get_keys().size() > 0 && (touch = IrrlichtEngine::Instance().i_get_keys().front())) {
			IrrlichtEngine::Instance().i_release_all();
			if (touch == M_KEY_REMOVE) {
				if (i > 0) {
					i--;
					IrrlichtEngine::Instance().g_remove_object(text.back());
					text.pop_back();
					refresh(img, i, text);
				}
			} else if (i < 6) {
				if (checkTouch(touch, i)) {
					_keys[i] = touch;
					std::string touchStr = IrrlichtEngine::Instance().i_translate_key(touch);
					addTextTouch(text, touchStr, i);
					IrrlichtEngine::Instance().g_add_object(text.back());
					i++;
					refresh(img, i, text);
					play("cmd_set.wav");
				} else {
					play("error.wav");
				}
			} else {
				if (touch == M_KEY_ENTER) {
					i++;
					IrrlichtEngine::Instance().g_remove_object(img);
					for (auto input : text) {
						IrrlichtEngine::Instance().g_remove_object(input);
					}
					break;
				}
			}
		}
	}
}