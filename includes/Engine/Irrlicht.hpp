/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Irrlicht header file
*/

#ifndef IRRLICHT_HPP_
#define IRRLICHT_HPP_

class Irrlicht;
#include "IInput.hpp"
#include "IGui.hpp"
#include "../Coord.hpp"
#include "../AObject3D.hpp"
#include "../AObject2D.hpp"
#include "../AObjectText.hpp"
#include "../ObjectExplosion.hpp"
#include "MyEventReceiver.hpp"

#include <irr/irrlicht.h>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>

class Irrlicht : public IInput, public IGui {
public:
	Irrlicht();
	~Irrlicht();

	/* IInput implementation */
	bool is_key(int index) const override;
	void push_key(int index) override;
	bool is_joystick(int index, char key) override;
	void push_joystick(int index, char key) override;
	void release_joystick(int index, char key) override;
	void release_key(int index) override;
	void release_all() override;
	std::vector<int> get_keys() override;
	std::string translate_key(int index) const override;

	/*IGui implementation */
	void add_object(std::shared_ptr<IObject> object) override;
	void add_object3D(std::shared_ptr<AObject3D> object);
	void draw_objectText(std::shared_ptr<ObjectText> object);
	irr::scene::IParticleSystemSceneNode *create_particle_system(
		const std::string &texture, int orientation, Coord3 pos, size_t radius);
	void add_explosion(std::shared_ptr<ObjectExplosion> object);
	void draw_object2D(std::shared_ptr<Object2D> object);
	void draw_object3D(int index, std::shared_ptr<AObject3D> object);
	void scale(int index, std::shared_ptr<AObject3D> object);
	void remove_object(std::shared_ptr<IObject> object) override;
	void set_window(const Coord2 &coord) override;
	void set_camera(const Coord3 &pos, const Coord3 &orientation) override;
	void draw_all() override;
	void clear_scene() override;
	void close_window() override;
	bool run();
	int _irrkey[irr::KEY_KEY_CODES_COUNT]; // convert irrlicht key to M_key
private:
  class Explo {
  public:
	  irr::scene::IParticleSystemSceneNode *top;
	  irr::scene::IParticleSystemSceneNode *bottom;
	  irr::scene::IParticleSystemSceneNode *right;
	  irr::scene::IParticleSystemSceneNode *left;
  };

	/* Input */
	void initKeys(); // set the convertion between keys
	std::string translate_joystick(int index) const;

	bool _keys[M_KEY_LAST]; // keys pushed or not
	std::unordered_map<int, std::unordered_map<char, bool>> _joy; // joystick key

	std::unique_ptr<MyEventReceiver> _event; // to handle events from irrlicht

	/*Gui*/
	void anime(std::shared_ptr<AObject3D> object);
	void playAnimation(irr::scene::IAnimatedMeshSceneNode *node, std::shared_ptr<AObject3D> object);
	void move(int index, Coord3 tmp_pos, Anime tmp_anim, irr::core::vector3df real_pos);

	std::vector<std::shared_ptr<AObject3D>> _3Dobjects;
	std::vector<std::shared_ptr<ObjectText>> _textObjects;
	std::vector<std::shared_ptr<Object2D>> _2Dobjects;
	std::vector<std::shared_ptr<ObjectExplosion>> _exploObjects;
	std::vector<Explo> _exploNodes;
	std::vector<irr::scene::IAnimatedMeshSceneNode *> _nodes;
	int _windowX;
	int _windowY;
	irr::IrrlichtDevice *_device;
	irr::video::IVideoDriver *_driver;
	irr::scene::ISceneManager *_sceneManager;		// ce qui permet de gerer les modele 3D
	irr::gui::IGUIEnvironment *_gui;              // ce qui permet d'afficher du texte 2D/boutons/etc à l'écran
	irr::scene::ICameraSceneNode *_camera;		// la caméra
};

#endif
