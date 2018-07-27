/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** ICamera && ACamera
*/

#ifndef ICAMERA_HPP_
#define ICAMERA_HPP_

class ICamera {
public:
	virtual ~ICamera() {};
	virtual void update() = 0;
	virtual void setPos(Coord3 pos) = 0;
	virtual void setLook(Coord3 look) = 0;
	virtual Coord3 getPos() = 0;
	virtual Coord3 getLook() = 0;
};

class ACamera : public ICamera {
public:
	ACamera(const Coord3 pos, const Coord3 look) {setPos(pos); setLook(look);}
	virtual ~ACamera() = default;
	virtual void update() = 0;
	void setPos(Coord3 pos) override { _pos = pos; };
	void setLook(Coord3 look) override { _look = look; };
	Coord3 getPos() override { return _pos; };
	Coord3 getLook() override { return _look; };
private:
	Coord3 _pos;
	Coord3 _look;
};

class Camera : public ACamera {
public:
	Camera(Coord3 pos = Coord3{0, 0, 0}, Coord3 look = Coord3{0, 0, 0}) : ACamera(pos, look) {}
	void update() override {};
};

#endif /* !ICamera */
