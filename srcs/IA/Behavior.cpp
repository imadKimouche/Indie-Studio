/*
** EPITECH PROJECT, 2018
** Indie Studio Bomberman
** File description:
** Behavior
*/

#include "Behavior.hpp"

Behavior::Behavior(int** logicalarray, int id, int radius, Coord2 size)
{
    this->_logicalarray = logicalarray;
    this->_radius = radius;
    this->_size = size;
    this->_id = id;
    this->_safety = 3;
    int inc = 0;
    _threatMatrix = new int*[_size.x];
    while (inc < _size.x){
        _threatMatrix[inc] = new int[_size.y];
        inc++;
    }
}

Behavior::~Behavior()
{
}

void Behavior::setSafety(int level)
{
    this->_safety = level;
}

// NSEW are for directions, 0 is for waiting, B is for bombing
char Behavior::getAction(std::vector<Coord2> position, int id)
{
    this->_id = id;
    resetThreat();
    generateThreat();
    //debugprint(position);
    if (getInMatrix(position[id].x,position[id].y) > _safety){
        return findSafeWay(position[id]);
    }
    /*if (findPowerUp(position[id]) != 'X'){
        std::cout << "GO POWER" << std::endl;
        return findPowerUp(position[id]);
    }*/
    if (canIHitFrom(position[id], position)){
        return 'B';
    }
    if (isWallNear(position[id]) && canRun(position[id])){
        if (std::rand() % 30 == 0)
            return 'B';
    }
    return hunt(position[id], 6);
}

void Behavior::resetThreat()
{
    int x = 0;
    int y = 0;
    while (y < _size.y){
        while (x < _size.x){
            setInMatrix(x,y,0);
            x++;
        }
        x = 0;
        y++;
    }
}

void Behavior::generateThreat()
{
    int x = 0;
    int y = 0;
    while (y < _size.y){
        while (x < _size.x){
            if (getInLogical(x,y) == BOMB){
                Coord2 loc(x,y);
                //bombSetThreat(loc, 'N', 7);
                //bombSetThreat(loc, 'S', 7);
                //bombSetThreat(loc, 'E', 7);
                //bombSetThreat(loc, 'W', 7);
                bombSimpleSet({x,y});
            }
            x++;
        }
        x = 0;
        y++;
    }
}

void Behavior::bombSetThreat(Coord2 loc, char direction, int intensity)
{
    Coord2 nextloc(loc.x,loc.y);
    if (intensity <= 0 || getInLogical(loc.x, loc.y) == WALL || getInLogical(loc.x, loc.y) == WALL_INDE)
        return;
    if (direction == 'N'){
        nextloc.y += -1;
    }
    else if (direction == 'S'){
        nextloc.y += 1;
    }
    else if (direction == 'E'){
        nextloc.x += 1;
    }
    else if (direction == 'W'){
        nextloc.x += -1;
    }
    if (getInMatrix(loc.x, loc.y) < intensity){
        setInMatrix(loc.x, loc.y, intensity);
    }
    bombSetThreat(nextloc, direction, intensity - 1);
}

char Behavior::findSafeWay(Coord2 position)
{
    int north = distFromSafe({position.x, position.y - 1}, 0);
    int south = distFromSafe({position.x, position.y+1}, 0);
    int east = distFromSafe({position.x+1, position.y}, 0);
    int west = distFromSafe({position.x-1, position.y}, 0);
    if (north < 10 && north == std::min(std::min(north,south),std::min(east,west))){
        return 'N';
    }
    if (south < 10 && south == std::min(std::min(north,south),std::min(east,west))){
        return 'S';
    }
    if (east < 10 && east == std::min(std::min(north,south),std::min(east,west))){
        return 'E';
    }
    if (west < 10 && west == std::min(std::min(north,south),std::min(east,west))){
        return 'W';
    }
    return 'X';
}

