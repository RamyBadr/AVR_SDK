/*
 * SEVEN_SEG_config.h
 *
 * Created: 11/09/2018 11:45:43 AM
 *  Author: Ramy Badr
 */ 
#include "SEVEN_SEG.h"

#ifndef SEVEN_SEG_CONFIG_H_
#define SEVEN_SEG_CONFIG_H_



#define	SG_NUM	2 //All seven segments count
extern const PinType config_All_SgPins[2][5];
extern const SEVEN_SEG SEVEN_SEGs_Arr[SG_NUM];

void InitSevenSegs();


#endif /* SEVEN_SEG_CONFIG_H_ */