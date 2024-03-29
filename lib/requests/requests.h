#ifndef REQUESTS_H
#define REQUESTS_H

/* *********** Macros *********** */

#define MAX_REQUEST_SIZE 262144

/* *********** Typedefs *********** */

typedef struct request request_t;
typedef enum request_type request_type_t;

/* *********** Request *********** */

enum request_type { GET, POST, PUT, DELETE };

struct request {
    request_type_t type;
};

request_t *request_read(int fd);

#endif /* REQUESTS_H */