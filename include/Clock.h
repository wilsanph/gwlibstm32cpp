

#pragma once

#include "../memorymap/ClockMap.h"



namespace clock
{

	namespace options
	{

		namespace address
		{
			enum _address
			{
				RCC_ADDRESS = 0x40023800
			};
		}

	}


	namespace config
	{
		namespace peripherals
		{
			namespace gpio
			{
				enum _gpio
				{
					PORTA,
					PORTB,
					PORTC,
					PORTD,
					PORTE,
					PORTF,
					PORTG,
					PORTH,
					PORTI
				};
			}
		}
	}

	template<options::address::_address pAddress>
	class TClock
	{
	public:
		static void enableClockGpio( config::peripherals::gpio::_gpio pGpioPeripheral );
	};



	class Clock
	{
	public:
		Clock();
		~Clock();

		void enableClockGpio( config::peripherals::gpio::_gpio pGpioPeripheral );

	private:
		options::address::_address m_address;
	};



	namespace cf
	{
		void enableClockGpio( config::peripherals::gpio::_gpio pGpioPeripheral );
	}




}

typedef clock::TClock<clock::options::address::RCC_ADDRESS> SYSTEM_CLOCK;

#include "../src/ClockImplement.h"

