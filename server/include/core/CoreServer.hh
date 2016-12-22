//
// CoreServer.hh for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:19:16 2016 Maxime Lecoq
// Last update Thu Dec 22 12:22:10 2016 julien dufrene
//

#ifndef CORESERVER_HH_
# define CORESERVER_HH_

# include "ACore.hh"
# include "ManagerServer.hh"
# include "UserNetworkUDPUnix.hh"
# include <map>
# include "IPacket.hh"
# include "ServerData.hh"

using namespace Network;
using namespace Error;

class CoreServer : public ACore
{
  #define LOGIN_EMPTY "Login or password is empty"
  #define WRONG_AUTHENTIFICATION "Authentification failed : error on password or this account is already connected"
  #define ERROR_CREATE_ROOM "The room's creation failed"
#define ERROR_START_GAME "Can't start the game with this room's configuration"
public:
  CoreServer();
  ~CoreServer();
  void		run();
  bool		initManager();
  void		deleteManager();
private:
  bool		managePackets();
private:
  typedef bool	(CoreServer::*fPkt)(const IPacket *, IUserNetwork *);
  bool		connect(const IPacket *, IUserNetwork *);
  bool		login(const IPacket *, IUserNetwork *);
  bool		createRoom(const IPacket *, IUserNetwork *);
  bool		leaveRoom(const IPacket *, IUserNetwork *);
  bool		joinRoom(const IPacket *, IUserNetwork *);
  bool		watchGame(const IPacket *, IUserNetwork *);
  bool		startGame(const IPacket *, IUserNetwork *);
  bool		udpData(const IPacket *, IUserNetwork *);
private:
  IManagerServer			*_manager;
  IGameManager				*_gameManager;
  std::map<IPacket::PacketType, fPkt>	_packetPtr;
  ServerData				*_data;
};

#endif /* !CORESERVER_HH_ */
