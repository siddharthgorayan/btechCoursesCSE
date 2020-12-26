/* Assignment 5
   Name: Siddharth Saini
   Roll No: CS19B1024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <math.h>

int INFINITY = 99999;

struct adjacencyList
{
    struct node* head;
};

struct graph
{
    int numberOfVertices;
    struct adjacencyList* array;
};

struct node
{
    int value;
    int length;
    struct node* next;
};

struct heapNode
{
    int value;
    int length;
};

struct minimumHeap
{
    int currSize;
    int* position;
    struct heapNode** array;
};

/* ---------------------------------------------------------------- */

/* Creates a new node. */
struct node* newNode(int value, int length)
{
    struct node* new;
    new = (struct node*)malloc(sizeof(struct node));
    
    new->value = value;
    new->next = NULL;
    new->length = length;
    
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
    
    /* inititalising the array. */
    for(i = 0; i < numberOfVertices; i++)
    {
        Graph->array[i].head = NULL;
    }
    return Graph;
}

/* ---------------------------------------------------------------- */

/* Function to add a new edge in the graph given the starting "u" and ending "v" vertex and weight = 'length'. */
void newEdge(struct graph* Graph, int vertex_u, int vertex_v, int length)
{
    struct node* new = newNode(vertex_v, length);
    
    new->next = Graph->array[vertex_u].head;
    Graph->array[vertex_u].head = new;
}

/* ---------------------------------------------------------------- */

/* Function to create a new minimumHeap. */
struct minimumHeap* newMinimumHeap(int noOfVertices)
{
    struct minimumHeap* minHeap = (struct minimumHeap*)malloc(sizeof(struct minimumHeap));
    
    /* this array stores the indices of all the nodes in the heap. */
    minHeap->position = (int*)malloc(noOfVertices * sizeof(int));
    minHeap->currSize = 0;
    
    /* this array stores all the nodes of the heap in the form of array. */
    minHeap->array = (struct heapNode**)malloc(noOfVertices * sizeof(struct heapNode*));
    return minHeap;
}

/* ---------------------------------------------------------------- */

/* Finction to create new heapNode. */
struct heapNode* newHeapNode(int value, int length)
{
    struct heapNode* newNode = (struct heapNode*)malloc(sizeof(struct heapNode));
    newNode->value = value;
    newNode->length = length;
    return newNode;
}

/* ---------------------------------------------------------------- */

