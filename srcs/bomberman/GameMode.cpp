/*
** EPITECH PROJECT, 2018
** INdieStudio
** File description:
** GameMode.cpp
*/

#include "GameMode.hpp"

GameMode::GameMode(Coord2 mapSize, std::vector<std::shared_ptr<PlayerController>> characters, std::vector<std::shared_ptr<IAController>> iAs) :
		_walls(), _characters(), _bombs(), _powersUp(), _map(), _mapSize(mapSize), _startAnimation(false), _iAs(iAs)
{
	this->_finish = false;
	initMap();
	initCharacters(characters, iAs);
	_walls = _map->getObjects();
}

GameMode::~GameMode()
{
	for (int i = 0 ; i < _mapSize.x ; i++) {
		delete _mapLogique[i];
	}
	delete _mapLogique;
}

void GameMode::startMusic()
{
	std::string sound = AUDIO_SOURCES;
	sound += "background.wav";
	int track = IrrlichtEngine::Instance().s_add_sound(S_TRACKS, sound);
	if (track < 0)
		return;
	IrrlichtEngine::Instance().s_loop_tracks(track, true);
	IrrlichtEngine::Instance().s_volume_tracks(track, 10);
	IrrlichtEngine::Instance().s_play(S_TRACKS, track);
}

void GameMode::startAnimation()
{
	play("StartGame.wav");
	std::shared_ptr<Object2D> start;
	std::string name;
	Coord2 coor(350, 208);

	for (int i = 1 ; i < 5 ; i++) {
		start = std::make_shared<Object2D>(coor, "./ressources/images/inGame/redlight" + std::to_string(i) + ".png");
		IrrlichtEngine::Instance().g_add_object(start);
		IrrlichtEngine::Instance().update();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		IrrlichtEngine::Instance().g_remove_object(start);
	}
}

void GameMode::start()
{
	IrrlichtEngine::Instance().s_remove_all();
	//IrrlichtEngine::Instance().g_set_camera(Camera(Coord3(_mapSize.x / 2, (_mapSize.x + _mapSize.y) / 2 + 2, _mapSize.x / 2), Coord3(_mapSize.x / 2, 0, _mapSize.y / 2)));
	IrrlichtEngine::Instance().g_set_camera(Camera(Coord3(_mapSize.x / 2, (_mapSize.x + _mapSize.y) / 2 + 2, 1), Coord3(_mapSize.x / 2, 0, _mapSize.y / 2)));
	std::shared_ptr<AObject3D> backsound(new Background(Coord3(_mapSize.x, (_mapSize.x + _mapSize.y) / 2 + 2, 5), "ressources/bg.obj", "ressources/background.jpg"));
	IrrlichtEngine::Instance().g_add_object(backsound);
	for (auto wall : _walls)
		IrrlichtEngine::Instance().g_add_object(wall);
	for (auto player : _characters)
		IrrlichtEngine::Instance().g_add_object(player->get_character());
	for (int i = -1 ; i < _mapSize.x + 1 ; i++) {
		for (int j = -1 ; j < _mapSize.y + 1 ; j++) {
			IrrlichtEngine::Instance().g_add_object(std::make_shared<Floor>(1, Coord3(i, -1, j)));
		}
	}
}

bool GameMode::update()
{
	if (!_startAnimation) {
		startAnimation();
		_startAnimation = true;
		startMusic();
	}

	for (auto &ia : this->_iAs)
		ia->setlogical(_mapLogique);
	for (auto &character : _characters)
		character.get()->update();
	if (!_finish) {
		for (auto bomb : _bombs) {
			bomb.get()->update();
		}
		deleteBombs();
		for (auto powerUp : _powersUp)
			powerUp.get()->update();
		checkCollisions();
		if (_characters.size() <= 1) {
			_finish = true;
			IrrlichtEngine::Instance().g_add_object(std::make_shared<Object2D>(Coord2(0, 0), "./ressources/images/inGame/top1.png"));
			return false;
		}
	}
	if (_finish) {
		static int times = 0;
		Coord3 coor = _characters.front()->get_character()->getPosition3D();
		Coord3 toGo = Coord3(coor.x, 6, coor.z - 5);
		Coord3 cam = IrrlichtEngine::Instance().g_get_camera().getPos();

		if (times == 5) {
			if (cam.x < toGo.x)
				cam.x++;
			else if (cam.x > toGo.x)
				cam.x--;
			if (cam.y < toGo.y)
				cam.y++;
			else if (cam.y > toGo.y)
				cam.y--;
			if (cam.z < toGo.z)
				cam.z++;
			else if (cam.z > toGo.z)
				cam.z--;
			IrrlichtEngine::Instance().g_set_camera(Camera(cam, Coord3(coor.x, 0, coor.z)));
			times = 0;
		} else {
			times++;
		}
	}
	return true;
}

