/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Player
*/

#ifndef PLAYER_HPP_
	#define PLAYER_HPP_
	#define INITIAL_DELAY_BOMB 3
	#define NAME_PERSO "belzeee"
	#define MESH_PERSO "./ressources/bomberman.obj"
	#define TEXTURE_PERSO "./ressources/textures/bman_txtr.png"
	#define DELAY_SPECIALISATION 2
	#include "Character.hpp"
	#include <chrono>
	#include "Bomb.hpp"

	class Player : public Character {
		public:
			Player (const std::string &name,Coord2 &pos2D, Coord3 &pos3D, Coord3f &scale,const std::string &m, const std::string &t, GameModeProtocol* gameModeProtocol = NULL);
			Player (GameModeProtocol* gameModeProtocol = NULL);
			Player (Coord2 &spone, GameModeProtocol* gameModeProtocol  = NULL);
			~Player();
			bool CheckTimeLeft(int timetocompare, std::chrono::time_point<std::chrono::system_clock> end) const;
			virtual void update() override = 0;
			virtual void special() override = 0;
		protected:
			Coord3 getDir() const;
		protected:
			std::chrono::time_point<std::chrono::system_clock> _startSpec;
			std::chrono::time_point<std::chrono::system_clock> _endSpec;
			int _durationSpec;
			bool _inUse;
	};
#endif /* !PLAYER_HPP_ */
