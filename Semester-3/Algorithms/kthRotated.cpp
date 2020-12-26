//
//  main.cpp
//  kthRotated
//  Question:

/*  The input is a sorted array of n distinct numbers that has been right-rotated k steps, for an unknown integer k between 1 and n−1. That is, A[1,2,...,k] and A[k + 1, . . . , n] are in increasing order, with A[n] < A[1].
    An example is the sequence 10,14,17,24,25,3,4,7 where n = 8 and k = 3.
    Describe an algorithm that to find the unknown value of k, given an input array of the form described above. */
//
//  Created by Siddharth Gorayan on 04/10/20.
//  Copyright © 2020 Siddharth Saini. All rights reserved.
//

#include <iostream>

int kthRotated(int A[], int start, int end)
{
    if(end<start)
    {
        return 0;
    }
    else if(end==start)
    {
        return start;
    }
    else
    {
        int mid;
        mid = (end+start)/2;
        if(A[mid+1] < A[mid])
        {
            return mid+1;
        }
        else if (A[mid] < A[mid-1])
        {
            return mid;
        }
        else if(A[mid]<A[end])
        {
            return kthRotated(A, start, mid-1);
        }
        else
        {
            return kthRotated(A, mid+1, end);
        }
    }
    
}

int main()
{
    int A[] = {30, 10, 14, 17, 24, 25};
    std::cout << kthRotated(A, 1, sizeof(A)/sizeof(A[0]));
    return 0;
}
