NAME = sonar
CC = gcc
FLAGS = -Wall -Wextra -Werror 
NCURSES = -lncurses
SRC = ft_server.c ft_free_and_exit.c room.c sonar.c
UTILS = ft_split.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c
UTILSDIR = utilities
UTILSOBJ = $(UTILS:%.c=$(UTILSDIR)/%.o)
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ) $(UTILSOBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(NCURSES) $(OBJ) $(UTILSOBJ)

clean:
	@rm -f $(OBJ) $(UTILSOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re