//
// C:\Users\Guimauve\Documents\RType\common\include\tools\mutex.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Fri Dec  2 10:05:27 2016 La Guimauve
// Last update Mon Dec 26 16:47:27 2016 La Guimauve
//

#ifndef _MUTEX_HH_
# define _MUTEX_HH_

#include <mutex>
#include "Imutex.hh"

namespace mymtx
{
  /*!
    \class mutex mutex.hh
    \brief classe pour l'abstraction des mutex
  */
  class mutex : public Imutex
  {
  public:
    /**
    * \fn mutex
    * \brief Constructeur de la classe mutex
    */
    mutex();
    /**
    * \fn ~mutex
    * \brief Destructeur de la classe mutex
    */
    ~mutex();

    /**
    * \fn void lock()
    * \brief Verrouillage des mutexs
    */
    void lock();
    /**
    * \fn void unlock()
    * \brief Déverrouillage des mutexs
    */
    void unlock();
    /**
    * \fn void try_lock()
    * \brief Connaitre si le verrouillage des mutexs est possibles
    */
    bool try_lock();
    std::mutex mtx; /** \brief mtx : mutex */
  };
}
#endif // _MUTEX_HH_
