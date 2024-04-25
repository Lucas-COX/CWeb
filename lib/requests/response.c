/*
 * =====================================================================================
 *
 *       Filename:  response.c
 *
 *    Description:  HTTP response utility functions
 *
 *        Version:  1.0
 *        Created:  25/04/2024 13:59:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <response.h>

#include <stdio.h>
#include <stdlib.h>

response_t *response_init(void)
{
    response_t *response = malloc(sizeof(response_t));

    response->data = malloc(2);
    response->data[0] = 'H';
    response->data[1] = '\0';
    response->code = 200;
    return response;
}

void response_destroy(response_t *response)
{
    if (!response)
        return;
    if (response->data)
        free(response->data);
    free(response);
}

char *response_write(response_t *response)
{
    char *buff = malloc(HTTP_STATUS_LINE_SIZE);
    
    sprintf(buff, "HTTP/1.1 %d\n", response->code);
    return buff;
}
