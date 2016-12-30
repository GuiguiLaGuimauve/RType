//
// SpriteMap.hpp for RType in /home/oger_a/rendu3/RType/RType/GUI
// 
// Made by Antonin Oger
// Login   <oger_a@epitech.net>
// 
// Started on  Fri Dec  2 15:23:46 2016 Antonin Oger
// Last update Fri Dec 30 21:52:54 2016 root
//

#ifndef _SPRITEMAP_HPP_
# define _SPRITEMAP_HPP_

#include <map>
#include "SFML/Graphics.hpp"
#include "Assets.hh"

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
    LoadTexture(PICTURE_SHIPS, "Ships");
    LoadTexture(PICTURE_SHOTS, "Shots");
    LoadTexture(PICTURE_POWERUP1, "PowerUp1");
    LoadTexture(PICTURE_BYDOS, "Bydos");
    LoadTexture(PICTURE_ENEMY7, "Enemy7");
    LoadTexture(PICTURE_ENEMY8, "Enemy8");
    LoadTexture(PICTURE_BOSS2, "Boss2");
    LoadTexture(PICTURE_SUPBOSS1, "SupBoss1");
    LoadTexture(PICTURE_LOGO, "Logo");
    LoadTexture(PICTURE_HEARTS, "Hearts");
	
    
    /********************************************/
    /*		LOAD	THE	SPRITES		*/
    /********************************************/
    LoadSpriteFromTexture("Ships", "Ship1", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Ships", "Ship2", 0, 17, 34, 20, 3, 3);
    LoadSpriteFromTexture("Ships", "Ship3", 0, 34, 34, 20, 3, 3);
    LoadSpriteFromTexture("Ships", "Ship4", 0, 51, 34, 20, 3, 3);
    LoadSpriteFromTexture("Shots", "Shot-1", 218, 133, 47, 18, 2, 2);
    LoadSpriteFromTexture("PowerUp1", "SpherePowerUp", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Bydos", "Bydos", 20, 0, 160, 210, 3, 3);
    LoadSpriteFromTexture("Enemy7", "Enemy7", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Enemy8", "Enemy8", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Boss2", "Boss2", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("SupBoss1", "SupBoss1", 0, 0, 34, 20, 3, 3);
    /* Menus Sprites */
    LoadSpriteFromTexture("Logo", "Logo", 0, 0, 445, 75, 1, 1);
    LoadSpriteFromTexture("Logo", "Logo2", 0, 75, 445, 75, 1, 1);
    LoadSpriteFromTexture("Logo", "Logo3", 0, 150, 445, 75, 1, 1);
    LoadSpriteFromTexture("Logo", "Logo4", 0, 225, 445, 75, 1, 1);
    LoadSpriteFromTexture("Hearts", "Heart1", 0, 0, 128, 128, 1, 1);
    LoadSpriteFromTexture("Hearts", "Heart2", 128, 0, 128, 128, 1, 1);
    LoadSpriteFromTexture("Hearts", "Heart3", 0, 128, 128, 128, 1, 1);
    LoadSpriteFromTexture("Hearts", "Heart4", 128, 128, 128, 128, 1, 1);
    LoadSpriteFromTexture("Hearts", "Heart5", 0, 256, 128, 128, 1, 1);
    LoadSpriteFromTexture("Hearts", "Dead", 128, 256, 128, 128, 1, 1);
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

    sprite.setScale((float) xScale, (float) yScale);
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
