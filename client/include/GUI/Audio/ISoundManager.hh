#ifndef ISOUND_MANAGER_HH
#define ISOUND_MANAGER_HH

#include <string>

namespace Gui
{
  namespace Audio
  {
    class ISoundManager
    {
    public:
      virtual ~ISoundManager(){};


      virtual void	loadSound(const std::string &, const std::string &) = 0;
      virtual void	playSound(const std::string &, float = 50) = 0;
      virtual void	playMusic(const std::string &, float = 50) = 0;
      virtual void	stopMusic() = 0;
    };
  }
}

#endif
