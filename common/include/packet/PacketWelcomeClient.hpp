//
// PacketWelcome
// 

#ifndef __PACKETWELCOME_HPP__
#define __PACKETWELCOME_HPP__

#include <string>
#include "PacketGlobal.hh"

namespace Packet
{
  /*! PacketWelcome contient un message de bienvenue qui sera lors de la connexion au serveur */
  class PacketWelcome : public PacketGlobalText
  {
  public:
    /*! Instancie un PacketWelcome avec un message de bienvenue en paramètre */
    PacketWelcome(const std::string & message) : PacketGlobalText(PacketType::WELCOME, message) {};
    /*! Instancie un PacketWelcome à partir d'un paquet brut */
    PacketWelcome(const uint8_t *data) : PacketGlobalText(PacketType::WELCOME, data) {};
  };
};

#endif
