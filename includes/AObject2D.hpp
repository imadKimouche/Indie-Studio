//
// EPITECH PROJECT, 2018
// indiestudio image
// File description:
// image
//

#ifndef A_OBJECT_2D
#define A_OBJECT_2D

#include "IObject.hpp"
#define IMG_DIR "./ressources/images/"
class Object2D : public IObject {
public:
	Object2D() : _type(IObject::ObjType::IMG), _pos2D(Coord2(0,0)), _texture(nullptr){}
	Object2D(Coord2 pos, const std::string &s) : _type(IObject::IMG), _pos2D(pos), _texture(s) {}
	Object2D(const Object2D &obj): _type(IObject::IMG), _pos2D(obj._pos2D), _texture(obj._texture) {}
	virtual ~Object2D() = default;

	void setPosition2D(Coord2 pos) override { _pos2D = pos; }
	Coord2 getPosition2D() const override { return _pos2D; }
	ObjType getType() const override { return _type; }
	void setTexture(const std::string &s) { _texture = s; }
	const std::string &getTexture() const { return _texture; }

	void update() { return; }

protected:

	ObjType _type;
	Coord2 _pos2D; 		//position du coin haut gauche de l'image
	std::string _texture;

};


#endif
