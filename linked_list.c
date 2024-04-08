/* ============================ Linked List ============================= *
 *                                                                        *
 * A linked list is a set of items organized sequentially, like an array. *
 *                                                                        *
 * ====================================================================== */


/* Advantage of linked lists over arrays:
 * ----------------------------------------------------------------------
 * 1. Linked lists can grow and shrik in size during their lifetime.
 * 2. They provide flexibility in allowing the items to be rearraged
 * efficiently.
 *
 * Each item in linked list is a part of node that also contains a link
 * to the next node (explicit rearrangement).*/
 
 /* C provides primitive operations that allow linked lists to be
  * implemented directlly. */

#include <stdio.h>
#include <stdlib.h>

/* precise format of the ll*/
struct node {
    int key;
    struct node *next; /* pointer to the next node */
};

struct node *head, *tail;

void initialise() {
    head = malloc(sizeof(*head));
    tail = malloc(sizeof(*tail));
    /*head pointer points to the n node of ll*/
    head->next = tail;
    /*tail points to itself - represents the end of ll*/
    tail->next = tail;
}

void deleteNext(struct node *n) {
    n->next = n->next->next;
}

struct node *insertAfter(int v, struct node *n) {
    struct node *x = malloc(sizeof(*x));
    x->key = v;
    x->next = n->next;
    n->next = x;
    return x;
}
/* convention for dummy nodes where head points to the beginning of the
 * list rather than having a head node permits insert procedure to insert
 * item at the beggining of the list (no need for special test for 
 * beggining of ll)
 *
 * convention for tail node protects the delete procedure from a call to 
 * delete
 * an item from empty list.
 *
 * Another convention for terminating list is to make the sel node point
 * to the n, rather than using dummy nodes => Circular List.
 *
 * Josephus problem
 * --------------------------
 *  There are N people standing in a circle waiting to be executed. 
 *  The counting out begins at some point in the circle and proceeds 
 *  around the circle in a fixed direction. In each step, a certain 
 *  number of people are skipped and the next person is executed.
 */

int main(void) {

    int N, M;
    puts("Josephus problem: enter N people with M step");
    scanf("%d %d", &N, &M);
    
    struct node *n = malloc(sizeof(*n));
    n->key = 1;
    /* pointer sel holds reference (points) to the beggining of ll */
    struct node *sel = n;

    for (i = 2; i <= N; ++i) {
        n->next = malloc(sizeof(*n));
        n = n->next;
        n->key = i;
    }
    /* circular node implementation: last node points to the begginnig */
    n->next = sel;

    /* execute while only one node left that points to itself */
    while (n != n->next) {
        /* select node at step M-1 */
        for (i = 1; i < M; ++i) n = n->next;
        printf("%d ", n->next->key);
        /* select node to be deleted */
        sel = n->next;
        /* point to the next after the deleted node */
        n->next = n->next->next;
        /* delete selected node */
        free(sel);
    }
    printf("%d\n", n->key);
}