void GameMode::initCharacters(std::vector<std::shared_ptr<PlayerController>> characters, std::vector<std::shared_ptr<IAController>> iAs)
{
	std::vector<Coord2> coords = _map->getSpawn();
	Coord2 coor;
	_characters.insert(_characters.end(), characters.begin(), characters.end());
	_characters.insert(_characters.end(), iAs.begin(), iAs.end());
	for (auto character : _characters) {
		coor = coords.back();
		character->get_character()->setGameModeProtocol(this);
		character->get_character()->setPosition3D(Coord3(coor.x, 0,coor.y));
		coords.pop_back();
	}
	for (auto &ia : iAs) {
		ia->setcharAll(_characters);
		ia->setlogical(_mapLogique);
	}
}

void GameMode::initMap()
{
	if (_mapSize.x % 2 == 0) {
		_mapSize.x++;
	}
	if (_mapSize.y % 2 == 0) {
		_mapSize.y++;
	}
	_mapLogique = new int*[_mapSize.x];
	for (int i = 0 ; i < _mapSize.x ; i++) {
		_mapLogique[i] = new int[_mapSize.y];
	}
	_map = new MapObserver("./srcs/Pattern/patternFiller.isb", _mapSize, _mapLogique);
}

void GameMode::checkCharactersWithPowerUp()
{
	Coord2 coor;
	std::vector<std::shared_ptr<APowerUp>>::iterator i;
	bool passed = false;

	for (auto character : _characters) {
		coor = character->get_character()->getPosition2D();
		if (_mapLogique[coor.x][coor.y] == POWERUP) {
			for ( auto it = _powersUp.begin(); it != _powersUp.end() ; ++it ) {
				if ((*it).get()->getPosition2D() == coor) {
					std::cout << "Power Up applicated" << std::endl;
					passed = (*it).get()->affect(character.get()->get_character());
					i = it;
				}
			}
			if (passed) {
				_mapLogique[coor.x][coor.y] = NONE;
				_powersUp.erase(i);
				IrrlichtEngine::Instance().g_remove_object(*(i));
				passed = false;
			}
		}
	}
}

bool GameMode::addWall(Coord3 coor)
{
	std::shared_ptr<Wall> sub;

	if (coor.x >= _mapSize.x || coor.z >= _mapSize.y || coor.x < 0 || coor.z < 0)
		return false;
	if (isFreeInCase({coor.x, coor.z})) {
		deletePowerUp({coor.x, coor.z});
		_mapLogique[coor.x][coor.z] = WALL;
		sub = std::make_shared<Wall>(true,coor);
		IrrlichtEngine::Instance().g_add_object(sub);
		_walls.push_back(std::move(sub));
		return true;
	}
	return false;
}

void GameMode::checkCollisions()
{
	checkCharactersWithPowerUp();
}

bool GameMode::isFreeInCase(Coord2 coor)
{
	if (coor.x >= _mapSize.x || coor.y >= _mapSize.y || coor.x < 0 || coor.y < 0)
		return false;
	if (_mapLogique[coor.x][coor.y] == NONE || _mapLogique[coor.x][coor.y] == POWERUP)
		return true;
	else
		return false;
}

void GameMode::exploseInCase(Coord2 coor, int radius)
{
	Coord2 left(-1, 0);
	Coord2 right(1, 0);
	Coord2 top(0, 1);
	Coord2 bot(0, -1);

	if (coor.x < 0 || coor.x >= _mapSize.x || coor.y >= _mapSize.y || coor.y < 0) {
		return;
	}
	deleteCharacter(coor);
	_mapLogique[coor.x][coor.y] = NONE;
	_bombsToExplose.push_back(coor);
	std::shared_ptr<IObject> explo(new ObjectExplosion("ressources/fire.bmp", Coord3(coor.x, 0, coor.y),
		exploseRecursion(coor, radius, top), exploseRecursion(coor, radius, bot),
		exploseRecursion(coor, radius, right), exploseRecursion(coor, radius, left)));
	IrrlichtEngine::Instance().g_add_object(explo);
	_particulesToDelete.push_back(ParticuleObject(explo));
}

