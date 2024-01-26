// Marco Sebastiani 2022

#include "sonar.h"

t_user user;

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
	printf("room <room_name> <room_password>: create and host new private room.\n");
	printf("connect <remote_ip>: connect to remote ip.\n");
	printf("join <remote_ip> <room_name> <room_password>: join existing room. You'll need it's key\n");
	printf("exit: close Sonar\n");
	printf("----------------------------------------------\n");
}

void host(char *arg) {
	printf("hosting...\n");
	
	ft_setup_server(arg);
}

void join() {
	printf("joining...\n");
}

void setName(char *str) {
	printf("str: %s\n", str);
	printf("setting name...\n");
	while (*str == ' ')
		str++;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '\n')
			str[i] = '\0';
		user.nickname[i] = str[i];
	}
	printf("name set to %s\n", user.nickname);
}

void connect_to_ip() {
	printf("connecting...\n");
}


void parse_command(char *command, char *arg) {
	printf("command: %s\n", command);
	printf("arg: %s\n", arg);
	if (!ft_strcmp("help", command)) {
		printf("help\n");
		ft_command_legend();
	} else if (!ft_strcmp("exit", command)) {
		printf("exit\n");
		exit (0);
	} else if (!ft_strncmp("host", command, 4)) {
		printf("host\n");
		host(arg);
	} else if (!ft_strncmp("connect", command, 7)) {
		printf("connect\n");
		connect_to_ip();
	} else if (!ft_strncmp("join", command, 4)) {
		printf("join\n");
		join();
	} else if (!ft_strncmp("setname", command, 7)) {
		printf("setname\n");
		setName(arg);
	}
}

int main(void)
{
	// t_room		*room;

	ft_welcome();
	ft_command_legend();
	
	for (;;) {
		char buf[1024];
		printf("Please, insert your command or type help for info\n");
		int b_read = read(0, buf, 1024);
		buf[b_read - 1] = '\0'; // remove newline
		if (strncmp(buf, "exit", 4) == 0)
			exit(0);
		char **split = ft_split(buf, ' ');
		for (int i = 0; split[i]; i++) {
			printf("split[%d]: %s|\n", i, split[i]);
			free(split[i]);
		}
		free(split);
		// parse_command(line, arg);
	}
	return (0);
}
