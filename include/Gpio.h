

#pragma once

#include "../memorymap/GpioMap.h"





namespace gpio
{

	namespace options
	{

		namespace port
		{
			enum _port
			{
				PORTA = 0x40020000,
				PORTB = 0x40020400,
				PORTC = 0x40020800,
				PORTD = 0x40020c00,
				PORTE = 0x40021000,
				PORTF = 0x40021400,
				PORTG = 0x40021800,
				PORTH = 0x40021c00,
				PORTI = 0x40022000,
				PORTJ = 0x40022400,
				PORTK = 0x40022800
			};
		}

		namespace pin
		{
			enum _pin
			{
				PIN0,
				PIN1,
				PIN2,
				PIN3,
				PIN4,
				PIN5,
				PIN6,
				PIN7,
				PIN8,
				PIN9,
				PIN10,
				PIN11,
				PIN12,
				PIN13,
				PIN14,
				PIN15
			};
		}
	}


	namespace config
	{

		namespace mode
		{
			enum _mode
			{
				INPUT = 0x00,
				OUTPUT = 0x01,
				ALTERNATE = 0x02,
				ANALOG = 0x03,
			};
		}


	}



	template<options::port::_port pPort,options::pin::_pin pPin>
	class TPin
	{
	public:

		static inline void setMode( config::mode::_mode pMode );

		
	};



	class Pin
	{
	public:
		Pin( options::port::_port pPort,
			 options::pin::_pin pPin );
		~Pin();

		void setMode( config::mode::_mode pMode );

	private:
		options::port::_port m_port;
		options::pin::_pin m_pin;
	};



	namespace cf
	{
		void pinSetMode( options::port::_port pPort,
			   			 options::pin::_pin pPin,
			   			 config::mode::_mode pMode );
	}


}


#include "../src/GpioImplement.h"

