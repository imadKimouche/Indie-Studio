/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Trap
*/

#ifndef TRAP_HPP_
	#define TRAP_HPP_
	#define MESH_TRAP "./ressources/cube.obj"
	#define TEXTURE_TRAP "./ressources/textures/bomb.png"
	/* INCLUDES */
	#include "APowerUp.hpp"
	#include "Character.hpp"
	#include "Coord.hpp"

	class Trap : public APowerUp {
	public:
		Trap(int _delay, Coord3 pos);
		~Trap() = default;
		bool affect(std::shared_ptr<Character> chk) override;
		void update() override;
	private:
		int _delay;
		bool _inUse;
		bool _passed;
		std::chrono::time_point<std::chrono::system_clock> _start;
	};

#endif /* !TRAP_HPP_ */
