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

#include <string.h>

my_client_t init_client(void)
{
    my_client_t client;
    
    memset(&client, 0, sizeof(client));
    client.pid = PARENT_PID;
    return client;
}
