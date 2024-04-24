/*
 * =====================================================================================
 *
 *       Filename:  connection.c
 *
 *    Description:  Handle connections to my HTTP server
 *
 *        Version:  1.0
 *        Created:  21/03/2024 16:30:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (),
 *   Organization:  
 *
 * =====================================================================================
 */

#include <my_server.h>

#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * @brief Resets a connection object
 *
 * @param[my_connection_t *] conn Pointer to the connection to reset
 */
void my_connection_destroy(my_connection_t *conn)
{
    if (!conn)
        return;
    if (conn->sock)
        fclose(conn->sock);
    if (conn->fd != CLOSED_FD)
        close(conn->fd);
    free(conn);
}

/**
 * @brief Displays information about the current connection
 *
 * @param[struct sockaddr_in] in_addr the address of the current client
 */
void display_connection_info(my_client_t *client, request_t *request)
{
    char addr[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(client->conn->addr), addr, INET_ADDRSTRLEN);
    printf("Received connection from %s.\n", addr);
    printf("Sent a %d request on %s.\n", request->method, request->route);
    for (int i = 0; i < request->attributes->len; i++)
        printf("{'%s': '%s'}\n", request->attributes->keys[i], request->attributes->values[i]);
}

/**
 * @brief Create an empty connection
 *
 * @return The created connection
 */
my_connection_t *my_connection_init(void)
{
    my_connection_t *conn = malloc(sizeof(my_connection_t));

    memset(conn, 0, sizeof(my_connection_t));
    conn->addr.sin_family = AF_INET;
    conn->fd = CLOSED_FD;
    return conn;
}

/**
 * @brief Handles the connection request and sends back the response,
 * by calling the corresponding handler.
 *
 * @param[my_handler_context_t *] ctx All information about the request, client, server
 * and response
 * @return NULL
 */
void *handle_connection(void *threadargs)
{
    my_handler_context_t *ctx = threadargs;
    int status = request_receive(ctx->req, ctx->client->conn->sock);
   
    if (status < 0)
        exit(1);
    display_connection_info(ctx->client, ctx->req);
    request_destroy(ctx->req);
    // TODO response_destroy
    free(ctx);
    return NULL;
}

