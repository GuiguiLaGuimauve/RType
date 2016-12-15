//
// IElement.hh
//

#ifndef __IELEMENT_HH__
#define __IELEMENT_HH__

#include <stdint.h>
#include <iostream>
#include <string.h>

namespace Element
{
  /*! Interface for game Element */
  class	IElement
  {
  public:
	 /*! Differents Element types */
     enum class ElementType : uint8_t {
        PLAYER			= 0x00,
        ENNEMY			= 0x01,
        BACKGROUND		= 0x02,
        SHOT			= 0x03,
        DECOR			= 0x04
    };

    /*! IElement destructor */
	virtual ~IElement(){};
	
    /*! Get ElementType */
    virtual ElementType getType() const = 0;
	
    /*! Get X position */
    virtual uint16_t getX() const = 0;
	
    /*! Get Y position */
    virtual uint16_t getY() const = 0;
	
    /*! Get sprite X size */
    virtual uint16_t getSizeX() const = 0;
	
    /*! Get sprite Y size */
    virtual uint16_t getSizeY() const = 0;
	
    /*! Get tick Id */
    virtual uint32_t getTickId() const = 0;
	
	/*! Get sprite filename */
    virtual std::string getSpriteName() const = 0;

	/*! Check if the current element is in collision with and other element */
    virtual bool collisionWith(IElement *) const = 0;

	/*! List of positions */
	virtual std::vector<std::pair<uint32_t, uint32_t>> getPositions() const = 0;
  };
};

using namespace Element;

#endif
