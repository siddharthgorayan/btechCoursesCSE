// Name: Siddharth Saini
// Roll No.: CS19B1024
// Assignment 2 Question-1
// Finding the shortest Supersequence.

#include <iostream>
#include <string.h>

std::string shortestSupersequence(std::string string1, std::string string2)
{
    int i, j, len1, len2;
    len1 = (int32_t)string1.length();
    len2 = (int32_t)string2.length();
    
    int matrix[len1+1][len2+1];
    
    for(i=0; i<=len1; i++)
    {
        for(j=0; j<=len2; j++)
        {
            
            /* If first string is empty, the supersequence is the second string. */
            if(i == 0)
            {
                matrix[i][j] = j;
            }
            
            /* If second string is empty, the supersequence is the first string. */
            else if(j == 0)
            {
                matrix[i][j] = i;
            }
            
            /* If the character is same in both the strings, we add that character to the final superseq. */
            else if(string1[i-1] == string2[j-1])
            {
                matrix[i][j] = 1 + matrix[i-1][j-1];
            }
            else
            {
                matrix[i][j] = 1 + std::min(matrix[i-1][j], matrix[i][j-1]);
            }
        }
    }
    
    /* The length of the supersequence is the value in the right bottom most cell of the matrix. */
    int lengthOfSupersequence = matrix[len1][len2];
    std::string finalSupersequence;
    
    /* code to form the supersequence. */
    while(len1>0 && len2>0)
    {
        
        /* if the characters corresponding to the cell in each string are same, we add that character to the supersequence and decrease the length of each string by 1. */
        if(string1[len1-1] == string2[len2-1])
        {
            finalSupersequence.push_back(string1[len1-1]);
            len1--;
            len2--;
            lengthOfSupersequence--;
        }
        
        /* if the top cell has less value than left cell, add the character corresponding to that cell from string 2 to the final super string and move left. */
        else if (matrix[len1-1][len2] > matrix[len1][len2-1])
        {
            finalSupersequence.push_back(string2[len2-1]);
            len2--;
            lengthOfSupersequence--;
        }
        
         /* if the left cell has less value than top cell, add the character corresponding to that cell from string 1 to the final super string and move on the top. */
        else
        {
            finalSupersequence.push_back(string1[len1-1]);
            len1--;
            lengthOfSupersequence--;
        }
    }
    
    /* if the string2 becomes empty, add the rest of the string1 to super string. */
    while(len1>0)
    {
        finalSupersequence.push_back(string1[len1-1]);
        len1--;
        lengthOfSupersequence--;
    }
    
    /* if the string1 becomes empty, add the rest of the string2 to super string. */
    while(len2>0)
    {
        finalSupersequence.push_back(string2[len2-1]);
        len2--;
        lengthOfSupersequence--;
    }
    
    return finalSupersequence;
}

int main()
{
    std::string string1, string2;
    std::cout << "Enter the two strings:\n";
    std::cin >> string1 >> string2;
    std::cout << "The supersequence is: " << shortestSupersequence(string1, string2) << "\n";
    return 0;
}
