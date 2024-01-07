// Marco Sebastiani 2022

#include "sonar.h"


// void	ft_listen(int *sockfd, int *connfd)
// {
// 	int	len;
// 	struct sockaddr_in	cli;

// 	while (1)
// 	{
// 		if (listen((*sockfd), 5) != 0)
// 		{
// 			printf("SONAR: server can't listen. Retry\n");
// 			return ;
// 		}
// 		else
// 		{
// 			printf("Waiting for participants...\n");
// 		}
// 		len = sizeof(cli);
// 		// Accept the data packet from client and verification
// 		(*connfd) = accept((*sockfd), (SA*)&cli, (socklen_t *)&len);
// 		if ((*connfd) < 0)
// 		{
// 			printf("SONAR: Server accept failed...\n");
// 			return ;
// 		}
// 		else
// 			printf("New participant!\n");
// 	}
// }

void	ft_setup_server(char *arg)
{
	int	sockfd;
	int	connfd;
	int	len;
	// int	pid;
	struct sockaddr_in	servaddr;
	struct sockaddr_in	cli;

    (void)arg;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) 
	{
		printf("SONAR: socket creation failed. Retry\n");
		return ;
	}
	memset(&servaddr, '0', sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // check permissions (is any incoming message ok?)
	servaddr.sin_port = htons(PORT);
	// Binding newly created socket to given IP and verification
	if (bind(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0)
	{
		printf("SONAR: room socket bind failed. Retry\n");
		return ;
	}
	// Now server is ready to listen and verification
	if (listen(sockfd, 5) != 0)
	{
		printf("SONAR: server can't listen. Retry\n");
		return ;
	}
	else
		printf("SONAR: waiting for participants...\n");
	len = sizeof(cli);
	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, (socklen_t *)&len);
	if (connfd < 0)
	{
		printf("SONAR: Server accept failed...\n");
		return ;
	}
	else
		printf("SONAR: new entry!\n");
	return ;
}
