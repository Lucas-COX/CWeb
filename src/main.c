/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main function for my HTTP server
 *
 *        Version:  1.0
 *        Created:  20/03/2024 09:12:08
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
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int exited = 0;

/**
 * @brief Displays server info when it starts
 *
 * @param[my_server_t] server the server that started
 */
void display_server_info(my_server_t *server)
{
    char addr[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(server->conn.addr.sin_addr), addr, INET_ADDRSTRLEN);
    printf("Running on %s:%d\n", addr, ntohs(server->conn.addr.sin_port));
    printf("Accepting connections.\n");
}

int main(void)
{
    my_server_t *server = init_server();

    if (bind_and_listen(server, 8080, "127.0.0.1")) {
        cleanup_server(server);
        return EXIT_FAILURE;
    }
    display_server_info(server);
    if (setup_signal_handling() < 0) {
        perror("failed to setup signal handling");
        cleanup_server(server);
        return EXIT_FAILURE;
    }
    while (!exited) {
        accept_connections(server);
    }
    cleanup_server(server);
    return 0;
}
