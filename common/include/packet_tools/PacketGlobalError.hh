//
// PacketGlobalError.hh
// 

#ifndef __PACKETGLOBALERROR_HH__
#define __PACKETGLOBALERROR_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet
{
  /* La classe PacketGlobalError est un paquet générique contenant une std::string et le PacketType de l'erreur */
  class PacketGlobalError : public APacket
  {
  public:
    /*! Instancie un paquet d'erreur à partir de son IPacket::PacketType, de son message et de son erreur */
    PacketGlobalError(const IPacket::PacketType & type, const std::string & message, const IPacket::PacketType & errortype);
    /*! Instancie un paquet d'erreur à partir de son IPacket::PacketType et des données brutes */
    PacketGlobalError(const IPacket::PacketType & type, const uint8_t *data);
    ~PacketGlobalError();
    /*! Retourne le message d'erreur contenu dans le paquet */
    std::string  getMessage() const;
    /*! Retourne l'ID du paquet ayant posé problème */
    IPacket::PacketType getError() const;
  protected:
    /*! Message d'erreur contenu dans le paquet */
    std::string _message;
    /*! ID de l'erreur contenu dans le paquet */
    IPacket::PacketType _error;
  };
};

#endif
