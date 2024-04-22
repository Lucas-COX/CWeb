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

request_t *request_read(int fd)
{
    char *data = malloc(MAX_LINE_SIZE);
    size_t len = MAX_LINE_SIZE;
    ssize_t n_read = 0;
    FILE *file = fdopen(fd, "r");
    request_t *request = request_init();

    while ((n_read = getline(&data, &len, file)) != -1) {
        if (!strcmp(data, "\r\n")) {
            break;
        }
        if (request_parse(request, data, n_read) < 0) {
            printf("An error occured.\n");
            break;
        }
    }
    free(data);
    fclose(file);
    return request;
}
