/*
** EPITECH PROJECT, 2018
** Indie Studio
** File description:
** MapObserver
*/

#include "MapObserver.hpp"
// Size of the pattern
#define PATSIZ 4

MapObserver::MapObserver(std::string filler, Coord2 size, int **logicalarray)
{
    _pathFiller = filler;
    _size = size;
    _logical = "";
    this->_logicalarray = logicalarray;
    int space = (_size.x * _size.y);
    _logical.resize(space);
    while (--space >= 0){
        _logical[space] = '0';
    }
    generateMap();
    placeBorder();
    generateLogicalArray();
}

MapObserver::~MapObserver()
{
}

//Extract a pattern from the given files with the right ID.
std::string MapObserver::extractPattern(std::string path, int id)
{
    std::ifstream pattern(path.c_str());
    std::string iterator;
    int patnb;
    while (std::getline(pattern, iterator))
    {
        if (iterator[0] != '#' && iterator[1] != '#'){
            patnb = stoi(iterator);
            break;
        }
    }
    id = id % patnb;
    while (std::getline(pattern, iterator))
    {
        if (iterator[0] != '#' && iterator[1] != '#'){
            id--;
        }
        if (id < 0)
            return iterator;
    }
    return "";
}

// Generate a map with the size given in parametter and with enough spawn for
// each players
void MapObserver::generateMap()
{
    Coord2 actual(0,0);
    while (actual.y < _size.y){
        while (actual.x < _size.x){
            std::string type = getType();
            std::string pattern = extractPattern(type, std::rand());
            placePattern(actual, pattern);
            actual.x += PATSIZ;
        }
        actual.x = 0;
        actual.y += PATSIZ;
    }
}

// Return the Spawn path if the location is a spawn location
// The filler pattern in other cases
// 4PlayersSpawn: (0;0) (0;_size-4) (_size-4;0) (_size-4;_size-4)
// 8PlayersAdditionalSpawn: (4;4), (_size-8;4), (4;_size-8), (_size-8;_size-8)
std::string MapObserver::getType()
{
    return _pathFiller;
}

// Create the pattern at the location
void MapObserver::placePattern(Coord2 location, std::string pattern)
{
    int it = 0;
    int x = 0;
    int y = 0;
    while (y < PATSIZ){
        while (x < PATSIZ){
            Coord2 draw(location.x + x, location.y + y);
            placeOn(draw, pattern[it]);
            it++;
            x++;
        }
        x = 0;
        y++;
    }
}


void MapObserver::placeBorder()
{
    int x = -1;
    while (x <= _size.x){
        Coord2 draw(x, -1);
        Coord2 drawbot(x, _size.y);
        placeOut(draw, 2);
        placeOut(drawbot, 2);
        x++;
    }
    int y = 0;
    while (y <= _size.y){
        Coord2 left(-1, y);
        Coord2 right(_size.x, y);
        placeOut(left, 2);
        placeOut(right, 2);
        y++;
    }
}

// placeOn create an object corresponding to the ID and add it to the vector
// of object. PlaceOn can also create spawn location.
int MapObserver::placeOn(Coord2 location, int idBlock)
{
    if (isOut(location.x, location.y))
        return 0;
    Coord3 location3d(location.x, 0, location.y);
    if (location.x == 0 && location.y == 0){
        _logical[location.x+location.y*_size.x] = '3';
        Coord2 spawn (location.x, location.y);
        _spawnLocation.push_back(spawn);
        return 0;
    }
    if (location.x == _size.x-1 && location.y == 0){
        _logical[location.x+location.y*_size.x] = '3';
        Coord2 spawn (location.x, location.y);
        _spawnLocation.push_back(spawn);
        return 0;
    }
    if (location.x == 0 && location.y == _size.y-1){
        _logical[location.x+location.y*_size.x] = '3';
        Coord2 spawn (location.x, location.y);
        _spawnLocation.push_back(spawn);
        return 0;
    }
    if (location.x == _size.x-1 && location.y == _size.y-1){
        _logical[location.x+location.y*_size.x] = '3';
        Coord2 spawn (location.x, location.y);
        _spawnLocation.push_back(spawn);
        return 0;
    }
    if (location.x % 2 == 1 && location.y % 2 == 1){
        _logical[location.x+location.y*_size.x] = '2';
        std::shared_ptr<Wall> ptr_wall(new Wall(false, location3d));
        _objects.push_back(ptr_wall);
        if (idBlock == 3)
            return 1;
        return 0;
    }
    if (idBlock == '0' || isNearSpawn(location.x, location.y)){
        return 0;
    }
    if (idBlock == '1'){
        _logical[location.x+location.y*_size.x] = '1';
        std::shared_ptr<Wall> ptr_wall(new Wall(true, location3d));
        _objects.push_back(ptr_wall);
    }
    if (idBlock == '3'){
        _logical[location.x+location.y*_size.x] = '3';
        Coord2 spawn (location.x, location.y);
        _spawnLocation.push_back(spawn);
    }
    return 0;
}

// placeOn create an object corresponding to the ID and add it to the vector
// of object. PlaceOn can also create spawn location.
void MapObserver::placeOut(Coord2 location, int idBlock)
{
    Coord3 location3d(location.x, 0, location.y);
    if (idBlock == 0)   
        return;
    if (idBlock == 1){
        std::shared_ptr<Wall> ptr_wall(new Wall(true, location3d));
        _objects.push_back(ptr_wall);
    }
    if (idBlock == 2){
        std::shared_ptr<Wall> ptr_wall(new Wall(false, location3d));
        _objects.push_back(ptr_wall);
    }
    if (idBlock == 3){
        Coord2 spawn (location.x, location.y);
        _spawnLocation.push_back(spawn);
    }
}

void MapObserver::printLogical()
{
    int loc = 0;
    int space = _size.x * _size.y;
    while (loc < space){
        std::cout << _logical[loc];
        loc++;
        if (loc % _size.x == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::shared_ptr<Wall>> MapObserver::getObjects()
{
    return _objects;
}

bool MapObserver::isOut(int x, int y){
    if (x < 0 || y < 0)
        return true;
    if (x >= _size.x || y >= _size.y)
        return true;
    return false;
}

std::vector<Coord2> MapObserver::getSpawn()
{
    return _spawnLocation;
}

int **MapObserver::getLogicalArray()
{
    return _logicalarray;
}

// Generate a logical array of int ** with the string logical
void MapObserver::generateLogicalArray()
{
    int x = 0;
    int y = 0;
    int inc = 0;
    while (y < _size.y){
        while (x < _size.x){
            if (_logical[inc] == '3'){
                _logical[inc] = '0';
            }
            _logicalarray[x][y] = _logical[inc] - '0';
            x++;
            inc++;
        }
        x = 0;
        y++;
    }
}

bool MapObserver::isNearSpawn(int x, int y)
{
    if (x == 1 && y == 0)
        return true;
    if (x == 0 && y == 1)
        return true;
    if (x == 0 && y == _size.y - 2)
        return true;
    if (x == 1 && y == _size.y - 1)
        return true;
    if (x == _size.x - 2 && y == 0)
        return true;
    if (x == _size.x - 1 && y == 1)
        return true;
    if (x == _size.x - 2 && y == _size.y - 1)
        return true;
    if (x == _size.x - 1 && y == _size.y - 2)
        return true;
    return false;
}