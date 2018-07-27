/*
** EPITECH PROJECT, 2018
** IndieStudio.hpp
** File description:
** Level.hpp
*/

#ifndef LEVEL_HPP_
	#define LEVEL_HPP_
	#include "Coord.hpp"
	#include <fstream>
	#include <string>

class Level {
public:
	Level(int nbLevel);
	~Level();
	bool chargeLevel();
protected:
private:
	int _nbLevel;
	int _nbIA;
	Coord2 _mapSize;
	bool _isLast;
	int _difficulty;
};

#endif /* !LEVEL_HPP_ */
