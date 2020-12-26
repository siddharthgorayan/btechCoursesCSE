
/*
Assignment 3
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

/* if flag is 1, BST is empty, otherwise not. */
int flag = 0;

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

/* function to insert a new number plate in the BST. */
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

/* function to search a number plate in the BST and print the path of the searched node. */
struct node* SearchNumberPlate(struct node* node, char key[], char* path)
{
    if(strlen(path)%100==0)
    {
        path = (char*)realloc(path, sizeof(path)+100);
    }
    
    struct node *temp = node;
    /* base case when there are no nodes and when the node to be searched is not found. */
    if( temp == NULL )
    {
        free(path);
        printf("0\n");
    }
    /* When node to be searched is found. */
    else if(stringComparison(key, temp->key)==0)
    {
        printf("1 %s\n", path);
    }
    /* When the node to be found is less than current node, we search in the left half of the tree. */
    else if(stringComparison(key, temp->key)==1)
    {
        strcat(path, "L");
        return SearchNumberPlate(temp->L, key, path);
    }
    /* When the node to be found is greater than current node, we search in the right half of the tree. */
    else if(stringComparison(key, temp->key)==2)
    {
        strcat(path, "R");
        return SearchNumberPlate(temp->R, key, path);
    }
    return NULL;
}

/* used to find the minimum value of node in the tree. */
struct node* minValueOfTree(struct node* node)
{
    while(node->L)
    {
        node = node->L;
    }
    return node;
}

/* used to find maximum value of node in the tree. */
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

/* function to free the nodes of BST. */
struct node* freeTree(struct node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        freeTree(root->L);
        freeTree(root->R);
        free(root);
        return NULL;
    }
}

/* Splice function to splice a node in the BST. */
void splice(struct node* node)
{
    /* if node has 2 children. */
    if( node->L == NULL && node->R == NULL)
    {
        /* if "node" is the last node in the BST. */
        if(node->P == NULL)
        {
            node = NULL;
            free(node);
            flag = 1;
        }
        
        else if(node->P->L == node)
        {
            node->P->L = NULL;
            free(node->P->L);
        }
        else
        {
            node->P->R = NULL;
            free(node->P->R);
        }
    }
    
    /* if node had 1 child (left child) . */
    else if(node->R == NULL)
    {
        if(node->P == NULL)
        {
            strcpy(node->key, node->L->key);
            node->L = node->L->L;
            node->R = node->L->R;
        }
        else if(stringComparison(node->key, node->P->key) == 2)
        {
            node->P->R = node->L;
            node->L->P = node->P;
            node->L = NULL;
        }
        else
        {
            node->P->L = node->L;
            node->L->P = node->P;
            node->L = NULL;
        }
    }
    
    /* if node has 1 child (right child) . */
    else if(node->L == NULL)
    {
        if(node->P == NULL)
        {
            strcpy(node->key, node->R->key);
            node->L = node->R->L;
            node->R = node->R->R;
        }
        else if(stringComparison(node->key, node->P->key) == 2)
        {
            node->P->R = node->R;
            node->R->P = node->P;
            node->R = NULL;
        }
        else
        {
            node->P->L = node->R;
            node->R->P = node->P;
            node->R = NULL;
        }
    }
}

/* function to delete a node from the BST if it exists. */
struct node* deleteNumberPlate(struct node* root, char numberPlate[])
{
    if(root == NULL)
    {
        printf("-1\n");
    }
    
    /* if the root value is less than the numberPlate to be deleted than numberPlate lies in Right Sub-Tree. */
    else if(stringComparison(root->key, numberPlate) == 1)
    {
        deleteNumberPlate(root->R, numberPlate);
    }
    
    /* if the root value is greater than the numberPlate to be deleted than numberPlate lies in Left Sub-Tree. */
    else if(stringComparison(root->key, numberPlate) == 2)
    {
        deleteNumberPlate(root->L, numberPlate);
    }
    
    /* when the numberPlate to be deleted is found. */
    else
    {
        /* if there are no children of the node to be deleted. */
        if(root->L == NULL && root->R == NULL)
        {
            printf("0 \n");
            splice(root);
            free(root);
        }
        
        /* if there is only one child of the node to be deleted. */
        else if(root->R == NULL)
        {
            printf("1 %s\n",root->L->key);
            splice(root);
            
            /* when the node to be deleted is the root node. */
            if(root->P == NULL)
            {
                free(root->L);
            }
            else
            {
                free(root);
            }
        }
        
        else if(root->L == NULL)
        {
            printf("1 %s\n",root->R->key);
            splice(root);
            
            /* when the node to be deleted is the root node. */
            if(root->P == NULL)
            {
                free(root->R);
            }
            else
            {
                free(root);
            }
        }
        
        /* if there are two children of the child to be deleted. */
        else
        {
            struct node* temp = minValueOfTree(root->R);
            printf("2 %s\n",minValueOfTree(root->R)->key);
            splice(minValueOfTree(root->R));
            strcpy(root->key, temp->key);
            free(temp);
        }
    }
    if(flag == 1)
    {
        root = NULL;
    }
    return root;
}

/* function to print the values of BST using inorder traversal. */
void inorderTraversal(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    inorderTraversal(root->L);
    printf("%s ", root->key);
    inorderTraversal(root->R);
}

/* function to print the values of BST using postorder traversal. */
void postorderTraversal(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    postorderTraversal(root->L);
    postorderTraversal(root->R);
    printf("%s ",root->key);
}

int main()
{
    char choice = '\0', numberPlate[7];
    
    _Bool requests = 0;
    flag = 1;
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
                if(flag == 1)
                {
                    root = insertNewNumberPlate(root, numberPlate);
                    flag = 0;
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
    {
        // Ugly do-while to process first request line before first scanf.
        /* function call for searching the node. */
        if(choice == 'S')
        {
            char* path;
            path = (char*)malloc(100*sizeof(char));
            
            SearchNumberPlate(root, numberPlate, path);
        }

        /* function call for predecessor. */
        else if(choice == '<')
        {
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
        
        /* function call for successor. */
        else if(choice == '>')
        {
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
        
        /* printing the elements of BST using inorder traversal. */
        else if(choice == 'I')
        {
            inorderTraversal(root);
            printf("\n");
            
        /* printing the elements of BST using postorder traversal. */
        }
        else if (choice == 'P')
        {
            postorderTraversal(root);
            printf("\n");
        }
        
        /* function call to delete a numberPlate. */
        else if(choice == '-')
        {
            root = deleteNumberPlate(root, numberPlate);
        }
        
        /* funciton call to insert a new numberPlate. */
        else if (choice == '+')
        {
            if(flag == 1)
            {
                root = insertNewNumberPlate(root, numberPlate);
                flag = 0;
            }
            else
            {
                insertNewNumberPlate(root, numberPlate);
            }
        }
    }
        while(scanf("%*[\n]%c %6s",&choice, numberPlate)!=-1);
    
    freeTree(root);
    return(0);
}
