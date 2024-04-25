/*
 * =====================================================================================
 *
 *       Filename:  requests.h
 *
 *    Description:  HTTP Request delaration and utils
 *
 *        Version:  1.0
 *        Created:  25/04/2024 13:58:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef REQUESTS_H
#define REQUESTS_H

#include <map/map.h>

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

/* *********** Macros *********** */

#define MAX_LINE_SIZE 4096

/* *********** Typedefs *********** */

typedef enum request_method request_method_t;

typedef struct request request_t;

/* *********** Request *********** */

enum request_method { GET, POST, PUT, DELETE };

struct request {
    size_t size;
    uint16_t lines;
    char *route;
    char *version;
    request_method_t method;
    map_t *attributes;
};

void request_destroy(request_t *request);
request_t *request_init(void);
int request_receive(request_t *request, FILE *sock);

/* *********** Parse *********** */

int request_parse(request_t *request, char const *line, ssize_t n_read);
int request_parse_attributes(request_t *request, char const *line);
int request_parse_headline(request_t *request, char const *line);

#endif /* REQUESTS_H */
