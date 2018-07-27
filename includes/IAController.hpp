/*
** EPITECH PROJECT, 2018
** Indie Studio Bomberman
** File description:
** IAController
*/

#ifndef IACONTROLLER_HPP_
	#define IACONTROLLER_HPP_
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <algorithm>
#include "Coord.hpp"
#include "IController.hpp"
#include "Behavior.hpp"

class IAController : public IController {
	public:
		IAController(std::shared_ptr<Character> chara, Coord2 size);
		~IAController();
        virtual void update();
	virtual void set_keys(int keys[TOTAL_KEY]);
	virtual std::shared_ptr<Character> get_character();
        int getID();
        void initCoord();
        int **getlogical(){
                return _logical;
        }
        void setlogical(int **logical){
                this->_logical = logical;
        }
        void setcharAll(std::vector<std::shared_ptr<IController>> &charAll){
                this->_charAll = charAll;
        }
	protected:
        std::shared_ptr<Character> _character;
        std::vector<Coord2> _posList;
        std::vector<std::shared_ptr<IController>> _charAll;
        int _id;
        int **_logical;
        Coord2 _size;
};

#endif /* !IACONTROLLER_HPP_ */
