//
// ServerConf.hh for ServerConf in /home/lecoq_m/Rtype
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Tue Dec 20 02:32:21 2016 Maxime Lecoq
// Last update Tue Dec 20 23:00:20 2016 lecoq
//

#ifndef SERVERCONF_HH_
# define SERVERCONF_HH_

# include <vector>
# include <iostream>
# include <string>
# include "DataRoom.hpp"
# include "DataPlayer.hpp"
# include "File.hh"
# include "Convert.hpp"
# include "Vector.hh"
# include "Crypt.hh"

class ServerConf {
public:
  ServerConf();
  ~ServerConf();
  void				reset();
  std::vector<DataPlayer *>	getPlayers() const;
  bool				findSomething() const;
  void				write(const std::vector<DataPlayer *> &);
  bool				query() const;
  void				save();
private:
  bool				notInList(const std::string &);
private:
  std::vector<DataPlayer *> _player;
};

#endif /* !SERVERCONF_HH_ */
