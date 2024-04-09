/* ===================== Linked List with Arrays =+====================== *
 *                                                                        
 * Using a parallel arrays where items are kept in key array and the links
 * in an next array.
 *                                                                       
 * ====================================================================== */

/* the advantage of ussing parallel arrays is the the structure can be build
 * on top of the data: the array key contains data and only data - all the 
 * structure is in the parallel array next. */

#include <stdio.h>

#define MAX 5

char key[MAX+2], next[MAX+2];
int head, z;
int x; // next unused position

void initialise(void) {
    head = 0, z = 1, x = 2;
    next[head] = z;
    next[z]    = z;

}

void deleteNext(int after) {
    /* int after is position of element after which initiate delete */
    next[after] = next[next[after]];
}

int insertafter(int val, int after) {
    key[x] = val; // setting free position with val in key array
    /* setting free position in next array with new link */
    next[x] = next[after];
    /* updating existing link */
    next[after] = x;
    /* resturn next free position */
    return ++x;
}

int main(void) {
    initialise();
    /* insert these after head */
    insertafter('S', 0);
    insertafter('L', 0);
    insertafter('A', 0);
    /* insert after L (witch is 3) */
    insertafter('I', 3);
    insertafter('T', 2);

    for (int i = 0; i < (MAX+2); ++i) 
        printf("%c::%d\n", key[i], next[i]);

    int j = 0;
    int test = MAX;
    printf("%c\n", key[next[j]]);
    while (--test) {
        j = next[j];
        printf("%c\n", key[next[j]]);
    }
    return 0;
}
