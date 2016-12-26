//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Imutex.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec  1 16:24:11 2016 La Guimauve
// Last update Mon Dec 26 16:47:20 2016 La Guimauve
//

#ifndef _IMUTEX_HH_
# define _IMUTEX_HH_

namespace mymtx
{
  /*!
    \class Imutex Imutex.hh
    \brief classe interface pour l'abstraction des mutex
  */
  class Imutex
  {
  public:
    /**
    * \fn ~Imutex
    * \brief Destructeur virtuel de la classe Imutex
    */
    virtual ~Imutex() {};

    /**
    * \fn virtual void lock()
    * \brief Abstract pure pour le verrouillage des mutexs
    */
    virtual void lock() = 0;
    /**
    * \fn virtual void unlock()
    * \brief Abstract pure pour le déverrouillage des mutexs
    */
    virtual void unlock() = 0;
    /**
    * \fn virtual void try_lock()
    * \brief Abstract pure pour connaitre si le verrouillage des mutexs est possibles
    */
    virtual bool try_lock() = 0;
  };
}

#endif //_IMUTEX_HH_
