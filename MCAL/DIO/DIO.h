/*
 * DIO.h
 *
 * Created: 09/09/2018 10:21:03 PM
 *  Author: Ramy Badr
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../avratmega32.h"


//////////////////////////////////////////////////////////////////////////////////
//                   Port Direction
//////////////////////////////////////////////////////////////////////////////////
U8 DIO_PortDir(U8 portBase, U8 dir);

U8 DIO_PinDir(U8 portBase, U8 pin, U8 dir);

U8 DIO_PortRangeDir(U8 portBase, U8 startPin, U8 endPin, U8 dir);

U8 DIO_PortMaskDir(U8 portBase, U8 mask, U8 pinsDir);

//////////////////////////////////////////////////////////////////////////////////
//                    Writing to Port
//////////////////////////////////////////////////////////////////////////////////

U8 DIO_PortWrite(U8 portBase, U8 val );

U8 DIO_PinWrite(U8 portBase, U8 pin, U8 val);

U8 DIO_PortRangeWrite(U8 portBase, U8 startPin, U8 endPin, U8 val);

U8 DIO_PortMaskWrite(U8 portBase, U8 mask, U8 val);

//////////////////////////////////////////////////////////////////////////////////
//                   Reading Port value
//////////////////////////////////////////////////////////////////////////////////

U8 DIO_PortRead(U8 portBase, U8 *portVal );

U8 DIO_PinRead(U8 portBase, U8 pin, U8 *pinVal);

U8 DIO_PortRangeRead(U8 portBase, U8 startPin, U8 endPin, U8 *rangeReadVal);

U8 DIO_PortMaskRead(U8 portBase, U8 mask, U8 *binaryIndividuals_readVal);

//////////////////////////////////////////////////////////////////////////////////
//                    Toggle Port Value
//////////////////////////////////////////////////////////////////////////////////

U8 DIO_PortToggle(U8 portBase);

U8 DIO_PinToggle(U8 portBase, U8 pin);

U8 DIO_PortRangeToggle(U8 portBase, U8 startPin, U8 endPin);

U8 DIO_PortMaskToggle(U8 portBase, U8 mask);




#endif /* DIO_H_ */