//
// CatchString.hh for  in /home/lecoq_m/cpp_plazza
// 
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
// 
// Started on  Mon Apr 18 13:38:30 2016 Maxime LECOQ
// Last update Mon Apr 18 13:44:00 2016 Maxime LECOQ
//

#ifndef		__CATCHIT_HH__
# define	__CATCHIT_HH__

template<typename X>
class		CatchIt
{
private:
  X	_obj;
public:
  CatchIt(const X &obj) : _obj(obj) {};
  ~CatchIt() {};
  CatchIt(const CatchIt &cop) : _obj(cop._obj) {};
  CatchIt	&operator=(const CatchIt &cop)
  {
    if (this != &cop)
      {
	_obj = cop._obj;
      }
    return (*this);
  };

  X		getIt() const
  {
    return (_obj);
  };

};

#endif
