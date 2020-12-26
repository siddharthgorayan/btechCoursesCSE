//  Created by Siddharth Saini CS19B1024.
//  Copyright © 2019 Siddharth Saini. All rights reserved.
//

#include <stdio.h>
char brd[3][3];
   struct move                                                                      //defining a structure to let the values of row and column returned
   {
       int row, col;
   };
char human = 'X', comp = 'O';
//----------------------------------------------------
bool leftPos( char brd[3][3]);
int resultCheck(char brd[3][3]);
move bestSel(char brd[3][3]);
void dispGame(char brd[3][3]);
int max(int x, int y);
int min(int x, int y);
int posClash(char brd[3][3]);
int minimax(char brd[3][3] , int depth , bool Max, int alpha, int beta, int node);
//----------------------------------------------------
int main()                                                                          //main function
{
    move bestMove = bestSel(brd);
    char brd[3][3];
    int chse, result, i, j;
    printf("\n\nTIC TAC TOE \n\n");                                                 //display head
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            brd[i][j]=' ';                                                          //initialising board to empty
        }
    }
    dispGame(brd);
    printf("\n");
    printf("Choose who want to play first: \nYou(1) or Computer(2)?:\n ");          //asking the user for choosing the first turn
    scanf("%d",&chse);
    while(result != +100 && result != -100 && leftPos(brd)==true)
    {
        if(chse == 1 )                                                              //if user chose to go first, this happens
        {
            printf("\nIt's your turn: \nChoose the coordinates: \n");               //asking for coordinates from 0 to 2
            scanf("%d%d", &i, &j);
            if(brd[i][j]==' ')                                                      //checking if the chosen position is empty
            {
                brd[i][j] = human;                                                  //assigning the entered coordinate as X
                printf("\n");
                dispGame(brd);                                                      //calling function to display board
                printf("\n");
                result = resultCheck(brd);                                          //calculating result value from the function
                if(result == -100)
                {
                    printf("\nYou Won!\n");
                    break;
                }
                else if(result == +100)
                {
                    printf("\nComputer Won!\n");
                    break;
                }
                else if(leftPos(brd)==false)
                {
                    printf("\nThere's a tie.\n");
                    break;
                }
                
                printf("Computer's Turn: \n\n");                                    //giving turn to computer after human has taken his turn
                bestMove = bestSel(brd);                                            //calling the function to get the coordinates of bestmove
                brd[bestMove.row][bestMove.col] = comp;                             //assigning the coordinates of bestmove to O (Computer)
                printf("\n");
                dispGame(brd);
                printf("\n");
                result = resultCheck(brd);                                          //checking the result again
                if(result == -100)
                {
                    printf("\nYou Won!\n");
                    break;
                }
                else if(result == +100)
                {
                    printf("\nComputer Won!\n");
                    break;
                }
                else if(leftPos(brd)==false)
                {
                    printf("\nThere's a tie\n");
                    break;
                }
            }
            else                                                                   //for invalid moves
            {
                if(i>2 || j>2)                                                     //if chosen coordinated doesn't exist
                {
                    printf("\nWarning: Invalid Selection. \nTry Again!\n\n");
                    posClash(brd);
                }
                else                                                               //if chosen coordinate is already occupied
                {
                    printf("\nWarning: You can't choose an already selected box! \nTry Again! \n");
                    posClash(brd);
                }
            }
            
           
        }
        else if (chse == 2)                                                        //if user chooses computer for the first turn
        {
            printf("Computer's Turn: \n\n");                                       //computer goes first and the rest remains the same
            bestMove = bestSel(brd);
            brd[bestMove.row][bestMove.col] = comp;
            printf("\n");
            dispGame(brd);
            printf("\n");
            result = resultCheck(brd);
            if(result == -100)
            {
                printf("\nYou Won!\n");
                break;
            }
            else if(result == +100)
            {
                printf("\nComputer Won!\n");
                break;
            }
            else if(leftPos(brd)==false)
            {
                printf("\nThere's a tie.\n");
                break;
            }
            
            printf("It's your turn: \nChoose the coordinates: \n");
            scanf("%d%d", &i, &j);
            if(brd[i][j]==' ')
            {
                brd[i][j] = human;
                printf("\n");
                dispGame(brd);
                printf("\n");
                result = resultCheck(brd);
                if(result == -100)
                {
                    printf("\nYou Won!\n");
                    break;
                }
                else if(result == +100)
                {
                    printf("\nComputer Won!\n");
                    break;
                }
                else if(leftPos(brd)==false)
                {
                    printf("\nThere's a tie.\n");
                    break;
                }
            }
             else
                {
                    if(i>2 || j>2)
                    {
                        printf("\nWarning: Invalid Selection. \nTry Again!\n\n");
                        posClash(brd);
                    }
                    else
                    {
                        printf("\nWarning: You can't choose an already selected box! \nTry Again! \n");
                        posClash(brd);
                    }
                }
        }
    }
}

