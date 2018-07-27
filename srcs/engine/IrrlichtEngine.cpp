/*
 ** EPITECH PROJECT, 2018
 ** IndieStudio
 ** File description:
 ** IrrlichtEngine
 */

#include "Engine/IrrlichtEngine.hpp"

IrrlichtEngine::IrrlichtEngine()
{
	std::shared_ptr<Irrlicht> irr(new Irrlicht());
	std::shared_ptr<ISound> sound(new SoundSfml());
	_gui = irr;
	_input = irr;
	_sound = sound = sound;
}

void IrrlichtEngine::update()
{
	_camera.update();
	_gui->set_camera(_camera.getPos(), _camera.getLook());
	_gui->draw_all();
}

IrrlichtEngine &IrrlichtEngine::Instance()
{
	static IrrlichtEngine instance;
	return instance;
}
