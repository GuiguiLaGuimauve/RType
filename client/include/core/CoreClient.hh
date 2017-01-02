//
// CoreServer.hh for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:19:16 2016 Maxime Lecoq
// Last update Mon Jan  2 20:15:51 2017 Lecoq Maxime
//

#ifndef CORECLIENT_HH_
# define CORECLIENT_HH_

# include	<map>
# include	"ACore.hh"
# include	"ManagerClient.hh"
# include	"EventQueue.hh"
# include	"StringCk.hpp"
# include	"Vector.hh"
# include	"Thread.hpp"
# include	"GameData.hpp"
# include	"Clock.hpp"

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
  typedef bool (CoreClient::*fBack)();
  bool		manageGui();
  bool		manageNetwork();
  bool		managePackets();

  bool                          quit(EventPart::Event);
  bool                          tryConnect(EventPart::Event);
  bool                          tryLogin(EventPart::Event);
  bool                          createGame(EventPart::Event);
  bool				leaveRoom(EventPart::Event);
  bool                          joinRoom(EventPart::Event);
  bool                          watchRoom(EventPart::Event);
  bool                          startGame(EventPart::Event);
  bool                          shoot(EventPart::Event);
  bool                          back(EventPart::Event);

  bool				welcome(const IPacket *, IUserNetwork *);
  bool				accept(const IPacket *, IUserNetwork *);
  bool				errorPacket(const IPacket *, IUserNetwork *);
  bool				rooms(const IPacket *, IUserNetwork *);
  bool				profile(const IPacket *, IUserNetwork *);
  bool				udpData(const IPacket *, IUserNetwork *);
  bool				ping(const IPacket *, IUserNetwork *);
  bool				pong(const IPacket *, IUserNetwork *);
  bool				positionPlayer(const IPacket *, IUserNetwork *);
  bool				players(const IPacket *, IUserNetwork *);
  bool				gameEnded(const IPacket *, IUserNetwork *);
  bool				shoots(const IPacket *, IUserNetwork *);
  bool				background(const IPacket *, IUserNetwork *);
  bool				ennemies(const IPacket *, IUserNetwork *);
  bool				gameData(const IPacket *, IUserNetwork *);

  bool				exitClient();
  bool				goConnect();
  bool				goLogin();
  bool				goRooms();
  void				timeLine();
private:
  IManagerClient	*_manager;
  IGUI			*_gui;
  ISoundManager		*_sound;
  IEventQueue		*_eventQueue;
  std::map<EventPart::Event::TYPE, fEvent>      _eventPtr;
  std::map<IPacket::PacketType, fPkt>      _packetPtr;
  std::map<std::string, fBack>      _backPtr;
  std::string		_status;
  GameData		*_gameData;
  Thread		*_th;
  std::string		_game;
  bool			_loop;
  uint64_t		_tickIdServ;
  uint8_t		_lvl;
};

#endif /* !CORECLIENT_HH_ */
