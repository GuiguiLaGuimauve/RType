//
// ManagerPacketClient.cpp for ManagerPacketClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 10:58:37 2016 Maxime Lecoq
// Last update Mon Jan  2 00:49:14 2017 Lecoq Maxime
//

#include "ManagerPacketClient.hh"

ManagerPacketClient::ManagerPacketClient()
{
  _factory->enableSerialiser("error");
  _factory->enableSerialiser("connect");
  _factory->enableSerialiser("createroom");
  _factory->enableSerialiser("joinroom");
  _factory->enableSerialiser("startgame");
  _factory->enableSerialiser("leaveroom");
  _factory->enableSerialiser("udpdata");
  _factory->enableSerialiser("watchgame");
  _factory->enableSerialiser("login");
  _factory->enableSerialiser("register");
  _factory->enableSerialiser("logout");
  _factory->enableSerialiser("disconnect");
  _factory->enableSerialiser("shootsclient");
  _factory->enableSerialiser("positionplayer");
  _factory->enableSerialiser("ping");
  _factory->enableSerialiser("pong");
  _factory->enableSerialiser("askroomdata");
  _factory->enableSerialiser("askrooms");
  _factory->enableDeserialiser("error");
  _factory->enableDeserialiser("welcome");
  _factory->enableDeserialiser("rooms");
  _factory->enableDeserialiser("joinerror");
  _factory->enableDeserialiser("starterror");
  _factory->enableDeserialiser("udpdata");
  _factory->enableDeserialiser("udpdatafree");
  _factory->enableDeserialiser("roomdata");
  _factory->enableDeserialiser("players");
  _factory->enableDeserialiser("shoots");
  _factory->enableDeserialiser("ennemies");
  _factory->enableDeserialiser("background");
  _factory->enableDeserialiser("music");
  _factory->enableDeserialiser("sound");
  _factory->enableDeserialiser("ping");
  _factory->enableDeserialiser("pong");
  _factory->enableDeserialiser("accept");
  _factory->enableDeserialiser("profile");
  _factory->enableDeserialiser("gameended"); 
  _factory->enableDeserialiser("positionplayer");
  _factory->enableDeserialiser("gamedata");
}

ManagerPacketClient::~ManagerPacketClient()
{
}
