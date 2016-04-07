##
## Makefile for Makefile in /home/besnai_m/rendu/Igraph/MUL_2014_fdf
## 
## Made by michael besnainou
## Login   <besnai_m@epitech.net>
## 
## Started on  Fri Dec  5 13:25:26 2014 michael besnainou
## Last update Sun Jan 11 17:04:29 2015 michael besnainou
##

SRC	= my_select.c \
	gere_key.c

SRCS	= lib/my/my_putchar.c \
	lib/my/my_putstr.c \
	lib/my/my_putint.c

CC	= gcc

FILE	= my_select

LIB	= libmy.a

OBJ	= $(SRC:.c=.o)

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	= -lncurses -Wall -Wextra -Werror -ansi

all: $(NAME) $(FILE)

$(LIB): $(OBJS)
	ar rc $(LIB) $(OBJS)
	ranlib $(LIB)

$(FILE): $(LIB) $(OBJ)
	$(CC) -o $(FILE) $(OBJ) $(LIB) $(CFLAGS)

clean: 
	$(RM) $(OBJ)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIB)
	$(RM) $(FILE)

re: fclean all

.PHONY: all clean fclean re
