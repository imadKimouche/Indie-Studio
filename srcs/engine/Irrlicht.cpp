/*
 ** EPITECH PROJECT, 2018
 ** IndieStudio
 ** File description:
 ** Irrlicht
 */

#include "Engine/Irrlicht.hpp"

Irrlicht::Irrlicht()
{
	_event = std::unique_ptr<MyEventReceiver>(new MyEventReceiver(this));
	for (size_t i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
		_irrkey[i] = M_KEY_NONE;
	_camera = nullptr;
	release_all();
	initKeys();
}

Irrlicht::~Irrlicht()
{
	close_window();
}

bool Irrlicht::is_key(int index) const
{
	if (index <= 0 || index > irr::KEY_KEY_CODES_COUNT)
		return false;
	return _keys[index];
}

void Irrlicht::push_key(int index)
{
	if (index <= 0|| index > irr::KEY_KEY_CODES_COUNT)
		return;
	_keys[index] = true;
}

void Irrlicht::release_key(int index)
{
	if (index <= 0 || index > irr::KEY_KEY_CODES_COUNT)
		return;
	_keys[index] = false;
}

void Irrlicht::release_all()
{
	for (size_t i = 0; i < M_KEY_LAST; i++)
		_keys[i] = false;
	for (size_t i = 0; i < MAX_JOYSTICK; i++) {
		for (size_t j = 0; j < M_JOYSTICK_END; j++)
			release_joystick(i, j);
	}
}

bool Irrlicht::is_joystick(int index, char key)
{
	return _joy[index][key];
}

void Irrlicht::push_joystick(int index, char key)
{
	if (index < MAX_JOYSTICK && key >= 0 && key < M_JOYSTICK_END)
	_joy[index][key] = true;
}

void Irrlicht::release_joystick(int index, char key)
{
	if (index < MAX_JOYSTICK && key >= 0 && key < M_JOYSTICK_END)
		_joy[index][key] = false;
}

std::vector<int> Irrlicht::get_keys()
{
	std::vector<int> pushed;

	for (int i = 0; i < M_KEY_LAST; i++) {
		if (_keys[i])
			pushed.push_back(i);
	}
	for (int i = 0; i < MAX_JOYSTICK; i++) {
		for (int j = 0; j < M_JOYSTICK_END; j++) {
			if (is_joystick(i, j))
				pushed.push_back((i + 1) * 100 + j);
		}
	}
	return pushed;
}

void Irrlicht::initKeys()
{
	_irrkey[irr::KEY_KEY_A] = M_KEY_A;
	_irrkey[irr::KEY_KEY_B] = M_KEY_B;
	_irrkey[irr::KEY_KEY_C] = M_KEY_C;
	_irrkey[irr::KEY_KEY_E] = M_KEY_E;
	_irrkey[irr::KEY_KEY_D] = M_KEY_D;
	_irrkey[irr::KEY_KEY_F] = M_KEY_F;
	_irrkey[irr::KEY_KEY_G] = M_KEY_G;
	_irrkey[irr::KEY_KEY_H] = M_KEY_H;
	_irrkey[irr::KEY_KEY_I] = M_KEY_I;
	_irrkey[irr::KEY_KEY_J] = M_KEY_J;
	_irrkey[irr::KEY_KEY_K] = M_KEY_K;
	_irrkey[irr::KEY_KEY_L] = M_KEY_L;
	_irrkey[irr::KEY_KEY_M] = M_KEY_M;
	_irrkey[irr::KEY_KEY_P] = M_KEY_P;
	_irrkey[irr::KEY_KEY_N] = M_KEY_N;
	_irrkey[irr::KEY_KEY_O] = M_KEY_O;
	_irrkey[irr::KEY_KEY_Q] = M_KEY_Q;
	_irrkey[irr::KEY_KEY_R] = M_KEY_R;
	_irrkey[irr::KEY_KEY_S] = M_KEY_S;
	_irrkey[irr::KEY_KEY_T] = M_KEY_T;
	_irrkey[irr::KEY_KEY_U] = M_KEY_U;
	_irrkey[irr::KEY_KEY_V] = M_KEY_V;
	_irrkey[irr::KEY_KEY_W] = M_KEY_W;
	_irrkey[irr::KEY_KEY_X] = M_KEY_X;
	_irrkey[irr::KEY_KEY_Y] = M_KEY_Y;
	_irrkey[irr::KEY_KEY_Z] = M_KEY_Z;
	_irrkey[irr::KEY_F10] = M_KEY_0;
	_irrkey[irr::KEY_F1] = M_KEY_1;
	_irrkey[irr::KEY_F2] = M_KEY_2;
	_irrkey[irr::KEY_F3] = M_KEY_3;
	_irrkey[irr::KEY_F4] = M_KEY_4;
	_irrkey[irr::KEY_F5] = M_KEY_5;
	_irrkey[irr::KEY_F6] = M_KEY_6;
	_irrkey[irr::KEY_F7] = M_KEY_7;
	_irrkey[irr::KEY_F8] = M_KEY_8;
	_irrkey[irr::KEY_F9] = M_KEY_9;
	_irrkey[irr::KEY_UP] = M_KEY_UP;
	_irrkey[irr::KEY_DOWN] = M_KEY_DOWN;
	_irrkey[irr::KEY_LEFT] = M_KEY_LEFT;
	_irrkey[irr::KEY_RIGHT] = M_KEY_RIGHT;
	_irrkey[irr::KEY_RETURN] = M_KEY_ENTER;
	_irrkey[irr::KEY_SHIFT] = M_KEY_SHIFT;
	_irrkey[irr::KEY_CONTROL] = M_KEY_CTRL;
	_irrkey[irr::KEY_MENU] = M_KEY_ALT;
	_irrkey[irr::KEY_DELETE] = M_KEY_SUPR;
	_irrkey[irr::KEY_BACK] = M_KEY_REMOVE;
	_irrkey[irr::KEY_SPACE] = M_KEY_SPACE;
	_irrkey[irr::KEY_ESCAPE] = M_KEY_ESC;
}

std::string Irrlicht::translate_joystick(int index) const
{
	std::string name;
	int joy = index / 100 - 1;
	int key = index % 100;
	if (joy >= MAX_JOYSTICK || joy < 0 || key < 0 || key > M_JOYSTICK_END)
			return "NONE";
	name += "J" + std::to_string(joy) + " ";
	switch (key) {
		case M_JOYSTICK_A:
			name += "A";
		break;
		case M_JOYSTICK_B:
			name += "B";
		break;
		case M_JOYSTICK_X:
			name += "X";
		break;
		case M_JOYSTICK_Y:
			name += "Y";
		break;
		case M_JOYSTICK_L1:
			name += "L1";
		break;
		case M_JOYSTICK_R1:
			name += "R1";
		break;
		case M_JOYSTICK_SELECT:
			name += "SELECT";
		break;
		case M_JOYSTICK_START:
			name += "START";
		break;
		case M_JOYSTICK_XBOX:
			name += "XBOX";
		break;
		case M_JOYSTICK_L3:
			name += "L3";
		break;
		case M_JOYSTICK_R3:
			name += "R3";
		break;
		case M_JOYSTICK_LEFT:
			name += "LEFT";
		break;
		case M_JOYSTICK_DOWN:
			name += "DOWN";
		break;
		case M_JOYSTICK_TOP:
			name += "TOP";
		break;
		case M_JOYSTICK_RIGHT:
			name += "RIGHT";
		break;
		default:
			name += "COOL";
		break;
	}
	return name;
}

std::string Irrlicht::translate_key(int index) const
{
	std::string charac;
	if (index > M_KEY_LAST)
		return translate_joystick(index);
	if (index >= 1 && index <= 26) {
		charac = (char)(64 + index);
		return charac;
	} else if (index >= 27 && index <= 36) {
		charac = 48 + index - 27;
		return charac;
	}
	switch (index) {
		case 37:
			return "UP";
		break;
		case 38:
			return "DOWN";
		break;
		case 39:
			return "LEFT";
		break;
		case 40:
			return "RIGHT";
		break;
		case 41:
			return "ENTER";
		break;
		case 42:
			return "SHIFT";
		break;
		case 43:
			return "CTRL";
		break;
		case 44:
			return "ALT";
		break;
		case 45:
			return "SUPR";
		break;
		case 46:
			return "REMOVE";
		break;
		case 47:
			return "SPACE";
		break;
		case 48:
			return "ECHAP";
		break;
		default :
			return "NONE";
		break;
	}
}

void Irrlicht::set_window(const Coord2 &coord)
{
	_windowX = coord.x;
	_windowY = coord.y;
	_device = irr::createDevice(
			irr::video::EDT_OPENGL,
			irr::core::dimension2d<irr::u32>(coord.x, coord.y),
			32,false,false,false,_event.get());
	_driver = _device->getVideoDriver();
	_sceneManager = _device->getSceneManager();
	_gui = _device->getGUIEnvironment();
	_device->setWindowCaption(L"Bomberman");
	irr::core::array<irr::SJoystickInfo> joystickInfo;
	_device->activateJoysticks(joystickInfo);
	//for(irr::u32 joystick = 0; joystick < joystickInfo.size(); ++joystick)
	//	std::cout << "Joystick detected :" << joystickInfo[joystick].Name.c_str() << " with " << joystickInfo[joystick].Buttons << " buttons" << '\n';
}

void Irrlicht::close_window()
{
	_device->closeDevice();
}

void Irrlicht::set_camera(const Coord3 &pos, const Coord3 &orientation)
{
	irr::core::vector3df posi(pos.x, pos.y,pos.z);
	irr::core::vector3df lookat(orientation.x, orientation.y, orientation.z);

	if (!_camera)
		_camera = _sceneManager->addCameraSceneNode(0, posi, lookat);
	else {
		_camera->setPosition(posi);
		_camera->setTarget(lookat);
	}
}

void Irrlicht::add_object(std::shared_ptr<IObject> object)
{
	IObject::ObjType type = object->getType();
	if (type == IObject::THREED) {
		std::shared_ptr<AObject3D> obj = std::static_pointer_cast<AObject3D>(object);
		add_object3D(obj);
	} else if (type == IObject::TEXT) {
		std::shared_ptr<ObjectText> obj = std::static_pointer_cast<ObjectText>(object);
		_textObjects.push_back(obj);
	} else if (type == IObject::IMG) {
		std::shared_ptr<Object2D> obj = std::static_pointer_cast<Object2D>(object);
		_2Dobjects.push_back(obj);
	} else if (type == IObject::EXPLO){
		std::shared_ptr<ObjectExplosion> obj = std::static_pointer_cast<ObjectExplosion>(object);
		add_explosion(obj);
	}
}

void Irrlicht::add_explosion(std::shared_ptr<ObjectExplosion> object)
{
	Coord3 pos = object->getPosition3D();
	Explo explo;
	explo.top = create_particle_system(object->getTexture(), 1, pos, object->getTopRadius());
	explo.bottom = create_particle_system(object->getTexture(), 2, pos, object->getBotRadius());
	explo.right = create_particle_system(object->getTexture(), 3, pos, object->getRightRadius());
	explo.left = create_particle_system(object->getTexture(), 4, pos, object->getLeftRadius());
	_exploNodes.push_back(explo);
	_exploObjects.push_back(object);
}

irr::scene::IParticleSystemSceneNode *Irrlicht::create_particle_system(
		const std::string &texture, int orientation, Coord3 pos, size_t rad)
{
	irr::core::vector3df direction(0.0f, 0.0f, 0.0f);
	switch(orientation) {
	case 1:
		direction.Z = 0.002f * rad;
		break;
	case 2:
		direction.Z = -0.002f * rad;
		break;
	case 3:
		direction.X = 0.002f * rad;
		break;
	case 4:
		direction.X = -0.002f * rad;
		break;
	}
	irr::scene::IParticleSystemSceneNode *ps = _sceneManager->addParticleSystemSceneNode();
	ps->setPosition(irr::core::vector3df(pos.x, pos.y,pos.z));
	ps->setScale(irr::core::vector3df(0.1f, 0.1f,0.1f));
	irr::scene::IParticleEmitter *emitter = ps->createPointEmitter(
		direction,        // direction et longueur de diffusion
			80,100,                                       // nb particules emises a la sec min / max
			irr::video::SColor(0,255,255,255),                  // couleur la plus sombre
			irr::video::SColor(0,255,255,255),            // couleur la plus claire
			600, 1000,                                    // duree de vie min / max
			0,                                            // angle max d'ecart / direction prevue
			irr::core::dimension2df(0.5f,0.5f),           // taille minimum
			irr::core::dimension2df(1.0f,1.0f));
	ps->setEmitter(emitter);
	emitter->drop();
	irr::scene::IParticleAffector *paf = ps->createFadeOutParticleAffector();
	ps->addAffector(paf);
	paf->drop();
	ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, _driver->getTexture(texture.c_str()));     // on colle une texture
	ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);						//on set la transparence
	return(ps);
}

