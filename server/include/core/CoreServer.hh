//
// CoreServer.hh for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:19:16 2016 Maxime Lecoq
// Last update Tue Dec 27 16:54:27 2016 lecoq
//

#ifndef CORESERVER_HH_
# define CORESERVER_HH_

# include "ACore.hh"
# include "ManagerServer.hh"
#ifdef _WIN32
# include "UserNetworkUDPWindows.hh"
#else
# include "UserNetworkUDPUnix.hh"
#endif

# include <map>
# include "IPacket.hh"
# include "ServerData.hh"
# include "ThreadPool.hpp"

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
  bool		ping(const IPacket *, IUserNetwork *);
  bool		pong(const IPacket *, IUserNetwork *);
  bool		askRooms(const IPacket *, IUserNetwork *);
  bool		game(const IPacket *, IUserNetwork *);

  void		createGame(DataRoom *, const uint8_t *);
private:
  IManagerServer			*_manager;
  IGameManager				*_gameManager;
  std::map<IPacket::PacketType, fPkt>	_packetPtr;
  ServerData				*_data;
  ThreadPool				*_threadPool;
};

#endif /* !CORESERVER_HH_ */
