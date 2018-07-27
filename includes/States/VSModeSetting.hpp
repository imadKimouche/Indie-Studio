/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** VSModeSetting.hpp
*/

#ifndef VSMODESETTING_HPP_
	#define VSMODESETTING_HPP_
	#include "../Coord.hpp"
	#include "../IController.hpp"
	#include <memory>
	#include <vector>
	#include "../IAController.hpp"

struct VSModeSetting {
	VSModeSetting(Coord2 mapSize, std::vector<std::shared_ptr<PlayerController>> characters, std::vector<std::shared_ptr<IAController>> iAs) :
	_iAs(iAs), _characters(characters), _mapSize(mapSize) {}
	~VSModeSetting() {}
	std::vector<std::shared_ptr<IAController>> _iAs;
	std::vector<std::shared_ptr<PlayerController>> _characters;
	Coord2 _mapSize;
};

#endif /* !VSMODESETTING_HPP_ */
