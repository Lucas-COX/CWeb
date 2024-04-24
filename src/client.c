/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  Client related functions for my HTTP server
 *
 *        Version:  1.0
 *        Created:  22/03/2024 10:37:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (),
 *   Organization:  
 *
 * =====================================================================================
 */

#include "requests/requests.h"
#include <my_server.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Initialize a client object and allocate memory for it
 *
 * @return The created client
 */
my_client_t *my_client_init(void)
{
    my_client_t *client = malloc(sizeof(my_client_t));

    client->conn = my_connection_init();
    return client;
}

void my_client_destroy(my_client_t *client)
{
    if (!client) 
        return;
    if (client->conn)
        my_connection_destroy(client->conn);
    free(client);
}

/**
 * @brief Handles upcoming connections to the server
 *
 * @param[my_server_t *] server the server to handle connections of
 * @return -1 on error, 0 otherwise
 */
my_client_t *accept_connections(my_server_t *server)
{
    my_client_t *client = my_client_init();
    socklen_t len = 0;
    my_handler_context_t *ctx = malloc(sizeof(my_handler_context_t));

    client->conn->fd = accept(server->conn->fd,\
            (struct sockaddr *)&(client->conn->addr), &len);
    if (client->conn->fd < 0) {
        my_client_destroy(client);
        free(ctx);
        return NULL;
    }
    client->conn->sock = fdopen(client->conn->fd, "rw");
    ctx->client = client;
    ctx->server = server;
    ctx->req = request_init();
    // TODO init response
    pthread_create(&client->thread, NULL,\
            handle_connection, ctx);
    return client;
}
