#ifndef SOUND_MANAGER_HH
#define SOUND_MANAGER_HH

#include <map>
#include <list>

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

      void      playSound(const std::string &, int = 50) ;
      void      stopSound(const std::string &);
    protected:
      std::map<std::string, sf::SoundBuffer *>	_soundsMemory;
      std::list<sf::Sound *>			_soundsInProgress;
    };
  }
}


#endif
