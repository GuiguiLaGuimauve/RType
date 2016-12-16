//
// AElement.hh
//

#ifndef __AELEMENT_HH__
#define __AELEMENT_HH__

#include "IElement.hh"

namespace Element
{
  class	AElement : public IElement
  {
  public:
    AElement(){};
    virtual ~AElement(){};
    IElement::ElementType getType() const;
    int16_t getX() const;
    int16_t getY() const;
    uint16_t getSizeX() const;
    uint16_t getSizeY() const;
    uint32_t getTickId() const;
    std::string getSpriteName() const;
    bool collisionWith(IElement *) const;
	std::vector<std::pair<int16_t, int16_t>> getPositions() const;
	uint16_t getHitBoxSizeX() const;
	uint16_t getHitBoxSizeY() const;
	int16_t getHitBoxX() const;
	int16_t getHitBoxY() const;	
	int16_t getSpriteY() const;
	int16_t getSpriteX() const;

  protected:
	/*! The Element type */
	IElement::ElementType _type;
	
	/*! The X position of the object in the window */
	int16_t _x;
	
	/*! The Y position of the object in the window */
	int16_t _y;
	
	/*! The sprite X size for the window */
	uint16_t _sizeX;
	
	/*! The sprite Y size for the window */
	uint16_t _sizeY;
	
	/*! The timer unique ID */
	uint32_t _tickId;
	
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
	
	/*! X Position of the object in the spritesheet */
	int16_t _spritePositionX;
	
	/*! Y Position of the object in the spritesheet */
	int16_t _spritePositionY;
	
	/*! Vector of differents positions */
	std::vector<std::pair<int16_t, int16_t>> _positions;	
  };
};

#endif
