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

	// RCC_CR *****************************************************************
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
	// ************************************************************************
	// RCC_PLLCFGR ************************************************************
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
	// ************************************************************************
	// RCC_CFGR ***************************************************************
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
	// ************************************************************************
	// RCC_AHB1ENR ************************************************************
	struct RCC_AHB1ENR_bits
	{
		u32 GPIOAEN	     : 1;
		u32 GPIOBEN	     : 1;
		u32 GPIOCEN	     : 1;
		u32 GPIODEN	     : 1;
		u32 GPIOEEN	     : 1;
		u32 GPIOFEN	     : 1;
		u32 GPIOGEN	     : 1;
		u32 GPIOHEN		 : 1;
		u32 GPIOIEN		 : 1;
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
		u32 OTGHSEN 	 : 1;
		u32 OTGHSULPIEN	 : 1;
		u32 reserved1 	 : 1;
	};

	union RCC_AHB1ENR_reg
	{
		u32 all;
		RCC_AHB1ENR_bits bits;
	};
	// ************************************************************************
	// RCC_AHB2ENR ************************************************************
	struct RCC_AHB2ENR_bits
	{
		u32 DCMIEN		: 1;
		u32 reserved1 	: 3;
		u32 CRYPEN		: 1;
		u32 HASHEN		: 1;
		u32 RNGEN		: 1;
		u32 OTGFSEN		: 1;
		u32 reserved1 	: 24;
	};

	union RCC_AHB2ENR_reg
	{
		u32 all;
		RCC_AHB2ENR_bits bits;
	};
	// ************************************************************************
	// RCC_AHB3ENR ************************************************************
	struct RCC_AHB3ENR_bits
	{
		u32 FSCM	     : 1;
		u32 reserved1 	 : 31;
	};

	union RCC_AHB3ENR_reg
	{
		u32 all;
		RCC_AHB3ENR_bits bits;
	};
	// ************************************************************************
	// RCC_APB1ENR ************************************************************
	struct RCC_APB1ENR_bits
	{
		u32 TIM2EN	 	 : 1;
		u32 TIM3EN	 	 : 1;
		u32 TIM4EN	 	 : 1;
		u32 TIM5EN	 	 : 1;
		u32 TIM6EN	 	 : 1;
		u32 TIM7EN	 	 : 1;
		u32 TIM12EN	 	 : 1;
		u32 TIM13EN	 	 : 1;
		u32 TIM14EN	 	 : 1;
		u32 reserved6	 : 2;
		u32 WWDGEN	 	 : 1;
		u32 reserved5	 : 2;
		u32 SPI2EN	 	 : 1;
		u32 SPI3EN	 	 : 1;
		u32 reserved4	 : 1;
		u32 USART2EN	 : 1;
		u32 USART3EN	 : 1;
		u32 UART4EN	 	 : 1;
		u32 UART5EN	 	 : 1;
		u32 I2C1EN	 	 : 1;
		u32 I2C2EN	 	 : 1;
		u32 I2C3EN	 	 : 1;
		u32 reserved3	 : 1;
		u32 CAN1EN	 	 : 1;
		u32 CAN2EN	 	 : 1;
		u32 reserved2 	 : 1;
		u32 PWREN	     : 1;
		u32 DACEN	     : 1;
		u32 reserved1 	 : 2;
	};

	union RCC_APB1ENR_reg
	{
		u32 all;
		RCC_APB1ENR_bits bits;
	};
	// ************************************************************************
	// RCC_APB2ENR ************************************************************
	struct RCC_APB2ENR_bits
	{
		u32 TIM1EN		: 1;
		u32 TIM8EN		: 1;
		u32 reserved5	: 2;
		u32 USART1EN	: 1;
		u32 USART6EN	: 1;
		u32 reserved4	: 2;
		u32 ADC1EN		: 1;
		u32 ADC2EN		: 1;
		u32 ADC3EN		: 1;
		u32 SDIOEN		: 1;
		u32 SPI1EN		: 1;
		u32 SPI4EN		: 1;
		u32 SYSCFGEN	: 1;
		u32 reserved3	: 1;
		u32 TIM9EN		: 1;
		u32 TIM10EN		: 1;
		u32 TIM11EN		: 1;
		u32 reserved2 	: 1;
		u32 SPI5EN		: 1;
		u32 SPI6EN		: 1;
		u32 reserved1 	: 10;
	};

	union RCC_APB2ENR_reg
	{
		u32 all;
		RCC_APB2ENR_bits bits;
	};
	// ************************************************************************




	struct MemoryMap
	{
		RCC_CR_reg RCC_CR;// 0x00
		RCC_PLLCFGR_reg RCC_PLLCFGR;// 0x04
		RCC_CFGR_reg RCC_CFGR;// 0x08
		u32 RCC_CIR;// 0x0c
		u32 RCC_AHB1RSTR;// 0x10
		u32 RCC_AHB2RSTR;// 0x14
		u32 RCC_AHB3RSTR;// 0x18
		u32 reserved1;// 0x1c
		u32 RCC_APB1RSTR;// 0x20
		u32 RCC_APB2RSTR;// 0x24
		u32 reserved2[2];// [0x28-0x2c]
		RCC_AHB1ENR_reg RCC_AHB1ENR;// 0x30
		RCC_AHB2ENR_reg RCC_AHB2ENR;// 0x34
		RCC_AHB3ENR_reg RCC_AHB3ENR;// 0x38
		u32 reserved3;// 0x3c
		RCC_APB1ENR_reg RCC_APB1ENR;// 0x40
		RCC_APB2ENR_reg RCC_APB2ENR;// 0x44
		u32 reserved4[2];// [0x48-0x4c]
		u32 RCC_AHB1LPENR;// 0x50
		u32 RCC_AHB2LPENR;// 0x54
		u32 RCC_AHB3LPENR;// 0x58
		u32 reserved5;// 0x5c
		u32 RCC_APB1LPENR;// 0x60
		u32 RCC_APB2LPENR;// 0x64
		u32 reserved6[2];// [0x68-0x6c]
		u32 RCC_BDCR;// 0x70
		u32 RCC_CSR;// 0x74
		u32 reserved7[2];// [0x78-0x7c]
		u32 RCC_SSCGR;// 0x80
		u32 RCC_PLLI2SCFGR;// 0x84
	};
	
}



#endif /* CLOCKMAP_H_ */
