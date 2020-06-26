#include "pca8561.h"






pca8561 :: pca8561(PinName SDA, PinName SCL): _i2c(SDA,SCL){
    
    _i2c.frequency (400000);
    
}

/**
* @brief    set_slave_address()
* @details  updates internal address value for slave, hardware connection of pins
*           A0 and A1 determine the address data sheet p 27
* @param    slave address before shifting in w/r bit
* @return   
* @warning  set address of slave before calling any other functions.
* 
*/

void pca8561 :: set_slave_address(char address){
    
    _addr8bit = address << 1;
    
}

/**
* @brief    software_reset()
* @details  Resets driver via i2c
* @param    NA
* @return   
* @warning  Software_reset_release() is called  after this function a 10us delay 
*           required between reset and release. 
* 
*/

void pca8561 :: software_reset(){
    
    char cmd[2];
    
    cmd[0] = SOFTWARE_RESET;                  // Software_reset register
    cmd[1] = 0x2C;                  // software reset
    _i2c.write(_addr8bit,&cmd[0], 2);

    
    
}

/**
* @brief    Software_reset_release()
* @details  Releases the software reset
* @param    NA
* @return   
* @warning  10us delay required between reset and release.
* 
*/

void pca8561 :: software_reset_release(){
    
    char cmd[2];
    
    cmd[0] = SOFTWARE_RESET;                  // Software_reset register
    cmd[1] = 0x00;                  // realese software reset
    _i2c.write(_addr8bit,&cmd[0], 2);
    
    
}

/**
* @brief    set_device_ctrl()
* @details  sets register, freq,osc and clock output see data sheet p7
* @param    value for register
* @return   
* @warning  
* 
*/

void pca8561 :: set_device_ctrl(char value){
    
    char cmd[2];
    
    cmd[0] = DEVICE_CONTROL;
    cmd[1] = value;
    
    _i2c.write(_addr8bit, &cmd[0], 2);
    
}

/**
* @brief    set_display_ctrl_1()
* @details  sets register, power drive scheme, mutiplex mode selection,bias mode selecion, display enable data sheet p8
* @param    value for register
* @return   
* @warning  To Dissable the device clear bit 0 of the value sent as a parameter.
* 
*/

void pca8561 :: set_display_ctrl_1(char value){
    
    char cmd[2];
    
    cmd[0] = DISPLAY_CONTROL_1;
    cmd[1] = value;
    
    _i2c.write(_addr8bit, &cmd[0], 2);
    
    
    
}

/**
* @brief    set_display_ctrl_2()
* @details  sets register, blink control and invession mode selection data sheet p9
* @param    value for register
* @return   
* @warning  
* 
*/

void pca8561 :: set_display_ctrl_2(char value){
    
    char cmd[2];
    
    cmd[0] = DISPLAY_CONTROL_2;
    cmd[1] = value;
    
    _i2c.write(_addr8bit, &cmd[0], 2);
    
}

/**
* @brief    display_number()
* @details  Interface to display functions.
* @param    Number to display and digit position on LCD 0,1,2 or 3.
* @return   
* @warning  
* 
*/

void pca8561 :: display_number(char number, char position){
    
    switch(number){
        
        case 0:
            display_zero(position);
            break;
            
        case 1:
            display_one(position);
            break;
        
        case 2:
            display_two(position);
            break;
            
        case 3:
            display_three(position);
            break;
            
        case 4:
            display_four(position);
            break;
            
        case 5:
            display_five(position);
            break;
            
        case 6:
            display_six(position);
            break;
            
        case 7:
            display_seven(position);
            break;
            
        case 8:
            display_eight(position);
            break;
            
        case 9:
            display_nine(position);
            break;
            
        default:
            break;
            
        
    }
    
}

/**
* @brief    display_update()
* @details  Functions to update the display once the segment registers are updated.
* @param    
* @return   
* @warning  This function must be called once any of the segment registers are 
*           updated or the update will not be reflecetd on the lcd
* 
*/

