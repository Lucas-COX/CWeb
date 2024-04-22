/*
 * =====================================================================================
 *
 *       Filename:  parse.c
 *
 *    Description:  Parsing utilities for request library
 *
 *        Version:  1.0
 *        Created:  22/04/2024 11:04:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <requests.h>

/**
 * @brief Parse an HTTP request line and emply the given request
 * object.
 *
 * @param[request_t *] request Pointer to the request object
 * @param[char const *] line Line to be parsed and emplied
 * @return -1 on error, 0 otherwise
 */
int request_parse(request_t *request, char const *line, ssize_t n_read)
{
    if (request->lines == 0)
        request_parse_headline(request, line);
    else
        request_parse_attributes(request, line);
    request->lines++;
    request->size += n_read;
    return 0;
}

