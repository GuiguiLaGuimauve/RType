//
// String.hpp for String in /home/lecoq_m/cpp_babel
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Nov 10 11:54:31 2016 Maxime Lecoq
// Last update Sat Nov 12 17:31:36 2016 lecoq
//

#ifndef STRINGCK_HPP_
# define STRINGCK_HPP_

class StringCk
{
public:
  StringCk() {};
  ~StringCk() {};
  bool	isNumber(const std::string &str) {
    uint64_t i;
    i = 0;
    while (i < str.size())
      {
	if (str[i] == '-' && i != 0)
	  return (false);
	else if (str[i] < '0' || str[i] > '9')
	  return (false);
	else
	  i++;
      }
      return (true);
  }
  std::string lower(const std::string &s)
  {
    std::string	ret;
    uint64_t	i;

    i = 0;
    while (i < s.size())
      {
	if (s[i] >= 'A' && s[i] <= 'Z')
	  ret += (s[i] + 32);
	else
	  ret += s[i];
	i++;
      }
    return (ret);
  }
};

#endif /* !STRINGCK_HPP_ */
