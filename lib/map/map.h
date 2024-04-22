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

#endif /* MAP_H_ */
