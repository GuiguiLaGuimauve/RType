//
// AUserNetwork.hh for AUserNetwork.hh in /home/dufren_b/teck3/rendu/CPP/cpp_babel/common/include
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Fri Dec 23 06:46:00 2016 julien dufrene
//

#ifndef _AUSERNETWORK_HH_
#define _AUSERNETWORK_HH_

#include "IUserNetwork.hh"
#include "Buffer.hh"
#include <iostream>
#include "PacketDeserializer.hh"

namespace Network
{
  /*!
  en :AUserNetwork defines the methods for UserNetworkClient and UserNetworkServer classes
  fr :L'Abstract AUserNetwork définit les méthodes des classes UserNetworkClient et UserNetworkServer.
  */
  class		AUserNetwork : public IUserNetwork {
  public:
    AUserNetwork();
    virtual ~AUserNetwork() {};
    /* La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
    virtual IUserNetwork			*readSocket(ISocket *) = 0;
    /* La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
    virtual void				writeSocket(ISocket *) = 0;
    /* La methode setFd(const int32_t) permet de set le Descripteur de fichier du client. */
    void					setFd(const int32_t &);
    /* La methode getFd() permet de récupérer le Descripteur de fichier du client. */
    int32_t					getFd() const;
    /* La methode setIp(const std::string &) permet de set l'adresse ip du client. */
    void					setIp(const std::string &);
    /* La methode getIp() permet de récupérer l'adresse ip du client. */
    const std::string				&getIp() const;
    /* La methode setPort(const uint32_t) permet de set le Port de la socket du client. */
    void					setPort(const uint32_t &);
    /* La methode getPort() permet de récupérer le port de la socket du client. */
    uint32_t					getPort() const;
    /* La méthode pushBufferWrite() permet d'ajouter une chaine dans le buffer d'écriture */
    void					pushBufferWrite(const PacketUnknown &);
    /* La méthode pushBufferRead() permet d'ajouter une chaine dans le buffer de lecture */
    void					pushBufferRead(const PacketUnknown &);
    /* La méthode popBufferRead() permet de récupérer une chaine dans le buffer de lecture */
    PacketUnknown				popBufferRead();
    /* La méthode popBufferWrite() permet de récupérer une chaine dans le buffer d'écriture */
    PacketUnknown				popBufferWrite();
    /* La méthode closeFd() permet de fermer la socket du client*/
    virtual void				closeFd() = 0;
    /* La méthode haveSomethingToWrite() permet de savoir si il y a des pacquets dans le buffer d'écriture */
    bool					haveSomethingToWrite() const;
    /* La méthode haveSomethingToRead() permet de savoir si il y a des pacquets dans le buffer de lecture */
    bool					haveSomethingToRead() const;
    /* La méthode getStatus() permet de savoir si l'utilisateur est connecté ou non */
    bool					getStatus() const;
    /* La méthode setStatus() permet de spécifier si l'utilisateur est connecté ou non */
    void					setStatus(bool);
    /* La méthode setPseudo() permet de spécifier un pseudo à l'utilisateur */
    void                                        setPseudo(const std::string &);
    /* La méthode getPseudo() permet de récupérer le pseudo de l'utilisateur */
    const std::string				&getPseudo() const;
    void					cutRead(uint8_t *, const int32_t &);
  protected:
    /* Le booléen _status permet de savoir si l'utilisateur est connecté ou non */
    bool				_status;
    /*! L'int32_t qui permet de stocker le Descripteur de la socket du client. */
    int32_t				_fd;
    /*! La string contenant l'adresse ip du client. */
    std::string				_ip;
    /*! La string contenant l'adresse ip du client. */
    std::string				_pseudo;
    /* L'int32_t qui permet de stocker le port de la socket du client. */
    int32_t				_port;
    /*! Le Buffer tournant contenant le texte lu sur le socket. */
    Buffer				buff_r;
    /*! Le Buffer tournant contenant le texte à écrire sur le socket. */
    Buffer				buff_w;
  };
};

#endif
