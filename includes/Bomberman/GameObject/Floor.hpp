/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Floor
*/

#ifndef FLOOR_HPP_
	#define FLOOR_HPP_
	#define FLOOR_MESH "./ressources/cube.obj"
	#define FLOOR_TEXTURE "./ressources/textures/floor.png"
	#include "AObject3D.hpp"

	class Floor : public AObject3D {
		public:
			Floor();
			Floor(int mapSize, Coord3 pos);
			double getCaseSize() const;
			~Floor();
		protected:
			int _mapSize;
	};
#endif /* !FLOOR_HPP_ */
