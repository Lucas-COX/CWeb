#ifndef LLIST_H_
#define LLIST_H_

#include <stdbool.h>
#include <sys/types.h>

#define UNUSED __attribute__((unused))

/* *********** Typedefs *********** */

typedef struct llist llist_t;
typedef struct llist_node llist_node_t;

/* *********** Llist ************ */

struct llist {
    u_int16_t n_elem;
    llist_node_t *head;
};

void llist_destroy(llist_t *list);
llist_t *llist_init(void);
void *llist_get(llist_t *list, int i);
void llist_push(llist_t *list, void *p);
void *llist_pop(llist_t *list);
void *llist_remove_by_p(llist_t *list, void *p);

/* *********** Llist node *********** */

struct llist_node {
    void *p;
    llist_node_t *next;
};

void llist_node_destroy(llist_node_t *node);
llist_node_t *llist_node_init(void *p);

#endif /* LLIST_H_ */
