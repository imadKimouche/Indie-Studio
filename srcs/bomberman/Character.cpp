/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Character
*/

#include "Character.hpp"
#include <iostream>

Character::Character(const std::string &name,Coord2 &pos2D, Coord3 &pos3D, Coord3f &scale, const std::string &m, const std::string &t, GameModeProtocol* gameModeProtocol) : AObject3D(pos2D,pos3D,scale,m,t)
{
	_name = name;
	_gameModeProtocol = gameModeProtocol;
	_max_bomb = INITIAL_BOMB_NB;
	_radius = INITIAL_RADIUS;
	_animation._speed = INITIAL_SPEED;
	_move = true;
	setScale(Coord3f(0.5f, 0.5f, 0.5f));
}

Character::Character(const std::string &name,const std::string &m, const std::string &t, Coord2 spone, GameModeProtocol* gameModeProtocol) : AObject3D()
{
	_name = name;
	this->_mesh = m;
	this->_texture = t;
	_spone = spone;
	_max_bomb = INITIAL_BOMB_NB;
	_radius = INITIAL_RADIUS;
	_pos2D = spone;
	_gameModeProtocol = gameModeProtocol;
	_animation._speed = INITIAL_SPEED;
	_move = true;
	setScale(Coord3f(0.5f, 0.5f, 0.5f));
}

Character::Character(const std::string &name,const std::string &m, const std::string &t, GameModeProtocol* gameModeProtocol) : AObject3D()
{
	_name = name;
	this->_mesh = m;
	this->_texture = t;
	_max_bomb = INITIAL_BOMB_NB;
	_radius = INITIAL_RADIUS;
	_gameModeProtocol = gameModeProtocol;
	_animation._speed = INITIAL_SPEED;
	_move = true;
	setScale(Coord3f(0.5f, 0.5f, 0.5f));
}

Character::~Character()
{
}

void Character::setBombMax(int max_bomb)
{
	if (max_bomb >= MIN_BOMB_POSSIBLE && max_bomb <= LIMIT_BOMB)
		_max_bomb = max_bomb;
	else if (max_bomb > LIMIT_BOMB)
		_max_bomb = LIMIT_BOMB;
	else
		_max_bomb = MIN_BOMB_POSSIBLE;
}

void Character::setBombNb(int nb_bomb)
{
	if (nb_bomb >= MIN_BOMB_POSSIBLE && nb_bomb <= LIMIT_BOMB)
		_nb_bomb = nb_bomb;
	else if (nb_bomb > LIMIT_BOMB)
		_nb_bomb = LIMIT_BOMB;
	else
		_nb_bomb = MIN_BOMB_POSSIBLE;
}

void Character::setBombDelay(int delay)
{
	if (delay >= MIN_DELAY_POSSIBLE && delay <= LIMIT_DELAY)
		_delay = delay;
	else if ( delay > LIMIT_DELAY)
		_delay = LIMIT_DELAY;
	else
		_delay = MIN_DELAY_POSSIBLE;
}

void Character::setRadius(int radius)
{
	if (radius >= MIN_RADIUS_POSSIBLE && radius <= LIMIT_RADIUS)
		_radius = radius;
	else if ( radius > LIMIT_RADIUS)
		_radius = LIMIT_RADIUS;
	else
		_radius = MIN_RADIUS_POSSIBLE;
}

void Character::setSpeed(float speed)
{
	if ( speed >= MIN_SPEED_POSSIBLE && speed <= LIMIT_SPEED)
		_animation._speed = speed;
	else if ( speed > LIMIT_SPEED)
		_animation._speed = LIMIT_SPEED;
	else
		_animation._speed = MIN_SPEED_POSSIBLE;
}

bool Character::poseBomb()
{
	if (_bomb.empty() || !_gameModeProtocol->isFreeInCase(getPosition2D()))
		return false;

	std::shared_ptr<ABomb> bomb = _bomb.front();
	bomb->putBomb();
	if (_gameModeProtocol->putBomb(bomb)) {
		_bomb.pop();
		_nb_bomb--;
		return true;
	}
	return false;
}

void Character::getBackBomb()
{
	std::shared_ptr<Bomb> sub;

	if ((int)_bomb.size() < _max_bomb) {
		sub = std::make_shared<Bomb>(this,_radius,_delay);
		_bomb.push(std::move(sub));
		//_nb_bomb++;
	}
}

void Character::getBackAll()
{
	std::shared_ptr<Bomb> sub;

	while ((int)_bomb.size() < _max_bomb) {
		sub = std::make_shared<Bomb>(this,_radius,_delay);
		_bomb.push(std::move(sub));
		//_nb_bomb++;
	}
}
void Character::move(const Coord2 pos)
{
	Coord3 tmp = getPosition3D();
	int newd = computeDirection(pos);

	tmp.x += pos.x;
	tmp.z += pos.y;
	if (!getAnimation()._moving) {
		setDirection(newd);
	}
	if (_gameModeProtocol == NULL || _gameModeProtocol->isFreeInCase({tmp.x, tmp.z}) == false)
		return;
	if (!getAnimation()._moving) {
		setPosition3D(tmp);
		setPosition2D(Coord2(tmp.x, tmp.z));
		getAnimation()._movingChanged = true;
	} else if ((newd == 90 && getDirection() == 270) || (newd == 0 && getDirection() == 180) ||
		 (newd == 270 && getDirection() == 90) || (newd == 180 && getDirection() == 0)) {
		setPosition3D(tmp);
		setPosition2D(Coord2(tmp.x, tmp.z));
		setDirection(newd);
		getAnimation()._movingChanged = true;
	}
}

int Character::computeDirection(Coord2 coord)
{
	int direction = getDirection();

	if (std::abs(coord.x) - std::abs(coord.y) > 0)
		direction = (coord.x > 0) ? 270 : 90;
	else if (std::abs(coord.y) - std::abs(coord.x) > 0)
		direction = (coord.y > 0) ? 180 : 0;
	return direction;
}
