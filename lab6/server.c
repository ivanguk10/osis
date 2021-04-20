#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void start(int sockfd)
{
	char buff[MAX];
	int n;
	while (1)
	{
		bzero(buff, MAX);

		read(sockfd, buff, sizeof(buff));
		printf("Message: %s", buff);
		write(sockfd, buff, sizeof(buff));

		if (strncmp("exit", buff, 4) == 0)
		{
			printf("Exit...\n");
			break;
		}
	}
}

int main()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printf("Socket creation failed...\n");
		close(sockfd);
		exit(0);
	}
	else
	{
		printf("Socket successfully created..\n");
	}
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
	{
		printf("Socket bind failed...\n");
		close(sockfd);
		exit(0);
	}
	else
	{
		printf("Socket successfully binded..\n");
	}

	if ((listen(sockfd, 5)) != 0)
	{
		printf("Listen failed...\n");
		close(sockfd);
		exit(0);
	}
	else
	{
		printf("Server listening..\n");
	}
	len = sizeof(cli);

	connfd = accept(sockfd, (SA *)&cli, &len);
	if (connfd < 0)
	{
		printf("server acccept failed...\n");
		close(sockfd);
		exit(0);
	}
	else
	{
		printf("server acccept the client...\n");
	}

	start(connfd);

	close(sockfd);
}
