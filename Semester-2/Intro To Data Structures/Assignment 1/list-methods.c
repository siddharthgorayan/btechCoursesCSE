#include "list-types.h"
#include <stdio.h>
#include <stdlib.h>

/* Returns number of elements in the list, given pointer to head  */
int size(node* head) {
  int count=0;
  node* current = head;
  while(current!=NULL){
    count++;
    current = current->next;
  }
  return count;
}

/* Prints list data elements in order, separated by a single space */
void print_list(node* head) {
  node* curr = head;
  while(curr!=NULL) {
    printf("%d ",curr->data);
    curr=curr->next;
  }
  printf("\n");
}

/* Returns 1 if list is empty, 0 if not */
int is_empty(node* head) {
  if(head==NULL)
    return 1;
  else return 0;
}


/* Returns pointer to the last element in the list */
node* get_last(node* head) {
  node* curr=head;
  if(curr==NULL) { //if empty list
    return NULL;
  }

  while(curr->next!=NULL) {
    curr= curr->next;
  }
  return curr;
}

/* Inserts a node with given value into the list before head.
Returns pointer to new head (which is the node inserted) */
node* insert_at_start(node* head, int value) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = value;
    new_node->next = head;
    return new_node; // return pointer to newly inserted node.
}

/* Implement the other functions specified in list-interface below this line  */

/* ------------------------------------------------------------------------------------------------- */

/* Search for the given data key. Prints Not Found if the element isn't present and Found if it is present.
 */
node* search_list(node* head, int key) {
    if(head==NULL)                                /*    if not found after traversing the  whole list. */
    {
        printf("Not Found.\n");
    }
    else if(head->data == key)                    /*    else if it is found. */
    {
        printf("Found.\n");
    }
    else
    {
        search_list(head->next, key);             /*    else, call the function recursively. */
    }
    return head;
}

/* ------------------------------------------------------------------------------------------------- */

/* Delete the node pointed to by position.
 Return the NEXT node in the list (NULL if position is the last node)
 */

/* Need to send the position pointer while callling this function in the main function, as argument. */
node* delete_node(node* head, node* position) {
    node* current = head;                          /*   store head in current. */
    node* curPrev = head;                          /*   store head in curPrev to use the previous pointer to current later. */
    if(position==head)                             /*   since head can't be changed in the main function, we do it by copying. */
    {
        *(head) = *(head->next);
        free(head->next);
    }
    else
    {
        while(current!=position)                   /*   in cases where position is not head. */
        {
            curPrev = current;
            current = current->next;
        }
        free(current);
        curPrev->next = current->next;
        if(current->next == NULL)
        {
            return NULL;                           /*   if next to deleted node is NULL. */
        }
    }
    return current->next;
}

/* ------------------------------------------------------------------------------------------------- */

/* inserts a new node with data key to be at position place_num in the list .
If place_num is larger than listlength +1, prints "Error" and returns NULL
Else, returns pointer to the newly inserted node.
 */
node* insert_kth(node* head, int key, int place_num) {
    node* current = head;                          /*   store head in current. */
    node* curPrev = head;                          /*   store head in curPrev to use the previous pointer to current later. */
    int count=0;
    if(place_num > size(head)+1 || place_num < 1)
    {
        printf("Error! \n");
        return NULL;
    }
    else
    {
        if(place_num == 1)                         /*   since head can't be changed in the main function, we do it by copying. */
        {
            struct node* newNode = (struct node*) malloc(sizeof(struct node));
            *(newNode) = *(head);                  /*   copies newNode in head. */
            head->data = key;                      /*  puts key in the head data, i.e. positions it on 1. */
            newNode->next = head->next;
            head->next = newNode;
            return head;
        }
        else
        {
            while(count!=place_num-1)              /* current is assigned to place_num and curPrev to place_num-1 after this loop. */
            {
                count++;
                curPrev = current;
                current = current->next;
            }
            struct node* newNode = (struct node*) malloc(sizeof(struct node));
            newNode->data = key;
            newNode->next = current;
            curPrev->next = newNode;
            return newNode;
        }
    }
}

/* ------------------------------------------------------------------------------------------------- */

/* Delete entire list */
void delete_list(node* head) {
    node* current = head;
    while(head!=NULL)                              /*   till all the elements are deleted. */
    {
        free(head);
        head = current->next;
        current = head;
    }
    if(head==NULL)
    {
        printf("List Deleted");                    /*   since we can't return anything, so we print here. */
    }
}
 
/* ------------------------------------------------------------------------------------------------- */

/* Print the elements in the list in reverse order */
void print_reverse_order(node* head) {
    if(head==NULL)
    {
        return;
    }
    else
    {
        print_reverse_order(head->next);           /* traverse the list by recursion and starts printing from end. */
        printf("%d ", head->data);
    }
}

/* ------------------------------------------------------------------------------------------------- */

/* Rotate the list by a number k. E.g. list = 1,2,3,4,5. rotate_list(2) will make
the new list (4,5,1,2,3). Returns pointer to new head of list.
  */

/* Need to call the value of head in main function. */

node* rotate_list(node*head, int k) {
    node* current = head;
    int count=1;
    if(k==0)
    {
        return head;
    }
    else
    {
        while(count<k && current!=NULL)            /* Current reached the kth position at the end of this loop. */
        {
            current = current->next;
            count++;
        }
        if(current==NULL)
        {
            return head;
        }
        else
        {
            node* kNode = current;                 /* point kNode to the current, i.e. actually kth node. */
            while(current->next!=NULL)             /* current points to the last node at the end of this loop. */
            {
                current = current->next;
            }
                current->next = head;              /* change the pointer next to the last(current) node to head. */
                head = kNode->next;                /* change hed pointer to the node next to kth node. */
                kNode->next = NULL;                /* change the pointer next to kth node to NULL. */
        }
    }
    return head;
}

/* ------------------------------------------------------------------------------------------------- */

/* Reverses the list. Returns pointer to new head */
node* reverse_list(node* head) {
    node* prev = NULL;                             /* point the prev pointer to NULL. */
    node* current = head;                          /* point the current pointer to head. */
    node* next = NULL;                             /* pont the next pointer too NULL. */
    
    while(current!=NULL)
    {
        next = current->next;                      /* point next to the next node of current */
        current->next = prev;                      /* Reverse the pointer of current node. */
        
                                                   /* move pointers one-one position ahead */
        
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

/* ------------------------------------------------------------------------------------------------- */