//---------------------------------------------------------------------------------------------

bool leftPos( char brd[3][3])                                                      //function to check whether any position is left on the board or not
{
    int i, j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(brd[i][j]==' ')
            {
                return true;                                                       //returns true if there's some space on board and game can be continued
            }
        }
    }
    return false;                                                                  //else returns false which means the game has a draw or win
}

//----------------------------------------------------------------------------------------------

int resultCheck(char brd[3][3])                                                    //function to check the result
{
    int row, col;
    for(row=0 ; row<3 ; row++)                                                     //testing for the rows if filled completely
    {
        if(brd[row][0]==brd[row][1] && brd[row][1]==brd[row][2])
        {
            if(brd[row][0]==human)
            {
                return -100;                                                       //returns -100 if human wins
            }
            else if(brd[row][0]==comp)
            {
                return +100;                                                       //returns +100 if computer wins
            }
        }
    }
    for(col=0 ; col<3 ; col++)                                                     //testing for the columns if filled completely
    {
        if(brd[0][col]==brd[1][col] && brd[1][col]==brd[2][col])
        {
            if(brd[0][col]==human)
            {
                return -100;
            }
            else if(brd[0][col]==comp)
            {
                return +100;
            }
        }
    }
    if(brd[0][0]==brd[1][1] && brd[1][1]==brd[2][2] )                              //testing for the diagonal 1 if filled completely
    {
        if(brd[0][0] == human)
        {
            return -100;
        }
        else if(brd[0][0]==comp)
        {
            return +100;
        }
    }
    if(brd[0][2]==brd[1][1] && brd[1][1]==brd[2][0])                                //testing for the diagonal 2 if filled completely
    {
        if(brd[0][2] == human)
        {
            return -100;
        }
        else if(brd[0][2]==comp)
        {
            return +100;
        }
    }
    return 0;                                                                       //returns 0 by default which means game continues
}

//-----------------------------------------------------------------------------------------------

int minimax(char brd[3][3] , int depth , bool Max, int alpha, int beta, int node)   //function to test for all possible moves and choose the best move
{
    int score, i, j;
    score = resultCheck(brd);                                                       //checking the score
    if(score == 100)
    {
        return score;
    }
    if(score == -100)
    {
        return score;
    }
    if(leftPos(brd)==false)
    {
        return 0;
    }
    
    if(Max)                                                                         //if computer has a turn i.e. maximising player
    {
        int best = -1000;                                                           //initialised with -1000 so that the function always works
        for(i=0 ; i<3 ; i++)
        {
            for(j=0 ; j<3 ; j++)
            {
                if(brd[i][j]==' ')
                {
                    brd[i][j] = comp;                                               //assigning the position to computer and finding all the possible boards
                    best = max(best,minimax(brd, depth+1, !Max, alpha, beta,  node*2+i));   //finding maximum out of best and minimax to maximise utility
                    brd[i][j]=' ';                                                  //undoing the move
                    alpha = max(alpha, best);                                       //alpha beta pruning
                    if(beta<=alpha)                                                 //if this happen, we don't need to go forward as all will have same utility
                    {
                        break;                                                      //breaks and comes out of the loop
                    }
                }
            }
        }
        return best;
    }
    else                                                                            //if human has a turn i.e. minimising player
    {
        int best = +1000;                                                           //initialised with +1000 so that the function always works
        for(i=0 ; i<3 ; i++)
        {
            for(j=0 ; j<3 ; j++)
            {
                if(brd[i][j]==' ')
                {
                    brd[i][j] = human;                                              //assigning the position to human and finding all the possible boards
                    best = min(best,minimax(brd, depth+1, !Max, alpha, beta,  node*2+i));   //finding minimum out of best and minimax to minimise utility
                    brd[i][j]=' ';
                    alpha = min(alpha, best);
                    if(beta<=alpha)
                    {
                        break;
                    }
                   
                }
            }
        }
        return best;                                                                //returning best everytime so that it can go back to minimax
    }
}

