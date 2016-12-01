//
// PacketGlobalText.hh
// 

#ifndef __PACKETGLOBALTEXT_HH__
#define __PACKETGLOBALTEXT_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet
{
  /* La classe PacketGlobalText est un paquet générique contenant une std::string */
  class PacketGlobalText : public APacket
  {
  public:
    /*! Instancie un paquet global à partir de son IPacket::PacketType et de son message */
    PacketGlobalText(const IPacket::PacketType & type, const std::string & message);
    /*! Instancie un paquet global à partir des données brutes */
    PacketGlobalText(const IPacket::PacketType & type, const uint8_t *data);
    ~PacketGlobalText();
    /*! Retourne le message contenue dans le paquet */
    std::string  getMessage() const;
  protected:
    /*! Message contenu dans le paquet */
    std::string _message;
  };
};

#endif
