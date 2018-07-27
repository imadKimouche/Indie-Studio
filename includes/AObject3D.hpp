//
// EPITECH PROJECT, 2018
// indistudio
// File description:
// A 3D Object
//

#ifndef A_OBJECT_3D_HPP
	#define A_OBJECT_3D_HPP
	#include "IObject.hpp"
	#define NONE 0
	#define WALL 1
	#define WALL_INDE 2
	#define POWERUP 3
	#define BOMB 4
	#define CHARACTER 5

struct Anime {
	//function
	Anime() : _start(0), _end(0), _frame(0), _speed(7),
	 	_animeStart(std::chrono::system_clock::now()), _moving(false),
		 _animeTime(0), _movingChanged(false), _changed(true),
		 _teleport(false) {}
	Anime(int start, int end) : _start(start), _end(end), _frame(0), _speed(7),
	 	_animeStart(std::chrono::system_clock::now()), _moving(false),
		 _animeTime(0), _movingChanged(false), _changed(true),
		 _teleport(false) {}
	void frame(int start, int end) {_start = start; _end = end; _changed = true;}
	void frameSpeed(int start, int end, int speed) {_start = start; _end = end; _frame = speed; _changed = true;}
	//attribute
	int _start;
	int _end;
	int _frame;
	float _speed;
	std::chrono::time_point<std::chrono::system_clock> _animeStart;
	bool _moving;
	double _animeTime;
	bool _movingChanged;
	bool _changed;
	bool _teleport;
};


class AObject3D : public IObject{
public:
	AObject3D() : _type(IObject::ObjType::THREED), _pos2D(Coord2(0,0)),
		_pos3D(Coord3(0,0,0)),_scale(Coord3f(1,1,1)), _animation(Anime{}), _direction(0) {}
	AObject3D(Coord2 &pos2D, Coord3 &pos3D, Coord3f &scale, const std::string &m, const std::string &t)
	: _type(IObject::ObjType::THREED), _pos2D(pos2D), _pos3D(pos3D), _scale(scale), _mesh(m),
	 _texture(t), _animation(Anime{}), _direction(0)
	{
	}

	virtual ~AObject3D() = default;
	void update() override { return; }

	/* Setters */
	void setPosition3D(const Coord3 &pos) { _pos3D = pos; }
	void setPosition2D(Coord2 pos) override { _pos2D = pos; }
	void setMesh(const std::string &s) {_mesh = s; }
	void setTexture(const std::string &s) { _texture = s; }
	void setScale(const Coord3f& s) { _scale = s; }
	void setAnimation(const Anime &animation) { _animation = animation; }
	void setDirection(int direction) { _direction = direction; }

	/* Getters */
	ObjType getType() const override { return _type; }
	Coord3 getPosition3D() const { return _pos3D; }
	Coord2 getPosition2D() const override { return _pos2D; }
	const std::string &getMesh() const { return _mesh; }
	Coord3f getScale() const { return _scale; }
	const std::string &getTexture() const { return _texture; }
	Anime &getAnimation() { return _animation; }
	int getDirection() { return _direction; }

protected:

	/* IObject */
	ObjType _type;
	Coord2 _pos2D;

	/* 3D Object */
	Coord3 _pos3D;
	Coord3f _scale;
	std::string _mesh;
	std::string _texture;
	Anime _animation;
	int _direction;
};

#endif
