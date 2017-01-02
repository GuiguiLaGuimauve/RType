//
// ICore.hh for ICore in /home/lecoq_m/RType/build
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:12:15 2016 Maxime Lecoq
// Last update Fri Dec 16 10:58:00 2016 lecoq
//

#ifndef ICORE_HH_
# define ICORE_HH_

class ICore
{
public:
  virtual ~ICore() {};
  virtual void run() = 0;
  virtual bool initManager() = 0;
  virtual void deleteManager() = 0;
};

#endif /* !ICORE_HH_ */