void Irrlicht::add_object3D(std::shared_ptr<AObject3D> object)
{
	Coord3 pos = object->getPosition3D();
	Coord3f scale = object->getScale();
	irr::scene::IAnimatedMeshSceneNode *model = _sceneManager->addAnimatedMeshSceneNode(
			_sceneManager->getMesh(object->getMesh().c_str()),
			0, -1,
			irr::core::vector3df(pos.x, pos.y, pos.z));

	model->setScale(irr::core::vector3df(scale.x, scale.y, scale.z));
	model->setMaterialFlag(irr::video::EMF_LIGHTING, false);					//non sensible à l'éclairage
	model->setMaterialTexture(0, _driver->getTexture(object->getTexture().c_str()));		//texture
	_nodes.push_back(model);
	_3Dobjects.push_back(object);
}

void Irrlicht::scale(int index, std::shared_ptr<AObject3D> object)
{
	irr::core::vector3df r_scale = _nodes[index]->getScale();
	Coord3f scale = object->getScale();

	if (r_scale.X == scale.x && r_scale.Y == scale.y && r_scale.Z == scale.z)
		return;
	r_scale.X = scale.x;
	r_scale.Y = scale.y;
	r_scale.Z = scale.z;
	_nodes[index]->setScale(r_scale);
}

