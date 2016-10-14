//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "Timer.h"
#include "BlinkLed.h"

#include "../include/gwlibstm32cpp/include/Common.h"
#include "../include/gwlibstm32cpp/include/Gpio.h"
#include "../include/gwlibstm32cpp/include/Clock.h"

// ----------------------------------------------------------------------------
//
// Semihosting STM32F4 led blink sample (trace via DEBUG).
//
// In debug configurations, demonstrate how to print a greeting message
// on the trace device. In release configurations the message is
// simply discarded.
//
// To demonstrate semihosting, display a message on the standard output
// and another message on the standard error.
//
// Then demonstrates how to blink a led with 1 Hz, using a
// continuous loop and SysTick delays.
//
// On DEBUG, the uptime in seconds is also displayed on the trace device.
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// Definitions visible only within this translation unit.
namespace
{
  // ----- Timing definitions -------------------------------------------------

  // Keep the LED on for 2/3 of a second.
  constexpr Timer::ticks_t BLINK_ON_TICKS = Timer::FREQUENCY_HZ * 1 / 2;
  constexpr Timer::ticks_t BLINK_OFF_TICKS = Timer::FREQUENCY_HZ
      - BLINK_ON_TICKS;
}

// ----- LED definitions ------------------------------------------------------
#warning "Assume a STM32F4-Discovery board, PD12-PD15, active high."
// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int main(int argc, char* argv[])
{
  // Show the program parameters (passed via semihosting).
  // Output is via the semihosting output channel.
  trace_dump_args(argc, argv);

  // Send a greeting to the trace device (skipped on Release).
  trace_puts("Hello ARM World!");

  // Send a message to the standard output.
  puts("Standard output message.");

  // Send a message to the standard error.
  fprintf(stderr, "Standard error message.\n");

  // At this stage the system clock should have already been configured
  // at high speed.
  trace_printf("System clock: %u Hz\n", SystemCoreClock);

  Timer timer;
  timer.start ();

  // Perform all necessary initialisations for the LEDs.

  SYSTEM_CLOCK::enableClockGpio( clock::config::peripherals::gpio::PORTD );

  PD12::setMode( gpio::config::mode::OUTPUT );
  PD12::setOutputType( gpio::config::outputType::PUSH_PULL );
  PD12::setOutputSpeed( gpio::config::outputSpeed::HIGH );
  PD12::setPullResistor( gpio::config::pullResistor::PULL_UP );

  uint32_t seconds = 0;

  // First second is long.
  timer.sleep (Timer::FREQUENCY_HZ);
  PD12::setHigh();
  timer.sleep (Timer::FREQUENCY_HZ);
  PD12::setLow();
  timer.sleep (Timer::FREQUENCY_HZ);

  u8 q = 0;
  for ( q = 0; q < 5; q++ )
  {
    PD12::toggle();
    timer.sleep (BLINK_ON_TICKS);
    PD12::toggle();
    timer.sleep (BLINK_OFF_TICKS);
    seconds++;
  }

  timer.sleep (Timer::FREQUENCY_HZ);

  ++seconds;

  trace_printf ("Second %u\n", seconds);


  return 0;
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
