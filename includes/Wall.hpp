/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Wall.hpp
*/

#ifndef WALL_HPP_
	#define WALL_HPP_
	#define WALL_MESH "./ressources/cube.obj"
	#define WALL_TEXTURE "./ressources/textures/wall.png"
	#define WALL_MESH_DESTRUCTIBLE "./ressources/cube.obj"
	#define WALL_TEXTURE_DESTRUCTIBLE "./ressources/textures/wall_d.png"
	#define MAX_POWERSTATSCH 6
	#define CHANCEOFDROP 25
	#include "IObject.hpp"
	#include "AObject3D.hpp"
	#include "PowerStat.hpp"
	#include <experimental/random>
	#include <memory>

class Wall : public AObject3D {
	public:
		Wall(bool,Coord3);
		~Wall();
		std::shared_ptr<APowerUp> destroy();
	protected:
		bool _destroyable;
	};

#endif /* !WALL_HPP_ */
