/* Assignment 4
   Name: Siddharth Saini
   Roll No: CS19B1024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct adjacencyList
{
    struct node* head;
};

struct graph
{
    int numberOfVertices;
    struct adjacencyList* array;
    bool* visited;
};

struct node
{
    int value;
    struct node* next;
};

struct Queue
{
    struct node *front, *end;
};

/* ---------------------------------------------------------------- */

/* Creates a new node for the queue. */
struct node* newNode(int value)
{
    struct node* new;
    new = (struct node*)malloc(sizeof(struct node));
    
    new->value = value;
    new->next = NULL;
    return new;
}

/* ---------------------------------------------------------------- */

/* Function to create a new graph. */
struct graph* newGraph(int numberOfVertices)
{
    int i;
    struct graph* Graph = (struct graph*)malloc(sizeof(struct graph));
    Graph->numberOfVertices = numberOfVertices;
    
    /* array to store the head vertices of the graph, i.e. "v". */
    Graph->array = (struct adjacencyList*)malloc(numberOfVertices * sizeof(struct adjacencyList));
    
    /* inititalising both the arrays. */
    for(i = 0; i < numberOfVertices; i++)
    {
        Graph->array[i].head = NULL;
    }
    return Graph;
}

/* ---------------------------------------------------------------- */

/* Function to add a new edge in the graph given the starting "u" and ending "v" vertex. */
void newEdge(struct graph* Graph, int vertex_u, int vertex_v)
{
    struct node* new = newNode(vertex_v);
    new->next = Graph->array[vertex_u].head;
    Graph->array[vertex_u].head = new;
    
    /* since the graph is undirected foe the emergency vehicles. */
    new = newNode(vertex_u);
    new->next = Graph->array[vertex_v].head;
    Graph->array[vertex_v].head = new;
}

/* ---------------------------------------------------------------- */

/* Return the size of the Queue. */
int sizeOfQueue(struct Queue* Q)
{
    int count=0;
    struct node* temp;
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
    struct node* temp;
    temp = Q->front;
    while(temp != NULL)
    {
        printf("%d  ",temp->value);
        temp = temp->next;
    }
}

/* ---------------------------------------------------------------- */

/* CREATE_QUEUE: Creates an empty que for the starting of the program. */
struct Queue* createQueue()
{
    struct Queue* queue;
    queue = (struct Queue*)malloc(sizeof(struct Queue));
    
    /* point end and front of the queue to NULL since no node is present in beginning. */
    queue->end = NULL;
    queue->front = NULL;
    return queue;
}

/* ---------------------------------------------------------------- */

/* Function to check whether a Queue is empty or not. */
int isEmpty(struct Queue* Q)
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

/* ENQUEUE: adds an element with value = "value" at the end of the queue. */
void enqueue(struct Queue* Q, int value)
{
    /* creates a new node with next pointed to null, by calling newNode function. */
    struct node* new;
    new = newNode(value);
    
    /* if queue was empty, the new node will be both front and end of the queue. */
    if(isEmpty(Q)==1)
    {
        Q->end = new;
        Q->front = new;
        new->next = NULL;
    }
    
    /* if queue wasn't empty, point the pointers accordingly to make it linked. */
    else
    {
        Q->end->next = new;
        Q->end = new;
        new->next = NULL;
    }
}

/* ---------------------------------------------------------------- */

/* DEQUEUE: deletes an element from the front of the queue. */
int dequeue(struct Queue* Q)
{
    /* if queue is empty, nothing can be dequeued. shows an error and returns NULL. */
    if(isEmpty(Q)==1)
    {
        printf("Queue is empty, nothing to dequeue. \n\n");
    }
    
    else
    {
        int returnValue;
        struct node* temp = NULL;
        
        /* store the data of front node in temp. */
        temp = Q->front;
        
        /* make the node next to the front node as the front node. */
        Q->front = Q->front->next;
        
        /* if queue becomes empty after removing front, make the end also NULL. The queue becomes empty. */
        if(Q->front==NULL)
        {
            Q->end = NULL;
        }
        
        /* copy the value of the dequeued node to return it later */
        returnValue = temp->value;
        
        /* free the space of the dequeued node, */
        free(temp);
        return returnValue;
    }
    return 0;
}

/* ---------------------------------------------------------------- */

/* Function to merge the sorted sublists. */
struct node* merge(struct node* subList1Head, struct node* subList2Head)
{
    /* if any out of the two lists are empty, return the other list. */
    if(subList1Head == NULL)
    {
        return subList2Head;
    }
    else if(subList2Head == NULL)
    {
        return subList1Head;
    }
    else
    {
        struct node* HEAD = NULL;
        
        if(subList1Head->value <= subList2Head->value)
        {
            HEAD = subList1Head;
            HEAD->next = merge(subList1Head->next, subList2Head);
        }
        else
        {
            HEAD = subList2Head;
            HEAD->next = merge(subList1Head, subList2Head->next);
        }
        return HEAD;
    }
}

