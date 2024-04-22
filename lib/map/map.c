/*
 * =====================================================================================
 *
 *       Filename:  map.c
 *
 *    Description:  Map utility functions
 *
 *        Version:  1.0
 *        Created:  22/04/2024 15:28:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <map.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *map_get(map_t *map, char const *key)
{
    int i = 0;

    for (; i < map->len && strcmp(map->keys[i], key); i++);
    return i >= map->len ? NULL : map->values[i];
}

int map_insert(map_t *map, char const *key, char const *value)
{
    map->keys = realloc(map->keys, (map->len + 1) * sizeof(char *));
    map->values = realloc(map->values, (map->len + 1) * sizeof(char *));
    map->keys[map->len] = strdup(key);
    map->values[map->len] = strdup(value);
    map->len++;
    return 0;
}

void map_destroy(map_t *map)
{
    if (!map)
        return;
    for (int i = 0; i < map->len; i++) {
        free(map->keys[i]);
        free(map->values[i]);
    }
    if (map->keys)
        free(map->keys);
    if (map->values)
        free(map->values);
}

map_t *map_init(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->keys = NULL;
    map->values = NULL;
    return map;
}