void pca8561 :: display_update(){
    
    char cmd[2];
    
    cmd[0] = COM0;
    cmd[1] = com0_val;
    _i2c.write(_addr8bit,&cmd[0], 2);
    
    cmd[0] = COM1;
    cmd[1] = com1_val; 
    _i2c.write(_addr8bit,&cmd[0], 2);
    
    cmd[0] = COM2;
    cmd[1] = com2_val;
    _i2c.write(_addr8bit,&cmd[0], 2);
    
    cmd[0] = COM3;
    cmd[1] = com3_val;
    _i2c.write(_addr8bit,&cmd[0], 2);
       
}

/**
* @brief    display_zero()
* @details  Sets selected 7 segment display to zero
* @param    digit 0,1,2 or3 (actual seven segment digit on lcd)
* @return   
* @warning  
* 
*/

void pca8561 :: display_zero(char digit){
    
          
        
    switch (digit){
        
        case 0:
        
            com0_val = set_bit(com0_val,0);
            
            com1_val = set_bit(com1_val,0);
            
            com1_val = set_bit(com1_val,1);
            
            com2_val = clear_bit(com2_val,0);
            
            com2_val = set_bit(com2_val,1);
            
            com3_val = set_bit(com3_val,0);
            
            com3_val = set_bit(com3_val,1);
            
        
            
            
            break;
            
        case 1:
        
            com0_val = set_bit(com0_val,2);
            
            com1_val = set_bit(com1_val,2);
            
            com1_val = set_bit(com1_val,3);
            
            com2_val = clear_bit(com2_val,2);
            
            com2_val = set_bit(com2_val,3);
            
            com3_val = set_bit(com3_val,2);
            
            com3_val = set_bit(com3_val,3);
                       
            break;
            
        case 2:
        
            com0_val = set_bit(com0_val,4);
            
            com1_val = set_bit(com1_val,4);
            
            com1_val = set_bit(com1_val,5);
            
            com2_val = clear_bit(com2_val,4);
            
            com2_val = set_bit(com2_val,5);
            
            com3_val = set_bit(com3_val,4);
            
            com3_val = set_bit(com3_val,5);
        
                       
            break;
            
        case 3:
        
            com0_val = set_bit(com0_val,6);
            
            com1_val = set_bit(com1_val,6);
            
            com1_val = set_bit(com1_val,7);
            
            com2_val = clear_bit(com2_val,6);
            
            com2_val = set_bit(com2_val,7);
            
            com3_val = set_bit(com3_val,6);
            
            com3_val = set_bit(com3_val,7);
            
            break;
            
        default:
            break;
            
    }
    
    
    
}

/**
* @brief    display_one()
* @details  Sets selected 7 segment display to one.
* @param    digit 0,1,2 or3 (actual seven segment digit on lcd there are 4)
* @return   
* @warning  
* 
*/

void pca8561 :: display_one(char digit){
    
    switch (digit){
        
        case 0:
        
            com0_val = clear_bit(com0_val,0);
            
            com1_val = clear_bit(com1_val,0);
            
            com1_val = set_bit(com1_val,1);
            
            com2_val = clear_bit(com2_val,0);
            
            com2_val = set_bit(com2_val,1);
            
            com3_val = clear_bit(com3_val,0);
            
            com3_val = clear_bit(com3_val,1);
        
            break;
            
        case 1:
        
            com0_val = clear_bit(com0_val,2);
            
            com1_val = clear_bit(com1_val,2);
            
            com1_val = set_bit(com1_val,3);
            
            com2_val = clear_bit(com2_val,2);
            
            com2_val = set_bit(com2_val,3);
            
            com3_val = clear_bit(com3_val,2);
            
            com3_val = clear_bit(com3_val,3);
                      
            break;
            
        case 2:
        
           
            com0_val = clear_bit(com0_val,4);
            
            com1_val = clear_bit(com1_val,4);
            
            com1_val = set_bit(com1_val,5);
            
            com2_val = clear_bit(com2_val,4);
            
            com2_val = set_bit(com2_val,5);
            
            com3_val = clear_bit(com3_val,4);
            
            com3_val = clear_bit(com3_val,5);
           
            break;
            
        case 3:
        
            com0_val = clear_bit(com0_val,6);
            
            com1_val = clear_bit(com1_val,6);
            
            com1_val = set_bit(com1_val,7);
            
            com2_val = clear_bit(com2_val,6);
            
            com2_val = set_bit(com2_val,7);
            
            com3_val = clear_bit(com3_val,6);
            
            com3_val = clear_bit(com3_val,7);
                        
            break;
            
        default:
            break;
            
    }
    

}

