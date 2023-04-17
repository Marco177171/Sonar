// Marco Sebastiani 2022

#include "sonar.h"
 
void	ft_client(t_user *user, t_room *room, t_message *message)
{
	int sockfd;
	struct sockaddr_in  servaddr;

	room->name = readline("what's the name of the room? >> ");
	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printf("SONAR: socket creation failed...\n");
		return ;
	}
	else
		printf("SONAR: socket successfully created..\n");
	memset(&servaddr, '0', sizeof(servaddr));
	// assign IP and PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);
	// connect the client socket to server socket
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0)
	{
		perror("connect");
		printf("SONAR: couldn't connect\n");
		return ;
	}
	else
		printf("SONAR: connection enstablished\n");
	ft_chat(sockfd, user, room, message);
	close(sockfd);
	return ;
}
