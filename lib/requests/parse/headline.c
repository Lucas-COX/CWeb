/*
 * =====================================================================================
 *
 *       Filename:  headline.c
 *
 *    Description:  Utility functions for parsing HTTP request headline
 *
 *        Version:  1.0
 *        Created:  22/04/2024 12:35:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <requests.h>

#include <stdlib.h>
#include <string.h>

int request_parse_headline(request_t *request, char const *line)
{
    char *buff = strdup(line);
    char *method = strtok(buff, " ");
    char *route = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    if (!strcmp(method, "GET"))
        request->method = GET;
    if (!strcmp(method, "POST"))
        request->method = POST;
    if (!strcmp(method, "PUT"))
        request->method = PUT;
    if (!strcmp(method, "DELETE"))
        request->method = DELETE;
    request->route = strdup(route);
    request->version = strdup(version);
    free(buff);
    return 0;
}