void Irrlicht::draw_object3D(int index, std::shared_ptr<AObject3D> object)
{
	Coord3 tmp_pos = object->getPosition3D();
	Anime tmp_anim = object->getAnimation();
	irr::core::vector3df real_pos = _nodes[index]->getPosition();
	scale(index, object);
	_nodes[index]->setRotation(irr::core::vector3df(0, object->getDirection() -90, 0));
	if (object->getAnimation()._teleport) {
		_nodes[index]->setPosition(irr::core::vector3df(tmp_pos.x, tmp_pos.y, tmp_pos.z));
		tmp_anim._movingChanged = false;
		tmp_anim._moving = false;
		_nodes[index]->removeAnimators();
	}
	if (tmp_anim._moving)
		anime(object);
	if (tmp_anim._movingChanged)
		move(index, tmp_pos, tmp_anim, real_pos);
	playAnimation(_nodes[index], object);
}

void Irrlicht::draw_object2D(std::shared_ptr<Object2D> object)
{
	irr::video::ITexture *image = _driver->getTexture(object->getTexture().c_str());
	irr::core::dimension2d<irr::u32> size = image->getSize();
	irr::core::position2d<irr::s32> pos(object->getPosition2D().x, object->getPosition2D().y);
	irr::core::position2d<irr::s32> leftTop(0,0);
	irr::core::position2d<irr::s32> rightBottom(size.Width, size.Height);
	irr::core::rect<irr::s32> rect(leftTop, rightBottom);
	_driver->draw2DImage(image, pos, rect, 0, irr::video::SColor(255,255,255,255), true);
}

