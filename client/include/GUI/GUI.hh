#ifndef GUI_HH
#define GUI_HH

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cctype>
#include <cstdio>
#include <utility>

#include "IGUI.hh"

#include "Widget.hh"
#include "Window.hh"
#include "SoundManager.hh"
#include "GuiEventManager.hh"
#include "EventQueue.hh"
#include "Key.hh"
#include "DataRoom.hpp"

void	TextColorNoFocus(Gui::IWidget *w);
void	TextColorFocus(Gui::IWidget *w);
void	textEntered(Gui::IWidget *w, const std::string &c);

namespace Gui
{

  

  class GUI: public IGUI
  {
  protected:

    struct      data
    {
      int x = 50;
      int y = 50;
      int health = 100;
      //char *name = "1";
      int       type = 1;
    };
    
    struct Start
    {
      IWidget	*title = NULL;
      IWidget	*texte = NULL;
      IWidget	*imput = NULL;
      IWidget	*button = NULL;
      IWidget	*chevron = NULL;
    };

    struct Login
    {
      IWidget	*login = NULL;
      IWidget	*password = NULL;
      IWidget	*text1 = NULL;
      IWidget	*text2 = NULL;
      IWidget	*confirm = NULL;
      IWidget	*chevron1 = NULL;
      IWidget	*chevron2 = NULL;
    };

    struct Menu
    {
      IWidget	*GameText = NULL; // affiche le texte "GAME"
      IWidget	*GameInfos = NULL; // affiche le texte "Info"
      IWidget	*selectedGame = NULL; // va servir à affichier les infos de la game selectionnée
	  int		selectedRoom = -1; // id dans le vecteur de la game selectionnée
      std::vector<IWidget *>	games; // affichage de toutes les games
      IWidget	*profile = NULL; // affiche "PROFILE"
      IWidget	*profileInfo = NULL; // affiches les informations liées au user
      IWidget	*createGame = NULL; // bouton pour créer une gaùe
      IWidget	*confirm = NULL; // bouton pour confirmier
      /* Vecteur de joueurs connectés */
      /* Container des joueurs connectés */
    };

    struct Game
    {
      uint8_t                   levelId;
    };
  public:
    GUI();
    virtual ~GUI();
    
    void        callback();
    void        displayGame();
    void        displayStart();
    void        displayMenu();
    void		displayLogin();
    void        updateGameInfo(/*const GameInfo &*/);
    void		setEventQueue(EventPart::IEventQueue *);
    void		setSoundManager(Audio::ISoundManager *);
    void		showPopup(const std::string &s, int tMilli = 2000);
    void		loadSoundAssets();
    void		setRooms(const std::vector<DataRoom *> &);
    void		setProfile(DataPlayer *p);
  protected:
    void	deleteWidgets();
  protected:
    Audio::ISoundManager	*_audio;
    IWindow					*_win;
    IGuiEventManager		*_userEvents;
	// pour gérer le menu
    std::vector<DataRoom*>	_menuInfos;
    DataRoom				*_currentGame = NULL;
    DataPlayer				*_profile = NULL;
	// les queues d'events
    EventPart::IEventQueue	*_coreQueue;
    EventPart::IEventQueue	*_guiQueue;
    // gestion effets graphiques
    IWidget					*_hoverWidget = NULL;
    IWidget					*_focusWidget = NULL;
    // liste des widgets dans les structures
    Start					*_startWidgets = NULL;
    Login					*_loginWidgets = NULL;
    Menu					*_menuWidgets = NULL;
    Game					*_gameWidgets = NULL;
    // popup
    IWidget					*_fadedWidget = NULL;
    /* temp pour test GUI */
    std::vector<data>		players;
    std::vector<data>		shots;
    std::vector<data>		envs;
    std::vector<data>		monsters;
  };
}

#endif
