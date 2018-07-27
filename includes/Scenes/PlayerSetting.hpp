/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** PlayerSetting.hpp
*/

#ifndef PLAYERSETTING_HPP_
	#define PLAYERSETTING_HPP_
	#include "../IController.hpp"
	#include "../PlayerController.hpp"
	#include "./Bomberman/Job/Builder.hpp"
	#include "./Bomberman/Job/Hunter.hpp"
	#include "Musician.hpp"
	#define IMAGES_DIR "./ressources/images/Input/InputMode"

class PlayerSetting : public Musician {
public:
	PlayerSetting(int id);
	~PlayerSetting();
	void setUpTouch();
	void update();
	void changeCursor();
	std::shared_ptr<PlayerController> getPlayerController();
	void destroy();
	void refresh(std::shared_ptr<IObject> &img, int i, std::vector<std::shared_ptr<ObjectText>> inputs);
	bool checkTouch(int touch, int i);
	void addTextTouch(std::vector<std::shared_ptr<ObjectText>> &text, std::string str, int i);
	int _keys[TOTAL_KEY];
	int _id;
	int _selectionned;
	std::string _cursorName;
	std::shared_ptr<Object2D> _cursor;
	std::shared_ptr<Object2D> _character;
};

int StringToWString(std::wstring &ws, const std::string &s);

#endif /* !PLAYERSETTING_HPP_ */
