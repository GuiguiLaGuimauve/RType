##
## Makefile for 301danone in /home/oger_a/rendu3/Maths/301danone/301danone
## 
## Made by Antonin Oger
## Login   <oger_a@epitech.net>
## 
## Started on  Tue Sep 20 14:10:17 2016 Antonin Oger
## Last update Tue Nov 22 18:16:33 2016 Simon BERTHO
##

SRCS	= src/main_gui.cpp			\

SFML_REPO = ./lib/

OBJS	= $(SRCS:.cpp=.o)

NAME	= gomoku

CPPFLAGS= -std=c++11 -g -Iinclude -Iinclude/Audio -I../Event/include

BLINUX3 = yes

ifeq ($(BLINUX3),yes)
	LDFLAGS = -Wl,-rpath=$(SFML_REPO) -L $(SFML_REPO)
endif

LDFLAGS += -lsfml-graphics -lsfml-window -lsfml-system 

CC	= g++

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
