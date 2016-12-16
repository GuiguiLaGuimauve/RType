//
// main.cpp for main in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 14:47:53 2016 Maxime Lecoq
// Last update Fri Dec 16 15:25:44 2016 lecoq
//

#include "CoreClient.hh"

int	main()
{
  CoreClient	core;

  if (core.initManager() == false)
    return (0);
  core.run();
  core.deleteManager();
  return (0);
}
