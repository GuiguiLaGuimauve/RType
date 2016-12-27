//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alien.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:13:44 2016 La Guimauve
// Last update Tue Dec 27 17:51:58 2016 La Guimauve
//

#ifndef _ALIEN_HH_
# define _ALIEN_HH_

#include <utility>
#include <vector>

#ifdef ALIEN_EXPORTS
# define ALIEN_API __declspec(dllexport)
#else
# define ALIEN_API __declspec(dllimport)
#endif //ALIEN_EXPORTS

class Alien
{
private:
  uint16_t _sizeX;
  uint16_t _sizeY;
  int32_t _hitboxDeltaX;
  int32_t _hitboxDeltaY;
  uint32_t _hitboxSizeX;
  uint32_t _hitboxSizeY;
  std::vector<std::pair<uint16_t, uint16_t>> _posititions;
public:
  Alien();
  uint16_t getSizeX();
  uint16_t getSizeY();
  int32_t  getHitboxDeltaX();
  int32_t  getHitboxDeltaY();
  uint32_t getHitboxSizeX();
  uint32_t getHitboxSizeY();
  std::vector<std::pair<uint16_t, uint16_t>> getPositions();
};

#endif //_ALIEN_HH_
