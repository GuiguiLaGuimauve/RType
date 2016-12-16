//
// ErrorSocket.hh for  in /home/lecoq_m/cpp_arcade
//
// Made by Maxime Lecoq
// Login   <lecoq_m@epitech.net>
//
// Started on  Fri Mar 18 09:35:48 2016 Maxime Lecoq
// Last update Fri Dec 16 10:56:40 2016 lecoq
//

#ifndef		__ERRORSERVER_HH__
# define	__ERRORSERVER_HH__

# include	"AError.hh"

namespace Error
{
  class ErrorServer : public AError
  {
  public:
    ErrorServer(std::string const & err) : AError(err, "ErrorServer") {};
    virtual ~ErrorServer() throw() {}
  };
};

#endif		/*__ERROR_HH__ */
