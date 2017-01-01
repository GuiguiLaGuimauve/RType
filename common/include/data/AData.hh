//
// AData.hh
//

#ifndef __AELEMENT_HH__
#define __AELEMENT_HH__

#include "IData.hh"

namespace Data
{
  class	AData : public IData
  {
  public:
    AData(){};
    virtual ~AData(){};
    int16_t getX() const;
    int16_t getY() const;
    uint16_t getSizeX() const;
	uint16_t getSizeY() const;
    std::string getSpriteName() const;
    bool collisionWith(IData *) const;
	uint16_t getHitBoxSizeX() const;
	uint16_t getHitBoxSizeY() const;
	int16_t getHitBoxX() const;
	int16_t getHitBoxY() const;
	void setSpriteName(const std::string &);
	void setHitBoxSizeX(const uint16_t &);
	void setHitBoxSizeY(const uint16_t &);
	void setDeltaHitBoxX(const int16_t &);
	void setDeltaHitBoxY(const int16_t &);
	void setSizeY(const uint16_t &);
	void setSizeX(const uint16_t &);
	void setY(const int16_t &);
	void setX(const int16_t &);
	void setHealth(const int16_t &);
	int16_t getHealth() const;

  protected:	
	/*! The X position of the object in the window */
	int16_t _x;
	
	/*! The Y position of the object in the window */
	int16_t _y;
	
	/*! The sprite X size for the window */
	uint16_t _sizeX;
	
	/*! The sprite Y size for the window */
	uint16_t _sizeY;

	/*! The HitBox X delta position from the _x value */
	int32_t _hitboxDeltaX;
	
	/*! The HitBox Y delta position from the _y value */
	int32_t _hitboxDeltaY;
	
	/*! The HitBox X size */
	uint32_t _hitboxSizeX;
	
	/*! The HitBox Y size */
	uint32_t _hitboxSizeY;
	
	/*! Filename of the sprite */
	std::string _spriteFileName;
	
	/*! Health of the Data */
	int16_t _health;
  };
};

#endif