/**
* @brief    display_two()
* @details  Sets selected 7 segment display to two.
* @param    digit 0,1,2 or3 (actual seven segment digit on lcd there are 4)
* @return   
* @warning  
* 
*/


void pca8561 :: display_two(char digit){
    
    
    
    switch (digit){
        
        case 0:
        
            com0_val = set_bit(com0_val,0);
            
            com1_val = set_bit(com1_val,0);
            
            com1_val = clear_bit(com1_val,1);
            
            com2_val = set_bit(com2_val,0);
            
            com2_val = set_bit(com2_val,1);
            
            com3_val = clear_bit(com3_val,0);
            
            com3_val = set_bit(com3_val,1);
            
            break;
            
        case 1:
            
            com0_val = set_bit(com0_val,2);
            
            com1_val = set_bit(com1_val,2);
            
            com1_val = clear_bit(com1_val,3);
            
            com2_val = set_bit(com2_val,2);
            
            com2_val = set_bit(com2_val,3);
            
            com3_val = clear_bit(com3_val,2);
            
            com3_val = set_bit(com3_val,3);
            
            break;
            
        case 2:
        
            com0_val = set_bit(com0_val,4);
            
            com1_val = set_bit(com1_val,4);
            
            com1_val = clear_bit(com1_val,5);
            
            com2_val = set_bit(com2_val,4);
            
            com2_val = set_bit(com2_val,5);
            
            com3_val = clear_bit(com3_val,4);
            
            com3_val = set_bit(com3_val,5);
            
            break;
            
        case 3:
            
            com0_val = set_bit(com0_val,6);
            
            com1_val = set_bit(com1_val,6);
            
            com1_val = clear_bit(com1_val,7);
            
            com2_val = set_bit(com2_val,6);
            
            com2_val = set_bit(com2_val,7);
            
            com3_val = clear_bit(com3_val,6);
            
            com3_val = set_bit(com3_val,7);
            
            
            break;
            
        default:
            break;
            
    }
    
    
    
    
}
/**
* @brief    display_three()
* @details  Sets selected 7 segment display to three.
* @param    digit 0,1,2 or3 (actual seven segment digit on lcd there are 4)
* @return   
* @warning  
* 
*/

void pca8561 :: display_three(char digit){
    
    
    switch (digit){
        
        case 0:
        
            com0_val = set_bit(com0_val,0);
            
            com1_val = clear_bit(com1_val,0);
            
            com1_val = set_bit(com1_val,1);
            
            com2_val = set_bit(com2_val,0);
            
            com2_val = set_bit(com2_val,1);
            
            com3_val = clear_bit(com3_val,0);
            
            com3_val = set_bit(com3_val,1);
            
            break;
            
        case 1:
            
            com0_val = set_bit(com0_val,2);
            
            com1_val = clear_bit(com1_val,2);
            
            com1_val = set_bit(com1_val,3);
            
            com2_val = set_bit(com2_val,2);
            
            com2_val = set_bit(com2_val,3);
            
            com3_val = clear_bit(com3_val,2);
            
            com3_val = set_bit(com3_val,3);
            
            break;
            
        case 2:
        
            com0_val = set_bit(com0_val,4);
            
            com1_val = clear_bit(com1_val,4);
            
            com1_val = set_bit(com1_val,5);
            
            com2_val = set_bit(com2_val,4);
            
            com2_val = set_bit(com2_val,5);
            
            com3_val = clear_bit(com3_val,4);
            
            com3_val = set_bit(com3_val,5);
            
            break;
            
        case 3:
            
            com0_val = set_bit(com0_val,6);
            
            com1_val = clear_bit(com1_val,6);
            
            com1_val = set_bit(com1_val,7);
            
            com2_val = set_bit(com2_val,6);
            
            com2_val = set_bit(com2_val,7);
            
            com3_val = clear_bit(com3_val,6);
            
            com3_val = set_bit(com3_val,7);
            
            break;
            
        default:
            break;
            
    }
    
}

