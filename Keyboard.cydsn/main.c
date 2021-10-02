/*
Keyboard PSoC - V1.0
Code by adrianyyxy
Date: 10/02/2021
*/

#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8 key, row; //values to read the pin
char str[16];   //variable to save the data
uint8 c=0;   //control of the pins iteration
uint8 p=0;    //position pointer

void message()
{
    LCD_Position(0,0);
    LCD_PrintString("Write:");
}

//change the status of the pins
CY_ISR(INT_IT){
    if(c==1){
        Columns_Write(0x0E);
    }
    if(c==2){
        Columns_Write(0x0D);
    }
    if(c==3){
        Columns_Write(0x0B);
    }
    if(c==4){
        Columns_Write(0x07);
        c=0;
    }
    c++;
}

//read the keyboard
CY_ISR(INT_KB){
    
    row=Rows_Read();    //read the status of the Rows
    key=Columns_Read(); //read the status fo the Columns
    key=key<<4; //move the bits to the left
    key=key|row;    //or
    
    /*
    LCD_Position(x,p);  //select the position to write the key - x is row and p is column
    str[p]='1'; //save the key in the position of the chain - p is position
    LCD_PutChar('1');   //function to show in the LCD
    p++;    //change position
    */
    
    if(key==0x7E){
        LCD_Position(1,p);
        str[p]='1';
        LCD_PutChar('1');
        p++;
    }
    if(key==0x7D){
        LCD_Position(1,p);
        str[p]='2';
        LCD_PutChar('2');
        p++;
    }
    if(key==0x7B){
        LCD_Position(1,p);
        str[p]='3';
        LCD_PutChar('3');
        p++;
    }
    if(key==0x77){  //A - Delete the previus position
        //////////////////////
        //the if function is needed so as not to break the function with negative numbers / positions 
        if(0<p){    //as long as p is greater than 0, we can return to the previus position
            p--;    //return a position
            str[p]=' '; //write nothing/"clear" the chain
            LCD_Position(1,p); //select the position to write
            LCD_PutChar(' ');   //write a nothing in the position - clear the position
            
        }
        //do nothing if the position is zero - dont move to the p[-1] position
        else{
        }
        //////////////////////
    }
    if(key==0xBE){
        LCD_Position(1,p);
        str[p]='4';
        LCD_PutChar('4');
        p++;
    }
    if(key==0xBD){
        LCD_Position(1,p);
        str[p]='5';
        LCD_PutChar('5');
        p++;
    }
    if(key==0xBB){
        LCD_Position(1,p);
        str[p]='6';
        LCD_PutChar('6');
        p++;
    }
    if(key==0xB7){  //B - Delete all
        LCD_ClearDisplay(); //Clear the display
        message();  //Print a message
        strcpy(str,""); //Clear the chain variable
        p=0;    //Restart the position of the chain and the prints functions
    }
    if(key==0xDE){
        LCD_Position(1,p);
        str[p]='7';
        LCD_PutChar('7');
        p++;
    }
    if(key==0xDD){
        LCD_Position(1,p);
        str[p]='8';
        LCD_PutChar('8');
        p++;
    }
    if(key==0xDB){
        LCD_Position(1,p);
        str[p]='9';
        LCD_PutChar('9');
        p++;
    }
    if(key==0xD7){  //C - No fuction
        LCD_Position(1,p);
        str[p]='1';
        LCD_PutChar('1');
        p++;
    }
    if(key==0xEE){  //* - No fuction
        LCD_Position(1,p);
        str[p]='1';
        LCD_PutChar('1');
        p++;
    }
    if(key==0xED){
        LCD_Position(1,p);
        str[p]='0';
        LCD_PutChar('0');
        p++;
    }
    if(key==0xEB){  //# - No fuction
        LCD_Position(1,p);
        str[p]='1';
        LCD_PutChar('1');
        p++;
    }
    if(key==0xE7){  //D - Enter or change to the window (?) its something like that
        LCD_ClearDisplay(); //clear the screen
        LCD_Position(0,0);  //select the position
        LCD_PrintString(str);   //write the chain
        //////////////////////
        //function to clear the chain
        for(int i=0;i!=p;i++){
            str[i]=' ';
        }
        //////////////////////
        p=0;    //restart the positions of the functions
        //////////////////////
    }
    
    while(Rows_Read()!=0x0F)

    CyDelay(10);
    Rows_ClearInterrupt();

}



int main(void)
{
    CyGlobalIntEnable;
    
    //Inicializate the modules
    LCD_Start();
    Timer_Start();
    
    //Inicializate interrupts
    isr_Keyboard_StartEx(INT_KB);
    isr_Iteration_StartEx(INT_IT);
    
    //print the message
    message();
    for(;;)
    {
    }
}