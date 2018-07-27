/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IPowerUp
*/

#ifndef APOWERUP_HPP_
	#define APOWERUP_HPP_
	#include "AObject3D.hpp"
	#include "Character.hpp"
	/*#define M_KEY_P 64
	#define M_KEY_O 128
	#define M_KEY_N 256
	#define M_KEY_B 512
	#define M_KEY_R 1024
	#define M_KEY_SPACE 2048*/

	class APowerUp : public AObject3D {
		public:
			APowerUp() : AObject3D() { };
			~APowerUp() = default;
			virtual bool affect(std::shared_ptr<Character> s) = 0;
			virtual void update() = 0;
		protected:
		private:
	};

#endif /* !APOWERUP_HPP_ */