int GameMode::exploseRecursion(Coord2 coor, int radius, Coord2 coord2)
{
	if (radius == 0)
		return 0;
	coor = coor += coord2;
	if (coor.x < 0 || coor.x >= _mapSize.x || coor.y >= _mapSize.y || coor.y < 0) {
		return 0;
	}
	switch (_mapLogique[coor.x][coor.y]) {
		case WALL_INDE:
			return 0;
		case WALL:
			deleteWall(coor);
			return 1;
		case POWERUP:
			deletePowerUp(coor);
			break;
		case BOMB:
			for (auto bomb : _bombs) {
				if (bomb.get()->getPosition2D() == coor) {
					bomb.get()->explosion();
				}
			}
			break;
		default:
			deleteCharacter(coor);
	}
	return exploseRecursion(coor, radius - 1, coord2) + 1;
}

void GameMode::deleteCharacter(Coord2 coor)
{
	_characters.erase(std::remove_if(_characters.begin(), _characters.end(),
					[=](std::shared_ptr<IController> character) {
						if (character->get_character()->getPosition2D() == coor) {
							this->play("player_die.wav");
							IrrlichtEngine::Instance().g_remove_object(character->get_character());
							return true;
						} else {
							return false;
						}
						return true;
					}), _characters.end());
	_iAs.erase(std::remove_if(_iAs.begin(), _iAs.end(),
					[=](std::shared_ptr<IController> character) {
						if (character->get_character()->getPosition2D() == coor) {
							this->play("player_die.wav");
							IrrlichtEngine::Instance().g_remove_object(character->get_character());
							return true;
						} else {
							return false;
						}
						return true;
					}), _iAs.end());
}

void GameMode::deleteBombs()
{
	_bombs.erase(std::remove_if(_bombs.begin(), _bombs.end(),
					[=](std::shared_ptr<ABomb> bomb) {
						for (auto &coor : _bombsToExplose) {
							if (bomb.get()->getPosition2D() == coor) {
								IrrlichtEngine::Instance().g_remove_object(bomb);
								return true;
							}
						}
						return false;
					}), _bombs.end());
	_bombsToExplose.clear();
	_particulesToDelete.erase(std::remove_if(_particulesToDelete.begin(), _particulesToDelete.end(),
					[=](ParticuleObject &particule) {
						if (particule.isFinished()) {
							IrrlichtEngine::Instance().g_remove_object(particule._particule);
							return true;
						} else
							return false;
					}), _particulesToDelete.end());

}

void GameMode::deletePowerUp(Coord2 coor)
{
	std::cout << "Delete Power Up is used" << std::endl;
	_powersUp.erase(std::remove_if(_powersUp.begin(), _powersUp.end(),
					[=](std::shared_ptr<APowerUp> powerUp) {
						if (powerUp.get()->getPosition2D() == coor) {
							_mapLogique[coor.x][coor.y] = NONE;
							IrrlichtEngine::Instance().g_remove_object(powerUp);
							return true;
						}
						return false;
					}), _powersUp.end());
}

void GameMode::putPowerUp(std::shared_ptr<APowerUp> powerUp)
{
	Coord2 coor = powerUp.get()->getPosition2D();
	if (!isFreeInCase(coor))
		return;
	deletePowerUp(coor);
	_mapLogique[coor.x][coor.y] = POWERUP;
	this->_powersUp.push_back(powerUp);
	IrrlichtEngine::Instance().g_add_object(powerUp);
}

void GameMode::deleteWall(Coord2 coor)
{
	_mapLogique[coor.x][coor.y] = 0;
	_walls.erase(std::remove_if(_walls.begin(), _walls.end(),
					[=](std::shared_ptr<Wall> wall) {
						std::shared_ptr<APowerUp> powerUp;
						if (wall.get()->getPosition2D() == coor) {
							std::shared_ptr<APowerUp> powerUp;
							IrrlichtEngine::Instance().g_remove_object(wall);
							if ((powerUp = wall.get()->destroy()) != 0) {
								IrrlichtEngine::Instance().g_add_object(powerUp);
								_mapLogique[coor.x][coor.y] = POWERUP;
								_powersUp.push_back(powerUp);
							}
							return true;
						}
						return false;
					}), _walls.end());
}

bool GameMode::putBomb(std::shared_ptr<ABomb> bomb)
{
	Coord2 coor = bomb.get()->getPosition2D();
	if (coor.x < 0 || coor.y < 0 || coor.x >= _mapSize.x || coor.y >= _mapSize.y)
		return false;
	if (_mapLogique[coor.x][coor.y] == 0) {
		IrrlichtEngine::Instance().g_add_object(bomb);
		_mapLogique[coor.x][coor.y] = BOMB;
		_bombs.push_back(bomb);
		return true;
	}
	return false;
}
