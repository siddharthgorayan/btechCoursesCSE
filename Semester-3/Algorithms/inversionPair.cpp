//
//  main.cpp
//  inversionPair
//
//  Created by Siddharth Saini CS19B1024.
//  Copyright © 2020 Siddharth Saini. All rights reserved.
//

#include <iostream>

/* initialize global variable to count Number of Inversions. */
int numberOfInversions = 0;

/* Merge Function to combine the two arrays recursively. */
int merge(int a[], int start, int mid, int end)
{
    int i, j, k, aArrayElements, bArrayElements;
    
    /* number of elements in aArray and bArray after each partition. */
    aArrayElements = mid - start + 1;
    bArrayElements = end - mid;
    
    
    int aArray[aArrayElements];
    int bArray[bArrayElements];
    
    /* adding elements to the new arrays. */
    for(i=0; i<aArrayElements; i++)
    {
        aArray[i] = a[start+i];
    }
    for(j=0; j<bArrayElements; j++)
    {
        bArray[j] = a[mid+1+j];
    }
    
    i = 0;
    j = 0;
    k = start;
    
    /* sorting the two arrays and combing them into one. */
    while(i<aArrayElements && j<bArrayElements)
    {
        if(aArray[i]<=bArray[j])
        {
            a[k] = aArray[i];
            i++;
        }
        else
        {
            a[k] = bArray[j];
            j++;
            
/* when aArray[i] > bArray[j] then A[i] > A[j] and i<j in the original array, for all values in "aArray" except the values at ith index and less than ith index. */
            
            numberOfInversions = numberOfInversions + (aArrayElements-i);
            
        }
        k++;
    }
    
    /* adding all the left values of aArray and bArray in the final sorted array. */
    while (i < aArrayElements)
    {
        a[k] = aArray[i];
        i++;
        k++;
    }
    while (j < bArrayElements)
    {
        a[k] = bArray[j];
        j++;
        k++;
    }
    
    /* returning the Number of Inversions after each call of Merge Function. */
    return numberOfInversions;
}

int mergeSort(int a[], int start, int end)
{
    int mid, numberOfInversions, totalInversions = 0;
    
    if(start<end)
    {
        mid = start + (end - start)/2;
        mergeSort(a, start, mid);
        mergeSort(a, mid+1, end);
        numberOfInversions = merge(a, start, mid, end);
        
        /* Total Inversions sums up all the Inversions in all the calls of Merge Function.*/
        totalInversions = totalInversions + numberOfInversions;
    }
    return totalInversions;
}

int main()
{
    int i,t, totalInversions;
    std::cin >> t;
    int A[t];
    for(i=0; i<t; i++)
    {
        std::cin >> A[i];
    }
    totalInversions = mergeSort(A, 0, t-1);
    std::cout << totalInversions << "\n";
}
