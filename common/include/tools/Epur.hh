//
// Epur.hh for  in /home/lecoq_m/cpp_plazza
// 
// Made by Maxime Lecoq
// Login   <lecoq_m@epitech.net>
// 
// Started on  Sat Apr 23 19:13:31 2016 Maxime Lecoq
// Last update Fri Dec 23 16:09:42 2016 lecoq
//

#ifndef		__EPUR_HH__
# define	__EPUR_HH__

# include	<iostream>
# include	<string>

class		Epur
{
private:
  std::string	_str;
public:
  Epur() {};
  Epur(const std::string &);
  Epur(const std::string &, const char &);
  ~Epur();
  Epur(const Epur &);
  Epur &operator=(const Epur &);
public:
  const std::string	&getString() const;
  std::string		epur(const std::string &, const char &);
  std::string		replace(const std::string &, const char &, const char &);
};

#endif
