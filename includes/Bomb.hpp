/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
	#define BOMB_HPP_
	#include "ABomb.hpp"
	class Bomb;
	#include "GameModeProtocol.hpp"
	#include "Character.hpp"
	#include <chrono>
	#include <ctime>
	#include <unistd.h>
	#include <iostream>
	#include <sys/types.h>
	#define RADIUS_NORMAL_BOMB 5
	#define DEFAULT_TIME_BOMB 2
	#define BOMB_MESH "./ressources/bomb.obj"
	#define BOMB_TEXTURE "./ressources/textures/bomb.png"
	#define TIME_NORMAL_BOMB 5

	class Bomb : public ABomb {
		public:
			Bomb(Character *p, Coord2 pos2D, Coord3 pos3D, Coord3f scale);
			Bomb(Character *p, int radius, int delay);
			Bomb(Character *p);
			bool isExplose() const;
			~Bomb() = default;
			void explosion() override;
			bool putBomb() override;
			void update() override;

			// SETTER
			void setTime(int time) { _time = time;}
			void setPlayer(Character *player) { _player = player;}
			void setRadius(int radius) { _radius = radius;}

			// GETTER
			int getTime() const { return _time;}
			Character *getPlayer() const{ return _player;}
			int getRadius() const { return _radius;}
		protected:
			Character *_player;
			int _time;
			bool _explose;
			std::chrono::time_point<std::chrono::system_clock> _start;
	};
#endif /* !BOMB_HPP_ */
