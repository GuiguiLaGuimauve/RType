//
// Game.hh for Game in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:54:48 2016 Maxime Lecoq
// Last update Mon Jan  2 09:56:55 2017 Lecoq Maxime
//

#ifndef GAME_HH_
# define GAME_HH_

# include	<iostream>
# include	<string>
# include	<vector>
# include	<map>
# include	<ctime>
# include	"IElement.hh"
# include	"IGame.hh"
# include	"DataRoom.hpp"
# include	"IManageNetwork.hh"
# include	"PacketFactory.hh"
# include	"Clock.hpp"
# include	"Printer.hpp"
# include	"EnnemyGenerator.hh"
# include	"DataBackground.hpp"
# include	"DataEnnemy.hpp"
# include	"ShootPlayer.hpp"

class Game : public IGame
{
public:
  typedef void (IGame::*ptr)(const IPacket *, const std::string &);
  typedef void (Game::*fMonster)();
  Game(DataRoom *);
  ~Game();
  std::vector<std::string> getPlayersName() const;
  std::vector<std::string> getViewersName() const;
  std::vector<std::string> getAllName() const;
  void				setFactory(PacketFactory *);
  void				setUdp(IManageNetwork *);
  void				run();
  void				end();
  void				timeLine();
  void				movements();
  void				monster();
  void				background();
  const std::string		&getName() const { return (_name); }
  bool                          playerPresent(const std::string &);
  void                          execPacket(const IPacket *, const std::string &);
  void				updatePosPlayer(const IPacket *, const std::string &);
  void				updatePlayerShoots(const IPacket *, const std::string &);
  void				updatePlayer(const IPacket *, const std::string &);
  void				addThread(mythrd::Thread *);
private:
  void				refreshEnnemy();
  void				lvl1();
  void				lvl2();
  void				lvl3();
  void				boss();
private:
  DataRoom			*_room;
  std::string			_name;
  uint8_t			_lvl;
  IManageNetwork		*_udp;
  PacketFactory			*_factory;
  uint64_t			_timeline;
  std::map<IPacket::PacketType, ptr>	_ptr;
  std::vector<DataShoot *>	_shoots;
  std::vector<DataShoot *>	_shootsEn;
  EnnemyGenerator		*_ennemyGenerator;
  std::vector<DataEnnemy *>	_ennemyList;
  std::vector<DataEnnemy *>	_ennemy;
  DataEnnemy			*_boss;
  std::vector<DataBackground *>	_background;
  std::map<uint8_t, fMonster>	_ptrM;
  bool				_bossMod;
  bool				_bossSet;
  std::vector<mythrd::Thread *>	_th;
};

#endif /* !GAME_HH_ */