/**
* @brief    display_four()
* @details  Sets selected 7 segment display to four.
* @param    digit 0,1,2 or3 (actual seven segment digit on lcd there are 4)
* @return   
* @warning  
* 
*/

void pca8561:: display_four(char digit){
    
    
    switch (digit){
        
        case 0:
        
            com0_val = clear_bit(com0_val,0);
            
            com1_val = clear_bit(com1_val,0);
            
            com1_val = set_bit(com1_val,1);
            
            com2_val = set_bit(com2_val,0);
            
            com2_val = set_bit(com2_val,1);
            
            com3_val = set_bit(com3_val,0);
            
            com3_val = clear_bit(com3_val,1);
            
           
            
            break;
            
        case 1:
        
            com0_val = clear_bit(com0_val,2);
            
            com1_val = clear_bit(com1_val,2);
            
            com1_val = set_bit(com1_val,3);
            
            com2_val = set_bit(com2_val,2);
            
            com2_val = set_bit(com2_val,3);
            
            com3_val = set_bit(com3_val,2);
            
            com3_val = clear_bit(com3_val,3);
            
            break;
            
        case 2:
        
            com0_val = clear_bit(com0_val,4);
            
            com1_val = clear_bit(com1_val,4);
            
            com1_val = set_bit(com1_val,5);
            
            com2_val = set_bit(com2_val,4);
            
            com2_val = set_bit(com2_val,5);
            
            com3_val = set_bit(com3_val,4);
            
            com3_val = clear_bit(com3_val,5);
            
            break;
            
        case 3:
        
            com0_val = clear_bit(com0_val,6);
            
            com1_val = clear_bit(com1_val,6);
            
            com1_val = set_bit(com1_val,7);
            
            com2_val = set_bit(com2_val,6);
            
            com2_val = set_bit(com2_val,7);
            
            com3_val = set_bit(com3_val,6);
            
            com3_val = clear_bit(com3_val,7);
            
            break;
            
        default:
            break;
            
    }
    
   
}

/**
* @brief    display_five()
* @details  Sets selected 7 segment display to five.
* @param    digit 0,1,2 or3 (actual seven segment digit on lcd there are 4)
* @return   
* @warning  
* 
*/

void pca8561 :: display_five(char digit){
    
   
    
    switch (digit){
        
        case 0:
        
            com0_val = set_bit(com0_val,0);
            
            com1_val = clear_bit(com1_val,0);
            
            com1_val = set_bit(com1_val,1);
            
            com2_val = set_bit(com2_val,0);
            
            com2_val = clear_bit(com2_val,1);
            
            com3_val = set_bit(com3_val,0);
            
            com3_val = set_bit(com3_val,1);
            
            break;
            
        case 1:
            
            com0_val = set_bit(com0_val,2);
            
            com1_val = clear_bit(com1_val,2);
            
            com1_val = set_bit(com1_val,3);
            
            com2_val = set_bit(com2_val,2);
            
            com2_val = clear_bit(com2_val,3);
            
            com3_val = set_bit(com3_val,2);
            
            com3_val = set_bit(com3_val,3);
            
            break;
            
        case 2:
        
            com0_val = set_bit(com0_val,4);
            
            com1_val = clear_bit(com1_val,4);
            
            com1_val = set_bit(com1_val,5);
            
            com2_val = set_bit(com2_val,4);
            
            com2_val = clear_bit(com2_val,5);
            
            com3_val = set_bit(com3_val,4);
            
            com3_val = set_bit(com3_val,5);
            
            break;
            
        case 3:
            
            com0_val = set_bit(com0_val,6);
            
            com1_val = clear_bit(com1_val,6);
            
            com1_val = set_bit(com1_val,7);
            
            com2_val = set_bit(com2_val,6);
            
            com2_val = clear_bit(com2_val,7);
            
            com3_val = set_bit(com3_val,6);
            
            com3_val = set_bit(com3_val,7);
            
            break;
            
        default:
            break;
            
    }
    
}

/**
* @brief    display_six()
* @details  Sets selected 7 segment display to six.
* @param    digit 0,1,2 or3 (actual seven segment digit on lcd there are 4)
* @return   
* @warning  
* 
*/


