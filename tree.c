/*************************************************************************
	> File Name: tree.c
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Jul 2016 11:51:04 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define ROUND 4

void generateDist(double probility[4]);

int power(int ,int);

static double tree[4096]={0.0};

int power(int i,int j)
{
    int temp=i;
    while(--j>0)
        i *= temp;
    return i;
}

double treepro()
{
    double probility[4];
    generateDist(probility);
    /* generate the tree*/
    int k=0;
    tree[0]=-1;
    tree[1]=1;
    for(int i=1;i<ROUND+1;i++)
    {
        k=0;
        for(int j=power(2,i);j<power(2,i+1);j++,k=(k+1)%4)
            tree[j]=probility[k];
    }

    /* temp array to store the probility*/
    double protemp[power(2,ROUND)];
    for(int i = 0 ; i<power(2,ROUND);i++)// initiate the array as all 1
        protemp[i]=1;
    
    /* compute the tree trace problity*/
    int j=0;
    for(int i=power(2,ROUND);i<power(2,ROUND+1);i++,j++)
    {
        int k=i;
        while(k>0)
        {
            protemp[j] *= tree[k];
            k=k/2;
        }
    }

    /* sum the 0 or the 1 probility*/
    double sum0=0;
    double sum1=0;
    for(int i=0;i<power(2,ROUND);i=i+2)
    {
        sum0 += protemp[i];
        sum1 += protemp[i+1];
    }
    
    printf("\nsum0:%f\nsum1:%f\n",sum0,sum1);
    return sum0;
}

