/*
Assignment 2
Roll Number: CS19B1024
Name: Siddharth Saini

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char key[7];
    struct node *L;
    struct node *R;
    struct node *P;
};

struct node* pred1 = NULL;
struct node* succ1 = NULL;

/* function to make new node everytime a node has to be inserted in the tree. */
struct node* newNode(char numberPlate[])
{
    struct node* newNumberPlate = (struct node*)malloc(sizeof(struct node));
    strcpy(newNumberPlate->key, numberPlate);
    newNumberPlate->L = NULL;
    newNumberPlate->R = NULL;
    newNumberPlate->P = NULL;
    return newNumberPlate;
}

/* String comparison function from the assignment 0, modified a bit to make use of it.*/
int stringComparison(char string1[], char string2[])
{
    int i = 0;
    while(string1[i] == string2[i] && string1[i] != '\0')
    {
        i++;
    }
    if(string1[i] < string2[i])
    {
        return 1;
    }
    else if(string1[i] > string2[i])
    {
        return 2;
    }
    return 0;
}

struct node* insertNewNumberPlate(struct node* node, char key[])
{
    /* If there are no nodes in the tree, the node to be inserted is the root node. */
    if(node == NULL)
    {
        return newNode(key);
    }
    /* if the node to be inserted is less than the parent node, we insert it in left half of the tree. */
    else if(stringComparison(key, node->key)==1)
    {
        node->L = insertNewNumberPlate(node->L, key);
        node->L->P = node;
    }
    /* if the node to be inserted is greater than the parent node, we insert it in right half of the tree. */
    else if(stringComparison(key, node->key)==2)
    {
        node->R = insertNewNumberPlate(node->R, key);
        node->R->P = node;
    }
    return node;
}

char* SearchNumberPlate(struct node* node, char key[])
{
    struct node* temp = node;
    char* path = (char*)malloc(5*sizeof(char));
    
    if(node == NULL)
    {
        return "0";
    }
    strcat(path, "1 ");
    while(temp!=NULL && stringComparison(temp->key, key)!=0)
    {
        if(strlen(path)+2%(sizeof(*path)/sizeof(char))==0)
        {
            path = realloc(path, sizeof(path)*2);
        }
        if(stringComparison(key, temp->key) == 2)
        {
            temp = temp->R;
            strcat(path, "R");
        }
        else
        {
            temp = temp->L;
            strcat(path, "L");
        }
    }
    if(temp == NULL)
    {
        free(path);
        return "0";
    }
    return path;
}

/* used to find the minimum value of node in the right subtree. */
struct node* minValueOfTree(struct node* node)
{
    while(node->L)
    {
        node = node->L;
    }
    return node;
}

/* used to find maximum value of node in left subtree. */
struct node* maxValueOfTree(struct node* node)
{
    while(node->R)
    {
        node = node->R;
    }
    return node;
}

/* funtion to find the successor. */
void successor(struct node* root, char numberPlate[], struct node* succ)
{
    if(root == NULL)
    {
        return;
    }
    
    else if(stringComparison(root->key, numberPlate)==0)
    {
        if(root->R != NULL)
        {
           succ1 = minValueOfTree(root->R);
        }
    }
    
    else if(stringComparison(root->key, numberPlate)==2)
    {
        succ1 = root;
        successor(root->L, numberPlate, succ1);
    }
    else
    {
        successor(root->R, numberPlate, succ1);
    }
}

/* function to find the predecessor. */
void predecessor(struct node* root, char numberPlate[], struct node* pred)
{
    if(root == NULL)
    {
        return;
    }

    else if(stringComparison(root->key, numberPlate)==0)
    {
        if(root->L != NULL)
        {
            pred1 = maxValueOfTree(root->L);
        }
    }
    
    else if(stringComparison(root->key, numberPlate)==2)
    {
        predecessor(root->L, numberPlate, pred1);
    }
    else
    {
        pred1 = root;
        predecessor(root->R, numberPlate, pred1);
    }
}

int main()
{
    char choice = '\0', numberPlate[7];
    
    _Bool requests = 0;
    int count = 0;
    struct node* root = NULL;
    
    // Fetching till we hit the first request
    while(scanf("%s",numberPlate)!=-1)
    {
        if(!requests)
        {
            if(strlen(numberPlate) == 1)
        { // Detecting start of request lines.
            choice = numberPlate[0];
            requests = 1;
        }
            else
            {
                // *** Call your insert function here with argument numberPlate ***
                if(count == 0)
                {
                    root = insertNewNumberPlate(root, numberPlate);
                    count++;
                }
                else
                {
                    insertNewNumberPlate(root, numberPlate);
                }
            }
        }
        else break; // choice and numberPlate have values to be processed!!
    }
      
    do
    { // Ugly do-while to process first request line before first scanf.
        if(choice == 'S')
        {
            char* path = SearchNumberPlate(root, numberPlate);
            //*** Call your search function here with argument numberPlate ***
            path = SearchNumberPlate(root, numberPlate);
            printf("%s\n", path);
        }
        else if(choice == '<')
        {
            //*** Call your predecessor function here with argument numberPlate ***
            predecessor(root, numberPlate, pred1);
            if(pred1 == NULL)
            {
                printf("0\n");
            }
            else
            {
                printf("%s\n", pred1->key);
                pred1 = NULL;
            }
        }
        else if(choice == '>')
        {
            //*** Call your successor function here with argument numberPlate ***
            successor(root, numberPlate, succ1);
            if(succ1 == NULL)
            {
                printf("0\n");
            }
            else
            {
                printf("%s\n", succ1->key);
                succ1 = NULL;
            }
        }
    }
        while(scanf("%*[\n]%c %6s",&choice, numberPlate)!=-1);
    
    return(0);
}
