##
## Makefile for test_gui in /home/bertho_i/tek3/RType/GUI
## 
## Made by Simon BERTHO
## Login   <bertho_i@epitech.net>
## 
## Started on  Tue Nov 22 18:23:01 2016 Simon BERTHO
## Last update Tue Nov 22 18:47:03 2016 Simon BERTHO
##

SRCS	=	src/main_gui.cpp			\
		src/Widget.cpp				\
		src/Window.cpp				\

SFML_REPO =	./lib/

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	gui_test

CPPFLAGS= 	-std=c++11 -g -Iinclude -Iinclude/Audio -I../Event/include

BLINUX3 = 	yes

ifeq ($(BLINUX3),yes)
	LDFLAGS = -Wl,-rpath=$(SFML_REPO) -L $(SFML_REPO)
endif

LDFLAGS += 	-lsfml-graphics -lsfml-window -lsfml-system 

CC	=	g++

all:	$(NAME)

$(NAME):	  $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:	fclean	all

fast:	fclean
	@make -j4
