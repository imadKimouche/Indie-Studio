/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** GameMode.hpp
*/

#ifndef GAMEMODE_HPP_
	#define GAMEMODE_HPP_
	#include "MapObserver.hpp"
	#include <algorithm>
	#include "Engine/IrrlichtEngine.hpp"
	#include "Character.hpp"
	#include "IController.hpp"
	#include "PlayerController.hpp"
	#include "Wall.hpp"
	#include "PowerStat.hpp"
	#include "Bomberman/GameObject/Floor.hpp"
	#include "Bomb.hpp"
	#include "GameModeProtocol.hpp"
	#include "IAController.hpp"
	#include <thread>
	#include <chrono>
	#include "Background.hpp"
	#include "Musician.hpp"
	#include "ParticuleObject.hpp"

class GameMode : public GameModeProtocol, public Musician {
public:
	GameMode(Coord2 mapSize, std::vector<std::shared_ptr<PlayerController>> characters, std::vector<std::shared_ptr<IAController>> iAs);
	~GameMode();
	void initMap();
	void initCharacters(std::vector<std::shared_ptr<PlayerController>> characters, std::vector<std::shared_ptr<IAController>> iAs);
	void start();
	void startAnimation();
	bool update();
	bool isFreeInCase(Coord2 coor) final;
	void exploseInCase(Coord2 coor, int radius) final;
	bool putBomb(std::shared_ptr<ABomb> bomb) final;
	void putPowerUp(std::shared_ptr<APowerUp> powerUp) final;
	bool addWall(Coord3 coor) final;
private:
	void startMusic();
	void checkCollisions();
	void checkCharactersWithPowerUp();
	int exploseRecursion(Coord2 coor, int radius, Coord2 coord2);
	void deleteBombs();
	void deletePowerUp(Coord2 coor);
	void deleteCharacter(Coord2 coor);
	void deleteWall(Coord2 coor);
	std::vector<std::shared_ptr<Wall>> _walls;
	std::vector<std::shared_ptr<IController>> _characters;
	std::vector<std::shared_ptr<ABomb>> _bombs;
	std::vector<std::shared_ptr<APowerUp>> _powersUp;
	MapObserver *_map;
	std::vector<Coord2> _bombsToExplose;
	int **_mapLogique;
	Coord2 _mapSize;
	bool _finish;
	bool _startAnimation;
	std::vector<std::shared_ptr<IAController>> _iAs;
	std::vector<ParticuleObject> _particulesToDelete;
};

void deleteParticule(std::shared_ptr<IObject> particule, int millisecondes);


#endif /* !GAMEMODE_HPP_ */
