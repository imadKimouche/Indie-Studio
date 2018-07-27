/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(const std::string &name,Coord2 &pos2D, Coord3 &pos3D, Coord3f &scale,const std::string &m, const std::string &t, GameModeProtocol* gameModeProtocol) : Character(name,pos2D,pos3D,scale,m,t, gameModeProtocol)
{
	this->_max_bomb = INITIAL_BOMB_NB;
	this->_delay = INITIAL_DELAY_BOMB;
	this->_nb_bomb = _max_bomb;

	std::shared_ptr<Bomb> sub;

	for (int i = 0; i < _max_bomb; i++) {
		sub = std::make_shared<Bomb>(this,_radius,_delay);
		_bomb.push(std::move(sub));
	}
	_durationSpec = DELAY_SPECIALISATION;
	_inUse = false;
}

Player::Player(GameModeProtocol* gameModeProtocol) : Character(NAME_PERSO,MESH_PERSO,TEXTURE_PERSO)
{
	this->_max_bomb = INITIAL_BOMB_NB;
	this->_delay = INITIAL_DELAY_BOMB;
	this->_nb_bomb = _max_bomb;
	std::shared_ptr<Bomb> sub;

	for (int i = 0; i < _max_bomb; i++) {
		sub = std::make_shared<Bomb>(this,_radius,_delay);
		_bomb.push(std::move(sub));
	}
	_gameModeProtocol = gameModeProtocol;
	_durationSpec = DELAY_SPECIALISATION;
	_inUse = false;
}

Coord3 Player::getDir() const
{
	Coord3 pos;

	pos = this->_pos3D;
	if (_direction == 0)
		pos.z -= 1;
	else if (_direction == 90)
		pos.x += 1;
	else if (_direction == 180)
		pos.z += 1;
	else
		pos.x -= 1;
	return pos;
}

bool Player::CheckTimeLeft(int timetocompare, std::chrono::time_point<std::chrono::system_clock> end) const
{
	std::chrono::time_point<std::chrono::system_clock> now;
	int seconds = 0;

	now = std::chrono::system_clock::now();
	seconds =  std::chrono::duration_cast<std::chrono::seconds>(now - end).count();
	if (seconds >= timetocompare)
		return true;
	return false;
}

Player::Player(Coord2 &spone, GameModeProtocol* gameModeProtocol) : Character(NAME_PERSO,MESH_PERSO,TEXTURE_PERSO,spone)
{
	this->_max_bomb = INITIAL_BOMB_NB;
	this->_delay = INITIAL_DELAY_BOMB;
	this->_nb_bomb = _max_bomb;
	std::shared_ptr<Bomb> sub;

	for (int i = 0; i < _max_bomb; i++) {
		sub = std::make_shared<Bomb>(this,_radius,_delay);
		_bomb.push(std::move(sub));
	}
	_gameModeProtocol = gameModeProtocol;
	_durationSpec = DELAY_SPECIALISATION;
	_inUse = false;
}

Player::~Player()
{

}
