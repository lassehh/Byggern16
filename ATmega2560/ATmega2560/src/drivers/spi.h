/*
 * spi.h
 *
 * Created: 05.10.2016 10:04:42
 *  Author: elsala
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <stdio.h>

void SPI_master_init();
uint8_t SPI_transcieve(uint8_t data); // Data must be transmitted to receive data. Reading can be done by sending junk data.
void SPI_SS_low();
void SPI_SS_high();

// Constants
#define DDR_SPI	DDRB
#define DD_MOSI	PB2
#define DD_SCK	PB1
#define DD_CS	PB0
#define DD_SS	PB7

#endif /* SPI_H_ */