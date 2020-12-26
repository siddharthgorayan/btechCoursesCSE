/* Includes queue-types.h header file */
#include "queue-types.h"

/* Creates an empty que for the starting of the program. */
struct Queue* create_Queue(void);

/* adds an element with value = "value" at the end of the queue. */
void enqueue(struct Queue* Q, int value);

/* deletes an element from the end of the queue. */
int dequeue(struct Queue* Q);

/* Returns a pointer to the top node of the queue. */
int top(struct Queue* Q);

/* returns 1 if empty, 0 if not empty */
int is_empty(struct Queue* Q);

/* This operation will copy over an entire queue and return a pointer to the new queue. */
struct Queue* clone_queue(struct Queue* Q);

/* This operation sorts the queue; with the minimum element at the front of the queue. */
struct Queue* sort_queue(struct Queue* Q);

/*  Consider the elements in the queue as a group of friends gathering to play hide-and-seek, and want to decide who is the person who will seek. To do this, they imagine themselves as being in a circle, and start counting from 1...k; 1 being the top of the queue. The k-th person from the start is removed. The count restarts from the next person, and goes around the circle to remove the second person in a similar way. This goes on, until only one person remains, who will be the seeker.
    The above method returns the position of such a person in the queue.
 */
int play_queue(struct Queue* Q, int k);

/* This procedure modifies the queue in-place, and returns a Queue pointer to the modified queue. */
struct Queue* remove_duplicates(struct Queue* Q);
