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
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void reset_connection(my_connection_t *conn)
{
    if (conn->fd != CLOSED_FD) {
        close(conn->fd);
    }
    memset(conn, 0, sizeof(my_connection_t));
    conn->fd = CLOSED_FD;
}

/**
 * @brief Displays information about the current connection
 *
 * @param[struct sockaddr_in] in_addr the address of the current client
 */
void display_connection_info(my_client_t client)
{
    char addr[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(client.conn.addr), addr, INET_ADDRSTRLEN);
    printf("Received connection from %s\n", addr);
}

my_connection_t init_connection(void)
{
    my_connection_t conn;

    reset_connection(&conn);
    return conn;
}

int handle_connection(my_server_t *server, my_client_t *client)
{
    return 0;
}

/**
 * @brief Handles upcoming connections to the server
 *
 * @param[my_server_t *] server the server to handle connections of
 * @return -1 on error, 0 otherwise
 */
int accept_connections(my_server_t *server)
{
    my_client_t client = init_client();
    pid_t pid = PARENT_PID;

    client.conn.fd = accept(server->conn.fd, (struct sockaddr *)&(client.conn.addr), NULL);
    pid = fork();
    switch (pid) {
    case -1:
        perror("fork");
        return -1;
    case 0:
        display_connection_info(client);
        return close(client.conn.fd);
    default:
        server->clients.
        return 0;
    }
}