void pca8561 :: display_six(char digit){
    
    
    switch (digit){
        
        case 0:
        
            com0_val = set_bit(com0_val,0);
            
            com1_val = set_bit(com1_val,0);
            
            com1_val = set_bit(com1_val,1);
            
            com2_val = set_bit(com2_val,0);
            
            com2_val = clear_bit(com2_val,1);
            
            com3_val = set_bit(com3_val,0);
            
            com3_val = set_bit(com3_val,1);
            
            break;
            
        case 1:
            
            com0_val = set_bit(com0_val,2);
            
            com1_val = set_bit(com1_val,2);
            
            com1_val = set_bit(com1_val,3);
            
            com2_val = set_bit(com2_val,2);
            
            com2_val = clear_bit(com2_val,3);
            
            com3_val = set_bit(com3_val,2);
            
            com3_val = set_bit(com3_val,3);
            
            break;
            
        case 2:
        
            com0_val = set_bit(com0_val,4);
            
            com1_val = set_bit(com1_val,4);
            
            com1_val = set_bit(com1_val,5);
            
            com2_val = set_bit(com2_val,4);
            
            com2_val = clear_bit(com2_val,5);
            
            com3_val = set_bit(com3_val,4);
            
            com3_val = set_bit(com3_val,5);
            
            break;
            
        case 3:
            
            com0_val = set_bit(com0_val,6);
            
            com1_val = set_bit(com1_val,6);
            
            com1_val = set_bit(com1_val,7);
            
            com2_val = set_bit(com2_val,6);
            
            com2_val = clear_bit(com2_val,7);
            
            com3_val = set_bit(com3_val,6);
            
            com3_val = set_bit(com3_val,7);
            
            break;
            
        default:
            break;
            
    }
    
    
    
}

/**
* @brief    display_seven()
* @details  Sets selected 7 segment display to seven.
* @param    digit 0,1,2 or3 (actual seven segment digit on lcd there are 4)
* @return   
* @warning  
* 
*/

void pca8561 :: display_seven(char digit){
    
       
    switch (digit){
        
        case 0:
        
            com0_val = clear_bit(com0_val,0);
            
            com1_val = clear_bit(com1_val,0);
            
            com1_val = set_bit(com1_val,1);
            
            com2_val = clear_bit(com2_val,0);
            
            com2_val = set_bit(com2_val,1);
            
            com3_val = clear_bit(com3_val,0);
            
            com3_val = set_bit(com3_val,1);
        
                      
            break;
            
        case 1:
        
            com0_val = clear_bit(com0_val,2);
            
            com1_val = clear_bit(com1_val,2);
            
            com1_val = set_bit(com1_val,3);
            
            com2_val = clear_bit(com2_val,2);
            
            com2_val = set_bit(com2_val,3);
            
            com3_val = clear_bit(com3_val,2);
            
            com3_val = set_bit(com3_val,3);
                       
            break;
            
        case 2:
        
            com0_val = clear_bit(com0_val,4);
            
            com1_val = clear_bit(com1_val,4);
            
            com1_val = set_bit(com1_val,5);
            
            com2_val = clear_bit(com2_val,4);
            
            com2_val = set_bit(com2_val,5);
            
            com3_val = clear_bit(com3_val,4);
            
            com3_val = set_bit(com3_val,5);
                     
            break;
            
        case 3:
        
            com0_val = clear_bit(com0_val,6);
            
            com1_val = clear_bit(com1_val,6);
            
            com1_val = set_bit(com1_val,7);
            
            com2_val = clear_bit(com2_val,6);
            
            com2_val = set_bit(com2_val,7);
            
            com3_val = clear_bit(com3_val,6);
            
            com3_val = set_bit(com3_val,7);
                                  
            break;
            
        default:
            break;
            
    }
      
}

/**
* @brief    display_eight()
* @details  Sets selected 7 segment display to eight.
* @param    digit 0,1,2 or3 (actual seven segment digit on lcd there are 4)
* @return   
* @warning  
* 
*/

