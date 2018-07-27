/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** GameModeProtocol.hpp
*/

#ifndef GAMEMODEPROTOCOL_HPP_
	#define GAMEMODEPROTOCOL_HPP_
	#include "Coord.hpp"
	#include "Bomb.hpp"
	#include <memory>
	class APowerUp;
	#include "APowerUp.hpp"

class GameModeProtocol {
public:
	~GameModeProtocol() {}
	virtual bool isFreeInCase(Coord2 coor) = 0;
	virtual void exploseInCase(Coord2 coor, int radius) = 0;
	virtual bool putBomb(std::shared_ptr<ABomb> bomb) = 0;
	virtual void putPowerUp(std::shared_ptr<APowerUp> powerUp) = 0;
	virtual bool addWall(Coord3 coor) = 0;
protected:
private:
};

#endif /* !GAMEMODEPROTOCOL_HPP_ */