void Irrlicht::draw_objectText(std::shared_ptr<ObjectText> object)
{
	const wchar_t *text = object->getText();

	irr::gui::IGUIFont *font = _gui->getFont(object->getFont().c_str());

	Coord2 pos = object->getPosition2D();
	irr::core::dimension2d<irr::u32> size = font->getDimension(text);
	Color color = object->getColor();

	if (font) {
		font->draw(text,
		        irr::core::rect<irr::s32>(pos.x, pos.y, pos.x + size.Width, pos.y + size.Height),
			irr::video::SColor(color.a, color.r, color.g, color.b));
	}
}

void Irrlicht::remove_object(std::shared_ptr<IObject> object)
{
	if (object->getType() == IObject::THREED) {
		auto obj = std::find(_3Dobjects.begin(), _3Dobjects.end(), object);
		if (obj == _3Dobjects.end())
			return;
		ptrdiff_t pos = std::distance(_3Dobjects.begin(), obj);
		_3Dobjects.erase(_3Dobjects.begin() + pos);
		_nodes[pos]->removeAnimators();
		_nodes[pos]->remove();
		_nodes.erase(_nodes.begin() + pos);
	} else if (object->getType() == IObject::IMG) {
		auto it = std::find(_2Dobjects.begin(), _2Dobjects.end(), object);
		ptrdiff_t pos = std::distance(_2Dobjects.begin(), it);
		if (it != _2Dobjects.end())
			_2Dobjects.erase(_2Dobjects.begin() + pos);
	} else if (object->getType() == IObject::TEXT){
		auto it = std::find(_textObjects.begin(), _textObjects.end(), object);
		ptrdiff_t pos = std::distance(_textObjects.begin(), it);
		if (it != _textObjects.end())
			_textObjects.erase(_textObjects.begin() + pos);
	} else if (object->getType() == IObject::EXPLO) {
		auto it = std::find(_exploObjects.begin(), _exploObjects.end(), object);
		ptrdiff_t pos = std::distance(_exploObjects.begin(), it);
		if (it != _exploObjects.end())
			_exploObjects.erase(it);
		_exploNodes[pos].top->removeAllAffectors();
		_exploNodes[pos].bottom->removeAllAffectors();
		_exploNodes[pos].right->removeAllAffectors();
		_exploNodes[pos].left->removeAllAffectors();
		_exploNodes[pos].top->remove();
		_exploNodes[pos].bottom->remove();
		_exploNodes[pos].right->remove();
		_exploNodes[pos].left->remove();
		_exploNodes.erase(_exploNodes.begin() + pos);
	}
}