void pca8561 :: display_eight(char digit){
    
    
    switch (digit){
        
        case 0:
        
            com0_val = set_bit(com0_val,0);
            
            com1_val = set_bit(com1_val,0);
            
            com1_val = set_bit(com1_val,1);
            
            com2_val = set_bit(com2_val,0);
            
            com2_val = set_bit(com2_val,1);
            
            com3_val = set_bit(com3_val,0);
            
            com3_val = set_bit(com3_val,1);
            
            break;
            
        case 1:
            
            com0_val = set_bit(com0_val,2);
            
            com1_val = set_bit(com1_val,2);
            
            com1_val = set_bit(com1_val,3);
            
            com2_val = set_bit(com2_val,2);
            
            com2_val = set_bit(com2_val,3);
            
            com3_val = set_bit(com3_val,2);
            
            com3_val = set_bit(com3_val,3);
            
            break;
            
        case 2:
        
            com0_val = set_bit(com0_val,4);
            
            com1_val = set_bit(com1_val,4);
            
            com1_val = set_bit(com1_val,5);
            
            com2_val = set_bit(com2_val,4);
            
            com2_val = set_bit(com2_val,5);
            
            com3_val = set_bit(com3_val,4);
            
            com3_val = set_bit(com3_val,5);
            
            break;
            
        case 3:
            
            com0_val = set_bit(com0_val,6);
            
            com1_val = set_bit(com1_val,6);
            
            com1_val = set_bit(com1_val,7);
            
            com2_val = set_bit(com2_val,6);
            
            com2_val = set_bit(com2_val,7);
            
            com3_val = set_bit(com3_val,6);
            
            com3_val = set_bit(com3_val,7);
            
            break;
            
        default:
            break;
            
    }
    
}

/**
* @brief    display_nine()
* @details  Sets selected 7 segment display to nine.
* @param    digit 0,1,2 or3 (actual seven segment digit on lcd there are 4)
* @return   
* @warning  
* 
*/

void pca8561 :: display_nine(char digit){
    
     
    
    switch (digit){
        
        case 0:
        
            com0_val = clear_bit(com0_val,0);
            
            com1_val = clear_bit(com1_val,0);
            
            com1_val = set_bit(com1_val,1);
            
            com2_val = set_bit(com2_val,0);
            
            com2_val = set_bit(com2_val,1);
            
            com3_val = set_bit(com3_val,0);
            
            com3_val = set_bit(com3_val,1);
            
            break;
            
        case 1:
            
            com0_val = clear_bit(com0_val,2);
            
            com1_val = clear_bit(com1_val,2);
            
            com1_val = set_bit(com1_val,3);
            
            com2_val = set_bit(com2_val,2);
            
            com2_val = set_bit(com2_val,3);
            
            com3_val = set_bit(com3_val,2);
            
            com3_val = set_bit(com3_val,3);
            
            break;
            
        case 2:
        
            com0_val = clear_bit(com0_val,4);
            
            com1_val = clear_bit(com1_val,4);
            
            com1_val = set_bit(com1_val,5);
            
            com2_val = set_bit(com2_val,4);
            
            com2_val = set_bit(com2_val,5);
            
            com3_val = set_bit(com3_val,4);
            
            com3_val = set_bit(com3_val,5);
            
            break;
            
        case 3:
            
            com0_val = clear_bit(com0_val,6);
            
            com1_val = clear_bit(com1_val,6);
            
            com1_val = set_bit(com1_val,7);
            
            com2_val = set_bit(com2_val,6);
            
            com2_val = set_bit(com2_val,7);
            
            com3_val = set_bit(com3_val,6);
            
            com3_val = set_bit(com3_val,7);
            
            break;
            
        default:
            break;
            
    }
       
}

/**
* @brief    display_dp1()
* @details  Sets of clears the 1st decimal point segment bit.
* @param    status for decimal point off or on.
* @return   
* @warning  
* 
*/

void pca8561 :: display_dp1(char status){
    
    
    switch(status){
        
        case OFF:
        
            com0_val = clear_bit(com0_val,1);
            break;
            
        case ON:
        
            com0_val = set_bit(com0_val,1);
            break;
            
        default:
            break;   
        
    }
    
    
    
}



/**
* @brief    display_dp2()
* @details  Sets or clears the 2nd decimal point segment bit.
* @param    status for decimal point off or on.
* @return   
* @warning  
* 
*/

