//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alien.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:13:44 2016 La Guimauve
// Last update Sat Dec 31 23:21:07 2016 La Guimauve
//

#ifndef _ALF_HH_
# define _ALF_HH_

#include <utility>
#include <vector>
#include "IElement.hh"
#include "Ennemy.hh"

#ifdef _WIN32
# define ALF_API __declspec(dllexport)
#endif //_WIN32

class Alf : public Ennemy
{
private:
  /*uint16_t _sizeX;
  uint16_t _sizeY;
  int32_t _hitboxDeltaX;
  int32_t _hitboxDeltaY;
  uint32_t _hitboxSizeX;
  uint32_t _hitboxSizeY;
  std::string _spriteName;
  std::vector<std::pair<uint16_t, uint16_t>> _posititions;*/
public:
	Alf();
  virtual uint16_t getSizeX();
  virtual uint16_t getSizeY();
  virtual int32_t  getHitboxDeltaX();
  virtual int32_t  getHitboxDeltaY();
  virtual uint32_t getHitboxSizeX();
  virtual uint32_t getHitboxSizeY();
  virtual std::string getSpriteName();
  virtual std::vector<std::pair<int16_t, int16_t>> getPositions();
};

extern "C"
#ifdef _WIN32
ALF_API
#endif //_WIN32
 Ennemy	*entrypoint();

#endif //_ALF_HH_
