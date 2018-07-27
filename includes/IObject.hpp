/*
 ** EPITECH PROJECT, 2018
 ** cpp_indie_studio
 ** File description:
 ** IObject
 */

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_
#include "Coord.hpp"
#include "Engine/IInput.hpp"
#include <string>
#include <chrono>

class IObject {
public:

	enum ObjType {
		THREED,
		TEXT,
		IMG,
		BUTTON,
		EXPLO
	};

		virtual void update() = 0;
		virtual void setPosition2D(Coord2 pos) = 0;
		virtual Coord2 getPosition2D() const = 0;
		virtual ObjType getType() const = 0;

};

#endif /* !IOBJECT_HPP_ */
