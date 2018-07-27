//
// EPITECH PROJECT, 2018
// Indie Studio
// File description:
// Player Controller
//


#ifndef PLAYERCONTROLLER_HPP_
#define PLAYERCONTROLLER_HPP_

#include "IController.hpp"
#include "Bomberman/Job/Marathonian.hpp"
#include "Bomberman/Job/Illusioniste.hpp"
class PlayerController: public IController
{
private:
	int _keys[TOTAL_KEY];
	std::shared_ptr<Character> _character;
public:
	PlayerController(std::shared_ptr<Character> player);
	~PlayerController() = default;
	void set_keys(int keys[TOTAL_KEY]) override;
  void update() override;
	std::shared_ptr<Character> get_character() override;
	bool checkKey(int key);
};

#endif /* !PLAYERCONTROLLER */
