#include "csapp.h"

int main(int argc, char **argv){
    int clientfd;                       //socket fd(for. connect server)
    char *host, *port, buf[MAXLINE];    //server host명, port, data 담는 buffer
    rio_t rio;                          //RIO buffer 구조체(입출력 관리)

    if (argc != 3){
        fprintf(stderr, "usage: %s <host> <post>\n", argv[0]);
        exit(0);
    }
    host = argv[1];
    port = argv[2];

    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);

    while (Fgets(buf, MAXLINE, stdin) != NULL)
    {
        Rio_writen(clientfd, buf, strlen(buf));
        Rio_readlineb(&rio, buf, MAXLINE);
        Fputs(buf, stdout);
    }
    Close(clientfd);
    exit(0);
}