//
// CoreServer.hh for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:19:16 2016 Maxime Lecoq
// Last update Tue Dec 20 13:58:18 2016 lecoq
//

#ifndef CORECLIENT_HH_
# define CORECLIENT_HH_

# include	<map>
# include	"ACore.hh"
# include	"ManagerClient.hh"
# include	"EventQueue.hh"
# include	"StringCk.hpp"
# include	"Vector.hh"

using namespace Gui;
using namespace Gui::Audio;
using namespace Network;
using namespace Error;
using namespace EventPart;

class CoreClient : public ACore
{
# define IP_FORMAT_ERROR "The IP is not correct"
# define PORT_FORMAT_ERROR "The port is not correct"
# define LOGIN_ERROR	"Login or password is empty"
  
public:
  CoreClient();
  ~CoreClient();
  void		run();
  bool		initManager();
  void		deleteManager();
private:
  typedef bool (CoreClient::*fEvent)(EventPart::Event);
  typedef bool (CoreClient::*fPkt)(const IPacket *, IUserNetwork *);
  bool		manageGui();
  bool		manageNetwork();
  bool		managePackets();

  bool                          quit(EventPart::Event);
  bool                          tryConnect(EventPart::Event);
  bool                          tryLogin(EventPart::Event);
  bool                          createGame(EventPart::Event);

  bool				welcome(const IPacket *, IUserNetwork *);
  bool				accept(const IPacket *, IUserNetwork *);
  bool				errorPacket(const IPacket *, IUserNetwork *);
  bool				rooms(const IPacket *, IUserNetwork *);
  bool				profile(const IPacket *, IUserNetwork *);
private:
  IManagerClient	*_manager;
  IGUI			*_gui;
  ISoundManager		*_sound;
  IEventQueue		*_eventQueue;
  std::map<EventPart::Event::TYPE, fEvent>      _eventPtr;
  std::map<IPacket::PacketType, fPkt>      _packetPtr;
  bool			_isConnectToServ;
};

#endif /* !CORECLIENT_HH_ */
