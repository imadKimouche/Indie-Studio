/*
** EPITECH PROJECT, 2018
** Indie Studio
** File description:
** MapObserver.hpp
*/

#ifndef MAPOBSERVER_HPP_
	#define MAPOBSERVER_HPP_
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <cstdlib>
#include "Coord.hpp"
#include "Wall.hpp"
#include "IObject.hpp"

class MapObserver {
	public:
	MapObserver(std::string filler, Coord2 size, int **logicalarray);
	~MapObserver();
        void generateMap();
        std::string extractPattern(std::string path, int id);
        void placePattern(Coord2 location, std::string pattern);
        std::string getType();
        int placeOn(Coord2 location, int idBlock);
        void placeOut(Coord2 location, int idBlock);
        void printLogical();
        std::vector<std::shared_ptr<Wall>> getObjects();
        std::vector<Coord2> getSpawn();
        void placeBorder();
        void generateLogicalArray();
        int **getLogicalArray();
        bool canRun(Coord2 loc, char from, int len);
        bool isNearSpawn(int x, int y);
        bool isOut(int x, int y);
	protected:
        std::vector<std::shared_ptr<Wall>> _objects;
        Coord2 _size;
        std::vector<Coord2> _spawnLocation;
        std::string _pathFiller;
        std::string _logical;
        int** _logicalarray;
};

#endif /* !MAPOBSERVER_HPP_ */
