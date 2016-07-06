/*************************************************************************
	> File Name: 01distable.c
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Jul 2016 04:56:55 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>


static uint8_t sbox[16]=
{
    0xc,0x5,0x6,0xB,0x9,0x0,0xa,0xd,0x3,0xe,0xf,0x8,0x4,0x7,0x1,0x2
};

static uint8_t sbox_toy[16]=
{
    0x6,0x4,0xc,0x5,0x0,0x7,0x2,0xe,0x1,0xf,0x3,0xd,0x8,0xa,0x9,0xb
};

static uint8_t invsbox_toy[16]=
{
    0x4,0x8,0x6,0xa,0x1,0x3,0x0,0x5,0xc,0xe,0xd,0xf,0x2,0xb,0x7,0x9
};

static uint8_t ptable[16]=
{
    0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15
};

static uint8_t invptable[16]=
{
    0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15
};

uint8_t soleS(uint8_t in)
{
    return sbox_toy[in];
}

uint16_t soleinvS(uint16_t in)
{
    return invsbox_toy[in];
}

uint16_t P(uint16_t in)
{
    uint16_t temp=0;
    for(int i=0;i<16;i++)
        temp = (temp << 1) + ((in >> (15-ptable[i])) & 1);
    return temp;
}

uint16_t invP(uint16_t out)
{
    uint16_t temp=0;
    for(int i=0;i<16;i++)
        temp = (temp << 1) + ((out >> (15-invptable[i])) & 1);
    return temp;
}

uint16_t S(uint16_t m)
{
    uint16_t temp;
    temp =  soleS(m & 0xf);
    temp += soleS(m>>4 & 0xf)<<4;
    temp += soleS(m>>8 & 0xf)<<8;
    temp += soleS(m>>12 & 0xf)<<12;
    return temp;
}

uint16_t invS(uint16_t c)
{
    uint16_t temp;
    temp =   soleinvS(c & 0xf);
    temp +=  (soleinvS(c>>4 & 0xf)<<4);
    temp +=  (soleinvS(c>>8 & 0xf)<<8);
    temp +=  (soleinvS(c>>12 & 0xf)<<12);
    return temp;

}


/*
int main()
{
    uint16_t a=0xabcd;
    printf("%#x\n",S(a));
    printf("%#x\n",invS(S(a)));
    return 0;

}
*/

