//
// main.cpp for main in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 14:47:53 2016 Maxime Lecoq
// Last update Thu Dec 15 14:48:45 2016 lecoq
//

#include "CoreClient.cpp"

int	main()
{
  CoreClient	core;

  core.initManager();
  core.run();
  core.deleteManager();
  return (0);
}
