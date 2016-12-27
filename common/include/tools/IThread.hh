//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Ithread.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Fri Dec  2 13:32:58 2016 La Guimauve
// Last update Mon Dec 26 15:24:03 2016 La Guimauve
//

#ifndef _ITHREAD_HH_
# define _ITHREAD_HH_

#include <thread>

namespace mythrd
{
  /*!
    \class IThread IThread.hh
    \brief classe interface pour l'abstraction des threads
  */
  class IThread
  {
  public:
    /**
    * \fn ~IThread
    * \brief Destructeur virtuel de la classe IThread
    */
    virtual ~IThread() {};

    /**
    * \fn virtual bool joinable() const
    * \brief Abstract pure pour savoir si la thread est joignable
    *
    * \return un bool true si la thread est joignable / false si elle n'est pas joignable
    */
    virtual bool joinable() const = 0;
    /**
    * \fn virtual void join() const
    * \brief Abstract pure pour joindre la thread
    */
    virtual void join() = 0;
    /**
    * \fn virtual void detach() const
    * \brief Abstract pure detacher la thread
    */
    virtual void detach() = 0;
    /**
    * \fn virtual void pause(const uint32_t &a) const
    * \brief Abstract pure pour mettre en pause la thread pendant c secondes
    *
    * \param a le nombre de seconde de pause pour la thread
    */
    virtual void pause(const uint32_t &a) const = 0;
  };
}

#endif // _ITHREAD_HH_
