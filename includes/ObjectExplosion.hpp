//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// particle explosion 
//

#ifndef OBJECT_EXPLOSION_HPP
#define OBJECT_EXPLOSION_HPP

#include "IObject.hpp"
#include <vector>

class ObjectExplosion : public IObject {

public:

	ObjectExplosion(const std::string &texture, Coord3 pos = Coord3(0,0,0),
			size_t top = 1, size_t bot = 1, size_t right = 1, size_t left = 1):
		_type(IObject::EXPLO), _pos2D(Coord2(pos.x,pos.z)), _pos3D(pos), _texture(texture),
		_topRadius(top), _botRadius(bot), _rightRadius(right), _leftRadius(left) {}
	virtual ~ObjectExplosion() {}

	void update() override {}
	Coord2 getPosition2D()const override { return (_pos2D); }
	void setPosition2D(Coord2 pos) override { _pos2D = pos; }
	ObjType getType() const override { return _type; }

	Coord3 getPosition3D() const { return _pos3D;}
	size_t getTopRadius() const { return _topRadius; }
	size_t getBotRadius() const { return _botRadius; }
	size_t getRightRadius() const { return _rightRadius; }
	size_t getLeftRadius() const { return _leftRadius; }
	const std::string &getTexture() const { return _texture; }

private:

	ObjType _type;
	Coord2 _pos2D;

	Coord3 _pos3D;
	std::string _texture;
	size_t _topRadius;
	size_t _botRadius;
	size_t _rightRadius;
	size_t _leftRadius;

};

#endif
