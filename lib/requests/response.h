/*
 * =====================================================================================
 *
 *       Filename:  response.h
 *
 *    Description:  Declarations for the HTTP response object and utility functions
 *
 *        Version:  1.0
 *        Created:  25/04/2024 12:41:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef RESPONSE_H_
#define RESPONSE_H_

/* ********** Macros *********** */

#define HTTP_STATUS_LINE_SIZE 14

/* ********** Typedefs *********** */

typedef struct response response_t;

/* ********** Response *********** */

struct response {
    int code;
    char *data;
};

response_t *response_init(void);
void response_destroy(response_t *response);
char *response_write(response_t *response);

#endif /* RESPONSE_H_ */