bool Irrlicht::run()
{
	if (_device)
		return _device->run();
	else
		return false;
}

void Irrlicht::draw_all()
{
	if(!_device->run() || !_device->isWindowActive())
		return;
	for (size_t i = 0; i < _3Dobjects.size(); i++)
		draw_object3D(i, _3Dobjects[i]);
	_driver->beginScene(true, true,0);
	_sceneManager->drawAll();
	for(size_t i = 0; i < _2Dobjects.size(); i++)
		draw_object2D(_2Dobjects[i]);
	for(size_t i = 0; i < _textObjects.size(); i++)
		draw_objectText(_textObjects[i]);
	_gui->drawAll();
	_driver->endScene();
}

void Irrlicht::clear_scene()
{
	_textObjects.clear();
	_2Dobjects.clear();
	_3Dobjects.clear();
	_exploObjects.clear();
	std::for_each(_nodes.begin(), _nodes.end(), [](irr::scene::IAnimatedMeshSceneNode *node){
		node->removeAnimators();
		node->remove();
	});
	_nodes.clear();
	std::for_each(_exploNodes.begin(), _exploNodes.end(), [](Explo explo){
		explo.top->removeAllAffectors();
		explo.top->remove();
		explo.bottom->removeAllAffectors();
		explo.bottom->remove();
		explo.right->removeAllAffectors();
		explo.right->remove();
		explo.left->removeAllAffectors();
		explo.left->remove();
	});
	_exploNodes.clear();

}

void Irrlicht::anime(std::shared_ptr<AObject3D> object)
{
	Anime tmp_anim = object->getAnimation();

	auto now = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = now - tmp_anim._animeStart;
	if (diff.count() > tmp_anim._animeTime / 1000)
		tmp_anim._moving = false;
	object->setAnimation(tmp_anim);
}

void Irrlicht::move(int index, Coord3 tmp_pos, Anime tmp_anim, irr::core::vector3df real_pos)
{
	double m_time = (NORME(_nodes[index]->getPosition().X - tmp_pos.x,
	        _nodes[index]->getPosition().Y - tmp_pos.y,
		_nodes[index]->getPosition().Z - tmp_pos.z) / tmp_anim._speed) * 1000;
	auto now = std::chrono::system_clock::now();
	irr::scene::ISceneNodeAnimator* anim = nullptr;
	if (!tmp_anim._moving) {
		anim = _sceneManager->createFlyStraightAnimator(real_pos,
			irr::core::vector3df(tmp_pos.x, tmp_pos.y, tmp_pos.z),
			m_time, false);
		tmp_anim._animeTime = m_time;
		tmp_anim._animeStart = now;
	} else {
		std::chrono::duration<double> diff = now - tmp_anim._animeStart;
		m_time = diff.count() * 1000;
		std::chrono::milliseconds dur((long)(tmp_anim._animeTime - m_time));
		std::chrono::time_point<std::chrono::system_clock> dt(dur);
		tmp_anim._animeStart = now;
		tmp_anim._animeTime = m_time;
		_nodes[index]->removeAnimators();
		anim = _sceneManager->createFlyStraightAnimator(real_pos,
		        irr::core::vector3df(tmp_pos.x, tmp_pos.y, tmp_pos.z),
			m_time, false);
	}
	if (anim) {
		_nodes[index]->addAnimator(anim);
		anim->drop();
	}
	tmp_anim._moving = true;
	tmp_anim._movingChanged = false;
	((AObject3D*)_3Dobjects[index].get())->setAnimation(tmp_anim);
}

void Irrlicht::playAnimation(irr::scene::IAnimatedMeshSceneNode *node, std::shared_ptr<AObject3D> object)
{
	Anime anim = object->getAnimation();

	if (!anim._changed)
		return;
	if (node)
	{
		node->setFrameLoop(anim._start, anim._end);
		node->setAnimationSpeed(anim._frame);
	}
	anim._changed = false;
	object->setAnimation(anim);
}
