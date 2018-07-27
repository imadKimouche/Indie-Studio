/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Hunter
*/

#ifndef HUNTER_HPP_
	#define HUNTER_HPP_
	#define NAME_CLASS_HUNTER "Hunter"
	#define INITIAL_DELAY_HUNTER 3
	#define HUNTERCOOLDOWN 30
	#include "Player.hpp"
	#include "Musician.hpp"
	#include "../GameObject/Trap.hpp"

	class Hunter : public Player, public Musician {
		public:
			Hunter(Coord2 spone, GameModeProtocol* gameModeProtocol);
			~Hunter() = default;
			void special() override;
			void update() override;
	};
#endif /* !HUNTER_HPP_ */
