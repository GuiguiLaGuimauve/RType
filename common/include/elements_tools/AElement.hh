//
// AElement.hh
//

#ifndef __AELEMENT_HH__
#define __AELEMENT_HH__

#include "IElement.hh"

namespace AElement
{
  class	AElement : public IElement
  {
  public:
    AElement(){};
    virtual ~AElement(){};
    ElementType getType() const;
    uint16_t getX() const;
    uint16_t getY() const;
    uint16_t getSizeX() const;
    uint16_t getSizeY() const;
    uint32_t getTickId() const;
    std::string getSpriteName() const;
    bool collisionWith(IElement *) const;
	std::vector<std::pair<uint32_t, uint32_t>> getPositions() const;

  protected:
	IElement::ElementType _type;
	int32_t _x;
	int32_t _y;
	uint32_t _sizeX;
	uint32_t _sizeY;
	int32_t _hitboxDeltaX;
	int32_t _hitboxDeltaY;
	uint32_t _hitboxSizeX;
	uint32_t _hitboxSizeY;
	std::vector<std::pair<uint64_t, uint64_t>> _postions;	
  };
};

#endif