/* Function to swap two heap Nodes. */
void swapHeapNode(struct heapNode** node1, struct heapNode** node2)
{
    struct heapNode* temp;
    temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

/* ---------------------------------------------------------------- */

/* Function to heapify the heap. */
void heapify(struct minimumHeap* minHeap, int index)
{
    int minIndex, leftIndex, rightIndex;
    leftIndex = 2 * index + 1;
    rightIndex = 2 * index + 2;
    
    /* condition include both the cases when weight are same and less. */
    if(leftIndex < minHeap->currSize && minHeap->array[leftIndex]->length <= minHeap->array[index]->length)
    {
        /* this condition is to break the tie between the veritces having same weights. */
        if(minHeap->array[leftIndex]->length == minHeap->array[index]->length)
        {
            if(minHeap->array[leftIndex]->value < minHeap->array[index]->value)
            {
                minIndex = leftIndex;
            }
            else
            {
                minIndex = index;
            }
        }
        else
        {
            minIndex = leftIndex;
        }
    }
    else
    {
        minIndex = index;
    }
    
    /* condition include both the cases when weight are same and less. */
    if(rightIndex < minHeap->currSize && minHeap->array[rightIndex]->length <= minHeap->array[minIndex]->length)
    {
        /* this condition is to break the tie between the veritces having same weights. */
        if(minHeap->array[rightIndex]->length == minHeap->array[minIndex]->length)
        {
            if(minHeap->array[rightIndex]->value < minHeap->array[minIndex]->value)
            {
                minIndex = rightIndex;
            }
            else
            {
                minIndex = minIndex;
            }
        }
        else
        {
            minIndex = rightIndex;
        }
    }
    
    if(minIndex != index)
    {
        /* store the minNode and indexNode. */
        struct heapNode* minNode = minHeap->array[minIndex];
        struct heapNode* indexNode = minHeap->array[index];
        
        /* swap the positions of minNode and indexNode. */
        minHeap->position[minNode->value] = index;
        minHeap->position[indexNode->value] = minIndex;
        
        /* swap the nodes which includes swapping of both length and value of the nodes. */
        swapHeapNode(&minHeap->array[minIndex],&minHeap->array[index]);
        heapify(minHeap, minIndex);
    }
}

/* ---------------------------------------------------------------- */

/* Function to decrease the length assigned to a vertex. */
void decreaseKey(struct minimumHeap* minHeap, int start, int length)
{
    int index, i;
    
    /* store the index of the node whose length is to be updated. */
    index = minHeap->position[start];
    
    /* update the length of the given node. */
    minHeap->array[index]->length = length;
    
    while (index != 0 && minHeap->array[index]->length < minHeap->array[(index-1)/2]->length)
    {
        /* swap the node with the parent node. */
        minHeap->position[minHeap->array[index]->value] = (index - 1)/2;
        minHeap->position[minHeap->array[(index - 1)/2]->value] = index;
        swapHeapNode(&minHeap->array[index], &minHeap->array[(index - 1)/2]);
        index = (index - 1)/2;
    }
    
    /* we call the heapify function again to heapify the heap and break the ties if any. */
    for(i= (minHeap->currSize/2)-1; i>=0; --i)
    {
        heapify(minHeap, i);
    }
}

/* ---------------------------------------------------------------- */

/* Function to extract the node with minimum length from the heap. */
struct heapNode* extractMinimum(struct minimumHeap* minHeap)
{
    if(minHeap->currSize == 0)
    {
        return  NULL;
    }
    else
    {
        /* store the root node and last node. */
        struct heapNode* rootNode = minHeap->array[0];
        struct heapNode* lastNode = minHeap->array[minHeap->currSize - 1];
        
        /* replace the root node with the last node. */
        minHeap->array[0] = lastNode;
        
        /* update the positions of the root node and the last node. */
        minHeap->position[rootNode->value] = minHeap->currSize - 1;
        minHeap->position[lastNode->value] = 0;
        
        minHeap->currSize--;
        heapify(minHeap, 0);
        return rootNode;
    }
}

/* ---------------------------------------------------------------- */

/* Recursive function to print path. */
void printPath(int path[], int endVertex)
{
    if(path[endVertex] == -1)
    {
        return;
    }
    else
    {
        printPath(path, path[endVertex]);
        printf("%d ",endVertex);
    }
}

/* Function for Dijkstras Algorithm. */
void dijkstras(struct graph* Graph, int start, int end)
{
    int i, vertex;
    
    /* create an array to store the lengths of the paths for each node in the heap. */
    int lengthArray[Graph->numberOfVertices];
    
    /* create an array to store the path followed. */
    int path[Graph->numberOfVertices];
    
    /* create a minimum heap with an array to store the nodes of length equal to the number of vertices. */
    struct minimumHeap* minHeap = newMinimumHeap(Graph->numberOfVertices);
    
    /* initialise the length array to INFINITY and update the nodes and their positions in the heap array. */
    for(i= 0; i<Graph->numberOfVertices; i++ )
    {
        lengthArray[i] = INFINITY;
        minHeap->array[i] = newHeapNode(i, lengthArray[i]);
        minHeap->position[i] = i;
    }
    
    /* initialise the starting vertex and assign the length as 0 so that it is picked first in the path. */
    minHeap->array[start] = newHeapNode(start, lengthArray[start]);
    minHeap->position[start] = start;
    lengthArray[start] = 0;
    path[start] = -1;
    decreaseKey(minHeap, start, lengthArray[start]);
    
    /* initialise the size of the heap array when it contains all the nodes = noOfVertices. */
    minHeap->currSize = Graph->numberOfVertices;
    
    /* iterate over the loop untill all the veritces are extracted from the heap, i.e. the length of all veritces is finalised. */
    while(minHeap->currSize != 0)
    {
        /* extract the minimum node from the heap. */
        struct heapNode* minimumNode = extractMinimum(minHeap);
        
        /* if the node extracted is the endVertex then we have reached the end vertex and we don't need to iterate further to find the length of all vertices uselessly. Therefore we break. */
        if(minimumNode->value == end)
        {
            break;
        }
        
        /* store the index  of the minimum node to iterate over all its adjacent vertices. */
        int indexMinNode;
        indexMinNode = minimumNode->value;
       
        struct node* temp = Graph->array[indexMinNode].head;
        
        /* iterate over the adjacent vertices of the extracted node. */
        while(temp != NULL)
        {
            
            vertex = temp->value;
            
            if(minHeap->position[vertex] < minHeap->currSize && lengthArray[indexMinNode] != INFINITY && temp->length + lengthArray[indexMinNode] < lengthArray[vertex])
            {
                lengthArray[vertex] = lengthArray[indexMinNode] + temp->length;
                path[vertex] = indexMinNode;
                decreaseKey(minHeap, vertex, lengthArray[vertex]);
            }
            temp = temp->next;
        }
        
    }
    
    /* if the length of any vertex is still INFINITY, then this vertex is never visited => can't be visited. */
    if(lengthArray[end] == INFINITY)
    {
        printf("-1\n");
    }
    
    /* we print the path followed along with the length of the path. */
    else
    {
        printf("%d %d ", lengthArray[end], start);
        printPath(path, end);
        printf("\n");
    }
    
}

/* ---------------------------------------------------------------- */

int main()
{
    char choice;
    int numberOfVertices, startVertex, endVertex, length;
    // Fetching number of vertices
    scanf("%d",&numberOfVertices);
    // Create your adjacency list's array of head vertices here.
    struct graph* Graph;
    Graph = newGraph(numberOfVertices);
   
    while(scanf(" %c",&choice)!=-1)
    {
        char delimiter;
        if(choice == 'N')
        {
            scanf("%d", &startVertex);
            while(scanf("%d%c%d%c", &endVertex, &delimiter, &length, &delimiter))
            {
                // Add the edge (startVertex, endVertex) to your graph here.
                newEdge(Graph, startVertex, endVertex, length);
                if(delimiter == '\n')
                {
                    break; // Detecting end of line.
                }
            }
        }
        else if(choice == 'D')
        {
            scanf("%d%c%d",&startVertex, &delimiter, &endVertex);
            
            // Call dijkstras on your graph starting from startVertex here. }
            dijkstras(Graph, startVertex, endVertex);
        }
    }
    return 0;
}

