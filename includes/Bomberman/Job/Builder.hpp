/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Builder
*/

#ifndef BUILDER_HPP_
	#define BUILDER_HPP_
	#define NAME_CLASS_BUILDER "BUILDER"
	#include "Player.hpp"
	#include "Musician.hpp"

	class Builder : public Player, public Musician {
		enum DIR {
			HAUT,
			BAS,
			DROIT,
			GAUCHE
		};
		public:
			Builder(Coord2 spone, GameModeProtocol* gameModeProtocol);
			~Builder() = default;
			void special() override;
			void update() override;
		protected:
		private:
	};

#endif /* !BUILDER_HPP_ */