int Behavior::distFromSafe(Coord2 position, int dist)
{
    if(canWalk(position.x,position.y) == false){
        return 999;
    }
    if(getInMatrix(position.x, position.y) <= _safety){
        return dist;
    }
    dist++;
    if(dist > 10)
        return 15;
    int north = distFromSafe({position.x, position.y-1}, dist);
    int south = distFromSafe({position.x, position.y+1}, dist);
    int east = distFromSafe({position.x+1, position.y}, dist);
    int west = distFromSafe({position.x-1, position.y}, dist);
    return std::min(north,std::min(south,std::min(east,west)));
}

char Behavior::findPowerUp(Coord2 position)
{
    Coord2 cnorth = position;
    cnorth.y -= 1;
    int north = distFromPower(cnorth, 'N');
    Coord2 csouth = position;
    csouth.y += 1;
    int south = distFromPower(csouth, 'S');
    Coord2 ceast = position;
    ceast.x += 1;
    int east = distFromPower(ceast, 'E');
    Coord2 cwest = position;
    cnorth.x -= 1;
    int west = distFromPower(cwest, 'W');
    if (std::min(std::min(north,south),std::min(east,west)) >= 8){
        return 'X';
    }
    if (north == std::min(std::min(north,south),std::min(east,west))){
        return 'N';
    }
    if (south == std::min(std::min(north,south),std::min(east,west))){
        return 'S';
    }
    if (east == std::min(std::min(north,south),std::min(east,west))){
        return 'E';
    }
    if (west == std::min(std::min(north,south),std::min(east,west))){
        return 'W';
    }
    return 'X';
}

int Behavior::distFromPower(Coord2 position, char from)
{
    if(canWalk(position.x, position.y)){
        return 999;
    }
    if(getInLogical(position.x, position.y) == POWERUP){
        return 1;
    }
    int dist = 0;
    if (from != 'N'){
        Coord2 npos(position.x, position.y-1);
        dist = std::max(dist,distFromSafe(npos, 'S'));
    }
    if (from != 'S'){
        Coord2 npos(position.x, position.y+1);
        dist = std::max(dist,distFromSafe(npos, 'N'));
    }
    if (from != 'E'){
        Coord2 npos(position.x+1, position.y);
        dist = std::max(dist,distFromSafe(npos, 'W'));
    }
    if (from != 'W'){
        Coord2 npos(position.x-1, position.y);
        dist = std::max(dist,distFromSafe(npos, 'E'));
    }
    return dist;
}

bool Behavior::isEnemyHere(Coord2 check, std::vector<Coord2> loc)
{
    int explore = 0;
    while (explore < (int)loc.size()){
        if (explore != _id){
            if (check.x == loc[explore].x && check.y == loc[explore].y)
                return true;
        }
        explore++;
    }
    return false;
}

bool Behavior::canIHitFrom(Coord2 check, std::vector<Coord2> loc)
{
    int offset = 1;
    Coord2 duplicate(0,0);
    //Check direction
    while (offset <= _radius){
        duplicate.x = check.x;
        duplicate.y = check.y + offset;
        if (canWalk(duplicate.x, duplicate.y))
            break;
        if (isEnemyHere(duplicate, loc) == true)
            return true;
        offset++;
    }
    while (offset <= _radius){
        duplicate.x = check.x;
        duplicate.y = check.y - offset;
        if (canWalk(duplicate.x, duplicate.y))
            break;
        if (isEnemyHere(duplicate, loc) == true)
            return true;
        offset++;
    }
    while (offset <= _radius){
        duplicate.x = check.x + offset;
        duplicate.y = check.y;
        if (canWalk(duplicate.x, duplicate.y))
            break;
        if (isEnemyHere(duplicate, loc) == true)
            return true;
        offset++;
    }
    while (offset <= _radius){
        duplicate.x = check.x - offset;
        duplicate.y = check.y;
        if (canWalk(duplicate.x, duplicate.y))
            break;
        if (isEnemyHere(duplicate, loc) == true)
            return true;
        offset++;
    }
    return false;
}

bool Behavior::isWallNear(Coord2 check)
{
    if (getInLogical(check.x-1, check.y) == WALL)
        return true;
    if (getInLogical(check.x+1, check.y) == WALL)
        return true;
    if (getInLogical(check.x, check.y-1) == WALL)
        return true;
    if (getInLogical(check.x, check.y+1) == WALL)
        return true;
    return false;
}

