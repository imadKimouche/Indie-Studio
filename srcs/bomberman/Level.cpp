/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Level.cpp
*/

#include "Level.hpp"

Level::Level(int nbLevel) : _nbLevel(nbLevel), _nbIA(0), _mapSize(10, 10), _isLast(1), _difficulty(1) 
{
}

Level::~Level()
{
}

bool Level::chargeLevel()
{
	fstream file("level" + std::to_string(_nbLevel));
	std::string tmp;

	if (file.is_open() == false)
		return false;
	file >> tmp;
	file >> _mapSize.x;
	file >> _mapSize.y;
	file >> tmp;
	file >> _difficulty;
	file >> tmp;
	file >> _nbIA;
	file >> tmp;
	file >> _isLast;
	return true;
}