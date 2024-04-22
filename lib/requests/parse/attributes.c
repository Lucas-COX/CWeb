/*
 * =====================================================================================
 *
 *       Filename:  attributes.c
 *
 *    Description:  Parse HTTP request attributes
 *
 *        Version:  1.0
 *        Created:  22/04/2024 14:04:17
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

/**
 * @brief Parse the attributes of an HTTP request
 *
 * @param[request_t *] request Request to fill with the attributes
 * @param[char consst *] line Line containing an attribute
 * @return 0 on success, -1 otherwise
 */
int request_parse_attributes(request_t *request, char const *line)
{
    char *buff = strdup(line);
    char *key = strtok(buff, ": ");
    char *value = strtok(NULL, "\r\n");

    map_insert(request->attributes, key, value);
    free(buff);
    return 0;
}

