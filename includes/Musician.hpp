/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Musician
*/

#ifndef MUSICIAN_HPP_
#define MUSICIAN_HPP_

#include "Engine/IrrlichtEngine.hpp"
#include <unordered_map>
#include <string>

class Musician {
public:
  void play(std::string music) {
    int index = 0;
    music = AUDIO_SOURCES + music;
    auto got = _sounds.find(music);
    if (got == _sounds.end()) {
      index = IrrlichtEngine::Instance().s_add_sound(S_SOUND, music);
      if (index < 0)
        return;
      _sounds.insert(std::make_pair(music, index));
      IrrlichtEngine::Instance().s_play(S_SOUND, index);
    } else
      IrrlichtEngine::Instance().s_play(S_SOUND, got->second);
  }
private:
  std::unordered_map<std::string, int> _sounds;
};

#endif
