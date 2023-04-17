// Marco Sebastiani 2022

// GENERAL
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
// SERVER AND CLIENT
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
// UI
#include <ncurses.h>

// DEFINES
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

typedef struct s_user {
	char	*nickname;
	int		is_host;
}	t_user;

typedef struct s_room {
	char	*name;
	char	*key;
}	t_room;

typedef struct s_message {
	char			*content;
}	t_message;

// USER
void	ft_choose_nickname(t_user *user);
void	ft_create_room(t_room *room, t_user *user, t_message *message);

// CHAT
void	ft_chat(int fd, t_user *user, t_room *room, t_message *message);
int		ft_options(t_user *user, t_room *room, t_message *message);
void	ft_receiver(int fd);

// SINGALS
// void	ft_signals(void);

// WELCOME MESSAGES AND EXPLANATIONS
void	ft_welcome(void);
void	ft_command_legend(void);

// START
void    ft_init(t_user *user, t_room *room, t_message *message);
void	ft_start(t_room *room, t_user *user, t_message *message);

// UTILITIES
int 	ft_strcmp(char *str1, char *str2);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

// QUIT SONAR
void 	ft_free_and_exit(t_user *user, t_room *room);

// SERVER AND CLIENT
void	ft_setup_server(t_user *user, t_room *room, t_message *message);
void	ft_client(t_user *user, t_room *room, t_message *message);
