#include "nGLCD.h"

nBlock_nGLCD :: nBlock_nGLCD(PinName SDA, PinName SCL,char slave_address,char leading_zeros): _nGLCD(SDA,SCL){
	
	_leading_zeros = leading_zeros;
	
	_nGLCD.set_slave_address(slave_address);
    _nGLCD.software_reset();
	_nGLCD.software_reset_release();
    _nGLCD.set_device_ctrl(0x04); // 64 hz
    _nGLCD.set_display_ctrl_1(0x01); // standard power drive scheme, 1:4 multiplex drive mode, 1⁄3 bias (abias = 2), display enabled, device is in power-on mode
    _nGLCD.set_display_ctrl_2(0x00);// leave as defaults
	
	//_nGLCD.display_colon(1);  // todo: this needs to be turned on and off externally may be 2nd input 
		
}


/**
* @brief    triggerInput()
* @details  When the input is triggered, the value on the input split into individual digits to display in the correct position on the nGLCD.
* @param    Number of the input, value of the input.
* @return   NA.
* 
*/


void nBlock_nGLCD :: triggerInput(uint32_t inputNumber, uint32_t value){
	
	
	
	int unit_place = 0;
    int ten_place = 0;
    int hundred_place = 0;
    int thousand_place = 0;
	
	
	
			if(value < 10){
				
				if(_leading_zeros){
					
					_nGLCD.display_number(0,0);
					_nGLCD.display_number(0,1);
					_nGLCD.display_number(0,2);
				}
				else{
				
					_nGLCD.clear_digit(0);
					_nGLCD.clear_digit(1);
					_nGLCD.clear_digit(2);
				}
            
				_nGLCD.display_number(value,3);
					
            }
            
            if(value >= 10 && value < 100){
                
                ten_place = value/10;
                unit_place = value % 10;
				
				if(_leading_zeros){
					
					_nGLCD.display_number(0,0);
					_nGLCD.display_number(0,1);
				}
				else{
					
					_nGLCD.clear_digit(0);
					_nGLCD.clear_digit(1);
				}
				
				
                _nGLCD.display_number(ten_place,2);  
                _nGLCD.display_number(unit_place,3);                
                
            }
            
            if(value >= 100 && value < 1000){
                
                hundred_place = value/100;
                
                ten_place = value/10;
                ten_place = ten_place % 10;
                
                unit_place = value % 10;
				
				if(_leading_zeros){
					
					_nGLCD.display_number(0,0);
				}
				
				else{
					
					 _nGLCD.clear_digit(0);
				}
               
               
				_nGLCD.display_number(hundred_place,1);
				_nGLCD.display_number(ten_place,2); 
                _nGLCD.display_number(unit_place,3);
                       
                
            }
            
            if(value >= 1000 && value <10000){
                
                thousand_place = value/1000;
                
                hundred_place = value/100;
                hundred_place = hundred_place % 10;
                
                ten_place = value/10;
                ten_place = ten_place % 10;
                
                unit_place = value % 10; 

				
                _nGLCD.display_number(thousand_place,0);
				_nGLCD.display_number(hundred_place,1);
				_nGLCD.display_number(ten_place,2);
                _nGLCD.display_number(unit_place,3);
                
               
                
                
            }
            
                      
             
           _nGLCD.display_update();
           
           
	
	
	
	
	
}