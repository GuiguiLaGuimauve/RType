//
// IData.hh
//

#ifndef __IDATA_HH__
#define __IDATA_HH__

#include <stdint.h>
#include <iostream>
#include <vector>
#include <string.h>

/*! Namespace Data for drawables objects */
namespace Data
{
  /*! Interface for game Data */
  class	IData
  {
  public:

    /*! IData destructor */
	virtual ~IData(){};

    /*! Get X position */
    virtual int16_t getX() const = 0;
	
    /*! Get Y position */
    virtual int16_t getY() const = 0;
	
    /*! Get sprite X size */
    virtual uint16_t getSizeX() const = 0;
	virtual void setSizeX(const uint16_t &) = 0;

    /*! Get sprite Y size */
    virtual uint16_t getSizeY() const = 0;
	virtual void setSizeY(const uint16_t &) = 0;
	
	/* Get the Hitbox size X */
	virtual uint16_t getHitBoxSizeX() const = 0;
	virtual void setHitBoxSizeX(const uint16_t &) = 0;

	/* Get the Hitbox size X */
	virtual uint16_t getHitBoxSizeY() const = 0;
	virtual void setHitBoxSizeY(const uint16_t &) = 0;

	/* Get the Hitbox X position */
	virtual int16_t getHitBoxX() const = 0;

	/* Get the Hitbox X position */
	virtual int16_t getHitBoxY() const = 0;
	
	/*! Get sprite filename */
    virtual std::string getSpriteName() const = 0;
	virtual void setSpriteName(const std::string &) = 0;

	/*! Check if the current element is in collision with and other element */
    virtual bool collisionWith(IData *) const = 0;

	virtual void setDeltaHitBoxX(const int16_t &) = 0;
	virtual void setDeltaHitBoxY(const int16_t &) = 0;
	
	virtual void setX(const int16_t &) = 0;
	virtual void setY(const int16_t &) = 0;
	
	virtual void setHealth(const int16_t &) = 0;
	virtual int16_t getHealth() const = 0;

  };
};

using namespace Data;

#endif
