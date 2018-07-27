/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IrrlichtEngine
*/

#ifndef IRRLICHTENGINE_HPP_
#define IRRLICHTENGINE_HPP_

#include "AEngine.hpp"
#include "Irrlicht.hpp"
#include "SoundSfml.hpp"

class IrrlichtEngine : public AEngine {
private:
	IrrlichtEngine();
public:
	//singleton
	IrrlichtEngine(const IrrlichtEngine&) = delete;
	IrrlichtEngine &operator=(const IrrlichtEngine&) = delete;
	~IrrlichtEngine() = default;
	static IrrlichtEngine &Instance();
	//functions
	void update() override;
};

#endif