/* ---------------------------------------------------------------- */

/* Function to split the linkedList in two halves. */
void splitList(struct node* head, struct node** subList1Ref, struct node** subList2Ref)
{
    /* if the length of the sunlists are less than 2 then we can separate this case. */
    if(head == NULL || head->next == NULL)
    {
        *subList1Ref = head;
        *subList2Ref = NULL;
    }
    
    /* else we use slow and fast pointer approach where slow pointer is incremented by one position and fast by 2 positions at a time which guarantees the split into two halves at slow pointer. */
    else
    {
        struct node* slow = head;
        struct node* fast = head->next;
        
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        /* sublist 1 starts at head. */
        *subList1Ref = head;
        
        /* sublist 2 starts at slow->next. */
        *subList2Ref = slow->next;
        
        /* assign the next pointer of the last element od sublist 1 as NULL. */
        slow->next = NULL;
    }
}

/* ---------------------------------------------------------------- */

/* Function to sort linked list with Merge Sort. */
void mergeSort(struct node** head)
{
    /* when list is empty or has only 1 element, it is already sorted. */
    if(*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    
    else
    {
        /* head reference to the two splitted sublists. */
        struct node* subList1;
        struct node* subList2;
        
        /* splitting the lists into two sublists recursively. */
        splitList(*head, &subList1, &subList2);
        
        /* recursively sorting the splitted sublists. */
        mergeSort(&subList1);
        mergeSort(&subList2);
        
        /* merging the two splitted sublists and returning the head pointer. */
        *head = merge(subList1, subList2);
    }
}

/* ---------------------------------------------------------------- */

/* Function to sort the linked list corresponding to each head before we QUEUE them. */
/* I have used Merge Sort to sort the linked lists which take O(nlogn) time which is much less than Bubble Sort.*/
struct graph* sortQueue(struct graph* Graph)
{
    int i;
    
    for(i=0; i<Graph->numberOfVertices; i++)
    {
        mergeSort(&Graph->array[i].head);
    }
    return Graph;
}


/* ---------------------------------------------------------------- */

/* Function for Breadth First Saerch. */
void breadthFirstSearch(struct graph* Graph, int startingVertex)
{
    struct Queue* Q;
    Q = createQueue();
    
    /*  initialising the first vertex as visited. */
    Graph->visited[startingVertex] = 1;
    enqueue(Q, startingVertex);
    
    while (!isEmpty(Q))
    {
        int currVertex;
        currVertex = dequeue(Q);
        
        /* dequeue the vertex and print it. */
        printf("%d ",currVertex);
        
        struct node* temp;
        temp = Graph->array[currVertex].head;
        
        /* enqueue the neighbouring vertices. */
        while(temp)
        {
            int adjacentVertex;
            adjacentVertex = temp->value;
            
            if(Graph->visited[adjacentVertex] == 0)
            {
                Graph->visited[adjacentVertex] = 1;
                enqueue(Q, adjacentVertex);
            }
            temp = temp->next;
        }
    }
    free(Q);
    printf("\n");
}

/* ---------------------------------------------------------------- */

int main()
{
    bool flag = 0;
    int i;
    char choice;
    int numberOfVertices, startVertex, endVertex;
    // Fetching number of vertices
    scanf("%d",&numberOfVertices);
    // Create your adjacency list's array of head vertices here.
    struct graph* Graph;
    Graph = newGraph(numberOfVertices);
   
    while(scanf(" %c",&choice)!=-1)
    {
        if(choice == 'N')
        {
            char delimiter;
            scanf("%d", &startVertex);
            while(scanf("%d%c", &endVertex, &delimiter))
            {
                // Add the edge (startVertex, endVertex) to your graph here.
                newEdge(Graph, startVertex, endVertex);
                if(delimiter == '\n')
                {
                    break; // Detecting end of line.
                }
            }
        }
        else if(choice == 'B')
        {
            /* sorting the queues. */
            if(flag == 0)
            {
                sortQueue(Graph);
                flag = 1;
            }
            
            scanf("%d",&startVertex);
            
            /* array to track whether a vertex is visited or not during traversal. */
            Graph->visited = malloc(numberOfVertices * sizeof(bool));
            
            /* Initialising the Visited array again with 0 for next execution. */
            for(i=0; i<Graph->numberOfVertices; i++)
            {
                Graph->visited[i] = 0;
            }
            
            // Call BFS on your graph starting from startVertex here. }
            breadthFirstSearch(Graph, startVertex);
            free(Graph->visited);
        }
    }
    return 0;
}

