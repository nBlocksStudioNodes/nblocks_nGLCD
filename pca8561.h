/**
* @file     pca8561.h
* @brief    header file for lcd driver interface.
* 
*
* @author   Ian Aherne
*
* @date     19/09/18
*/

#ifndef PCA8561_H
#define PCA8561_H

#include "mbed.h"


class pca8561{
    
    
    public:
    
        typedef enum{
            
            SOFTWARE_RESET = 0x00,
            DEVICE_CONTROL = 0x01,
            DISPLAY_CONTROL_1 = 0x02,
            DISPLAY_CONTROL_2 = 0x03,
            
        }commandRegisters_t;
        
        /* display registers, each common has 3 register addresses for seg 0-7,seg 8-15,seg16-17 below is for 8 segment LCD only*/
        
        typedef enum{
            
            COM0 = 0x04,
            COM1 = 0x07,
            COM2 = 0x0A,
            COM3 = 0x0D
            
        }displayDataRegisters_t;
        
      
        
        typedef enum{
            
            OFF = 0 ,
            ON  = 1  
            
        }states_t;
    
        pca8561(PinName SDA, PinName SCL);
        void set_slave_address(char address = 0x38);// default
        void software_reset();
		void software_reset_release();
        void set_device_ctrl(char value);
        void set_display_ctrl_1(char value);
        void set_display_ctrl_2(char value);
        
        void display_number(char number,char position);
        
        void display_update();
        
        void display_zero(char digit);
        void display_one(char digit);
        void display_two(char digit);
        void display_three(char digit);
        void display_four(char digit);
        void display_five(char digit);
        void display_six(char digit);
        void display_seven(char digit);
        void display_eight(char digit);
        void display_nine(char digit);
        void display_dp1(char status);
        void display_dp2(char status);
        void display_dp3(char status);
        void display_colon(char status);
        
        void clear_digit(char position);
        
        char set_bit(char byte, char bit_number);
        char clear_bit(char byte,char bit_number);
        
    
    
    private:
    
        I2C _i2c;
        int _addr8bit;// 8bit I2C address, 0x70 page 27 data sheet A0 and A1 are 0
        char com0_val;
        char com1_val;
        char com2_val;
        char com3_val;
    
    
    
    
    
    
};










#endif