/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Image.hpp
*/

#ifndef IMAGE_HPP_
	#define IMAGE_HPP_
	#include <string>
	#include "Coord.hpp"

class Image {
	public:
		Image(std::string image, Coord pos) : _image(image),
			_pos(pos.x, pos.y)
		{
		}
		~Image();
	protected:
	private:
		std::string _image;
		Coord _pos;
};

#endif /* !IMAGE_HPP_ */
