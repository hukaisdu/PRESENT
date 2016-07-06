/*************************************************************************
	> File Name: 01distable.c
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Jul 2016 04:56:55 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include"toy.h"

#define BIT 0 

void generateDist(double dist[4])
{
    int count[2][2]={0};
    for(int i=1;i<16;i++)//input differential 
    {
        {
            for(int j=0;j<16;j++)//actual input
            {
                int output= S(j)^S(j^i);//output differential
                if(((i>>BIT)&1)==0)
                {
                    if(((output>>BIT)&1)==0) 
                        count[0][0]++;
                    else 
                        count[0][1]++;
                }
                else
                {
                    if(((output>>BIT)&1)==0)
                        count[1][0]++;
                    else
                        count[1][1]++;
                }
            }
        }
    }

    dist[0]=(double)(count[0][0])/(double)(count[0][0]+count[0][1]);
    dist[1]=(double)(count[0][1])/(double)(count[0][0]+count[0][1]);
    dist[2]=(double)(count[1][0])/(double)(count[1][0]+count[1][1]);
    dist[3]=(double)(count[1][1])/(double)(count[1][0]+count[1][1]);

    printf("%f\t%f\t%f\t%f",dist[0],dist[1],dist[2],dist[3]);
}

int main()
{
    double dist[4];
    generateDist(dist);
    return 0;
}

