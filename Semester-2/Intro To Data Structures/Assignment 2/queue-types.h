/* Header file that implements structures needed for queues and list data type*/

/* Basic node data type for a linked list*/
struct nodeForQueue {
    int value;
    struct nodeForQueue* next;
    struct nodeForQueue* prev;
};

/* Basic node data type  for a queue*/
struct Queue {
    struct nodeForQueue *front, *end;
};

