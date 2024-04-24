/*
 * =====================================================================================
 *
 *       Filename:  request.c
 *
 *    Description:  Basic functions for manipulating request_t objects
 *
 *        Version:  1.0
 *        Created:  22/04/2024 12:16:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "map/map.h"
#include <requests.h>

#include <stdlib.h>
#include <string.h>

void request_destroy(request_t *request)
{
    if (!request)
        return;
    if (request->version)
        free(request->version);
    if (request->route)
        free(request->route);
    map_destroy(request->attributes);
    free(request);
}

request_t *request_init(void)
{
    request_t *request = malloc(sizeof(request_t));

    memset(request, 0, sizeof(request_t));
    request->attributes = map_init();
    return request;
}

