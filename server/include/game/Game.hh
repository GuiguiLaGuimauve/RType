//
// Game.hh for Game in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:54:48 2016 Maxime Lecoq
// Last update Sun Jan  1 04:59:13 2017 Lecoq Maxime
//

#ifndef GAME_HH_
# define GAME_HH_

# include	<iostream>
# include	<string>
# include	<vector>
# include	<map>
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

class Game : public IGame
{
public:
  typedef void (IGame::*ptr)(const IPacket *, const std::string &);
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
  const std::string		&getName() const { return (_name); }
  bool                          playerPresent(const std::string &);
  void                          execPacket(const IPacket *, const std::string &);
  void				updatePosPlayer(const IPacket *, const std::string &);
  void				updatePlayerShoots(const IPacket *, const std::string &);
private:
  DataRoom			*_room;
  std::string			_name;
  IGame::Stage			_stage;
  //std::vector<IElement *>	_elementList;
  IManageNetwork		*_udp;
  PacketFactory			*_factory;
  uint64_t			_timeline;
  std::map<IPacket::PacketType, ptr>	_ptr;
  std::vector<DataShoot *>	_shoots;
  EnnemyGenerator		*_ennemyGenerator;
  std::vector<DataEnnemy *>	_ennemyList;
  std::vector<DataEnnemy *>	_ennemy;
  std::vector<DataBackground *>	_background;
};

#endif /* !GAME_HH_ */
