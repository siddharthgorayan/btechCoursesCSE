#include<iostream>
#include<sstream>
#include<iterator>

using namespace std;

/* L: Left Child, R: Right Child, P: Parent, keyis the string of data for the node. */
struct node
{
    string key;
    struct node *L;
    struct node *R;
    struct node *P;
};

/* function to make new node everytime a node has to be inserted in the tree. */
struct node* newNode(string numberPlate)
{
    struct node* newNumberPlate = new node;
    newNumberPlate->key = numberPlate;
    newNumberPlate->L = NULL;
    newNumberPlate->R = NULL;
    newNumberPlate->P = NULL;
    return newNumberPlate;
}

/* String comparison function from the assignment 0, modified a bit to make use of it.*/
int stringComparison(string string1, string string2)
{
    if(string1<string2)
    {
        return 1;
    }
    else if(string1 == string2)
    {
        return 0;
    }
    return 2;
}

struct node* insertNewNumberPlate(struct node* node, string key)
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

struct node* SearchNumberPlate(struct node* node, string key, string path)
{
    struct node *temp = node;
    string paths = path;
    /* base case when there are no nodes and when the node to be searched is not found. */
    if( temp == NULL )
    {
        cout << 0 << "\n";
        return NULL;
    }
    /* When node to be searched is found. */
    else if(stringComparison(key, temp->key)==0)
    {
        cout << 1 << " " << paths << "\n";
        return NULL;
    }
    /* When the node to be found is less than current node, we search in the left half of the tree. */
    else if(stringComparison(key, temp->key)==1)
    {
        paths = paths + "L";
        return SearchNumberPlate(temp->L, key, paths);
    }
    /* When the node to be found is greater than current node, we search in the right half of the tree. */
    else if(stringComparison(key, temp->key)==2)
    {
        paths = paths + "R";
        return SearchNumberPlate(temp->R, key, paths);
    }
    return NULL;
}

int main()
{
    string firstLine;
    string numberPlate;
    char choice;
    int count = 0;
    
    struct node* root = NULL;
    //Fetching only the first line of input.
    getline(cin,firstLine);
    stringstream stringSplitter(firstLine);

    // Parsing the string word by word.
    while(stringSplitter >> numberPlate)
    {
        // Call your BST Insert function here with argument: numberPlate
        // Assigning the root node.
        if(count == 0)
        {
            root = insertNewNumberPlate(NULL, numberPlate);
            count++;
        }
        else
        {
            insertNewNumberPlate(root, numberPlate);
        }
        
    }

    // Main input handler to serve requests.
    while(cin >> choice >> numberPlate)
    {
        if(choice=='S')
        {
            // Call your BST Search function here with argument: numberPlate
            SearchNumberPlate(root, numberPlate, "");
        }
    }
  
    return(0);
}

