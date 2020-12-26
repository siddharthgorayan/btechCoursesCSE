#include<stdio.h>
#include<stdlib.h>
#include "queue-interface.h"

/* Declaring the additional functions which shouldn't be declared in interface file. */

/* Adds a new node. */
struct nodeForQueue* newNode(int value);

/* Return the size of the Queue. */
int sizeOfQueue(struct Queue* Q);

/* Prints the queue */
void printQueue(struct Queue* Q);

/* ---------------------------------------------------------------- */

int main()
{
    /* Test for create_Queue function. */
    struct Queue* Q;
    Q = create_Queue();
    enqueue(Q, 10);
    
    /* Test for initial function. */
    printf("The size of the queue is: %d \n",sizeOfQueue(Q));
    printf("The Queue is: \nFront---  ");
    printQueue(Q);
    printf("---End\n\n");
    
    /* Enqueue and Dequeue functions can work even if the list is empty, so it goes here. */
    
    /* Test for dequeue function. + Twst for the sizeOfQueue function. */
    dequeue(Q);
    printf("The New size of the queue after DEQUEUE is: %d \n",sizeOfQueue(Q));
    printf("The New Queue after DEQUEUE is: \nFront---  ");
    printQueue(Q);
    printf("---End\n\n");
    
    /* Test for enqueue function. */
    enqueue(Q, 20);
    enqueue(Q, 50);
    enqueue(Q, 70);
    enqueue(Q, 30);
    enqueue(Q, 20);

    printf("The New size of the queue after ENQUEUE is: %d \n",sizeOfQueue(Q));
    printf("The New Queue after ENQUEUE is: \nFront---  ");
    printQueue(Q);
    printf("---End\n\n");
    
    /* Functions which work when queue is empty goes here. */
    if(is_empty(Q)==0)
    {
        
        /* Test for top function. */
        printf("The TOP of the queue is: %d \n\n",top(Q));

        /* Test for clone_queue function. */
        struct Queue* newQueue = clone_queue(Q);
        printf("The CLONED QUEUE is: \nFront---  ");
        printQueue(newQueue);
        printf("---End\n\n");

        /* Test for sort_queue function. */
        sort_queue(Q);
        printf("The SORTED QUEUE is: \nFront---  ");
        printQueue(Q);
        printf("---End\n\n");
        
        /* Test for play_queue function. */
        printf("The POSITION of the SEEKER is: %d\n\n",play_queue(Q, 6));
        
        /* Test for removing duplicates from the Queue. */
        remove_duplicates(Q);
        printf("The Queue after REMOVING DUPLICATES is: \nFront---  ");
        printQueue(Q);
        printf("---End\n\n");
    }
    
    /* If the queue is empty, don't call the functions and show an error! */
    else
    {
        printf("The Queue is Empty.\nAdd some elements in it.\n\n");
        printf("TOP of the queue doesn't exist. \n");
        printf("No elements in the queue to CLONE. \n");
        printf("No elements in the queue to SORT. \n");
        printf("No players in the queue to find the POSITION of SEEKER. \n");
        printf("No elements in the queue to REMOVE DUPLICATES. \n");
    }
    return 0;
}


