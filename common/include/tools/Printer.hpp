//
// Print.hh for  in /home/lecoq_m/cpp_plazza
// 
// Made by Maxime Lecoq
// Login   <lecoq_m@epitech.net>
// 
// Started on  Sun Apr 24 15:07:28 2016 Maxime Lecoq
// Last update Wed Apr 27 18:59:28 2016 Maxime LECOQ
//

#ifndef		__PRINTER_HH__
# define	__PRINTER_HH__

# include	<iostream>
# include	<string>
# include	<vector>

class		Printer
{
public:
  Printer() {}
  ~Printer() {}
private:
  Printer(const Printer &cop) { (void)cop; }
  Printer &operator=(const Printer &cop) { (void)cop; return (*this); }
public:
  template<typename T>
  void	print(std::vector<T> ve)
  {
    size_t i;
    size_t size;

    i = 0;
    size = ve.size();
    while (i < size)
      std::cout << ve[i++] << std::endl;
  }
  template<typename X>
  void print(const X &s) { std::cout << s << std::endl; }
};

#endif
