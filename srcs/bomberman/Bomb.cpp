/*
** EPITECH PROJECT, 2018
** INdi
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomb::Bomb(Character *p, Coord2 pos2D, Coord3 pos3D, Coord3f scale) : ABomb(pos2D,pos3D,scale,BOMB_MESH,BOMB_TEXTURE)
{
	this->_player = p;
	this->_radius = RADIUS_NORMAL_BOMB;
	this->_time = DEFAULT_TIME_BOMB;
	this->_Bombtype = BOMB_TYPE::NORMAL_BOMB;
	setScale(Coord3f(0.6, 0.6, 0.6));
}

Bomb::Bomb(Character *p, int radius, int delay) : ABomb()
{
	this->_mesh = BOMB_MESH;
	this->_texture = BOMB_TEXTURE;
	this->_player = p;
	this->_radius = radius;
	this->_time = delay;
	this->_Bombtype = BOMB_TYPE::NORMAL_BOMB;
	this->_explose = false;
	setScale(Coord3f(0.6, 0.6, 0.6));
}

Bomb::Bomb(Character *p) : ABomb()
{
	this->_mesh = BOMB_MESH;
	this->_texture = BOMB_TEXTURE;
	this->_player = p;
	this->_radius = RADIUS_NORMAL_BOMB;
	this->_time = DEFAULT_TIME_BOMB;
	this->_Bombtype = BOMB_TYPE::NORMAL_BOMB;
	this->_explose = false;
	setScale(Coord3f(0.6, 0.6, 0.6));
}

bool Bomb::putBomb()
{
	this->setPosition2D(this->_player->getPosition2D());
	this->setPosition3D(this->_player->getPosition3D());
	_start = std::chrono::system_clock::now();
	play("dropbomb.wav");
	return true;
}

bool Bomb::isExplose() const
{
	return _explose;
}

void Bomb::explosion()
{
	GameModeProtocol *g =  this->_player->getGameModeProtocol();
	bool antisegfault = false;
	if (!g)
		return;
	std::cout << "Radius" << this->_radius << std::endl;
	if (_player->getPosition2D() == _pos2D)
		antisegfault = true;
	g->exploseInCase(_pos2D, this->_radius);
	if (!antisegfault && _player != NULL)
		this->_player->getBackBomb();
	this->_explose = true;
	play("explode.wav");
}

void Bomb::update()
{
	if (_explose == true)
		return;
	std::chrono::time_point<std::chrono::system_clock> end;
	int seconds = 0;

	end = std::chrono::system_clock::now();
	seconds = std::chrono::duration_cast<std::chrono::seconds>(end - _start).count();
	if (seconds >= _time)
		this->explosion();

}
