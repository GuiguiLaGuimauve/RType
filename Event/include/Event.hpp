//
// Event.hh for babel in /home/bertho_i/tek3/cpp_babel/d_client
// 
// Made by Simon BERTHO
// Login   <bertho_i@epitech.net>
// 
// Started on  Wed Oct 19 11:16:12 2016 Simon BERTHO
// Last update Wed Nov 23 12:43:47 2016 Simon BERTHO
//

#ifndef EVENT_HH
#define EVENT_HH

#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <stdint.h>

namespace EventPart
{
  struct Event
  {
  public:
    enum TYPE
      {
	DEFAULT,
	// interns events of the gui
	CLOSE_WINDOW,
	CLICK, // int["X"] int ["Y"] int["CLICK"]
	KEY_ATTACK,
	KEY_UP,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_LEFT
      };
    
    // constructeur classique
    Event(TYPE t = DEFAULT)
    {
      type = t;
    };
    
    // constructeur variadique
    template <typename ... Args>
    Event(TYPE t, const Args ... a)
    {
      type = t;
      setArgs(a ...);
    }
  protected:
    // fonctions pour set les arguments
    // au cas ou
    void	setArgs()
    {
      return ;
    }
  private:
    // pour quand y a plus de 2 arguments bonus pour int
    template <typename ... Args>
    void	setArgs(const std::string &s, int32_t i, const Args& ... a)
    {
      dataInt[s] = i;
      setArgs(a ...);
    }
    
    // pour la map d'int à la fin
    void	setArgs(const std::string &s, int32_t i)
    {
      dataInt[s] = i;
    }
    
    // pour quand y a plus de 2 arguments bonus pour string
    template <typename ... Args>
    void	setArgs(const std::string &s, const std::string &data,	\
			const Args& ... a)
    {
      dataString[s] = data;
      setArgs(a ...);
    }
    
    // pour la map d'string à la fin
    void	setArgs(const std::string &s, const std::string &data)
    {
      dataString[s] = data;
    }
    
    // attributs
  public:
    TYPE					type;
    std::map<std::string, int32_t>		dataInt;
    std::map<std::string, std::string>		dataString;
  };
};

#endif
