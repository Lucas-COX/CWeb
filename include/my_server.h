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

#include <llist/llist.h>
#include <requests/requests.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>

/* *********** Macros *********** */

#define CHILD_PID 0
#define CLOSED_FD -1
#define ERROR_PID -1
#define MAX_CONNECTIONS 10

/* *********** Typedefs *********** */

typedef struct my_client my_client_t;
typedef struct my_connection my_connection_t;
typedef struct my_handler_context my_handler_context_t;
typedef struct my_server my_server_t;

/* *********** Connections *********** */

struct my_connection {
    struct sockaddr_in addr;
    int fd;
    FILE *sock;
};

void reset_connection(my_connection_t *conn);
my_connection_t *init_connection(void);
void *handle_connection(void *params);

/* *********** Client *********** */

struct my_client {
    my_connection_t *conn;
    pthread_t thread;
    bool completed;
};

my_client_t *init_client(void);
my_client_t *accept_connections(my_server_t *server);

/* *********** Handler *********** */

struct my_handler_context {
    request_t *req;
    char *res; // TODO replace this by a response library
    my_client_t *client;
    my_server_t *server;
};

/* *********** Server *********** */

struct my_server {
    my_connection_t *conn;
    llist_t *clients;
};

int cleanup_server(my_server_t *server);
int bind_and_listen(my_server_t *server, int port, char const *ip);
int run_server(my_server_t *server);
my_server_t *init_server(void);

/* ********** Signals *********** */

int setup_signal_handling();

#endif /* MY_SERVER_H */
