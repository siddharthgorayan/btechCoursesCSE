//
//  main.cpp
//  kthRoot
//
//  Created by Siddharth Saini CS19B1024.
//  Copyright © 2020 Siddharth Saini. All rights reserved.
//

#include <iostream>

/* function to find out the power raised to k. */
unsigned long long int raiseToPower(unsigned long long int mid, unsigned long long int k)
{
    unsigned long long int returnValue;
    
    /* anything raise to power 0 is 1. */
    if(k == 0)
    {
        return 1;
    }
    
    /* recursively divide the exponent by 2 untill it becomes zero. */
    returnValue = raiseToPower(mid, k/2);
    
    /* if exponent is even, we square the result. */
    if(k%2 == 0)
    {
        return returnValue * returnValue;
    }
    
    /* if exponent is odd, we multiply the square of the result with mid. */
    else
    {
        return mid * returnValue * returnValue;
    }
}

/* main function to find the kth root of n, */
unsigned long long int kthRootOfN(unsigned long long int start, unsigned long long int end, unsigned long long int n, unsigned long long int k)
{
    if (start<=end)
    {
        unsigned long long int mid;
        mid = (start+end)/2;
        
        /* if mid raise to power k is less(when it's not perfect root) / equal(when it is perfect root) than n AND mid+1 raise to power k is greater than n, we have got the kth root of n. */
        if((raiseToPower(mid, k) <= n) && (raiseToPower(mid+1, k) > n))
        {
            return mid;
        }
        
        /* if mid raise to power k is less than n, we take the mid of the right half. */
        else if (raiseToPower(mid, k) < n)
        {
            return kthRootOfN(mid+1, end, n, k);
        }
        
        /* if mid raise to power k is greater than n, we take the mid of the left half. */
        else
        {
            return kthRootOfN(start, mid-1, n, k);
        }
    }
    return start;
}

int main()
{
    unsigned long long int n, k;
    int i,t;
    std::cin >> t;
    unsigned long long int A[t];
    for(i=0; i<t; i++)
    {
        std::cin >> n;
        std::cin >> k;
        
        /* Since n<= 10^16, even long long int is not sufficient to hold some values for n raise to power k.
         So we reduce the range of binary search by assigning the upper bound as 10^(ceil(16/k)). */
        
        A[i] = kthRootOfN(0, raiseToPower(10, 16/k + (16%k!=0) ), n, k);
        
    }
    for(i=0; i<t; i++)
    {
        std::cout << A[i] << "\n";
    }
    return 0;
}
