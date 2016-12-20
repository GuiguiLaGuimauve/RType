//
// SpriteMap.hpp for RType in /home/oger_a/rendu3/RType/RType/GUI
// 
// Made by Antonin Oger
// Login   <oger_a@epitech.net>
// 
// Started on  Fri Dec  2 15:23:46 2016 Antonin Oger
// Last update Sat Dec 17 22:52:16 2016 root
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
    /********************************************/
    /*		LOAD	THE	TEXTURES	*/
    /********************************************/
    LoadTexture("../client/Assets/r-typesheet42.gif", "Ships");
    LoadTexture("../client/Assets/r-typesheet1.gif", "Shots");
    LoadTexture("../client/Assets/r-typesheet3.gif", "PowerUp1");
    LoadTexture("../client/Assets/r-typesheet30.gif", "Bydos");
    LoadTexture("../client/Assets/r-typesheet20.gif", "Enemy7");
    LoadTexture("../client/Assets/r-typesheet19.gif", "Enemy8");
    LoadTexture("../client/Assets/r-typesheet38.gif", "Boss2");
    LoadTexture("../client/Assets/r-typesheet37.gif", "SupBoss1");
    LoadTexture("../client/Assets/r-type-logo.png", "Logo");
    LoadTexture("../client/Assets/hearts.jpg", "Hearts");
    
    /********************************************/
    /*		LOAD	THE	SPRITES		*/
    /********************************************/
    LoadSpriteFromTexture("Ships", "Ship1", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Ships", "Ship2", 0, 17, 34, 20, 3, 3);
    LoadSpriteFromTexture("Ships", "Ship3", 0, 34, 34, 20, 3, 3);
    LoadSpriteFromTexture("Ships", "Ship4", 0, 51, 34, 20, 3, 3);
    LoadSpriteFromTexture("Shots", "Shot-1", 218, 133, 47, 18, 3, 3);
    LoadSpriteFromTexture("PowerUp1", "SpherePowerUp", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Bydos", "Bydos", 20, 0, 160, 210, 3, 3);
    LoadSpriteFromTexture("Enemy7", "Enemy7", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Enemy8", "Enemy8", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Boss2", "Boss2", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("SupBoss1", "SupBoss1", 0, 0, 34, 20, 3, 3);
    /* Menus Sprites */
    LoadSpriteFromTexture("Logo", "Logo", 0, 0, 480, 100, 1, 1);
    LoadSpriteFromTexture("Hearts", "Heart1", 0, 0, 120, 120, 1, 1);
    LoadSpriteFromTexture("Hearts", "Heart2", 120, 0, 120, 120, 1, 1);
    LoadSpriteFromTexture("Hearts", "Heart3", 0, 130, 120, 120, 1, 1);
    LoadSpriteFromTexture("Hearts", "Heart4", 120, 130, 120, 120, 1, 1);
  };

  ~SpriteMap()
  {
  }

  static void	LoadTexture(const std::string &path, const std::string &name)
  {
    sf::Texture	texture;

    if (texture.loadFromFile(path))
      _textureMap[name] = texture;
    else
      std::cerr << "[Assets loading] - \"" << path << "\" not found." << std::endl;
  }

  static void	LoadSpriteFromTexture(const std::string &tname,
				      const std::string &sname,
				      int x, int y, int w, int h,
				      int xScale, int yScale)
  {
    if (_textureMap.find(tname) == _textureMap.end())
      return;

    sf::Sprite	sprite(_textureMap[tname], sf::IntRect(x, y, w, h));

    sprite.setScale(xScale, yScale);
    _spriteMap[sname] = sprite;
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
	std::cerr << "Sprite \"" << name << "\" not found." << std::endl;
    return (_spriteMap[name]);
  };

};

#endif