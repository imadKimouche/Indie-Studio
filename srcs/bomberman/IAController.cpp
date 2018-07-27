/*
** EPITECH PROJECT, 2018
** Indie Studio Bomberman
** File description:
** IAController
*/

#include "IAController.hpp"

IAController::IAController(std::shared_ptr<Character> chara, Coord2 size)
{
    this->_character = chara;
    initCoord();
    this->_size = size;
    this->_id = getID();
    std::vector<std::shared_ptr<IController>> charasempty;
    this->_charAll = charasempty;
}

IAController::~IAController()
{
}

int IAController::getID()
{
    int inc = 0;
    Coord2 charLoc = _character->getPosition2D();
    ////////std::cout << "(PosforGetID)X:" << charLoc.x << "Y:" << charLoc.y << std::endl;
    if (_posList.size() == 0)
        return 0;
    ////////std::cout << inc << "X:" << _posList[inc].x  << "Y:" << _posList[inc].y  << std::endl;    
    while (_posList[inc].x != charLoc.x || _posList[inc].y != charLoc.y){
        inc++;
        ////////std::cout << inc << "X:" << _posList[inc].x  << "Y:" << _posList[inc].y  << std::endl;  
        if (inc >= (int)_posList.size())
            break;
    }
    //////std::cout << "My ID is " << inc << std::endl;
    return inc;
}

void IAController::update()
{
    initCoord();
    this->_id = getID();
    Behavior comportment(_logical, _id, _character->getRadius(), _size);
    char action = comportment.getAction(_posList, _id);
    //////std::cout << "IA is doing :" << action << std::endl;
    if (action == 'X')
        return;
    if (action == 'B'){
        _character->poseBomb();
        return;
    }
    //Coord2 moveloc = _posList[_id];
    Coord2 moveloc = Coord2(0,0);
    if (action == 'N')
        moveloc.y += -1;
    if (action == 'S')
        moveloc.y += 1;
    if (action == 'E')
        moveloc.x += 1;
    if (action == 'W')
        moveloc.x += -1;
    _character->move(moveloc);
}

void IAController::set_keys(int keys[TOTAL_KEY])
{
    if (keys)
        return;
    return;
}

std::shared_ptr<Character> IAController::get_character()
{
    return _character;
}

void IAController::initCoord()
{
    int inc = 0;
    std::vector<Coord2> vect;
    while (inc < (int)_charAll.size()){
        vect.push_back(_charAll[inc]->get_character()->getPosition2D());
        inc++;
    }
    _posList = vect;
}