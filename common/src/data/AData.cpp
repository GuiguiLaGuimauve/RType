//
// AData.cpp
//

#include "AData.hh"

int16_t AData::getX() const
{
	return (_x);
}

int16_t AData::getY() const
{
	return (_y);
}

uint16_t AData::getSizeX() const
{
	return (_sizeX);
}

uint16_t AData::getSizeY() const
{
	return (_sizeY);
}

int16_t AData::getHitBoxX() const
{
	return (_x + _hitboxDeltaX);
}

int16_t AData::getHitBoxY() const
{
	return (_y + _hitboxDeltaY);
}

uint16_t AData::getHitBoxSizeX() const
{
	return (_hitboxSizeX);
}

uint16_t AData::getHitBoxSizeY() const
{
	return (_hitboxSizeY);
}

std::string AData::getSpriteName() const
{
	return (_spriteFileName);
}

bool AData::collisionWith(IData * elem2) const
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

void AData::setSizeX(const uint16_t &size)
{
	_sizeX = size;
}

void AData::setSizeY(const uint16_t &size)
{
	_sizeY = size;
}

void AData::setSpriteName(const std::string &name)
{
	_spriteFileName = name;
}

void AData::setHitBoxSizeX(const uint16_t &size)
{
	_hitboxSizeX = size;
}

void AData::setHitBoxSizeY(const uint16_t &size)
{
	_hitboxSizeY = size;
}

void AData::setDeltaHitBoxX(const int16_t &size)
{
	_hitboxDeltaX = size;
}

void AData::setDeltaHitBoxY(const int16_t &size)
{
	_hitboxDeltaY = size;
}

void AData::setY(const int16_t &y)
{
	_y = y;
}

void AData::setX(const int16_t &x)
{
	_x = x;
}

void AData::setHealth(const int16_t &h)
{
	_health = h;
}

int16_t AData::getHealth() const
{
	return (_health);
}