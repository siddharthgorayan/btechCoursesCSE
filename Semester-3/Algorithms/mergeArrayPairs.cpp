//
//  main.cpp
//  mergeArrayPairs
//
//  Created by Siddharth Gorayan on 04/10/20.
//  Copyright © 2020 Siddharth Saini. All rights reserved.
//

#include <iostream>

int merge(int aArray[], int bArray[], int sizeA, int sizeB)
{
    int numberOfInversions = 0;
    int i, j, k, aArrayElements, bArrayElements;
    int finalArray[sizeA+sizeB];
    aArrayElements = sizeA;
    bArrayElements = sizeB;
    i = 0;
    j = 0;
    k = 0;
    
    /* sorting the two arrays and combing them into one. */
    while(i<aArrayElements && j<bArrayElements)
    {
        if(aArray[i]<=bArray[j])
        {
            finalArray[k] = aArray[i];
            i++;
              
            /* when aArray[i] <= bArray[j] then A[i] < A[j] and i<j in the original array, for all values in "bArray" except the values at jth index and greater than jth index. */
                        
            numberOfInversions = numberOfInversions + (bArrayElements-j);
            std::cout << "round" << i << ":" << numberOfInversions << "\n";
        }
        else
        {
            finalArray[k] = bArray[j];
            j++;
        }
        k++;
    }
    
    /* adding all the left values of aArray and bArray in the final sorted array. */
    while (i < aArrayElements)
    {
        finalArray[k] = aArray[i];
        i++;
        k++;
    }
    while (j < bArrayElements)
    {
        finalArray[k] = bArray[j];
        j++;
        k++;
    }
    
    /* returning the Number of Inversions after each call of Merge Function. */
    return numberOfInversions;
}

int main()
{
    int aArray[] = {1, 3, 5, 7, 19};
    int bArray[] = {2, 4, 10, 14};
    std::cout << merge(aArray, bArray, sizeof(aArray)/sizeof(aArray[0]), sizeof(bArray)/sizeof(bArray[0])) << "\n";
    
}
