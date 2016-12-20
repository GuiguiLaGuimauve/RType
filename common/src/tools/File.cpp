//
// File.cpp for  in /home/lecoq_m/cpp_plazza
// 
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
// 
// Started on  Sat Apr 23 09:15:25 2016 Maxime LECOQ
// Last update Tue Apr 26 17:19:36 2016 Maxime LECOQ
//

#include	"File.hh"

File::File() : _file("File") {}

File::File(const std::string &file) : _file(file) {}

File::File(const File &cop) : _file(cop._file) {}

File::~File() {}

File		&File::operator=(const File &cop)
{
  if (this != &cop)
    _file = cop._file;
  return (*this);
}

void		File::writeAppend(const std::string &msg)
{
  if (msg.empty() == true)
    return;
  std::string   line;
  std::ifstream input_stream(_file.c_str());
  char          c;

  if (input_stream.is_open())
    {
      while (input_stream.get(c))
        line += c;
      input_stream.close();
    }
  else
    throw ErrorOpen("cannot open \"" + _file + "\" for writting a logfile.");
  if (line.empty() == false && line[line.size() - 1] != '\n')
    line += '\n';
  line += msg; 
  std::ofstream output_stream(_file.c_str());

  if (output_stream.is_open())
    {
      output_stream << line;
      output_stream.close();
    }
  else
    throw ErrorOpen("cannot open \"" + _file + "\" for writting a logfile.");
}

void		File::writeTronc(const std::string &msg)
{
  if (msg.empty() == true)
    return;
  std::ofstream output_stream(_file.c_str());

  if (output_stream.is_open())
    {
      output_stream << msg;
      output_stream.close();
    }
  else
    throw ErrorOpen("cannot open \"" + _file + "\" for writting a logfile.");
}

void		File::clear()
{
  std::ofstream output_stream(_file.c_str());

  if (output_stream.is_open())
    {
      output_stream << "";
      output_stream.close();
    }
  else
    throw ErrorOpen("cannot destroy \"" + _file + "\".");
}

std::string	File::read()
{
  std::string   line;
  std::ifstream input_stream(_file.c_str());
  char          c;

  if (input_stream.is_open())
    {
      while (input_stream.get(c))
        line += c;
      input_stream.close();
    }
  else
    throw ErrorOpen("cannot open \"" + _file + "\" for writting a logfile.");
  if (line.empty() == false && line[line.size() - 1] != '\n')
    line += '\n';
  return (line);
}

void		File::destroy()
{
  unlink(_file.c_str());
}

void		File::setFile(const std::string &f)
{
  _file = f;
}
