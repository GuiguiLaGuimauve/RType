//
// LogFile.cpp for  in /home/lecoq_m/cpp_plazza
// 
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
// 
// Started on  Sat Apr 23 09:11:38 2016 Maxime LECOQ
// Last update Tue Dec 20 03:09:38 2016 lecoq
//

#ifndef		__FILE_HH__
# define	__FILE_HH__

# include	<iostream>
# include	<string>
# include       <sstream>
# include       <fstream>
#ifdef UNIX
# include	<unistd.h>
#endif
# include	"ErrorOpen.hpp"

class		File
{
private:
  std::string	_file;
public:
  File();
  File(const std::string &);
  File(const File &);
  ~File();
  File &operator=(const File &);
  void	setFile(const std::string &);
  void	writeAppend(const std::string &);
  void	writeTronc(const std::string &);
  std::string read();
  void	destroy();
  void	clear();
};

#endif
