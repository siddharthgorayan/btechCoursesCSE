//
//  main.c
//  Question-1
//
//  Created by Siddharth Saini on 25/04/20.
//  Copyright © 2020 Siddharth Saini. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coordinates
{
    double xCord, yCord;
};

double euclideanDistance(double xCordP1, double yCordP1, double xCordP2, double yCordP2)
{
    return sqrt((xCordP1-xCordP2)*(xCordP1-xCordP2)+(yCordP1-yCordP2)*(yCordP1-yCordP2));
}



int main()
{
    struct coordinates *ptr;
    int i, j, noOfIncputs;
    double distance, minDistance = +INFINITY, maxDistance = -INFINITY, xMaxCordP1, yMaxCordP1, xMinCordP1, yMinCordP1, xMaxCordP2, yMaxCordP2, xMinCordP2, yMinCordP2;
    printf("Enter the number of inputs: ");
    scanf("%d",&noOfIncputs);
    ptr = (struct coordinates *)malloc(noOfIncputs * sizeof(struct coordinates));
    
    for(i=0; i<noOfIncputs; i++)
    {
        printf("Enter the x and the y co-ordinates: ");
        scanf("%lf %lf",&(ptr+i)->xCord,&(ptr+i)->yCord);
    }
    
    for(i=0; i<noOfIncputs-1; i++)
    {
        for(j=i+1; j<noOfIncputs; j++)
        {
            distance = euclideanDistance((ptr+i)->xCord, (ptr+i)->yCord, (ptr+j)->xCord, (ptr+j)->yCord);
            if(distance<minDistance)
            {
                minDistance = distance;
                xMinCordP1 = (ptr+i)->xCord;
                yMinCordP1 = (ptr+i)->yCord;
                xMinCordP2 = (ptr+j)->xCord;
                yMinCordP2 = (ptr+j)->yCord;
            }
            else if (distance>maxDistance)
            {
                maxDistance = distance;
                xMaxCordP1 = (ptr+i)->xCord;
                yMaxCordP1 = (ptr+i)->yCord;
                xMaxCordP2 = (ptr+j)->xCord;
                yMaxCordP2 = (ptr+j)->yCord;
            }
        }
    }
    
    printf("Closest Pair: (%lf,%lf) and (%lf,%lf).\n", xMinCordP1, yMinCordP1, xMinCordP2, yMinCordP2);
    printf("Farthest Pair: (%lf,%lf) and (%lf,%lf).\n", xMaxCordP1, yMaxCordP1, xMaxCordP2, yMaxCordP2);
    
    free(ptr);
    
    return 0;
}
