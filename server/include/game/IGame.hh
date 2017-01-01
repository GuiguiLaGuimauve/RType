//
// IGame.hh for IGame in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:54:14 2016 Maxime Lecoq
// Last update Sun Jan  1 04:29:30 2017 Lecoq Maxime
//

#ifndef IGAME_HH_
# define IGAME_HH_

# include	<vector>
# include	<iostream>
# include	<string>
# include       "IManageNetwork.hh"
# include       "PacketFactory.hh"

class IGame {
public:
  enum Stage
    {
      STAGE1 = 1,
      STAGE2 = 2,
      STAGE3,
      BOSS1,
      STAGE4,
      STAGE5,
      STAGE6,
      BOSS2
    };
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
  virtual const std::string		&getName() const = 0;
  virtual bool				playerPresent(const std::string &) = 0;
  virtual void				execPacket(const IPacket *, const std::string &) = 0;
  virtual void                          updatePosPlayer(const IPacket *, const std::string &) = 0;
  virtual void                          updatePlayerShoots(const IPacket *, const std::string &) = 0;
  virtual void				addViewer(DataPlayer *) = 0;
};

#endif /* !IGAME_HH_ */
