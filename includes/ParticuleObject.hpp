/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** ParticuleObject.hpp
*/

#ifndef PARTICULEOBJECT_HPP_
	#define PARTICULEOBJECT_HPP_
	#include "ObjectExplosion.hpp"
	#include <memory>
	#include <chrono>
	#define PARTICULE_TIME 750

class ParticuleObject {
public:
	ParticuleObject(std::shared_ptr<IObject> particule) : _particule(particule), _start(std::chrono::system_clock::now()) {}
	~ParticuleObject() {}
	bool isFinished() {
		int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - _start).count();
		if (milliseconds > PARTICULE_TIME)
			return true;
		else
			return false;
	}
	std::shared_ptr<IObject> _particule;
	std::chrono::time_point<std::chrono::system_clock> _start;
};

#endif /* !PARTICULEOBJECT_HPP_ */
