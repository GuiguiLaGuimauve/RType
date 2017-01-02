//
// DataClient.hh for DataClient in /home/lecoq_m/cpp_babel
// 
// Made by Maxime Lecoq
// Login   <lecoq_m@lecoq-HP-EliteBook-840-G1>
// 
// Started on  Wed Oct 19 16:13:36 2016 Maxime Lecoq
// Last update Fri Oct 28 15:31:41 2016 lecoq
//

#ifndef DATACLIENT_HPP_
# define DATACLIENT_HPP_

# include	<stdint.h>
# include	<string>

/* La classe DataClient est un conteneur de données de client. */
class	DataClient
{
public:
	DataClient() { _fd = -1; };
  ~DataClient() {};
  /* La méthode getIp() const permet de récuperer l'adresse ip du client. */
  const std::string &getIp() const { return _ip; };
  /* La méthode getFd() const permet de récuperer le descripteur de fichier du client. */
  int32_t getFd() const { return _fd; };
  /* La méthode setIp(const std::string &) permet de rentrer l'adresse ip du client. */
  void		setIp(const std::string &ip) { _ip = ip; };
  /* La méthode setFd(const std::int32_t &) permet de rentrer l'adresse ip du client. */
  void		setFd(const int32_t &fd) { _fd = fd; };
private:
  /* _ip est l'attribut contenant l'adresse ip du client. */
  std::string	_ip;
  /* _fd est l'attribut contenant le descripteur de fichier du client. */
  int32_t	_fd;
};


#endif /* !DATACLIENT_HPP_ */
