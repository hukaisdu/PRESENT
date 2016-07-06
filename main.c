/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Jul 2016 04:22:27 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<math.h>
#include"toy.h"

uint16_t key[6]=
{
    0x5b92,0x064b,0x1e03,0xa55f,0xecbd,0x1111
};

double treepro();
uint16_t lastdecrypt(uint16_t, uint16_t);
uint16_t fourroundencrypt(uint16_t,uint16_t*);

int main()
{
    uint16_t c1,c2;
    uint64_t T[2][2]={0};
    for(register uint16_t m1=0;m1<=0x4ff;m1++)
    {
        for(register uint64_t m2=1; m2<=0x4ff && m1!=m2;m2++)
        {
            c1=fourroundencrypt(m1,key);
            c2=fourroundencrypt(m2,key);
            if((m1^m2)%2==0)
            {
                if((c1^c2)%2==0)
                    T[0][0]++;
                else T[0][1]++;
            }
            else 
                if((c1^c2)%2==0)
                    T[1][0]++;
                else T[1][1]++;
        }
    }
    printf("T[0][0]:%ld\tT[0][1]:%ld\tT[1][0]:%ld\tT[1][1]:%ld\t\n",T[0][0],T[0][1],T[1][0],T[1][1]);
    return 0;
}
/*
int main()
{
    double sum0;
    uint8_t m1,m2,c1,c2;
    uint64_t count=0;
    sum0=treepro();
    printf("the main function 0:1 : %f\t%f\n",sum0,1-sum0);
    
    uint64_t T[2]={0};
    //for(uint16_t lastkey = 0 ; lastkey<0xffff ; lastkey++ )
    uint16_t lastkey=0x1122;
    {
        T[0]=0;
        T[1]=0;
        count=0;
        //while(1)
        {
            for(m1=0;m1<0xff;m1++)
                for(m2=1;m2<0xff&&m2!=m1;m2++)
                {
                    if((m1^m2)%2==0)
                    {
                        // printf("m1:%#x,m2:%#x\n",m1,m2);
                        count++;
                        c1= encrypt(m1,key);
                        c2= encrypt(m2,key);
                        c1= lastdecrypt(c1,lastkey);
                        c2= lastdecrypt(c2,lastkey);
                        //  printf("c1:%#x,c2:%#x\n",c1,c2);
                        if((c1^c2)%2==0)
                        T[0]++;
                        else
                        T[1]++;

                    }
                    else
                        continue;
                }
           // printf("Key: %#x\n 0:1 :  %lu : %lu\n",lastkey,T[0],T[1]);
        }
       // getchar();
        //if(T[0]<T[1])
        {
            double bias=(((double)T[1])/(T[0]+T[1]));
            if(bias<0.00001);
                printf("Key: %#x\n 0:1 :  %lu : %lu\n bias: %f",lastkey,T[0],T[1],bias);
                
        }
    }
    return 0;
}*/
