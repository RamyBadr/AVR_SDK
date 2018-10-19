/*
 * utils.h
 *
 * Created: 20/09/2018 05:48:19 PM
 *  Author: www
 */ 


#ifndef UTILS_H_
#define UTILS_H_
#include "datatypes.h"
#include <string.h>
#define STR_SIZE    16

void revstr(S8 * str);
void intostr(U16 n , S8 str[]);
void fltostr(S32 f , S8 str[],U8  persc);



#endif /* UTILS_H_ */