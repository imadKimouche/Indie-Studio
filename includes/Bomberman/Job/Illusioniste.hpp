/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Illusioniste
*/

#ifndef ILLUSIONISTE_HPP_
	#define ILLUSIONISTE_HPP_
	#define NAME_CLASS_ILLUSIONISTE "Illusioniste"
	#include "Player.hpp"
	#include "Musician.hpp"

	class Illusioniste : public Player, public Musician {
		public:
			Illusioniste(Coord2 spone, GameModeProtocol* gameModeProtocol);
			~Illusioniste() = default;
			void special() override;
			void update() override;
			void teleportation();
		protected:
			Coord2 _portail;
			int _teleporting;
		private:
	};
#endif /* !ILLUSIONISTE_HPP_ */
