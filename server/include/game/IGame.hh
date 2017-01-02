//
// IGame.hh for IGame in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:54:14 2016 Maxime Lecoq
// Last update Mon Jan  2 09:58:36 2017 Lecoq Maxime
//

#ifndef IGAME_HH_
# define IGAME_HH_

# include	<vector>
# include	<iostream>
# include	<string>
# include	<thread>
# include       "IManageNetwork.hh"
# include       "PacketFactory.hh"
# include	"Thread.hpp"

class IGame {
public:
  virtual ~IGame() {};
  virtual std::vector<std::string> getPlayersName() const = 0;
  virtual std::vector<std::string> getViewersName() const = 0;
  virtual std::vector<std::string> getAllName() const = 0;
  virtual void                          setFactory(PacketFactory *) = 0;
  virtual void                          setUdp(IManageNetwork *) = 0;
  virtual void                          run() = 0;
  virtual void                          end() = 0;
  virtual void				timeLine() = 0;
  virtual void				movements() = 0;
  virtual void				monster() = 0;
  virtual void				background() = 0;
  virtual const std::string		&getName() const = 0;
  virtual bool				playerPresent(const std::string &) = 0;
  virtual void				execPacket(const IPacket *, const std::string &) = 0;
  virtual void                          updatePosPlayer(const IPacket *, const std::string &) = 0;
  virtual void                          updatePlayerShoots(const IPacket *, const std::string &) = 0;
  virtual void                          updatePlayer(const IPacket *, const std::string &) = 0;
  virtual void				addThread(mythrd::Thread *) = 0;
};

#endif /* !IGAME_HH_ */
