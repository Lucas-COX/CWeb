/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  Server related functions
 *
 *        Version:  1.0
 *        Created:  20/03/2024 09:35:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <my_server.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @brief Binds the server to an address and a port and starts
 * listening for connections.
 *
 * @param[my_server_t *] server the server to bind
 * @param[int] port the port to bind at
 * @param[string] ip the ip address to bind at
 * @return -1 on error, 0 otherwise
 */
int bind_and_listen(my_server_t *server, int port, char const *ip)
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) {
        perror("socket failed");
        return 1;
    }
    server->addr = malloc(sizeof(struct sockaddr_in));
    server->addr->sin_family = AF_INET;
    server->addr->sin_port = htons(port);
    inet_pton(AF_INET, ip, &(server->addr->sin_addr));
    server->fd = socket_fd;
    if (bind(server->fd, (struct sockaddr *)server->addr, sizeof(*(server->addr))) < 0) {
        perror("bind failed");
        return 1;
    }
    if (listen(server->fd, 10) < 0) {
        perror("listen failed");
        return 1;
    }
    return 0;
}

/**
 * @brief Cleans up server memory
 *
 * @param[my_server_t *] server the server to clean up
 * @return -1 on error, 0 on success
 */
int cleanup_server(my_server_t *server)
{
    if (!server)
        return 0;
    if (close(server->fd) < 0) {
        perror("close failed");
        return 1;
    }
    if (server->addr) {
        free(server->addr);
    }
    free(server);
    return 0;
}


/**
 * @brief Creates an empty server and allocates the memory for it
 *
 * @return The created server
 */
my_server_t *init_server(void)
{
    my_server_t *server = malloc(sizeof(my_server_t));

    server->addr = NULL;
    server->fd = -1;
    return server;
}
