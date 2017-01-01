#ifndef SOUND_MANAGER_HH
#define SOUND_MANAGER_HH

#include <map>
#include <list>
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "ISoundManager.hh"

namespace Gui
{
  namespace Audio
  {
    class SoundManager: public ISoundManager
    {
    public:
      SoundManager();
      virtual ~SoundManager();

      void	loadSound(const std::string &path, const std::string &key);
      void      playSound(const std::string &, float = 50.0);
      void      playMusic(const std::string &, float = 50.0);
      void      stopMusic();
      void	clearCurrentSounds();
    protected:
      std::map<std::string, sf::SoundBuffer *>	_soundsMemory;
      std::list<sf::Sound *>			_currentSounds;
      sf::Sound					*_music = NULL;
      std::string				_musicName = "";
    };
  }
}


#endif
