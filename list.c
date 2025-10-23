//Daniel Guerrero
//W00427795

#include "list.h"
#include <stdlib.h>
// No additional headers required

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL) return NULL;
    struct ll_node *node = head;
    while (node->next != NULL) {
        node = node->next;
    }
    return node;
}

/**
 * TODO: Describe what the function does
 */
int ll_size(struct ll_node *head) {
    if (head == NULL) return 0;
    int count = 0;
    struct ll_node *node = head;
    while (node != NULL) {
        ++count;
        node = node->next;
    }
    return count;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    if (head == NULL) return NULL;
    struct ll_node *node = head;
    while (node != NULL) {
        if (node->data == value) return node;
        node = node->next;
    }
    return NULL;
}

/**
 * TODO: Describe what the function does
 */
int *ll_toarray(struct ll_node *head) {
    if (head == NULL) return NULL;
    int size = ll_size(head);
    if (size == 0) return NULL;
    int *arr = (int*)malloc(sizeof(int) * size);
    if (arr == NULL) return NULL;
    struct ll_node *node = head;
    int i = 0;
    while (node != NULL) {
        arr[i++] = node->data;
        node = node->next;
    }
    return arr;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_create(int data) {
    struct ll_node *n = (struct ll_node*)malloc(sizeof(struct ll_node));
    if (n == NULL) return NULL;
    n->data = data;
    n->next = NULL;
    return n;
}

/**
 * TODO: Describe what the function does
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *node = head;
    while (node != NULL) {
        struct ll_node *next = node->next;
        free(node);
        node = next;
    }
}

/**
 * TODO: Describe what the function does
 */
void ll_append(struct ll_node *head, int data) {
    if (head == NULL) return;
    struct ll_node *tail = ll_tail(head);
    if (tail == NULL) return; 
    struct ll_node *n = ll_create(data);
    if (n == NULL) return;
    tail->next = n;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if (data == NULL || len <= 0) return NULL;
    struct ll_node *head = NULL;
    struct ll_node *tail = NULL;
    for (int i = 0; i < len; ++i) {
        struct ll_node *n = ll_create(data[i]);
        if (n == NULL) {
            ll_destroy(head);
            return NULL;
        }
        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }
    return head;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    if (head == NULL) return NULL;

    // If head needs removal
    if (head->data == value) {
        struct ll_node *newhead = head->next;
        free(head);
        return newhead;
    }

    struct ll_node *prev = head;
    struct ll_node *cur = head->next;
    while (cur != NULL) {
        if (cur->data == value) {
            prev->next = cur->next;
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    return head; // value not found
}

