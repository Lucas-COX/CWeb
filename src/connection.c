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
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

/**
 * @brief Displays information about the current connection
 *
 * @param[struct sockaddr_in] in_addr the address of the current client
 */
void display_connection_info(struct sockaddr_in in_addr)
{
    char addr[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &in_addr, addr, INET_ADDRSTRLEN);
    printf("Received connection from %s\n", addr);
}

/**
 * @brief Handles upcoming connections to the server
 *
 * @param[my_server_t *] server the server to handle connections of
 * @return -1 on error, 0 otherwise
 */
int handle_connections(my_server_t *server)
{
    struct sockaddr_in client_addr;
    int client_fd = accept(server->fd, (struct sockaddr *)&client_addr, NULL);

    display_connection_info(client_addr);
    return close(client_fd);
}
