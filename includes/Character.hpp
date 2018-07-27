/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Character
*/

#ifndef Character_HPP_
	#define Character_HPP_
	/* LIMIT CHARACTER */
	#define LIMIT_BOMB 5
	#define LIMIT_RADIUS 5
	#define LIMIT_SPEED 7
	#define LIMIT_DELAY 15
	/* INITIAL VALUES CHARACTER */
	#define INITIAL_SPEED 5
	#define INITIAL_BOMB_NB 2
	#define INITIAL_RADIUS 3
	/* MIN VALUES CHARACTER */
	#define MIN_SPEED_POSSIBLE 3
	#define MIN_RADIUS_POSSIBLE 1
	#define MIN_DELAY_POSSIBLE 2
	#define MIN_BOMB_POSSIBLE 1
	#define TIMETOREUSEPOWER 4
	/* INCLUDES */
	#include "AObject3D.hpp"
	#include "ABomb.hpp"
	class Character;
	#include "Bomb.hpp"
	class GameModeProtocol;
	#include "GameModeProtocol.hpp"
	#include <vector>
	#include <string>
	#include <memory>
	#include <queue>

	class Character : public AObject3D {
		public:
			Character(const std::string &name,Coord2 &pos2D, Coord3 &pos3D, Coord3f &scale, const std::string &m, const std::string &t, GameModeProtocol* gamesceneprotocol = NULL);
			Character(const std::string &name,const std::string &m, const std::string &t, GameModeProtocol* gamesceneprotocol = NULL);
			Character(const std::string &name,const std::string &m, const std::string &t, Coord2 spone,GameModeProtocol* gamesceneprotocol = NULL);
			~Character();

			/* GETTER */
			std::string getName() const { return _name; };
			std::queue<std::shared_ptr<ABomb>> getBomb() const { return _bomb; };
			GameModeProtocol *getGameModeProtocol() const { return _gameModeProtocol; };
			unsigned int getBombMax() const { return _max_bomb; };
			unsigned int getBombNb() const { return _nb_bomb; }
			unsigned int getBombDelay() const { return _delay; };
			unsigned int getRadius() const { return _radius;};
			float getSpeed() const { return _animation._speed; };
			bool getMove() const { return _move; };

			/* SETTER */
			void setMove(bool move) { _move = move; };
			void setName(const std::string &str) { _name = str; };
			void setGameModeProtocol(GameModeProtocol *game) { _gameModeProtocol = game; };
			void setBombMax(int max_bomb);
			void setBombNb(int nb_bomb);
			void setBombDelay(int delay);
			void setRadius(int radius);
			void setSpeed(float speed);

			void getBackBomb();
			void getBackAll();
			virtual void update() = 0;
			virtual void special() = 0;
			void move(const Coord2 pos);
			bool poseBomb();
			int computeDirection(Coord2 coord);

		protected:
			std::string _name;
			std::queue<std::shared_ptr<ABomb>> _bomb;
			int _max_bomb;
			int _nb_bomb;
			int _delay;
			int _radius;
			Coord2 _spone;
			bool _move;
			GameModeProtocol* _gameModeProtocol;
		private:
	};

#endif /* !Character_HPP_ */
