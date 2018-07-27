/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Coord.hpp
*/

#ifndef COORD_HPP_
	#define COORD_HPP_

#define NORME(x,y,z) std::sqrt(std::pow(std::abs(x), 2) + std::pow(std::abs(y), 2) + std::pow(std::abs(z), 2))

struct Coord2 {
	public:
		Coord2(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
		Coord2(const Coord2 &coor)
		{
			this->x = coor.x;
			this->y = coor.y;
		}
		Coord2() { };
		~Coord2() = default;
		int x;
		int y;
		Coord2 &operator+=(const Coord2 coor) {
			this->x += coor.x;
			this->y += coor.y;
			return *this;
		}
		Coord2 &operator=(const Coord2 coor) {
			this->x = coor.x;
			this->y = coor.y;
			return *this;
		}
		bool operator==(const Coord2 coor) {
			if (this->x == coor.x && this->y == coor.y)
				return true;
			else
				return false;
		}
};

struct Coord3 {
	public:
		Coord3(int x, int y, int z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Coord3() { };
		~Coord3() = default;
		Coord3 &operator=(const Coord3 coor) {
			this->x = coor.x;
			this->y = coor.y;
			this->z = coor.z;
			return *this;
		}
		Coord3 &operator+=(const Coord3 coor) {
			this->x += coor.x;
			this->y += coor.y;
			this->z += coor.z;
			return *this;
		}
		bool operator==(const Coord3 coor) {
			if (this->x == coor.x && this->y == coor.y && this->z == coor.z)
				return true;
			else
				return false;
		}
		int x;
		int y;
		int z;
};

struct Coord3f {
	public:
		Coord3f(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Coord3f() : x(0), y(0), z(0) {};
		~Coord3f() = default;
		Coord3f &operator=(const Coord3f coor) {
			this->x = coor.x;
			this->y = coor.y;
			this->z = coor.z;
			return *this;
		}
		Coord3f &operator+=(const Coord3f coor) {
			this->x += coor.x;
			this->y += coor.y;
			this->z += coor.z;
			return *this;
		}
		bool operator==(const Coord3f coor) {
			if (this->x == coor.x && this->y == coor.y && this->z == coor.z)
				return true;
			else
				return false;
		}
		float x;
		float y;
		float z;
};

struct Color {
public:
	Color(int a, int r, int g, int b)
	{
		this->a = a;
		this->r = r;
		this->g = g;
		this->b = b;
	}
	~Color() = default;
	int a;
	int r;
	int g;
	int b;
};

#endif /* !COORD_HPP_ */
