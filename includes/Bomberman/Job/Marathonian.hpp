/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Marathonian
*/

#ifndef MARATHONIAN_HPP_
	#define MARATHONIAN_HPP_
	#define NAME_CLASS_MARATHONIAN "Marathonian"
	#define SPEEDMOVEMARATHONIAN 0.2
	#include "Player.hpp"

	class Marathonian : public  Player {
		public:
			Marathonian(Coord2 spone, GameModeProtocol* gameModeProtocol);
			~Marathonian() = default;
			void special() override;
			void update() override;
		protected:
			float _normalSpeed;
	};

#endif /* !MARATHONIAN_HPP_ */