//-----------------------------------------------------------------------------------------------

move bestSel(char brd[3][3])                                                       //function to return the coordinates for the best move
{
    int i,j, bestVal = -1000, moveVal;                                             //assigning bestVal to -1000 so that the condition goes true for the first time
    move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           if(brd[i][j]==' ')
           {
               brd[i][j] = comp;                                                  //assigning the best coordinates to the computer
               moveVal = minimax(brd , 0 , false, -1000, +1000, 0);               //calling minimax function to choose the best move outof all possible boards
               brd[i][j] = ' ';
               if(moveVal > bestVal)                                              //if current value is better than best, assign current value to the bestVal
               {
                   bestMove.row = i;                                              //assigning the row
                   bestMove.col = j;                                              //and the column
                   bestVal = moveVal;
               }
           }
        }
    }
    return bestMove;                                                              //returning the structure of coordinates
}

//-----------------------------------------------------------------------------------------------

void dispGame(char brd[3][3])                                                     //function to display the board
{
int i;
for(i=0;i<3;i++)
{
    printf("\n       |       |       \n");
    printf("   %c   |   %c   |   %c   ",brd[i][0],brd[i][1], brd[i][2]);
    printf("\n       |       |       ");
           
    if(i!=2)
    {
       
        printf("\n-------|-------|-------");
       
    }
}
printf("\n");
}

//-----------------------------------------------------------------------------------------------

int max(int x, int y)                                                              //function to find the maximum used in the minimax
{
   if(x > y)
   {
       return x;
   }
   else
   {
       return y;
   }
}

//------------------------------------------------------------------------------------------------

int min(int x, int y)                                                              //function to find the minimum in the minimax
{
   if(x < y)
   {
       return x;
   }
   else
   {
       return y;
   }
}

//------------------------------------------------------------------------------------------------

int posClash(char brd[3][3])                                                       //function to be called when there is a position clash on the board
{
    move bestMove = bestSel(brd);
    int chse, result, i, j;
    printf("\nIt's your turn: \nChoose the coordinates: \n");
    scanf("%d%d", &i, &j);
    if(brd[i][j]==' ')
    {
        brd[i][j] = human;
        printf("\n");
        dispGame(brd);
        printf("\n");
        result = resultCheck(brd);
        if(result == -100)
        {
            printf("\nYou Won!\n");
        }
        else if(result == +100)
        {
            printf("\nComputer Won!\n");
        }
        else if(leftPos(brd)==false)
        {
            printf("\nThere's a tie.\n");
        }
        
        printf("Computer's Turn: \n\n");
        bestMove = bestSel(brd);
        brd[bestMove.row][bestMove.col] = comp;
        printf("\n");
        dispGame(brd);
        printf("\n");
        result = resultCheck(brd);
        if(result == -100)
        {
            printf("\nYou Won!\n");
        }
        else if(result == +100)
        {
            printf("\nComputer Won!\n");
        }
        else if(leftPos(brd)==false)
        {
            printf("\nThere's a tie.\n");
        }
    }
      else
        {
            if(i>2 || j>2)
            {
                printf("\nWarning: Invalid Selection. \nTry Again!\n\n");
                posClash(brd);
            }
            else
            {
                printf("\nWarning: You can't choose an already selected box! \nTry Again! \n");
                posClash(brd);
            }
        }
    return 0;
}

//------------------------------------------------------------------------------------------------
    

