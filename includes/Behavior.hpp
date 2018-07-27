/*
** EPITECH PROJECT, 2018
** Indie Studio Bomberman
** File description:
** Behavior
*/

#ifndef BEHAVIOR_HPP_
	#define BEHAVIOR_HPP_
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <algorithm>
#include "Coord.hpp"
#include "AObject3D.hpp"

class Behavior {
	public:
		Behavior(int** logicalarray, int id, int radius, Coord2 size);
		~Behavior();
        char getAction(std::vector<Coord2> position, int id);
        void generateThreat();
        void bombSetThreat(Coord2 loc, char direction, int intensity);
        void resetThreat();
        char findSafeWay(Coord2 position);
        int distFromSafe(Coord2 position, int dist);
        char findPowerUp(Coord2 position);
        int distFromPower(Coord2 position, char from);
        void debugprint(std::vector<Coord2> position);
        void setRadius(int radius){
                this->_radius = radius;
        }
        void setSafety(int level);
        bool isEnemyHere(Coord2 check, std::vector<Coord2> loc);
        bool canIHitFrom(Coord2 check, std::vector<Coord2> loc);
        bool isWallNear(Coord2 check);
        int getInMatrix(int x, int y);
        int getInLogical(int x, int y);
        void setInMatrix(int x, int y, int value);
        void setInLogical(int x, int y, int value);
        bool canWalk(int x, int y);
        char hunt(Coord2 position, int tries);
        bool canRun(Coord2 loc);
        void bombSimpleSet(Coord2 loc);
	protected:
        int** _logicalarray;
        int** _threatMatrix;
        int _id;
        Coord2 _size;
        int _radius;
        int _safety;
};

#endif /* !BEHAVIOR_HPP_ */
