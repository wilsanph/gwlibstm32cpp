/*
 * GpioMap.h
 *
 *  Created on: Oct 6, 2016
 *      Author: gw
 */

#ifndef GPIOMAP_H_
#define GPIOMAP_H_

#include "../include/Common.h"

namespace gpioMap
{

	struct MemoryMap
	{
		u32 MODER;//Moder register 0x00
		u32 OTYPER;//Output typer register 0x04
		u32 OSPEEDR;//Output speed register 0x08
		u32 PUPDR;//PullUp PullDown register 0x0c
		u32 IDR;//Input data register 0x10
		u32 ODR;//Output data register 0x14
		u32 BSRR;//Bit set reset register 0x18
		u32 LCKR;// Configuration lock register 0x1c
		u64 AFR;// Alternate function register [0x20-0x24]
	};
	
}



#endif /* GPIOMAP_H_ */
