/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    MKL43Z256xxx4_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL43Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */



int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();


    //turn on both LEDS
    //SW3 service interrupt routine turns red led off sets global flag
    //main program waits 3 seconds then turns green led off


    //turns on the ports
    SIM->SCGC5 |= ((1<<11) | (1<<12) | (1<<13));

    //configures portD pin 5
    PORTD->PCR[5] = 0x100; //port D pin 5 GPIO (mux = 1) PS=PE=0 no pull up or down
    //configures portE pin 11
    PORTE->PCR[31] = 0x100; //port E pin 31 GPIO (mux = 1) PS=PE=0 no pull up or down
    //configure portC
    PTC->PDDR &=~0x08;

    PTD->PDDR |= (1 << 5);	//set bit 5 of port D to 1 (pin 5 is output)
    PTE->PDDR |= (1 << 31); //set bit 31 of port E to 1 (pin 11 is output)
    PORTC->PCR[3] |= 0x103; //configure the mux and pull up resistor

    //turn on the LEDS
    PTD->PDOR = 0; // set G_LED off
    PTE->PDOR = 0; // set R_LED off


    PORTC->PCR[3] &= ~0xF0000;	//Set field IRQC to 0000 (disable ISF)
    PORTC->PCR[3] |= 0xA0000; 	//Set field IRQC to 1010 (ISF flag and falling edge)

    NVIC_SetPriority(PORTC_PORTD_IRQn, 192);
    NVIC_ClearPendingIRQ(PORTC_PORTD_IRQn);

    NVIC_EnableIRQ(PORTC_PORTD_IRQn);
    __enable_irq();


    //enable the 3 second clock delay
    SysTick->CTRL |= 1<<0 | 1<<2;
    SysTick->LOAD = 0x8954400;


    while(1) {
    	if(PORT_PCR_ISF_MASK & (1 << 3)){ //check the state of the flag
        	while((SysTick->CTRL & 0x10000) == 0) {} // wait for clock
        	PTD->PDOR = (1<<5); // set G_LED off
    	}
    }

    return 0 ;

}

void PORTC_PORTD_IRQHandler(void) {

    switch(PORTC->ISFR) { // when there is an interrupt, the corresponding bit=1
        case(0b1000): // there is an interrupt on pin 3
            PORTC->PCR[3] |= PORT_PCR_ISF_MASK; //clear the flag
        	PTE->PDOR = (1<<31); // set R_LED off
            break;
    }
}
