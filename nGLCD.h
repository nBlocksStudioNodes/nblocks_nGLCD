/**
 * @brief       nGLCD.h
 * @details    	Header file for nGLCD driver node.
 */

#ifndef __NB_nGLCD
#define __NB_nGLCD

#include "mbed.h"
#include "nworkbench.h"
#include "pca8561.h"

class nBlock_nGLCD: public nBlockSimpleNode<1>{
	
	public:
	
	nBlock_nGLCD(PinName SDA, PinName SCL,char slave_address,char leading_zeros);
	void triggerInput(nBlocks_Message message);
	
	private:
	
	pca8561 _nGLCD;
	char _leading_zeros;
		
};


#endif