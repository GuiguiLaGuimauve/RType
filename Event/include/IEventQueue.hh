//
// IEventQueue.hh for cpp_babel in /home/oger_a/rendu3/Babel/cpp_babel
// 
// Made by Antonin Oger
// Login   <oger_a@epitech.net>
// 
// Started on  Wed Oct 19 11:22:16 2016 Antonin Oger
// Last update Sat Oct 22 00:36:22 2016 Simon BERTHO
//

#ifndef _IEVENTQUEUE_HH_
#define _IEVENTQUEUE_HH_

#include <queue>
#include <stdint.h>
#include <Event.hpp>

namespace EventPart
{
  /*!
    L'interface IEventQueue définit les méthodes de la classe EventQueue.
  */
  
  class			IEventQueue
  {
  public:
    virtual ~IEventQueue() {};
    /*! La méthode push(const Event &event) permet d'ajouter l'Event donné en paramètre
      à la queue. */
    virtual void		push(const Event &) = 0;
    /*! La méthode pop() permet de retirer le premier Event de la queue
      (après traitement, par exemple). */
    virtual Event		pop() = 0;
    /*! La méthode empty() permet de vider la totalité de la queue. */
    virtual bool		empty() const = 0;
    /*! La méthode size() renvoie un uint32_t correspondant au nombre d'Event dans la queue. */
    virtual uint32_t	size() const = 0;
    /*! La méthode getMutex() renvoie un booléen correspondant à l'attribut _mutex. */
    virtual bool		getMutex() const = 0;
    /*! La méthode setMutex(const bool &mutex) permet de déterminer la valeur
      de l'attribut _mutex. */
    virtual void		setMutex(const bool &) = 0;
  };
};

#endif
