//
// SpriteMap.hpp for RType in /home/oger_a/rendu3/RType/RType/GUI
// 
// Made by Antonin Oger
// Login   <oger_a@epitech.net>
// 
// Started on  Fri Dec  2 15:23:46 2016 Antonin Oger
// Last update Sun Dec  4 18:28:03 2016 Antonin Oger
//

#ifndef _SPRITEMAP_HPP_
# define _SPRITEMAP_HPP_

#include <map>
#include "SFML/Graphics.hpp"

class		SpriteMap
{
protected:
  static std::map<std::string, sf::Texture>	_textureMap;
  static std::map<std::string, sf::Sprite>	_spriteMap;

public:
  static void	SpriteMapLoad()
  {
    /* On charge tous les assets sa mère */
    sf::Texture	texture;

    /****************************/
    /*	LOAD	THE	SHIP1	*/
    /****************************/
    if (texture.loadFromFile("Assets/r-typesheet42.gif"))
      {
	_textureMap["Ship1"] = texture;
	sf::Sprite sprite(_textureMap["Ship1"], sf::IntRect(0, 0, 34, 20));
	sprite.setScale(3, 3);
	_spriteMap["Ship1"] = sprite;
      }
    else
      std::cerr << "Fail to load the file \"Assets/r-typesheet42.gif\"." << std::endl;
  };

  ~SpriteMap()
  {
  }

  static sf::Texture	&getTexture(const std::string &name)
  {
    if (name != "")
      if (_textureMap.find(name) == _textureMap.end())
	std::cerr << "Texture not found." << std::endl;//throw exception;
    return (_textureMap[name]);
  };

  static sf::Sprite	&getSprite(const std::string &name)
  {
    if (name != "")
      if (_spriteMap.find(name) == _spriteMap.end())
	std::cerr << "Sprite not found." << std::endl;
    return (_spriteMap[name]);
  };

};

#endif
