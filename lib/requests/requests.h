#ifndef REQUESTS_H
#define REQUESTS_H

#include <map/map.h>

#include <stdint.h>
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

void request_free(request_t *request);
request_t *request_init(void);
request_t *request_read(int fd);

/* *********** Parse *********** */

int request_parse(request_t *request, char const *line, ssize_t n_read);
int request_parse_attributes(request_t *request, char const *line);
int request_parse_headline(request_t *request, char const *line);

#endif /* REQUESTS_H */
