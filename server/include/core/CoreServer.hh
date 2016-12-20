//
// CoreServer.hh for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:19:16 2016 Maxime Lecoq
// Last update Tue Dec 20 03:46:13 2016 lecoq
//

#ifndef CORESERVER_HH_
# define CORESERVER_HH_

# include "ACore.hh"
# include "ManagerServer.hh"
# include <map>
# include "IPacket.hh"
# include "ServerData.hh"

using namespace Network;
using namespace Error;

class CoreServer : public ACore
{
  #define LOGIN_EMPTY "Login or password is empty"
  #define WRONG_AUTHENTIFICATION "Authentification failed, can be an error of password or this account is already online"
  #define ERROR_CREATE_ROOM "The creation of the room failed"
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
private:
  IManagerServer			*_manager;
  IGameManager				*_gameManager;
  std::map<IPacket::PacketType, fPkt>	_packetPtr;
  ServerData				*_data;
};

#endif /* !CORESERVER_HH_ */
