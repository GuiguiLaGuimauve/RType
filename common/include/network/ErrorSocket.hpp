//
// ErrorSocket.hh for  in /home/lecoq_m/cpp_arcade
//
// Made by Maxime Lecoq
// Login   <lecoq_m@epitech.net>
//
// Started on  Fri Mar 18 09:35:48 2016 Maxime Lecoq
// Last update Sun Nov 13 21:21:31 2016 La Guimauve
//

#ifndef		__ERRORSOCKET_HH__
# define	__ERRORSOCKET_HH__

# include	"AError.hh"

namespace Error
{
  class ErrorSocket : public AError
  {
  public:
    ErrorSocket(std::string const & err) : AError(err, "ErrorSocket") {};
    virtual ~ErrorSocket() throw() {}
  };
};

#endif		/*__ERROR_HH__ */
