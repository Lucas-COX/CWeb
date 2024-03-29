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

/* *********** Macros *********** */

#define CHILD_PID 0
#define CLOSED_FD -1
#define ERROR_PID -1
#define MAX_CONNECTIONS 10

/* *********** Typedefs *********** */

typedef struct my_client my_client_t;
typedef struct my_connection my_connection_t;
typedef struct my_server my_server_t;

/* *********** Connections *********** */

struct my_connection {
    struct sockaddr_in addr;
    int fd;
};

my_client_t *accept_connections(my_server_t *server);
void reset_connection(my_connection_t *conn);
my_connection_t init_connection(void);
int handle_connection(UNUSED my_server_t *server, my_client_t *client);

/* *********** Client *********** */

struct my_client {
    my_connection_t conn;
    pid_t pid;
};

my_client_t *init_client(void);

/* *********** Server *********** */

struct my_server {
    my_connection_t conn;
    llist_t *clients;
};

int cleanup_server(my_server_t *server);
int bind_and_listen(my_server_t *server, int port, char const *ip);
int run_server(my_server_t *server);
my_server_t *init_server(void);

/* ********** Signals *********** */

int setup_signal_handling();

#endif /* MY_SERVER_H */
