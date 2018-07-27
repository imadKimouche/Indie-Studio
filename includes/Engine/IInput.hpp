/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IInput header file
*/

#ifndef IINPUT_HPP_
#define IINPUT_HPP_

#include <vector>
#include <string>

#define M_KEY_NONE 0
#define M_KEY_A 1
#define M_KEY_B 2
#define M_KEY_C 3
#define M_KEY_D 4
#define M_KEY_E 5
#define M_KEY_F 6
#define M_KEY_G 7
#define M_KEY_H 8
#define M_KEY_I 9
#define M_KEY_J 10
#define M_KEY_K 11
#define M_KEY_L 12
#define M_KEY_M 13
#define M_KEY_N 14
#define M_KEY_O 15
#define M_KEY_P 16
#define M_KEY_Q 17
#define M_KEY_R 18
#define M_KEY_S 19
#define M_KEY_T 20
#define M_KEY_U 21
#define M_KEY_V 22
#define M_KEY_W 23
#define M_KEY_X 24
#define M_KEY_Y 25
#define M_KEY_Z 26
#define M_KEY_0 27
#define M_KEY_1 28
#define M_KEY_2 29
#define M_KEY_3 30
#define M_KEY_4 31
#define M_KEY_5 32
#define M_KEY_6 33
#define M_KEY_7 34
#define M_KEY_8 35
#define M_KEY_9 36
#define M_KEY_UP 37
#define M_KEY_DOWN 38
#define M_KEY_LEFT 39
#define M_KEY_RIGHT 40
#define M_KEY_ENTER 41
#define M_KEY_SHIFT 42
#define M_KEY_CTRL 43
#define M_KEY_ALT 44
#define M_KEY_SUPR 45
#define M_KEY_REMOVE 46
#define M_KEY_SPACE 47
#define M_KEY_ESC 48
#define M_KEY_LAST 49

#define M_JOYSTICK_A 0
#define M_JOYSTICK_B 1
#define M_JOYSTICK_X 2
#define M_JOYSTICK_Y 3
#define M_JOYSTICK_L1 4
#define M_JOYSTICK_R1 5
#define M_JOYSTICK_SELECT 6
#define M_JOYSTICK_START 7
#define M_JOYSTICK_XBOX 8
#define M_JOYSTICK_L3 9
#define M_JOYSTICK_R3 10
#define M_JOYSTICK_LEFT 11
#define M_JOYSTICK_DOWN 12
#define M_JOYSTICK_TOP 13
#define M_JOYSTICK_RIGHT 14
#define M_JOYSTICK_END 15

#define JOYSTICK_1 0
#define JOYSTICK_2 1
#define JOYSTICK_3 2
#define JOYSTICK_4 3
#define MAX_JOYSTICK 4

class IInput {
public:
	virtual ~IInput() {};
	virtual bool is_key(int index) const = 0;
	virtual bool is_joystick(int index, char key) = 0;
	virtual void push_key(int index) = 0;
	virtual void release_key(int index) = 0;
	virtual void push_joystick(int index, char key) = 0;
	virtual void release_joystick(int index, char key) = 0;
	virtual void release_all() = 0;
	virtual std::string translate_key(int index) const = 0;
	virtual std::vector<int> get_keys() = 0;
private:
};

#endif
