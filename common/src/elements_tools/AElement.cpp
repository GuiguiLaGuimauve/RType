//
// AElement.cpp
//

#include "AElement.hh"

IElement::ElementType AElement::getType() const
{
	return (_type);
}

int16_t AElement::getX() const
{
	return (_x);
}

int16_t AElement::getY() const
{
	return (_y);
}

void AElement::move(const int16_t & x, const int16_t & y)
{
	_x = x;
	_y = y;
}

int16_t AElement::getSpriteY() const
{
	return (_spritePositionY);
}

int16_t AElement::getSpriteX() const
{
	return (_spritePositionX);
}


uint16_t AElement::getSizeX() const
{
	return (_sizeX);
}

uint16_t AElement::getSizeY() const
{
	return (_sizeY);
}

int16_t AElement::getHitBoxX() const
{
	return (_x + _hitboxSizeX);
}

int16_t AElement::getHitBoxY() const
{
	return (_y + _hitboxSizeY);
}

uint16_t AElement::getHitBoxSizeX() const
{
	return (_hitboxSizeX);
}

uint16_t AElement::getHitBoxSizeY() const
{
	return (_hitboxSizeY);
}

uint32_t AElement::getTickId() const
{
	return (_tickId);
}

std::string AElement::getSpriteName() const
{
	return (_spriteFileName);
}

bool AElement::collisionWith(IElement * elem2) const
{
	if (getHitBoxSizeX() == 0 || getHitBoxSizeY() == 0 || elem2->getHitBoxSizeX() == 0 || elem2->getHitBoxSizeY() == 0)
		return (false);
	if (getHitBoxX() < elem2->getHitBoxX() + elem2->getHitBoxSizeX() &&
		getHitBoxX() + getHitBoxSizeX() > elem2-> getHitBoxX() &&
		getHitBoxY() < elem2->getHitBoxY() + elem2->getHitBoxSizeY() &&
		getHitBoxSizeY() + getHitBoxY() > elem2->getHitBoxY())
		return (true);
	return (false);
}

std::vector<std::pair<int16_t, int16_t>> AElement::getPositions() const
{
	return (_positions);
}

void AElement::setType(const IElement::ElementType &type)
{
	_type = type;
}

void AElement::setSizeX(const uint16_t &size)
{
	_sizeX = size;
}

void AElement::setSizeY(const uint16_t &size)
{
	_sizeY = size;
}

void AElement::setSpriteName(const std::string &name)
{
	_spriteFileName = name;
}

void AElement::setPositions(const std::vector<std::pair<int16_t, int16_t>> &pos)
{
	_positions = pos;
}

void AElement::setHitBoxSizeX(const uint16_t &size)
{
	_hitboxSizeX = size;
}

void AElement::setHitBoxSizeY(const uint16_t &size)
{
	_hitboxSizeY = size;
}

void AElement::setDeltaHitBoxX(const int32_t &size)
{
	_hitboxDeltaX = size;
}

void AElement::setDeltaHitBoxY(const int32_t &size)
{
	_hitboxDeltaY = size;
}