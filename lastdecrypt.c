/*************************************************************************
	> File Name: lastdecryp.c
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Jul 2016 05:01:26 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include"toy.h"

uint16_t lastdecrypt(uint16_t c,uint16_t lastkey)
{
    c ^= lastkey;
    c = invS(c);
    return c;
}


