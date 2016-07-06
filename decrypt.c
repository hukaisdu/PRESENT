/*************************************************************************
	> File Name: decrypt.c
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Jul 2016 01:59:36 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include"toy.h"

/*
uint16_t c = 0xaf12;
uint16_t k[6]=
{
    0x5b92,0x064b,0x1e03,0xa55f,0xacbd,0x7ca5
};
*/

uint16_t decrypt(uint16_t c,uint16_t k[6])
{
    c ^= k[5];
    c = invS(c);
    for(int i=4;i>0;i--)
    {
        c ^= k[i];
        c =  invP(c);
        c =  invS(c);
    }
    c ^= k[0];

    return c;
}
