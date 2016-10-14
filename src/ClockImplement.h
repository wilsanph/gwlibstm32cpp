

#pragma once

#include "../include/Clock.h"


namespace clock
{

	template <options::address::_address pAddress>
	void TClock<pAddress>::enableClockGpio( config::peripherals::gpio::_gpio pGpioPeripheral )
	{
		reinterpret_cast<clockMap::MemoryMap*>( pAddress )->RCC_AHB1ENR.all &= 0xffffffff - ( 1 << pGpioPeripheral );
		reinterpret_cast<clockMap::MemoryMap*>( pAddress )->RCC_AHB1ENR.all |= ( 1 << pGpioPeripheral );
	}


	Clock::Clock()
	{
		this->m_address = options::address::RCC_ADDRESS;
	}

	Clock::~Clock()
	{

	}

	void Clock::enableClockGpio( config::peripherals::gpio::_gpio pGpioPeripheral )
	{
		reinterpret_cast<clockMap::MemoryMap*>( this->m_address )->RCC_AHB1ENR.all &= 0xffffffff - ( 1 << pGpioPeripheral );
		reinterpret_cast<clockMap::MemoryMap*>( this->m_address )->RCC_AHB1ENR.all |= ( 1 << pGpioPeripheral );
	}

	namespace cf
	{
		void enableClockGpio( config::peripherals::gpio::_gpio pGpioPeripheral )
		{
			reinterpret_cast<clockMap::MemoryMap*>( options::address::RCC_ADDRESS )->RCC_AHB1ENR.all &= 0xffffffff - ( 1 << pGpioPeripheral );
			reinterpret_cast<clockMap::MemoryMap*>( options::address::RCC_ADDRESS )->RCC_AHB1ENR.all |= ( 1 << pGpioPeripheral );
		}
	}
}