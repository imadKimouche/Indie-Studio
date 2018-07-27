/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Text.hpp
*/

#ifndef TEXT_HPP_
	#define TEXT_HPP_
	#include <string>
	#include "Coord.hpp"

class Text {
	public:
		Text(std::string text, Coord pos) :
			_text(text), _pos(pos.x, pos.y) {}
		~Text();
	protected:
	private:
		std::string _text;
		Coord _pos;
};

#endif /* !TEXT_HPP_ */
