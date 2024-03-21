/*
 * =====================================================================================
 *
 *       Filename:  my_web.h
 *
 *    Description:  Type and function declarations related to my HTTP server
 *
 *        Version:  1.0
 *        Created:  20/03/2024 09:12:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef MY_SERVER_H
#define MY_SERVER_H

#include <arpa/inet.h>
#include <netinet/in.h>

/* *********** Server *********** */

typedef struct my_server {
    struct sockaddr_in *addr;
    int fd;
} my_server_t;

int cleanup_server(my_server_t *server);
int bind_and_listen(my_server_t *server, int port, char const *ip);
my_server_t *init_server(void);

/* ********** Signals *********** */

int setup_signal_handling();

/* *********** Connection *********** */

int handle_connections(my_server_t *server);

#endif /* MY_SERVER_H */
