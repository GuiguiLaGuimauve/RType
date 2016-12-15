//
// IGame.hh for IGame in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:54:14 2016 Maxime Lecoq
// Last update Thu Dec 15 11:57:41 2016 lecoq
//

#ifndef IGAME_HH_
# define IGAME_HH_

class IGame {
public:
  enum Stage
    {
      STAGE1 = 1,
      STAGE2 = 2,
      STAGE3,
      BOSS1,
      STAGE4,
      STAGE5,
      STAGE6,
      BOSS2
    };
  virtual ~IGame() {};
};

#endif /* !IGAME_HH_ */
