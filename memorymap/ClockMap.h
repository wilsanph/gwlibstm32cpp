/*
 * ClockMap.h
 *
 *  Created on: Oct 12, 2016
 *      Author: gw
 */

#ifndef CLOCKMAP_H_
#define CLOCKMAP_H_

#include "../include/Common.h"

namespace clockMap
{

	struct RCC_CR_bits
	{
		u32 HSION		: 1;
		u32 HSIRDY      : 1;
		u32 reserved3	: 1;
		u32 HSITRIM     : 5;
		u32 HSICAL		: 8;
		u32 HSEON		: 1;
		u32 HSERDY    	: 1;
		u32 HSEBYP 		: 1;
		u32 CSSON 		: 1;
		u32 reserved2	: 4;
		u32 PLLON 		: 1;
		u32 PLLRDY 		: 1;
		u32 PLLI2SON	: 1;
		u32 PLLI2SRDY	: 1;
		u32 reserved1 	: 4;
	};

	union RCC_CR_reg
	{
		u32 all;
		RCC_CR_bits bits;
	};

	struct RCC_PLLCFGR_bits
	{
		u32 PLLM		: 6;
		u32 PLLN    	: 9;
		u32 reserved4	: 1;
		u32 PLLP 		: 2;
		u32 reserved3	: 4;
		u32 PLLSRC		: 1;
		u32 reserved2 	: 1;
		u32 PLLQ		: 4;
		u32 reserved1 	: 4;
	};

	union RCC_PLLCFGR_reg
	{
		u32 all;
		RCC_PLLCFGR_bits bits;
	};

	struct RCC_CFGR_bits
	{
		u32 SW 			: 2;
		u32 SWS			: 2;
		u32 HPRE		: 4;
		u32 reserved 	: 2;
		u32 PPRE1    	: 3;
		u32 PPRE2		: 3;
		u32 RTCPRE 		: 5;
		u32 MCO1		: 2;
		u32 I2SSRC		: 1;
		u32 MCO1PRE 	: 3;
		u32 MCO2PRE		: 3;
		u32 MCO2 		: 2;
	};

	union RCC_CFGR_reg
	{
		u32 all;
		RCC_CFGR_bits bits;
	};

	struct RCC_AHB1ENR
	{
		u32 reserved5	 : 3;
		u32 CRCEN 		 : 1;
		u32 reserved4	 : 5;
		u32 BKPSRAMEN	 : 1;
		u32 reserved3 	 : 1;
		u32 CCMDATARAMEN : 1;
		u32 DMA1EN		 : 1;
		u32 DMA2EN		 : 1;
		u32 reserved2 	 : 2;
		u32 ETHMACEN	 : 1;
		u32 ETHMACTXEN	 : 1;
		u32 ETHMACRXEN	 : 1;
		u32 ETHMACPTPEN	 : 1;
		u32 OTGHSEN: 	 : 1;
		u32 OTGHSULPIEN	 : 1;
		u32 reserved1 	 : 1;
	};

	union RCC_CFGR_reg
	{
		u32 all;
		RCC_CFGR_bits bits;
	};

	struct MemoryMap
	{
		RCC_CR_reg RCC_CR;
		RCC_PLLCFGR_reg RCC_PLLCFGR;
		RCC_CFGR_reg RCC_CFGR;
	};
	
}



#endif /* CLOCKMAP_H_ */
