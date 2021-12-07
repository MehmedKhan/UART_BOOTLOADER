/****************************************
 *  GPIO.h
 *
 *  Created on: Nov 25, 2021
 *  Author: Mohamed Salah
 *
 ****************************************/

#ifndef TM4C123GH6PM_REGISTERS
#define TM4C123GH6PM_REGISTERS

/*****************************************************************************
GPIO registers (PORTA)
*****************************************************************************/
#define GPIO_PORTA_DATA_REG       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_REG        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_REG      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_PUR_REG        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_PDR_REG        (*((volatile unsigned long *)0x40004514))
#define GPIO_PORTA_DEN_REG        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_LOCK_REG       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_REG         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_REG      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_REG       (*((volatile unsigned long *)0x4000452C))

/*****************************************************************************
GPIO registers (PORTB)
*****************************************************************************/
#define GPIO_PORTB_DATA_REG       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_REG        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_REG      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PUR_REG        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_PDR_REG        (*((volatile unsigned long *)0x40005514))
#define GPIO_PORTB_DEN_REG        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_REG       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_REG         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_REG      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_REG       (*((volatile unsigned long *)0x4000552C))

/*****************************************************************************
GPIO registers (PORTC)
*****************************************************************************/
#define GPIO_PORTC_DATA_REG       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTC_DIR_REG        (*((volatile unsigned long *)0x40006400))
#define GPIO_PORTC_AFSEL_REG      (*((volatile unsigned long *)0x40006420))
#define GPIO_PORTC_PUR_REG        (*((volatile unsigned long *)0x40006510))
#define GPIO_PORTC_PDR_REG        (*((volatile unsigned long *)0x40006514))
#define GPIO_PORTC_DEN_REG        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_LOCK_REG       (*((volatile unsigned long *)0x40006520))
#define GPIO_PORTC_CR_REG         (*((volatile unsigned long *)0x40006524))
#define GPIO_PORTC_AMSEL_REG      (*((volatile unsigned long *)0x40006528))
#define GPIO_PORTC_PCTL_REG       (*((volatile unsigned long *)0x4000652C))

/*****************************************************************************
GPIO registers (PORTD)
*****************************************************************************/
#define GPIO_PORTD_DATA_REG       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_REG        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_AFSEL_REG      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_PUR_REG        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_PDR_REG        (*((volatile unsigned long *)0x40007514))
#define GPIO_PORTD_DEN_REG        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_LOCK_REG       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_REG         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_REG      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_REG       (*((volatile unsigned long *)0x4000752C))

/*****************************************************************************
GPIO registers (PORTE)
*****************************************************************************/
#define GPIO_PORTE_DATA_REG       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_REG        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_REG      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PUR_REG        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_PDR_REG        (*((volatile unsigned long *)0x40024514))
#define GPIO_PORTE_DEN_REG        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_REG       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_REG         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_REG      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_REG       (*((volatile unsigned long *)0x4002452C))

/*****************************************************************************
GPIO registers (PORTF)
*****************************************************************************/
#define GPIO_PORTF_DATA_REG       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_REG        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_REG        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_DEN_REG        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile unsigned long *)0x4002552C))

/*****************************************************************************
GPIO CLOCK ENABLE REGISTERS
*****************************************************************************/
#define RCGC_GPIO_REG             (*((volatile unsigned long *)0x400FE108))


/*****************************************************************************
SYSTICK TIMER
*****************************************************************************/
#define SYSTICK_CTRL_REG          (*((volatile unsigned long *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile unsigned long *)0xE000E014))
#define SYSTICK_CUR_VAL_REG       (*((volatile unsigned long *)0xE000E018))

#endif



