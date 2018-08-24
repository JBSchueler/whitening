/*
 * File:   Whitening.h
 * Author: Ben
 *
 * Created on 4 september 2014, 0:20
 */

#ifndef __WHITENING_H
#define __WHITENING_H

#if ARDUINO >= 100
  #include <Arduino.h> // Arduino 1.0
#else
  #include <WProgram.h> // Arduino 0022
#endif

void ComputeWhitening( uint8_t *buffer, uint16_t bufferSize );

#define ComputeDeWhitening( ... )   ComputeWhitening( __VA_ARGS__ )

#endif