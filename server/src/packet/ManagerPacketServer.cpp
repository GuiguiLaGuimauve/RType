//
// ManagerPacketServer.cpp for ManagerPacketServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 10:58:37 2016 Maxime Lecoq
// Last update Sun Dec 18 15:52:07 2016 lecoq
//

#include "ManagePacketServer.hh"

ManagePacketServer::ManagePacketServer()
{
  _factory->enableSerialiser("error");
  _factory->enableSerialiser("welcome");
  _factory->enableSerialiser("rooms");
  _factory->enableSerialiser("joinerror");
  _factory->enableSerialiser("starterror");
  _factory->enableSerialiser("udpdata");
  _factory->enableSerialiser("udpdatafree");
  _factory->enableSerialiser("roomdata");
  _factory->enableSerialiser("players");
  _factory->enableSerialiser("shoots");
  _factory->enableSerialiser("ennemies");
  _factory->enableSerialiser("background");
  _factory->enableSerialiser("music");
  _factory->enableSerialiser("sound");
  _factory->enableSerialiser("ping");
  _factory->enableSerialiser("pong");
  _factory->enableDeserialiser("error");
  _factory->enableDeserialiser("connect");
  _factory->enableDeserialiser("createroom");
  _factory->enableDeserialiser("joinroom");
  _factory->enableDeserialiser("startgame");
  _factory->enableDeserialiser("leaveroom");
  _factory->enableDeserialiser("udpdata");
  _factory->enableDeserialiser("watchgame");
  _factory->enableDeserialiser("login");
  _factory->enableDeserialiser("register");
  _factory->enableDeserialiser("logout");
  _factory->enableDeserialiser("disconnect");
  _factory->enableDeserialiser("shoot");
  _factory->enableDeserialiser("move");
  _factory->enableDeserialiser("ping");
  _factory->enableDeserialiser("pong"); 
}

ManagePacketServer::~ManagePacketServer()
{
}
