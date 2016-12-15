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

      virtual void	playSound(const std::string &, int = 50) = 0;
      virtual void	stopSound(const std::string &) = 0;
    };
  }
}

#endif
