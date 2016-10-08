

#pragma once

#include "../include/Gpio.h"

namespace gpio
{


	template<options::port::_port pPort,options::pin::_pin pPin>
	void TPin<pPort,pPin>::setMode( config::mode::_mode pMode )
	{

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

	}


	namespace cf
	{
		void pinSetMode( options::port::_port pPort,
			   			 options::pin::_pin pPin,
			   			 config::mode::_mode pMode )
		{

		}
	}


}