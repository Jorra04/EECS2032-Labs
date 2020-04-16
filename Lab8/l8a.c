/**
 * @file    LAB_8_Part_1.c
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
    PRINTF("Hello World\n");

    //turns on the ports
    SIM->SCGC5 |= ((1<<9) | (1<<11) | (1<<12) | (1<<13));

    //configures portA
    PORTA->PCR[4] = 0x103; //port A pin 4 GPIO(mux = 001) PS=PE=1 pull up resistor
    //configures portC
    PORTC->PCR[4] = 0x103; //port C pin 4 GPIO(mux = 001) PS=PE=1 pull up resistor
    //configures portD
    PORTD->PCR[5] = 0x100; //port D pin 5 GPIO (mux = 1) PS=PE=0 no pull up or down
    //configures portE
    PORTE->PCR[31] = 0x100; //port E pin 31 GPIO (mux = 1) PS=PE=0 no pull up or down

    //sets the port function
    PTA->PDDR &= ~(0x10); // set bit 4 of port A to 0 (input)
    PTC->PDDR &= ~(0x10);
    PTD->PDDR |= (1 << 5);// set bit 5 of port D to 1 (pin 5 is output)
    PTE->PDDR |= (1 << 31);

    //sets the default state to off
    PTD->PDOR = (1<<5); // set G_LED off
    PTE->PDOR = (1<<31); // set R_LED off

    bool temp = false;

    while(1) {

    	volatile int SW1 = PTA->PDIR & (1<<4); //SW1
    	volatile int SW3 = PTC->PDIR & (1<<4); //SW3

        if(SW1 == 1 && SW3 == 0){
        	PTD->PDOR = 0;
        	PTE->PDOR = 0;
         }else{
        	PTD->PDOR = (1<<5);
        	PTE->PDOR = (1<<31);
        }


        if(SW1 == 1 && SW3 == 1){
        	temp = true;
        }

        while(temp){
        	SW1 = PTA->PDIR & (1<<4); //SW1
        	SW3 = PTC->PDIR & (1<<4); //SW3

        	PTD->PDOR = 0;
        	PTE->PDOR = (1<<31);

        	if((SW1 == 0 && SW3 == 1) || (SW1 == 1 && SW3 == 0)){
        		PTE->PDOR = 0;
        		PTD->PDOR = (1<<31);
        	}else{
        		temp = false;
        	}

        }


    }

    return 0;
}
