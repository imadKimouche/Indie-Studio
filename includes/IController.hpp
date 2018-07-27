//
// EPITECH PROJECT, 2018
// Indie studio
// File description:
// Controller interface
//

#ifndef ICONTROLLER_HPP_
#define ICONTROLLER_HPP_

#include "Engine/IrrlichtEngine.hpp"
#include "Character.hpp"

#define TOTAL_KEY TOTAL_ACTION + TOTAL_MOVEMENT
#define TOTAL_ACTION 2
#define TOTAL_MOVEMENT 4
#define ACTION_UP 0
#define ACTION_DOWN 3
#define ACTION_RIGHT 2
#define ACTION_LEFT 1
#define ACTION_1 4
#define ACTION_2 5

class IController
{
public:
	virtual ~IController() {};
	virtual void update() = 0;
	virtual void set_keys(int keys[TOTAL_KEY]) = 0;
	virtual std::shared_ptr<Character> get_character() = 0;
protected:
	std::shared_ptr<Character> identity;
};

#endif
