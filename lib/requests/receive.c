/*
 * =====================================================================================
 *
 *       Filename:  requests/receive.c
 *
 *    Description:  Read the content of an HTTP request
 *
 *        Version:  1.0
 *        Created:  27/03/2024 11:49:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (),
 *   Organization:  
 *
 * =====================================================================================
 */

#include <requests.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int request_receive(request_t *request, FILE *sock)
{
    char *data = malloc(MAX_LINE_SIZE);
    size_t len = MAX_LINE_SIZE;
    ssize_t n_read = 0;

    while (sock && (n_read = getline(&data, &len, sock)) != -1) {
        if (!strcmp(data, "\r\n")) {
            break;
        }
        if (request_parse(request, data, n_read) < 0) {
            printf("An error occured.\n");
            break;
        }
    }
    free(data);
    return 0;
}
