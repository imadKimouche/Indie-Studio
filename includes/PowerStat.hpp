/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** PowerStat
*/

#ifndef CPP_INDIE_STUDIO_POWERSTAT_H
    #define CPP_INDIE_STUDIO_POWERSTAT_H
    /* BONUS */
    #define P_NB_BOMB_MAX 1
    #define P_RADIUS_BOMB_MAX 4
    #define P_SPEED 16
    /* MALUS */
    #define M_NB_BOMB_MAX 2
    #define M_RADIUS_BOMB_MAX 8
    #define M_SPEED 32
    /* STATS APPLIED */
    #define APPLIED_SPEED 0.2
    #define APPLIED_RADIUS 1
    #define APPLIED_BOMB 1
    /* MESH AND TEXTURES */
    #define MESH_POWERSTAT "./ressources/cube.obj"
    /* TEXTURES POWERUP BOMB */
    #define TEXTURE_POWERSTAT "./ressources/textures/bomb.png"
    #define TEXTURE_POWERSTAT_RANGE "./ressources/textures/powup_range.png"
    #define TEXTURE_POWERSTAT_BOMB "./ressources/textures/powup_bombe.png"
    #define TEXTURE_POWERSTAT_SPEED  "./ressources/textures/powup_speed.png"
    /* INCLUDES */
    #include "APowerUp.hpp"
    #include "Character.hpp"
    #include "Coord.hpp"

    class PowerStat : public APowerUp {
    public:
        PowerStat(short int powerUp);
        PowerStat(short int powerUp, Coord3 pos);
        ~PowerStat() = default;
        bool affect(std::shared_ptr<Character> chk) override;
        void update() override { return; };
        void addPowerUp(const short int &masque);
        void releasePowerUp(const short int &masque);
        short int getStatsPowerUp() { return _PowerUps; };
        bool isPowerUp(const short int &masque) const;
    private:
        short int _PowerUps;
    };
#endif //CPP_INDIE_STUDIO_POWERSTAT_H
