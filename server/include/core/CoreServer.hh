//
// CoreServer.hh for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:19:16 2016 Maxime Lecoq
// Last update Mon Dec 19 17:41:06 2016 lecoq
//

#ifndef CORESERVER_HH_
# define CORESERVER_HH_

# include "ACore.hh"
# include "ManagerServer.hh"
# include <map>
# include "IPacket.hh"

using namespace Network;
using namespace Error;

class CoreServer : public ACore
{
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
private:
  IManagerServer			*_manager;
  IGameManager				*_gameManager;
  std::map<IPacket::PacketType, fPkt>	_packetPtr;
};

#endif /* !CORESERVER_HH_ */
