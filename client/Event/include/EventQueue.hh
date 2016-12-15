//
// EventQueue.hh for cpp_babel in /home/oger_a/rendu3/Babel/cpp_babel
// 
// Made by Antonin Oger
// Login   <oger_a@epitech.net>
// 
// Started on  Wed Oct 19 11:11:01 2016 Antonin Oger
// Last update Sat Oct 22 00:35:26 2016 Simon BERTHO
//

#ifndef _EVENTQUEUE_HH_
# define _EVENTQUEUE_HH_

#include "IEventQueue.hh"
#include "Event.hpp"

namespace EventPart
{
  /*!
    La classe EventQueue a pour rôle de stocker un ou plusieurs Event,
    dans le but de les traiter ultérieurement.
  */
  
  class			EventQueue : public IEventQueue
  {
  protected:
    /*! Le booléen qui permet de définir si la queue doit utiliser ou non un mutex. */
    bool			_mutex;
    
  /*! La queue sert à stocker des Events 
    dans l'attente de les redistribuer et de les traiter.*/
    std::queue<Event>	_queue;
    
  public:
    /*! Le constructeur d'EventQueue attend en paramètre un booléen qui détermine _mutex. S'il
      n'est pas renseigné, par défaut, l'EventQueue n'en utilisera pas. */
    EventQueue(const bool &mutex = false);
    virtual ~EventQueue();
    
    /*! La méthode push(const Event &event) permet d'ajouter l'Event donné en paramètre
      à la queue. */
    void			push(const Event &event);
    /*! La méthode pop() permet de retirer le premier Event de la queue et le renvoye
      (après traitement, par exemple). */
    Event			pop();
    /*! La méthode empty() permet de savoir si la queue est vide. */
    bool			empty() const;
    /*! La méthode size() renvoie un uint32_t correspondant au nombre d'Event dans la queue. */
    uint32_t		size() const;
    /*! La méthode getMutex() renvoie un booléen correspondant à l'attribut _mutex. */
    bool			getMutex() const;
    /*! La méthode setMutex(const bool &mutex) permet de déterminer la valeur
      de l'attribut _mutex. */
    void			setMutex(const bool &mutex);
    
  };
};

#endif
