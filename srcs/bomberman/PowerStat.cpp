/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** PowerStat
*/

#include "PowerStat.hpp"

PowerStat::PowerStat(short int powerUp) :  APowerUp()
{
    _PowerUps = 000000000;
    addPowerUp(powerUp);
    _mesh = MESH_POWERSTAT;
	_texture = TEXTURE_POWERSTAT;

    switch (powerUp) {
        case P_NB_BOMB_MAX:
            _texture = TEXTURE_POWERSTAT_RANGE;
        break;
        case M_NB_BOMB_MAX:
            _texture = TEXTURE_POWERSTAT_RANGE;
        break;
        case P_RADIUS_BOMB_MAX:
            _texture = TEXTURE_POWERSTAT_RANGE;
        break;
        case M_RADIUS_BOMB_MAX:
            _texture = TEXTURE_POWERSTAT_RANGE;
        break;
        case P_SPEED:
            _texture = TEXTURE_POWERSTAT_SPEED;
        break;
        case M_SPEED:
            _texture = TEXTURE_POWERSTAT_SPEED;
        break;
        default:
            _texture = TEXTURE_POWERSTAT;
        break;
    };
    setScale(Coord3f(0.7f, 0.7f, 0.7f));
}

PowerStat::PowerStat(short int powerUp, Coord3 pos) : APowerUp()
{
    _PowerUps = 000000000;
    addPowerUp(powerUp);
    this->setPosition3D(pos);
    this->_pos2D.x = pos.x;
    this->_pos2D.y = pos.z;
    _mesh = MESH_POWERSTAT;

    switch (powerUp) {
        case P_NB_BOMB_MAX:
            _texture = TEXTURE_POWERSTAT_RANGE;
        break;
        case M_NB_BOMB_MAX:
            _texture = TEXTURE_POWERSTAT_RANGE;
        break;
        case P_RADIUS_BOMB_MAX:
            _texture = TEXTURE_POWERSTAT_RANGE;
        break;
        case M_RADIUS_BOMB_MAX:
            _texture = TEXTURE_POWERSTAT_RANGE;
        break;
        case P_SPEED:
            _texture = TEXTURE_POWERSTAT_SPEED;
        break;
        case M_SPEED:
            _texture = TEXTURE_POWERSTAT_SPEED;
        break;
        default:
            _texture = TEXTURE_POWERSTAT;
        break;
    };
    setScale(Coord3f(0.6f, 0.6f, 0.6f));
}

bool PowerStat::affect(std::shared_ptr<Character> ch)
{
    if (ch.get() == NULL || ch == nullptr)
        return false;
    std::cout << "Dans affect Charactere : max bomb :" << ch.get()->getBombMax() << " radius " << ch.get()->getRadius() << std::endl;
    if(isPowerUp(P_NB_BOMB_MAX))
        ch.get()->setBombMax(ch.get()->getBombMax() + APPLIED_BOMB);
    if(isPowerUp(M_NB_BOMB_MAX))
        ch.get()->setBombMax(ch.get()->getBombMax() - APPLIED_BOMB);
    if(isPowerUp(P_RADIUS_BOMB_MAX))
        ch.get()->setRadius(ch.get()->getRadius() + APPLIED_RADIUS);
    if(isPowerUp(M_RADIUS_BOMB_MAX))
        ch.get()->setRadius(ch.get()->getRadius() - APPLIED_RADIUS);
    if(isPowerUp(P_SPEED))
        ch.get()->setSpeed(ch.get()->getSpeed() + APPLIED_SPEED);
     if(isPowerUp(M_SPEED))
        ch.get()->setSpeed(ch.get()->getSpeed() - APPLIED_SPEED);
    std::cout << "Dans affect Charactere : max bomb :" << ch.get()->getBombMax() << " radius " << ch.get()->getRadius() << std::endl;
    ch.get()->getBackAll();
    return true;
}

void PowerStat::addPowerUp(const short int &masque)
{
    this->_PowerUps = (this->_PowerUps | masque);
}

void PowerStat::releasePowerUp(const short int &masque)
{
    this->_PowerUps = (this->_PowerUps ^ masque);
}

bool PowerStat::isPowerUp(const short int &masque) const
{
    return (this->_PowerUps & masque);
}