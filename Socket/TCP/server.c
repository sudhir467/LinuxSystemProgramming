/*Server program in socket programming*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /*for read,write,  close system calls*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Port number not provided. Program terminated\n");
        exit(1);
    }

    int sockfd, newsockfd, portno, n;
    char buffer[255];
    struct sockaddr_in serv_addr, cli_addr; /*server addr and client addr*/
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); /*0 defines its TCP*/
    if (sockfd < 0)
    {
        error("Error openeing socket");
    }

    bzero((char *)&serv_addr, sizeof(serv_addr)); /*bzero clear any data or text in what it refers to*/
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /*Binding process*/

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("Binding failed");
    }

    /*Listening function*/

    listen(sockfd, 5); /*Any interger 5 or 4 will give you the max number of clients connected*/
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0)
    {
        error("Error on Accept");
    }

    while (1)
    {
        bzero(buffer, 255);
        n = read(newsockfd, buffer, 255);
        if (n < 0)
        {
            error("Error on reading");
        }
        printf("client: %s \n", buffer);
        bzero(buffer, 255);
        fgets(buffer, 255, stdin); /*reads bytes from stream in to array pointed by buffer*/
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0)
        {
            error("Error on writing");
        }

        int i = strncmp("Bye", buffer, 3);

        if (i == 0)
        {
            break;
        }
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}