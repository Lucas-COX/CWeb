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
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <wait.h>

bool exited = false;

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
    my_connection_t *conn = init_connection();

    if (socket_fd < 0) {
        perror("socket failed");
        return 1;
    }
    conn->addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &(conn->addr.sin_addr));
    conn->fd = socket_fd;
    if (bind(conn->fd, (struct sockaddr *)&(conn->addr), sizeof(conn->addr)) < 0) {
        perror("bind failed");
        return 1;
    }
    if (listen(conn->fd, 10) < 0) {
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
    if (server->conn->fd != CLOSED_FD && close(server->conn->fd) < 0) {
        perror("close failed");
        return 1;
    }
    llist_destroy(server->clients);
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

    server->conn = init_connection();
    server->clients = llist_init();
    return server;
}

/**
 * @brief Runs the main server process
 *
 * @param[my_server_t *] server Server instance
 * @return -1 on error, 0 otherwise
 */
int run_server(my_server_t *server)
{
    my_client_t *client;

    while (!exited) {
        client = accept_connections(server);
        if (!client)
            break;
        llist_push(server->clients, client);
        printf("Server has %d connections.\n", server->clients->n_elem);
    }
    for (int i = 0; i < server->clients->n_elem; i++) {
        my_client_t *client = llist_get(server->clients, i);
        if (!client)
            continue;
        pthread_join(client->thread, NULL);
        printf("Ended a thread.\n");
    }
    return 0;
}