int Behavior::getInMatrix(int x, int y)
{
    if (x < 0 || y < 0 || x >= _size.x || y >= _size.y){
        return 999;
    }
    return _threatMatrix[x][y];
}

int Behavior::getInLogical(int x, int y)
{
    if (x < 0 || y < 0 || x >= _size.x || y >= _size.y){
        return WALL_INDE;
    }
    return _logicalarray[x][y];
}

void Behavior::setInMatrix(int x, int y, int value)
{
    if (x < 0 || y < 0 || x >= _size.x || y >= _size.y)
        return;
    _threatMatrix[x][y] = value;
}

void Behavior::setInLogical(int x, int y, int value)
{
    if (x < 0 || y < 0 || x >= _size.x || y >= _size.y)
        return;
    _logicalarray[x][y] = value;
}

bool Behavior::canWalk(int x, int y)
{
    int type = getInLogical(x,y);
    if (type != WALL && type != WALL_INDE && type != BOMB)
        return true;
    return false;
}

char Behavior::hunt(Coord2 position, int tries)
{
    if (tries <= 0){
        return 'X';
    }
    int rand = std::rand() % 4 + 1;
    if (rand == 1 && canWalk(position.x, position.y - 1) && getInMatrix(position.x, position.y-1) == 0)
        return 'N';
    if (rand == 2 && canWalk(position.x, position.y + 1) && getInMatrix(position.x, position.y+1) == 0)
        return 'S';
    if (rand == 3 && canWalk(position.x + 1, position.y) && getInMatrix(position.x+1, position.y) == 0)
        return 'E';
    if (rand == 4 && canWalk(position.x - 1, position.y) && getInMatrix(position.x-1, position.y) == 0)
        return 'W';
    return hunt(position, tries - 1);
}

bool Behavior::canRun(Coord2 loc)
{
    if (getInMatrix(loc.x+1, loc.y) == 0 && canWalk(loc.x+1, loc.y))
        return true;
    if (getInMatrix(loc.x-1, loc.y) == 0 && canWalk(loc.x-1, loc.y))
        return true;
    if (getInMatrix(loc.x, loc.y+1) == 0 && canWalk(loc.x, loc.y+1))
        return true;
    if (getInMatrix(loc.x, loc.y-1) == 0 && canWalk(loc.x, loc.y-1))
        return true;
    return false;
}

void Behavior::debugprint(std::vector<Coord2> position)
{
    std::cout << "IA is at X" << position[_id].x << "Y" << position[_id].y << std::endl;
    int x = 0;
    int y = 0;
    std::cout << "Logical :" << std::endl;
    while (y < _size.y){
        while (x < _size.x){
            std::cout << getInLogical(x,y);
            x++;
        }
        std::cout << std::endl;
        x = 0;
        y++;
    }
    x = 0;
    y = 0;
    std::cout << "Threat :" << std::endl;
    while (y < _size.y){
        while (x < _size.x){
            std::cout << getInMatrix(x,y);
            x++;
        }
        std::cout << std::endl;
        x = 0;
        y++;
    }
    std::cout << "Danger" << getInMatrix(position[_id].x,position[_id].y) << "Safety" << _safety << std::endl;
}

void Behavior::bombSimpleSet(Coord2 loc)
{
    setInMatrix(loc.x, loc.y, 7);
    setInMatrix(loc.x+1, loc.y, 7);
    setInMatrix(loc.x-1, loc.y, 7);
    setInMatrix(loc.x, loc.y+1, 7);
    setInMatrix(loc.x, loc.y-1, 7);
    setInMatrix(loc.x+2, loc.y, 7);
    setInMatrix(loc.x-2, loc.y, 7);
    setInMatrix(loc.x, loc.y+2, 7);
    setInMatrix(loc.x, loc.y-2, 7);
    setInMatrix(loc.x+3, loc.y, 7);
    setInMatrix(loc.x-3, loc.y, 7);
    setInMatrix(loc.x, loc.y+3, 7);
    setInMatrix(loc.x, loc.y-3, 7);
}