#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue-interface.h"

/* The condition when Queue is empty is taken care while calling the functions in main function in queue-test.c .*/

/* Some basic functions used in the implementation of the program. These functions are declared in the main function, since we can't declare them in interface file.  */


/* Creates a new node for the queue. */
struct nodeForQueue* newNode(int value)
{
    struct nodeForQueue* new;
    new = (struct nodeForQueue*)malloc(sizeof(struct nodeForQueue));
    
    new->value = value;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

/* ---------------------------------------------------------------- */

/* Return the size of the Queue. */
int sizeOfQueue(struct Queue* Q)
{
    int count=0;
    struct nodeForQueue* temp;
    temp = Q->front;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

/* ---------------------------------------------------------------- */

/* Prints the queue */
void printQueue(struct Queue* Q)
{
    struct nodeForQueue* temp;
    temp = Q->front;
    while(temp != NULL)
    {
        printf("%d  ",temp->value);
        temp = temp->next;
    }
}

/* ---------------------------------------------------------------- */
/* ---------------------------------------------------------------- */

/* Functions to be implemented as a part of Assignment. */


/* CREATE_QUEUE: Creates an empty que for the starting of the program. */
struct Queue* create_Queue()
{
    struct Queue* queue;
    queue = (struct Queue*)malloc(sizeof(struct Queue));
    
    /* point end and front of the queue to NULL since no node is present in beginning. */
    queue->end = NULL;
    queue->front = NULL;
    return queue;
}

/* ---------------------------------------------------------------- */

/* ENQUEUE: adds an element with value = "value" at the end of the queue. */
void enqueue(struct Queue* Q, int value)
{
    /* creates a new node with next and prev pointed to null, by calling newNode function. */
    struct nodeForQueue* new;
    new = newNode(value);
    
    /* if queue was empty, the new node will be both front and end of the queue. */
    if(is_empty(Q)==1)
    {
        Q->end = new;
        Q->front = new;
        new->prev = NULL;
        new->next = NULL;
    }
    
    /* if queue wasn't empty, point the pointers accordingly to make it doubly linked. */
    else
    {
        Q->end->next = new;
        new->prev = Q->end;
        Q->end = new;
        new->next = NULL;
    }
}

/* ---------------------------------------------------------------- */

/* DEQUEUE: deletes an element from the front of the queue. */
int dequeue(struct Queue* Q)
{
    /* if queue is empty, nothing can be dequeued. shows an error and returns NULL. */
    if(is_empty(Q)==1)
    {
        printf("Queue is empty, nothing to dequeue. \n\n");
    }
    
    else
    {
        int returnValue;
        struct nodeForQueue* temp = NULL;
        
        /* store the data of front node in temp. */
        temp = Q->front;
        
        /* make the node next to the front node as the front node. */
        Q->front = Q->front->next;
        
        /* if queue becomes empty after removing front, make the end also NULL. The queue becomes empty. */
        if(Q->front==NULL)
        {
            Q->end = NULL;
        }
        
        /* make the prev of the new front node as NULL. */
        else
        {
            Q->front->prev = NULL;
        }
        
        /* copy the value of the dequeued node to return it later */
        returnValue = temp->value;
        
        /* free the space of the dequeued node, */
        free(temp);
        return returnValue;
    }
    return INT_MAX ;
}

/* ---------------------------------------------------------------- */

/* IS_empty: returns 1 if empty, 0 if not empty */
int is_empty(struct Queue* Q)
{
    if(Q->front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* ---------------------------------------------------------------- */

/* TOP: Returns a pointer to the top node of the queue. */
int top(struct Queue* Q)
{
    return Q->front->value;
}

/* ---------------------------------------------------------------- */

/* CLONE_QUEUE: This operation will copy over an entire queue and return a pointer to the new queue. */
struct Queue* clone_queue(struct Queue* Q)
{
    /* create a new empty queue. */
    struct Queue* newQueue;
    newQueue = create_Queue();
    
    /* create "new" pointer to make new nodes in loop. */
    /* create temp to traverse the queue and copy data. */
    struct nodeForQueue* new;
    struct nodeForQueue* temp;
    temp = Q->front;
    
    /* makes the first node as the front and last initially, if there's only one node. */
    new = newNode(Q->front->value);
    newQueue->front = new;
    newQueue->end = new;
    
    /* temp traverse the loop and copies data to newQueue. */
    while(temp->next != NULL)
    {
        temp = temp->next;
        new = newNode(temp->value);
        
        /* point the pointers accordingly to make double linked. */
        new->prev = newQueue->end;
        new->next = NULL;
        new->prev->next = new;
        newQueue->end = new;
    }
    return newQueue;
}

/* ---------------------------------------------------------------- */

/* SORT_QUEUE: This operation sorts the queue; with the minimum element at the front of the queue. */
struct Queue* sort_queue(struct Queue* Q)
{
   
    int i,j;
         
    /* temp is used to traverse through the loop. */
    /* min is used to store the minimum value after each iteration. */
    struct nodeForQueue* temp;
    struct nodeForQueue* min;

    /* the minimum values are pushed to the front after consecutive enqueue and dequeue. */
    for(i=1; i<=sizeOfQueue(Q); i++)
    {
        /* min and temp are initialised to the first node everytime. */
        temp = Q->front;
        min = Q->front;
    
        /* traverses from the front node to the prev of sorted nodes. */
        for(j=1; j<sizeOfQueue(Q)-i+1; j++)
        {
            temp = temp->next;
            
            /* replaces the min with temp if temp<min */
            if(temp->value < min->value)
            {
                min = temp;
            }
        }
        
        /* inserts min-value at the end of the queue. */
        enqueue(Q, min->value);
        
        /* cpoies frond-node-value to the min-value. */
        min->value = Q->front->value;
        
        /* deletes the front node. */
        dequeue(Q);
    }
    return Q;
}

/* ---------------------------------------------------------------- */

/* PLAY_QUEUE: Returns the position of the player who is seeker. */
int play_queue(struct Queue* Q, int k)
{
    /* if queue has only one element, that will be the seeker. */
    if(Q->front == Q->end)
    {
        return 1;
    }
    
    else
    {
        int i;
        struct nodeForQueue* temp;
        
        /* clone the queue and store positions in its values. */
        struct Queue* newQueue = clone_queue(Q);
        temp = newQueue->front;
        for(i=1; i<=sizeOfQueue(Q); i++)
        {
            temp->value = i;
            temp = temp->next;
        }
        
        /* make the queue circular. */
        newQueue->end->next = newQueue->front;
        newQueue->front->prev = newQueue->end;
        
        /* temp traverses the queue till only one element is left. */
        temp = newQueue->front;
        while(1)
        {
            /* traverse the queue till the kth point every time. */
            for(i=1; i<k; i++)
            {
                temp = temp->next;
            }
            
            /* if only one element is left, return its position. */
            if(temp->prev->next == temp->next)
            {
                return temp->value;
            }
            
            /* otherwise delete the kth node everytime.*/
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                
                /* make the next node as the starting point. */
                temp = temp->next;
            }
        }
    }
}

/* ---------------------------------------------------------------- */

/* REMOVE_DUPLICATES: Removes duplicates and returns a Queue pointer to the modified queue. */
struct Queue* remove_duplicates(struct Queue* Q)
{
    struct nodeForQueue* temp;
    struct nodeForQueue* check;
    struct nodeForQueue* store;
    
    /* temp starts from the front node and moves to the next once check has traversed thorough the queue. */
    for(temp = Q->front; temp!=NULL; temp = temp->next)
    {
        
        /* check traverses through the queue for each value of temp. */
        for(check = temp->next; check!=NULL; check = check->next)
        {
            /* stores the duplicate in store. */
            if(temp->value == check->value)
            {
                store = check;
                
                /* change the prev pointer of duplicate to next pointer of duplicate.*/
                check->prev->next = check->next;
                
                /* if the duplicate is not the last node of queue, change the pointers.*/
                if(check->next!=NULL)
                {
                    check->next->prev = check->prev;
                    
                }
                
                /* if duplicate is last node, then make the prev of duplicate as last node. */
                else
                {
                    Q->end = check->prev;
                }
                store = NULL;
            }
        }
    }
    free(temp);
    free(store);
    return Q;
}

/* ---------------------------------------------------------------- */
/* ---------------------------------------------------------------- */

