//
// ErrorRead.hh for  in /home/lecoq_m/cpp_arcade
// 
// Made by Maxime Lecoq
// Login   <lecoq_m@epitech.net>
// 
// Started on  Fri Mar 18 09:35:48 2016 Maxime Lecoq
// Last update Mon Apr 18 14:58:24 2016 Maxime LECOQ
//

#ifndef		__ERROROPEN_HH__
# define	__ERROROPEN_HH__

# include	"AError.hh"

class ErrorOpen : public AError
{
public:
  ErrorOpen(std::string const & err) : AError(err, "ErrorOpen") {};
  virtual ~ErrorOpen() throw() {}
};

#endif		/*__ERROR_HH__ */
