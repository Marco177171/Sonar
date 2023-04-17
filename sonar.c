// Marco Sebastiani 2022

#include "sonar.h"
void	ft_welcome(void)

{
	printf("|---------------------------|\n");
	printf("| SONAR | instant messaging |\n");
	printf("|  made with </3 by Pulsar  |\n");
	printf("|---------------------------|\n");
}

void	ft_command_legend(void)
{
	printf("----------------------------------------------\n");
	printf("COMMANDS:\n");
	printf("room: create and host new private room.\n");
	printf("join: join existing room. You'll need it's key\n");
	printf("exit: close Sonar\n");
	printf("----------------------------------------------\n");
}

void	ft_start(t_room *room, t_user *user, t_message *message)
{
	char	*command;

	command = NULL;
	ft_command_legend();
	command = readline("what do you want to do? >> ");
	if (command[0] == '\0')
	{
		printf("empty command: use room, join or quit\n");
		free(command);
		ft_start(room, user, message);
	}
	else if (ft_strcmp("room", command) == 0)
	{
		free(command);
		ft_create_room(room, user, message);
		ft_start(room, user, message);
	}
	else if (ft_strcmp("join", command) == 0)
	{
		free(command);
		ft_client(user, room, message);
		ft_start(room, user, message);
	}
	else if (ft_strcmp("exit", command) == 0)
	{
		free(command);
		ft_free_and_exit(user, room);
	}
	else
	{
		printf("%s is not a valid command\n", command);
		free(command);
		ft_start(room, user, message);
	}
}

int main(void)
{
	t_room		room;
	t_user		user;
	t_message	message;

	ft_init(&user, &room, &message);
	ft_welcome();
	ft_choose_nickname(&user);
	ft_start(&room, &user, &message);
	return (0);
}
