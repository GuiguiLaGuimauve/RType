//
// PacketError.hpp
// 

#ifndef __PACKETERROR_HPP__
#define __PACKETERROR_HPP__

#include <string>
#include "PacketErrorGlobal.hh"

namespace Packet
{
  /*! PacketError contient un message d'erreur et le type de l'erreur */
  class PacketError : public PacketGlobalError
  {
  public:
    /*! Instancie un PacketErrorCall avec un message d'erreur et le type de l'erreur */
    PacketError(const std::string & message, const PacketType & error) : PacketGlobalError(PacketType::ERROR, message, error) {};
    /*! Instancie un PacketErrorCall à partir d'un paquet brut */
    PacketError(const uint8_t *data) : PacketGlobalError(PacketType::ERROR, data) {};
  };
};

#endif
