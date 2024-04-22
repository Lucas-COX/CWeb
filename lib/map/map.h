/*
 * =====================================================================================
 *
 *       Filename:  map.h
 *
 *    Description:  Map definitions
 *
 *        Version:  1.0
 *        Created:  22/04/2024 15:29:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef MAP_H_
#define MAP_H_

#include <stdint.h>

/* *********** Typedefs *********** */

typedef struct map map_t;

/* *********** Maps *********** */

struct map  {
    char **keys;
    char **values;
    uint16_t len;
};

map_t *map_init(void);
char *map_get(map_t *map, char const *key);
int map_insert(map_t *map, char const *key, char const *value);
void map_destroy(map_t *map);

#endif /* MAP_H_ */
