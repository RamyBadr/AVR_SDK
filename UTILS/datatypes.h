/*
 * datatypes.h
 *
 * Created: 09/09/2018 10:22:37 PM
 *  Author: Ramy Badr
 */ 


#ifndef DATATYPES_H_
#define DATATYPES_H_

typedef unsigned char			U8;
typedef unsigned short int		U16;
typedef unsigned long int		U32;

typedef signed char				S8;
typedef	signed short int		S16;
typedef	signed long int			S32;

typedef struct{
	U8 port_base;
	U8 pin_no;
}PinType;




#endif /* DATATYPES_H_ */