NAME = sonar
CC = gcc
FLAGS = -Wall -Wextra -Werror 
READLINE = -L.local/lib -lreadline
NCURSES = -lncurses
SRC = *.c
UTILS = ./utilities/*.c

$(NAME):
		$(CC) $(FLAGS) $(SRC) $(UTILS) -o $(NAME) $(READLINE) $(NCURSES)

clean:
		rm -f $(NAME)

all:	$(NAME)

re:		clean
		$(NAME)
