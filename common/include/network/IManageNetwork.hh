/*
** IManageNetwork.hh for  in /home/lecoq_m/cpp_babel
**
** Made by Maxime Lecoq
** Login   <lecoq_m@epitech.net>
**
** Started on  Mon Oct 17 13:11:20 2016 Maxime Lecoq
// Last update Wed Dec 21 06:44:51 2016 julien dufrene
*/

#ifndef		__IMANAGENETWORK_HH__
#define		__IMANAGENETWORK_HH__

#include	<iostream>
#include	<string>
#include	<vector>
#include	"ISocket.hh"
#include	"DataClient.hpp"
#include	"IUserNetwork.hh"
#include        "IPacketQueue.hh"
#include        "PacketFactory.hh"
#include	"StringCk.hpp"

namespace Network
{
# define WELCOME_SERVERM "Welcome to the server of rembur_g group's."
  /*!
  en :IManageNetwork class interface define the methods of the AManageNetwork class
  fr :L'interface IManageNetwork definit les méthodes de la classe AManageNetwork.*/
  class		IManageNetwork {
  public:
    virtual ~IManageNetwork() {};
    /*!
    en :init() initialize the files descriptor to survey
    fr :La méthode init() permet d'initialiser les descripteurs de ficher à surveiller.*/
    virtual bool				init() = 0;
    /*!
    en :selectIt() survey the activity of file descriptors
    fr :La méthode selectIt() permet de surveiller l'activité sur les descripteurs de fichiers.*/
    virtual bool				selectIt() = 0;
    /*!
    en :exec() execute an action on the active(s) file descriptor(s)
    fr :La méthode exec() permet d'executer une action sur le(s) descripteur(s) de fichier actif.*/
    virtual std::vector<IUserNetwork *>		exec() = 0;
    /*!
    en :run(port, nbClient) launch the network.
    fr :La méthode run(port, nbClient) permet de lancer le réseau. */
    virtual bool				run(const uint32_t & = 4242, const uint32_t & = 0) = 0;
    /*!
    en :getNetwork() get the network in use
    fr :La méthode getNetwork() permet de récuperer le réseau utilisé. */
    virtual ISocket				*getSocket() const = 0;
    /*!
    en :tryConnectClient() allow the client to try the connection to a server.
    fr :La méthode tryConnectClient() permet au client d'essayer de se connecter à un server. */
    virtual bool				tryConnectClient(const uint32_t &, const std::string &) = 0;
    /*!
      en :updateUsers() updates the user list (add/delete) and return a vector of disconnected users's pseudo
      fr :La méthode updateUsers() permet de mettre à jour la liste des clients (ajout/suppression) et renvoie les pseudos des utilisateurs déconnectés.
     */
    virtual std::vector<std::string>		updateUsers(const std::vector<IUserNetwork *> &) = 0;
    /*!
      en :pushTo(liste, message) is used to send message to a list of users.
      fr :La méthode pushTo(liste, message) sert à envoyer un message à une liste d'utilisateurs. */
    virtual void				pushTo(const std::vector<std::string> &, const PacketUnknown &) = 0;
    /*
      en :setPackectQueueRead(queue) is used to set the read packets.
      fr :setPackectQueueRead(queue) est utilisé pour initialisé la queue des packets lu.
     */
    virtual void				setPacketQueueRead(const IPacketQueue *) = 0;
    /*
      en :setPackectQueueWrite(queue) is used to set the writes packets.
      fr :setPackectQueueWrite(queue) est utilisé pour initialisé la queue des pacquets à écrire.
     */
    virtual void				setPacketQueueWrite(const IPacketQueue *) = 0;
    /*
      en :setPacketFactory(factory) is used to set a packet maker.
      fr :setPacketFactory(factory) est utiisé pour initialiser un fabriquant de pacquet.
     */
    virtual void				setPacketFactory(const PacketFactory *) = 0;
    /*
      en :hasServerRunning() is used only on client side to check if it is connected to a server.
      fr :La méthode hasServerRunning() permet de savoir si le client est connecté à un serveur.
     */
    virtual bool				hasServerRunning() const = 0;
    /*
      en :getServerRunning() is used to get the UserNetwork wich represent the server.
      fr :La méthode getServerRunning() permet de récupéré l'utilisateur correspondant au serveur.
     */
    virtual IUserNetwork	                *getServerRunning() const = 0;
  };
};

#endif
