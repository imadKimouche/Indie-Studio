/*
** EPITECH PROJECT, 2018
** Indie Studio
** File description:
** TesterMObserver.cpp
*/

#include "MapObserver.hpp"
#include "Coord.hpp"
#include "Behavior.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main(){
    std::srand(std::time(nullptr));
    Coord2 size(13,13);
    int **array;
    int y = 0;
    std::vector<std::shared_ptr<Wall>> list;
    std::vector<Coord2> lists;
    array = new int*[size.x];
    while (y < size.x){
        array[y] = new int[size.y];
        y++;
    }
    MapObserver test("patternFiller.isb", size, array);
    test.printLogical();
    list = test.getObjects();
    lists = test.getSpawn();
    std::cout << "Nb Wall " << list.size() << std::endl;
    std::cout << "Nb Spawn " << lists.size() << std::endl;
    Behavior *comp = new Behavior(test.getLogicalArray(),1,1,size);
    std::cout << comp->getAction(lists, 0);
    std::shared_ptr<Character> cptr = nullptr;
    return 0;
}
