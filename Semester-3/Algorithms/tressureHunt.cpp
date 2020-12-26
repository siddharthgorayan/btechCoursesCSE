// Name: Siddharth Saini
// Roll No.: CS19B1024
// Assignment 2 Question-2
// Tressure Hunt

#include <iostream>

int main()
{
    int i, j, m, n, maxSum;
    std::cout << "Enter the number of rows and columns: \n";
    std::cin >> m >> n;
    
    /* matrix is used to store the value of each coordinate and sumMatrix is used to store the maxSum of each coordinate if visited. */
    int matrix[m][n], sumMatrix[m][n];

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            std::cout << "Enter the value of matrix[" << i << "][" << j << "]:\n";
            std::cin >> matrix[i][j];
            sumMatrix[i][j] = 0;
        }
    }
    
    sumMatrix[0][-1] = 0;
    
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            /* filling the top row, since the only option is going "Right". */
            if(i == 0)
            {
                sumMatrix[i][j] = sumMatrix[i][j-1] + matrix[i][j];
            }
            
            /* filling the right-most column, since the only option to travel is coming "Down". */
            else if(j == 0)
            {
                sumMatrix[i][j] = sumMatrix[i-1][j] + matrix[i][j];
            }
            /* filling the rest of the cells with max value out of the upper and left cell path. */
            else
            {
                sumMatrix[i][j] = std::max(sumMatrix[i][j-1], sumMatrix[i-1][j]) + matrix[i][j];
            }
        }
    }
    
    /* the maxSum will be obtained at right bottom-most cell as we travelled from (1,1) to (m,n). */
    maxSum = sumMatrix[m-1][n-1];
    
    for(i=0; i<m; i++)
       {
           for(j=0; j<n; j++)
           {
               std::cout << sumMatrix[i][j] << "\t";
           }
           std::cout << "\n";
       }
    
    std::string path = "";
    
    i=0;
    j=0;
    
    /* printing the path to be taken as "Down" and "Right" directions from (1,1) to (m,n). */
    while(i!=m-1 || j!=n-1)
    {
        /* if we reach the last row, the only option is to travel "Right" till we reach (m,n). */
        if(i == m-1)
        {
            while(j<n-1)
            {
                path = path + "Right ";
                j++;
            }
        }
        
         /* if we reach the last column, the only option is to travel "Down" till we reach (m,n). */
        else if(j == n-1)
        {
            while(i<m-1)
            {
                path = path + "Down ";
                i++;
            }
        }
        
        /* if going right gives us more value. */
        else if(sumMatrix[i][j+1] > sumMatrix[i+1][j])
        {
            path = path + "Right ";
            j++;
        }
        
        /* if going down gives us more value. */
        else
        {
            path = path + "Down ";
            i++;
        }
    }
    
    /* printing the path and maximum sum obtained. */
    std::cout << "The path to be taken from matrix[0][0] is:\n" << path << ",\nwhich gives a total sum of: " << maxSum << "\n";
    
    return 0;
}
