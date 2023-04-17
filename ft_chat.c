// Marco Sebastiani 2022

#include "sonar.h"

int	ft_options(t_user *user, t_room *room, t_message *message)
{
	char	*option;

	option = readline("do you want to leave this room? (y/n) >> ");
	if (ft_strcmp(option, "y\0") == 0)
	{
		write(1, "leaving ", 9);
		write(1, room->name, ft_strlen(room->name));
		write(1, "\n", 1);
		free(option);
		return (1);
	}
	else if (ft_strcmp(option, "n\0") == 0)
	{
		free(option);
		return (0);
	}
	else
	{
		free(option);
		printf("answer properly: y = yes, n = no\n");
		ft_options(user, room, message);
	}
	return (0);
}

char	*ft_compose_line(t_user *user, t_room *room, t_message *message)
{
	char	*author;
	char	*room_str;
	char	*meta;
	char	*new_line;
	char	*result;

	author = ft_strjoin(user->nickname, "@");
	room_str = ft_strjoin(author, room->name);
	meta = ft_strjoin(room_str, ": ");
	result = ft_strjoin(meta, message->content);
	new_line = ft_strjoin(result, "\n");
	free(author);
	free(room_str);
	free(meta);
	free(result);
	return (new_line);
}

void	ft_receiver(int fd)
{
	char	incoming[MAX];

	memset(incoming, 0, sizeof(incoming));
	while (1)
	{
		read(fd, incoming, sizeof(incoming));
		write(1, incoming, ft_strlen(incoming));
		memset(incoming, 0, sizeof(incoming));
	}
}

void	ft_chat(int fd, t_user *user, t_room *room, t_message *message)
{
	int		pid;
	char	*line;

	pid = fork();
	if (pid == 0)
		ft_receiver(fd);
	else
	{
		write(fd, user->nickname, ft_strlen(user->nickname));
		write(fd, " joined the conversation\n", 26);
		while (1)
		{
			message->content = readline("write >> ");
			if (message->content[0] != '\0')
			{
				rl_on_new_line();
				if (ft_strcmp("exit", message->content) == 0)
				{
					if (ft_options(user, room, message) == 1)
					{
						free(message->content);
						write(fd, user->nickname, ft_strlen(user->nickname));
						write(fd, " is leaving.\n", 14);
						if (user->is_host == 1)
						{
							user->is_host = 0;
							write(fd, "Room closing\n", 14);
						}
						free(room->key);
						free(room->name);
						kill(0, SIGTERM);
						break;
					}
					else
					{
						free(message->content);
						write(1, "[]-> Back in the room\n", 23);
					}
				}
				else
				{
					line = ft_compose_line(user, room, message);
					write(fd, line, ft_strlen(line));
					write(1, line, ft_strlen(line));
					free(line);
					free(message->content);
				}
			}
			else
				free(message->content);
		}
	}
	return ;
}