void pca8561 :: display_dp2(char status){
    
    
    switch(status){
        
        case OFF:
        
            com0_val = clear_bit(com0_val,3);
            break;
            
        case ON:
        
            com0_val = set_bit(com0_val,3);
            break;
            
        default:
            break;   
        
    }
    
    
    
}

/**
* @brief    display_dp3()
* @details  Sets or clears the 3rd decimal point segment bit.
* @param    status for decimal point off or on.
* @return   
* @warning  
* 
*/

void pca8561 :: display_dp3(char status){
    
    
    switch(status){
        
        case OFF:
        
            com0_val = clear_bit(com0_val,5);
            break;
            
        case ON:
        
            com0_val = set_bit(com0_val,5);
            break;
            
        default:
            break;   
        
    }
    
    
    
}

/**
* @brief    display_colon()
* @details  Sets or clears the colon segment bit.
* @param    status for colon off or on.
* @return   
* @warning  
* 
*/

void pca8561 :: display_colon(char status){
    
    
    switch(status){
        
        case OFF:
        
            com0_val = clear_bit(com0_val,7);
            break;
            
        case ON:
        
            com0_val = set_bit(com0_val,7);
            break;
            
        default:
            break;   
        
    }  
    
}

/**
* @brief    clear_digit()
* @details  Clears the digit in the given position 0,1,2 or3
* @param    Position of digit to be cleared.
* @return   
* @warning  display_update()function must be called after for changes to take effect.
* 
*/

void pca8561 :: clear_digit(char position){
    
    switch(position){
        
        case 0:
        
            com0_val = clear_bit(com0_val,0);
            
            com1_val = clear_bit(com1_val,0);
            
            com1_val = clear_bit(com1_val,1);
            
            com2_val = clear_bit(com2_val,0);
            
            com2_val = clear_bit(com2_val,1);
            
            com3_val = clear_bit(com3_val,0);
            
            com3_val = clear_bit(com3_val,1);
            
            break;
            
        case 1:
        
            com0_val = clear_bit(com0_val,2);
            
            com1_val = clear_bit(com1_val,2);
            
            com1_val = clear_bit(com1_val,3);
            
            com2_val = clear_bit(com2_val,2);
            
            com2_val = clear_bit(com2_val,3);
            
            com3_val = clear_bit(com3_val,2);
            
            com3_val = clear_bit(com3_val,3);
            
            break;
            
        case 2:
        
            com0_val = clear_bit(com0_val,4);
            
            com1_val = clear_bit(com1_val,4);
            
            com1_val = clear_bit(com1_val,5);
            
            com2_val = clear_bit(com2_val,4);
            
            com2_val = clear_bit(com2_val,5);
            
            com3_val = clear_bit(com3_val,4);
            
            com3_val = clear_bit(com3_val,5);
            
            break;
            
        case 3:
        
            com0_val = clear_bit(com0_val,6);
            
            com1_val = clear_bit(com1_val,6);
            
            com1_val = clear_bit(com1_val,7);
            
            com2_val = clear_bit(com2_val,6);
            
            com2_val = clear_bit(com2_val,7);
            
            com3_val = clear_bit(com3_val,6);
            
            com3_val = clear_bit(com3_val,7);
            
            break;
            
        default:
            break;
            
        
    }
    
}



/**
* @brief    set_bit()
* @details  Function to set individual bits of value to send to segment register.
* @param    byte to be sent to register.
* @param    The bitnumber of bit to be set.
* @return   the modified byte.
* @warning  
* 
*/

char pca8561 :: set_bit(char byte,char bit_number){
    
    char mask = 1;
    mask = mask << bit_number;
    byte = byte | mask;
    
    return byte;
    
    
}

/**
* @brief    clear_bit()
* @details  Function to clear individual bits of value to send to segment register.
* @param    byte to be sent to register.
* @param    The bitnumber of bit to be cleared.
* @return   the modified byte.
* @warning  
* 
*/

char pca8561 :: clear_bit(char byte,char bit_number){
    
    char mask = 1;
    mask = mask << bit_number;
    mask = ~mask;
    byte = byte & mask;
    
    return byte;
    
}



