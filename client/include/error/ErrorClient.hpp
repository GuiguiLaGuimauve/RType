//
// ErrorSocket.hh for  in /home/lecoq_m/cpp_arcade
//
// Made by Maxime Lecoq
// Login   <lecoq_m@epitech.net>
//
// Started on  Fri Mar 18 09:35:48 2016 Maxime Lecoq
// Last update Fri Dec 16 11:36:46 2016 lecoq
//

#ifndef		__ERRORCLIENT_HH__
# define	__ERRORCLIENT_HH__

# include	"AError.hh"

namespace Error
{
  class ErrorClient : public AError
  {
  public:
    ErrorClient(std::string const & err) : AError(err, "ErrorClient") {};
    virtual ~ErrorClient() throw() {}
  };
};

#endif		/*__ERROR_HH__ */
