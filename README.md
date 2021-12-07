# UART_BOOTLOADER
** This bootloader is designed on TIVA C kit based on tm4c123gh6pm processor.
** This Bootloader is applying checksum validation on each record before flashing on the program memory
** This app is built on CodeComposer studio IDE 

I made the start address of the target app to start from 0x00001000 @ flash memory

* You can modify the start address of your target app with the following steps:

1 -- Modify the macro defined in FPEC.h file
2 -- In your target app code you need to modify the flash start address from the linker script 
3 -- Modify the .intvect section start address to be the same as the flash start address
4 -- If you are going to use interrupts in your target application you need to set the new offset 
     of the Interrupt vector table through the vector offset register (you will find it at address 0xE000ED08)
	 
* Always watch for the length of your app in the memory before you select the start address 

** You will find attached with this project a python script that reads .hex files 
** and send it one record at a time to the TIVA kit through uart 

** Operation steps 
1 -- power up the kit with the code of bootloader on it (kit is currently waiting to receive first record)
2 -- start the python script and enter the com port number on which the kit is connected to your computer 
3 -- You can monitor the progress of the flashing process through the console window of the script
4 -- When flashing is done you will be notified by the script and the bootloader will jump to start execution
	of your target application

** I hope you fing this code helpful & I am waiting for your feedback and discussion 
Contacts : msalah.96@outlook.com
