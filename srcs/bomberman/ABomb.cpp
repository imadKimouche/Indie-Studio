/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** ABomb
*/

#include "ABomb.hpp"

ABomb::ABomb(Coord2 &pos2D, Coord3 &pos3D, Coord3f &scale, const std::string &m, const std::string &t) : AObject3D(pos2D,pos3D,scale,m,t)
{

}

ABomb::ABomb() : AObject3D()
{
}

ABomb::BOMB_TYPE ABomb::getBombType()
{
	return _Bombtype;
}
