/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Wall.cpp
*/

#include "Wall.hpp"

static int PowerStatCh[MAX_POWERSTATSCH] = { P_NB_BOMB_MAX, M_NB_BOMB_MAX, P_RADIUS_BOMB_MAX, M_RADIUS_BOMB_MAX, P_SPEED, M_SPEED};

Wall::Wall(bool isDestroyable,Coord3 pos) : AObject3D(), _destroyable(isDestroyable)
{
	_pos3D = pos;
	_pos2D = Coord2(pos.x, pos.z);

	_mesh = WALL_MESH;
	if (_destroyable)
		_texture = WALL_TEXTURE_DESTRUCTIBLE;
	else
		_texture = WALL_TEXTURE;

	//generation d'un powerUp aleatoire
}

Wall::~Wall()
{

}

std::shared_ptr<APowerUp> Wall::destroy()
{
	int random_index = 0;
	int drop_chance = 0;

	if (!_destroyable)
		return 0;
	drop_chance = std::experimental::randint(0, 100);
	if (drop_chance > CHANCEOFDROP)
		return 0;
	random_index = std::experimental::randint(0, (MAX_POWERSTATSCH - 1));
	if (random_index < MAX_POWERSTATSCH)
		return std::make_shared<PowerStat>(PowerStatCh[random_index],this->getPosition3D());
	return 0;
}
