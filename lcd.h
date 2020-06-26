/**
 * @brief       lcd.h
 * @details    	Header file for Lcd driver node.
 * @pre         This code belongs to Nimbus Centre ( http://www.nimbus.cit.ie ).
 */

#ifndef __NB_LCD
#define __NB_LCD

#include "mbed.h"
#include "nworkbench.h"
#include "pca8561.h"

class nBlock_Lcd: public nBlockSimpleNode<1>{
	
	public:
	
	nBlock_Lcd(PinName SDA, PinName SCL,char slave_address,char leading_zeros);
	void triggerInput(uint32_t inputNumber, uint32_t value);
	
	private:
	
	pca8561 _lcd;
	char _leading_zeros;
		
};


#endif