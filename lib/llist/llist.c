/*
 * =====================================================================================
 *
 *       Filename:  llist.c
 *
 *    Description:  Library for manipulating linked lists
 *
 *        Version:  1.0
 *        Created:  25/03/2024 9:18:33
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
 * @brief Destroys the given list
 *
 * @param[llist_t *] list The list to destroy
 */
void llist_destroy(llist_t *list)
{
    llist_node_t *node = NULL;

    if (!list)
        return;
    while (list->head) {
        node = list->head;
        list->head = node->next;
        list->destr ? llist_node_destroyf(node, list->destr) : llist_node_destroy(node);
    };
    free(list);
}

/**
 * @brief Creates an empty list and allocated memory
 * for it.
 *
 * @return The created list
 */
llist_t *llist_init(void)
{
    llist_t *list = malloc(sizeof(llist_t));

    list->head = NULL;
    list->n_elem = 0;
    list->destr = NULL;
    return list;
}

/**
 * @brief Returns the element at the given index
 *
 * @param[llist_t *] list First node of the list
 * @param[int] i Index of the element to search for
 *
 * @return The found element, or NULL
 */
void *llist_get(llist_t *list, int i)
{
    llist_node_t *head = list->head;

    for (int n = 0; n < list->n_elem && n < i; n++, head = head->next);
    return head ? head->p : NULL;
}

/**
 * @brief Adds an element at the end of the list
 *
 * @param[llist_t *] list The list to add the element to
 * @param[void *] p The element to add
 */
void llist_push(llist_t *list, void *p)
{
    llist_node_t *head = NULL;

    if (list->head == NULL) {
        list->head = llist_node_init(p);
        list->n_elem = 1;
        return;
    }
    head = list->head;
    for (; head->next; head = head->next);
    head->next = llist_node_init(p);
    list->n_elem += 1;
}

/**
 * @brief Removes the last element from the list and returns it
 *
 * @param[llist_t *] list The list to remove the element from
 * @return void* The element, or NULL if the list is empty
 */
void *llist_pop(llist_t *list)
{
    llist_node_t *head = list->head;
    void *p = NULL;

    if (list->head == NULL || list->n_elem == 0)
        return NULL;
    if (list->n_elem == 1) {
        p = head->p;
        free(head);
        list->head = NULL;
        return p;
    }
    for (int i = 0; i < list->n_elem - 1; i++, head = head->next);
    p = head->next->p;
    free(head->next);
    head->next = NULL;
    return p;
}

/**
 * @brief Remove a list element searching by the pointer it contains
 *
 * @param[llist_t *] list List to remove the element from
 * @param[void *] p The pointer to look for
 * @return The element that got removed
 */
void *llist_remove_by_p(llist_t *list, void *p)
{
    llist_node_t *node = list->head;
    llist_node_t *next = NULL;
    void *value = NULL;

    if (node->p == p) {
        list->head = node->next;
        value = node->p;
        free(node);
        list->n_elem--;
        return value;
    }
    for (; node->next && node->next->p != p; node = node->next);
    if (node->next) {
        value = node->next->p;
        next = node->next;
        node->next = node->next->next;
        free(next);
        list->n_elem--;
    }
    return value;
}
