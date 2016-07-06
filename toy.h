/*************************************************************************
	> File Name: toy.h
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Jul 2016 01:01:06 AM PDT
 ************************************************************************/

#include<inttypes.h>
#ifndef _TOY_H
#define _TOY_H
/*
 *s_box substitution 
 */
uint16_t S(uint16_t);

/*
 * inverse sbox substitution
 */
uint16_t invS(uint16_t);

/*
 * perputation
 */
uint16_t P(uint16_t);

/* inverse p permution*/
uint16_t invP(uint16_t);

/* the encrpt processor*/
uint16_t encrypt(uint16_t m,uint16_t k[6]);

/* the decrypt processor*/
uint16_t decrypt(uint16_t c,uint16_t k[6]);

#endif
