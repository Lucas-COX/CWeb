/*
 * =====================================================================================
 *
 *       Filename:  llist_node.c
 *
 *    Description:  Library for manipulating linked lists
 *
 *        Version:  1.0
 *        Created:  25/03/2024 14:53:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (),
 *   Organization:  
 *
 * =====================================================================================
 */

#include <llist.h>

#include <stdlib.h>

/**
 * @brief Destroy a node and the pointer it contains
 *
 * @param[llist_node_t *] node The node to be destroyed
 */
void llist_node_destroy(llist_node_t *node)
{
    if (node && node->p)
        free(node->p);
    if (node)
        free(node);
}

/**
 * @brief Allocates memory and returns an empty node
 *
 * @return The created node, or NULL on error
 */
llist_node_t *llist_node_init(void *p)
{
    llist_node_t *node = malloc(sizeof(llist_node_t));

    node->next = NULL;
    node->p = p;
    return node;
}