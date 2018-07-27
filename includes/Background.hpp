/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Background
*/

#ifndef BACKGROUND_HPP_
	#define BACKGROUND_HPP_
	#include "AObject3D.hpp"

class Background : public AObject3D {
public:
  Background(Coord3 pos, std::string obj, std::string texture) : AObject3D() {
    this->_pos3D = {0,0,0};
  	this->_mesh = obj;
  	this->_texture = texture;
    setScale(Coord3f(2.4f, 2.4f, 2.4f));
		setPosition3D(pos);
  }
};

#endif
