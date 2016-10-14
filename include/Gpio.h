

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

		namespace outputType
		{
			enum _outputType
			{
				PUSH_PULL,
				OPEN_DRAIN
			};
		}

		namespace outputSpeed
		{
			enum _outputSpeed
			{
				LOW = 0x00,
				MEDIUM = 0x01,
				HIGH = 0x02,
				VERY_HIGH = 0x03
			};
		}

		namespace pullResistor
		{
			enum _pullResistor
			{
				NO_RESISTOR = 0x00,
				PULL_UP = 0x01,
				PULL_DOWN = 0x02
			};
		}
	}

	template<options::port::_port pPort,options::pin::_pin pPin>
	class TPin
	{
	public:

		static void setMode( config::mode::_mode pMode );
		static void setOutputType( config::outputType::_outputType pOType );
		static void setOutputSpeed( config::outputSpeed::_outputSpeed pOSpeed );
		static void setPullResistor( config::pullResistor::_pullResistor pPullResistor );
		static u32 getPortData();
		static bool isHigh();
		static bool isLow();

		static inline void toggle();
		static inline void setLow();
		static inline void setHigh();
	};



	class Pin
	{
	public:
		Pin( options::port::_port pPort,
			 options::pin::_pin pPin );
		~Pin();

		void setMode( config::mode::_mode pMode );
		void setOutputType( config::outputType::_outputType pOType );
		void setOutputSpeed( config::outputSpeed::_outputSpeed pOSpeed );
		void setPullResistor( config::pullResistor::_pullResistor pPullResistor );
		u32 getPortData();
		bool isHigh();
		bool isLow();
		void toggle();
		void setLow();
		void setHigh();

	private:
		options::port::_port m_port;
		options::pin::_pin m_pin;
	};



	namespace cf
	{
		void pinSetMode( options::port::_port pPort,
			   			 options::pin::_pin pPin,
			   			 config::mode::_mode pMode );

		void pinSetOutputType( options::port::_port pPort,
			   			 	   options::pin::_pin pPin,
			   			 	   config::outputType::_outputType pOType );

		void pinSetOutputSpeed( options::port::_port pPort,
			   			 		options::pin::_pin pPin,
			   			 		config::outputSpeed::_outputSpeed pOSpeed );

		void pinSetPullResistor( options::port::_port pPort,
			   			 		 options::pin::_pin pPin,
			   			 		 config::outputSpeed::_outputSpeed pPullResistor );

		u32 portGetPortData( options::port::_port pPort );

		bool pinIsHigh( options::port::_port pPort,
						options::pin::_pin pPin );

		bool pinIsLow( options::port::_port pPort,
					   options::pin::_pin pPin );

		void pinToggle( options::port::_port pPort,
					   options::pin::_pin pPin );

		void pinSetLow( options::port::_port pPort,
					    options::pin::_pin pPin );

		void pinSetHigh( options::port::_port pPort,
					     options::pin::_pin pPin );
	}




}

typedef gpio::TPin<gpio::options::port::PORTD,gpio::options::pin::PIN12> PD12;
typedef gpio::TPin<gpio::options::port::PORTD,gpio::options::pin::PIN13> PD13;
typedef gpio::TPin<gpio::options::port::PORTD,gpio::options::pin::PIN14> PD14;
typedef gpio::TPin<gpio::options::port::PORTD,gpio::options::pin::PIN15> PD15;


#include "../src/GpioImplement.h"

