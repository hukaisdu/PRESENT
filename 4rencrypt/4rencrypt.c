/*************************************************************************
	> File Name: toy.c
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Jul 2016 01:17:58 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include"toy.h"
uint16_t m=0x1111;

uint16_t k[6]=
{
    0x5b92,0x064b,0x1e03,0xa55f,0xacbd,0x7ca5
};
uint16_t fourroundencrypt(uint16_t m,uint16_t k[6])
{
    m ^= k[0];
    for(int i =1 ; i < 5; i++)
    {
        m = S(m);
        m = P(m);
        m ^= k[i];
    }
   // printf("%#x\n",m);
    return m;
}
int main()
{
    printf("%#x\n",fourroundencrypt(m,k));
    return 0;
}
