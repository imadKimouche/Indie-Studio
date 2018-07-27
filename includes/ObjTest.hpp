//
// EPITECH PROJECT, 2018
// indistudio
// File description:
// objtest
//

#include "IObject.hpp"

class ObjTest: public IObject {
public:

	ObjTest(ObjType type, Coord2 pos2D, Coord3 pos3D) : _type(type),_position3D(pos3D), _position2D(pos2D) {}
	void setPosition3D(Coord3 pos) { _position3D = pos; }
	void setPosition2D(Coord2 pos) { _position2D = pos; }
	void setMesh(const std::string &s) { _mesh = s; }
	void setTexture(const std::string &s) { _texture = s; }
	void setSize(float s) { _size = s; }
	Coord3 getPosition3D() const { return (_position3D); }
	Coord2 getPosition2D() const { return (_position2D); }
	std::string getMesh() const  { return (_mesh); };
	float getSize() const { return (_size); }
	std::string getTexture() const {return (_texture);}

private:

	ObjType _type;
	Coord3 _position3D;
	Coord2 _position2D;
	std::string _texture;
	std::string _mesh;
	float _size;

};
