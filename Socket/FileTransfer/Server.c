/*This program is to transfer file from client to server*/

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

    FILE *fp;
    int ch = 0;
    fp = fopen("glad_recieved.txt", "a");
    int words;

    read(newsockfd, &words, sizeof(int));

    while (ch != words)
    {
        read(newsockfd, buffer, 255);
        fprintf(fp, "%s ", buffer);
        ch++;
    }
    printf("The file has been recieved successfully.!!");

    close(newsockfd);
    close(sockfd);
    return 0;
}