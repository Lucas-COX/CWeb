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

#include <my_server.h>

#include <stdlib.h>
#include <string.h>

my_client_t *init_client(void)
{
    my_client_t *client = malloc(sizeof(my_client_t));

    client->pid = ERROR_PID;
    memset(&(client->conn), 0, sizeof(my_connection_t));
    return client;
}
