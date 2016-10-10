

#pragma once

#include "../include/Gpio.h"

namespace gpio
{


	template<options::port::_port pPort,options::pin::_pin pPin>
	void TPin<pPort,pPin>::setMode( config::mode::_mode pMode )
	{
		reinterpret_cast<gpioMap::MemoryMap*>( pPort )->MODER &= 0xffffffff - ( 0x3 << ( 2 * pPin ) );
		reinterpret_cast<gpioMap::MemoryMap*>( pPort )->MODER |= ( pMode << ( 2 * pPin ) );
	}


	template<options::port::_port pPort,options::pin::_pin pPin>
	void TPin<pPort,pPin>::setOutputType( config::outputType::_outputType pOType )
	{
		reinterpret_cast<gpioMap::MemoryMap*>( pPort )->OTYPER &= 0xffffffff - ( 1 << pPin );
		reinterpret_cast<gpioMap::MemoryMap*>( pPort )->OTYPER |= ( pOType << pPin );
	}


	template<options::port::_port pPort,options::pin::_pin pPin>
	void TPin<pPort,pPin>::setOutputSpeed( config::outputSpeed::_outputSpeed pOSpeed )
	{
		reinterpret_cast<gpioMap::MemoryMap*>( pPort )->OSPEEDR &= 0xffffffff - ( 0x3 << ( 2 * pPin ) );
		reinterpret_cast<gpioMap::MemoryMap*>( pPort )->OSPEEDR |= ( pOSpeed << ( 2 * pPin ) );
	}

	template<options::port::_port pPort,options::pin::_pin pPin>
	void TPin<pPort,pPin>::setPullResistor( config::pullResistor::_pullResistor pPullResistor )
	{
		reinterpret_cast<gpioMap::MemoryMap*>( pPort )->PUPDR &= 0xffffffff - ( 0x3 << ( 2 * pPin ) );
		reinterpret_cast<gpioMap::MemoryMap*>( pPort )->PUPDR |= ( pPullResistor << ( 2 * pPin ) );
	}	

	template<options::port::_port pPort,options::pin::_pin pPin>
	u32 TPin<pPort,pPin>::getPortData()
	{
		return reinterpret_cast<gpioMap::MemoryMap*>( pPort )->IDR;
	}

	template<options::port::_port pPort,options::pin::_pin pPin>
	bool TPin<pPort,pPin>::isHigh()
	{
		u32 _idr = reinterpret_cast<gpioMap::MemoryMap*>( pPort )->IDR;
		u32 _result = _idr & ( 1 << pPin );
		return ( _result != 0x00000000 );
	}

	template<options::port::_port pPort,options::pin::_pin pPin>
	bool TPin<pPort,pPin>::isLow()
	{
		return reinterpret_cast<gpioMap::MemoryMap*>( pPort )->IDR & ( 1 << pPin ) == 0x00000000;
	}

	template<options::port::_port pPort,options::pin::_pin pPin>
	void TPin<pPort,pPin>::setLow()
	{
		reinterpret_cast<gpioMap::MemoryMap*>( pPort )->BSRR = ( 1 << ( pPin + 16 ) );
	}

	template<options::port::_port pPort,options::pin::_pin pPin>
	void TPin<pPort,pPin>::setHigh()
	{
		reinterpret_cast<gpioMap::MemoryMap*>( pPort )->BSRR = ( 1 << pPin );
	}

	template<options::port::_port pPort,options::pin::_pin pPin>
	void TPin<pPort,pPin>::toggle()
	{
		if ( TPin<pPort,pPin>::isHigh() ) 
		{
			TPin<pPort,pPin>::setLow();
		}
		else 
		{
			TPin<pPort,pPin>::setHigh();
		}
	}

	Pin::Pin( options::port::_port pPort,
			  options::pin::_pin pPin )
	{
		this->m_port = pPort;
		this->m_pin = pPin;
	}

	Pin::~Pin()
	{

	}

	void Pin::setMode( config::mode::_mode pMode )
	{
		reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->MODER &= 0xffffffff - ( 0x3 << ( 2 * this->m_pin ) );
		reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->MODER |= ( pMode << ( 2 * this->m_pin ) );
	}

	void Pin::setOutputType( config::outputType::_outputType pOType )
	{
		reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->OTYPER &= 0xffffffff - ( 0x1 << this->m_pin );
		reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->OTYPER |= ( pOType << this->m_pin );
	}

	void Pin::setOutputSpeed( config::outputSpeed::_outputSpeed pOSpeed )
	{
		reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->OSPEEDR &= 0xffffffff - ( 0x3 << ( 2 * this->m_pin ) );
		reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->OSPEEDR |= ( pOSpeed << ( 2 * this->m_pin ) );
	}

