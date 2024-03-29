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

request_t *request_read(int fd)
{
    char data[MAX_REQUEST_SIZE];

    printf("Max request size is %d\n", MAX_REQUEST_SIZE);
    return NULL;
}