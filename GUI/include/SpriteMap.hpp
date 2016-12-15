//
// SpriteMap.hpp for RType in /home/oger_a/rendu3/RType/RType/GUI
// 
// Made by Antonin Oger
// Login   <oger_a@epitech.net>
// 
// Started on  Fri Dec  2 15:23:46 2016 Antonin Oger
// Last update Sun Dec  4 22:13:53 2016 Antonin Oger
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
    LoadTexture("Assets/r-typesheet42.gif", "Ships");
    LoadTexture("Assets/r-typesheet3.gif", "PowerUp1");
    LoadTexture("Assets/r-typesheet30.gif", "Bydos");
    LoadTexture("Assets/r-typesheet20.gif", "Enemy7");
    LoadTexture("Assets/r-typesheet19.gif", "Enemy8");
    LoadTexture("Assets/r-typesheet38.gif", "Boss2");
    LoadTexture("Assets/r-typesheet37.gif", "SupBoss1");
    LoadTexture("background1.jpg", "Background");
    
    /********************************************/
    /*		LOAD	THE	SPRITES		*/
    /********************************************/
    LoadSpriteFromTexture("Ships", "Ship1", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("PowerUp1", "SpherePowerUp", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Bydos", "Bydos", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Enemy7", "Enemy7", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Enemy8", "Enemy8", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Boss2", "Boss2", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("SupBoss1", "SupBoss1", 0, 0, 34, 20, 3, 3);
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
	std::cerr << "Sprite not found." << std::endl;
    return (_spriteMap[name]);
  };

};

#endif
