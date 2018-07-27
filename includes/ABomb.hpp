/*
** EPITECH PROJECT, 2018
** INdi
** File description:
** ABomb
*/

#ifndef ABOMB_HPP_
	#define ABOMB_HPP_
	#include "AObject3D.hpp"
	#include "ABomb.hpp"
	#include "Musician.hpp"

	class ABomb : public AObject3D, public Musician {
		public:
			enum BOMB_TYPE {
				NORMAL_BOMB,
				MINE
			};
			ABomb(Coord2 &pos2D, Coord3 &pos3D, Coord3f &scale, const std::string &m, const std::string &t);
			ABomb();
			virtual ~ABomb() = default;
			ABomb::BOMB_TYPE getBombType();
			virtual void update() = 0;
			virtual void explosion() = 0;
			virtual bool putBomb() = 0;
		protected:
			int _radius;
			ABomb::BOMB_TYPE _Bombtype;
		private:
	};

#endif /* !ABOMB_HPP_ */
