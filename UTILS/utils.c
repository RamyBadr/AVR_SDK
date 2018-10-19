/*
 * utils.c
 *
 * Created: 20/09/2018 05:48:07 PM
 *  Author: www
 */ 
#include "utils.h"
void revstr(S8 * str){
	int i = 0  , l = strlen(str) ;
	char temp ;
	for(i=0;i<=l/2;i++){
		temp = str[i] ;
		str[i] = str[l-i-1];
		str[l-i-1] = temp ;
	}
}

void intostr(U16 n , S8 str[]){
	int i , reminder;
	char c ;
	reminder = (n%10) ;
	for(i=0;i<STR_SIZE - 1&&reminder>0;i++){
		c = reminder + '0' ;
		str[i] = c ;
		n = (int) (n/10) ;
		reminder = (n%10) ;
	}
	str[i] = '\0' ;
	revstr(str) ;
}

void fltostr(S32 f , S8 str[],U8  perc){
	S16 n = (S16) f;
	S16 i  , reminder;
	S8 c , f_str[perc];
	S32 fraction = f - n ;
	intostr(n,str);
	f_str[0] = '.' ;
	for(i=1;i<=perc;i++){
		fraction*=10 ;
		reminder = (int) (fraction);
		fraction -= reminder ;
		f_str[i] = reminder + '0' ;
	}
	f_str[i] = '\0' ;
	strcat(str,f_str);
}
