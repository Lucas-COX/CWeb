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
    my_connection_t conn;

    if (socket_fd < 0) {
        perror("socket failed");
        return 1;
    }
    conn.addr.sin_family = AF_INET;
    conn.addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &(conn.addr.sin_addr));
    conn.fd = socket_fd;
    if (bind(conn.fd, (struct sockaddr *)&(conn.addr), sizeof(conn.addr)) < 0) {
        perror("bind failed");
        return 1;
    }
    if (listen(conn.fd, 10) < 0) {
        perror("listen failed");
        return 1;
    }
    server->conn = conn;
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
    if (close(server->conn.fd) < 0) {
        perror("close failed");
        return 1;
    }
    // TODO destroy all connections
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

    reset_connection(&(server->conn));
    server->clients = NULL;
    return server;
}