	void Pin::setPullResistor( config::pullResistor::_pullResistor pPullResistor )
	{
		reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->PUPDR &= 0xffffffff - ( 0x3 << ( 2 * this->m_pin ) );
		reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->PUPDR |= ( pPullResistor << ( 2 * this->m_pin ) );
	}

	u32 Pin::getPortData()
	{
		return reinterpret_cast<gpioMap::MemoryMap*>( this->m_pin )->IDR;
	}

	bool Pin::isHigh()
	{
		return reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->IDR && ( 1 << this->m_pin ) != 0x00000000;
	}

	bool Pin::isLow()
	{
		return reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->IDR && ( 1 << this->m_pin ) == 0x00000000;
	}

	void Pin::setLow()
	{
		reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->BSRR |= ( 1 << ( this->m_pin + 16 ) );
	}

	void Pin::setHigh()
	{
		reinterpret_cast<gpioMap::MemoryMap*>( this->m_port )->BSRR |= ( 1 << this->m_pin );
	}

	void Pin::toggle()
	{
		if ( this->isHigh() ) 
		{
			this->setLow();
		}
		else 
		{
			this->setHigh();
		}
	}


	namespace cf
	{
		void pinSetMode( options::port::_port pPort,
			   			 options::pin::_pin pPin,
			   			 config::mode::_mode pMode )
		{
			reinterpret_cast<gpioMap::MemoryMap*>( pPort )->MODER &= 0xffffffff - ( 0x3 << ( 2 * pPin ) );
			reinterpret_cast<gpioMap::MemoryMap*>( pPort )->MODER |= ( pMode << ( 2 * pPin ) );
		}

		void pinSetOutputType( options::port::_port pPort,
			   			 	   options::pin::_pin pPin,
			   			 	   config::outputType::_outputType pOType )
		{
			reinterpret_cast<gpioMap::MemoryMap*>( pPort )->OTYPER &= 0xffffffff - ( 0x1 << pPin );
			reinterpret_cast<gpioMap::MemoryMap*>( pPort )->OTYPER |= ( pOType << pPin );
		}

		void pinSetOutputSpeed( options::port::_port pPort,
			   			 		options::pin::_pin pPin,
			   			 		config::outputSpeed::_outputSpeed pOSpeed )
		{
			reinterpret_cast<gpioMap::MemoryMap*>( pPort )->OSPEEDR &= 0xffffffff - ( 0x3 << ( 2 * pPin ) );
			reinterpret_cast<gpioMap::MemoryMap*>( pPort )->OSPEEDR |= ( pOSpeed << ( 2 * pPin ) );
		}

		void pinSetPullResistor( options::port::_port pPort,
			   			 		 options::pin::_pin pPin,
			   			 		 config::pullResistor::_pullResistor pPullResistor )
		{
			reinterpret_cast<gpioMap::MemoryMap*>( pPort )->PUPDR &= 0xffffffff - ( 0x3 << ( 2 * pPin ) );
			reinterpret_cast<gpioMap::MemoryMap*>( pPort )->PUPDR |= ( pPullResistor << ( 2 * pPin ) );
		}

		u32 portGetPortData( options::port::_port pPort )
		{
			return reinterpret_cast<gpioMap::MemoryMap*>( pPort )->IDR;
		}

		bool pinIsHigh( options::port::_port pPort,
						options::pin::_pin pPin )
		{
			return reinterpret_cast<gpioMap::MemoryMap*>( pPort )->IDR && ( 1 << pPin ) != 0x00000000;
		}

		bool pinIsLow( options::port::_port pPort,
					   options::pin::_pin pPin )
		{
			return reinterpret_cast<gpioMap::MemoryMap*>( pPort )->IDR && ( 1 << pPin ) == 0x00000000;
		}

		void pinSetLow( options::port::_port pPort,
					    options::pin::_pin pPin )
		{
			reinterpret_cast<gpioMap::MemoryMap*>( pPort )->BSRR |= ( 1 << ( pPin + 16 ) );
		}

		void pinSetHigh( options::port::_port pPort,
					     options::pin::_pin pPin )
		{
			reinterpret_cast<gpioMap::MemoryMap*>( pPort )->BSRR |= ( 1 << pPin );
		}

		void pinToggle( options::port::_port pPort,
					    options::pin::_pin pPin )
		{
			if ( cf::pinIsHigh( pPort, pPin ) )
			{
				cf::pinSetLow( pPort, pPin );
			}
			else 
			{
				cf::pinSetHigh( pPort, pPin );
			}
		}
	}


}
