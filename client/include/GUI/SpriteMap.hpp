//
// SpriteMap.hpp for RType in /home/oger_a/rendu3/RType/RType/GUI
// 
// Made by Antonin Oger
// Login   <oger_a@epitech.net>
// 
// Started on  Fri Dec  2 15:23:46 2016 Antonin Oger
// Last update Mon Jan  2 16:23:23 2017 root
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
    LoadTexture(PICTURE_ENEMY1, "Enemy1");
    LoadTexture(PICTURE_BOSS2, "Boss2");
    LoadTexture(PICTURE_SUPBOSS1, "SupBoss1");
    LoadTexture(PICTURE_LOGO, "Logo");
    LoadTexture(PICTURE_HEARTS, "Hearts");
    LoadTexture(PICTURE_ENV1, "Env1");
    LoadTexture(PICTURE_ENV2, "Env2");
    LoadTexture(PICTURE_YOUWIN, "YouWin");
    LoadTexture(PICTURE_GAMEOVER, "GameOver");

    /********************************************/
    /*		LOAD	THE	SPRITES		*/
    /********************************************/
    /* Spaceships Sprites */ 
    LoadSpriteFromTexture("Ships", "Ship1", 1, 3, 32, 14, 3, 3);
    LoadSpriteFromTexture("Ships", "Ship2", 1, 20, 32, 14, 3, 3);
    LoadSpriteFromTexture("Ships", "Ship3", 1, 37, 32, 14, 3, 3);
    LoadSpriteFromTexture("Ships", "Ship4", 1, 54, 32, 14, 3, 3);
    LoadSpriteFromTexture("Ships", "Ship5", 1, 71, 32, 14, 3, 3);
    LoadSpriteFromTexture("Shots", "Shot-1", 217, 136, 48, 14, 2, 2);
    /* Misc Sprites */
    LoadSpriteFromTexture("PowerUp1", "SpherePowerUp", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("GameOver", "Loose-1", 0, 0, 128, 32, 3, 3);
    LoadSpriteFromTexture("GameOver", "Loose-2", 0, 32, 128, 32, 3, 3);
    LoadSpriteFromTexture("YouWin", "Win-1", 0, 0, 128, 32, 3, 3);
    LoadSpriteFromTexture("YouWin", "Win-2", 0, 32, 128, 32, 3, 3);
    LoadSpriteFromTexture("YouWin", "Win-3", 0, 64, 128, 32, 3, 3);
    /* Enemy Sprites*/
    LoadSpriteFromTexture("Bydos", "Bydos", 27, 217, 155, 204, 3, 3);
    LoadSpriteFromTexture("Enemy1", "Enemy1", 5, 6, 21, 24, 3, 3);/* Multiples de 33 pour les anims */
    LoadSpriteFromTexture("Enemy7", "Enemy7", 18, 3, 31, 28, 3, 3);
    LoadSpriteFromTexture("Enemy8", "Enemy8", 103, 38, 24, 21, 3, 3);
    /* Enemy Shots */
    LoadSpriteFromTexture("Enemy8", "Shot-Enemy1", 91, 88, 8, 8, 3, 3);
    LoadSpriteFromTexture("Enemy8", "Shot-Enemy7", 101, 88, 8, 8, 3, 3);
    LoadSpriteFromTexture("Enemy8", "Shot-Enemy8", 111, 88, 8, 8, 3, 3);
    LoadSpriteFromTexture("Enemy8", "Shot-Bydos", 121, 88, 8, 8, 3, 3);

    LoadSpriteFromTexture("SupBoss1", "SupBoss1", 0, 0, 34, 20, 3, 3);
    LoadSpriteFromTexture("Boss2", "Boss2", 0, 0, 34, 20, 3, 3);
    /* Env Sprites */
    LoadSpriteFromTexture("Env1", "Env-1", 0, 0, 128, 128, 2, 2);
    LoadSpriteFromTexture("Env1", "Env-1-2", 128, 0, 128, 128, 2, 2);
    LoadSpriteFromTexture("Env1", "Env-1-3", 0, 128, 128, 128, 2, 2);
    LoadSpriteFromTexture("Env1", "Env-1-4", 128, 128, 128, 128, 2, 2);
    LoadSpriteFromTexture("Env2", "Env-2", 0, 0, 128, 61, 2, 2);
    LoadSpriteFromTexture("Env2", "Env-2-2", 0, 61, 128, 61, 2, 2);
    LoadSpriteFromTexture("Env2", "Env-2-3", 0, 122, 128, 61, 2, 2);
    LoadSpriteFromTexture("Env2", "Env-2-4", 0, 183, 128, 61, 2, 2);
    /* Menus Sprites */
    LoadSpriteFromTexture("Logo", "Logo", 0, 0, 445, 75, 1, 1);
    LoadSpriteFromTexture("Logo", "Logo2", 0, 75, 445, 75, 1, 1);
    LoadSpriteFromTexture("Logo", "Logo3", 0, 150, 445, 75, 1, 1);
    LoadSpriteFromTexture("Logo", "Logo4", 0, 225, 445, 75, 1, 1);
    /* HUD Sprites */
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
