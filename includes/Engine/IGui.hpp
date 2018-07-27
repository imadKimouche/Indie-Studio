//
// EPITECH PROJECT, 2018
// indy studio
// File description:
// interface Igui
//

#ifndef IGUI_HPP
#define IGUI_HPP

#include "../IObject.hpp"
#include "../Coord.hpp"
#include <string>
#include <memory>

class IGui {
public:
	virtual void add_object(std::shared_ptr<IObject> object) = 0;
	virtual void remove_object(std::shared_ptr<IObject> objcet) = 0;
	virtual void set_window(const Coord2 &coord) = 0;
	virtual void set_camera(const Coord3 &pos, const Coord3 &orientation) = 0;
	virtual void draw_all() = 0;
	virtual void clear_scene() = 0;
	virtual void close_window() = 0;
	virtual bool run() = 0;
};

#endif
