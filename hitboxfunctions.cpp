int16_t AElement::getHitBoxX() const
{
	return (_x + _hitboxDeltaX);
}

int16_t AElement::getHitBoxY() const
{
	return (_y + _hitboxDeltaY);
}

uint16_t AElement::getHitBoxSizeX() const
{
	return (_hitboxSizeX);
}

uint16_t AElement::getHitBoxSizeY() const
{
	return (_hitboxSizeY);
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