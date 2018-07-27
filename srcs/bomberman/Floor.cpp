/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Floor
*/

#include "Bomberman/GameObject/Floor.hpp"
#include <iostream>

Floor::Floor() : AObject3D()
{
	Coord3 pos(0,0,-1);

	this->_pos3D = pos;
	this->_mesh = FLOOR_MESH;
	this->_texture = FLOOR_TEXTURE;
}

Floor::Floor(int mapSize, Coord3 pos) : AObject3D()
{
	this->_scale.x = mapSize;
    	this->_scale.z = mapSize;
	this->_scale.y = 1;
	this->_pos3D = pos;
	this->_mapSize = mapSize;
	this->_mesh = FLOOR_MESH;
	this->_texture = FLOOR_TEXTURE;
}

double Floor::getCaseSize() const
{
	return (1);
}

Floor::~Floor()
{
}
