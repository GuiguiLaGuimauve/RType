//
// ICore.hh for ICore in /home/lecoq_m/RType/build
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:12:15 2016 Maxime Lecoq
// Last update Thu Dec 15 14:36:43 2016 lecoq
//

#ifndef ICORE_HH_
# define ICORE_HH_

using namespace Gui;

class ICore
{
public:
  virtual ~ICore() {};
  virtual void run() = 0;
  virtual void initManager() = 0;
  virtual void deleteManager() = 0;
};

#endif /* !ICORE_HH_ */
