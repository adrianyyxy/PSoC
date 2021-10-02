#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8 key, row;
char str[16];
uint8 contador=0;
uint8 p=0;    //posicion

void message()
{
    LCD_Position(0,0);
    LCD_PrintString("Prueba:");
}

CY_ISR(INT_Cambio){
    if(contador==1){
        Columns_Write(0x0E);
    }
    if(contador==2){
        Columns_Write(0x0D);
    }
    if(contador==3){
        Columns_Write(0x0B);
    }
    if(contador==4){
        Columns_Write(0x07);
        contador=0;
    }
    contador++;
}

CY_ISR(INT_KB){
    
    row=Rows_Read();
    key=Columns_Read();
    key=key<<4;
    key=key|row;
    
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
    if(key==0x77){  //A - Retroceder
        //////////////////////
        if(0<p){
            p--;
            str[p]=' ';
            LCD_Position(1,p);
            LCD_PutChar(' ');
            
        }
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
    if(key==0xB7){  //B de Burro, ah no cierto, B de borrar todo
        LCD_ClearDisplay();
        message();
        strcpy(str,"");
        p=0;
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
    if(key==0xD7){  //C
        LCD_Position(1,p);
        str[p]='1';
        LCD_PutChar('1');
        p++;
    }
    if(key==0xEE){  //*
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
    if(key==0xEB){  //#
        LCD_Position(1,p);
        str[p]='1';
        LCD_PutChar('1');
        p++;
    }
    if(key==0xE7){  //D - Enter
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString(str);
        //////////////////////
        for(int i=0;i!=p;i++){
            str[i]=' ';
        }
        p=0;
        //////////////////////
    }
    
    while(Rows_Read()!=0x0F)

    CyDelay(10);
    Rows_ClearInterrupt();

}



int main(void)
{
    CyGlobalIntEnable;
    
    LCD_Start();
    Timer_Start();
    
    isr_Start_StartEx(INT_KB);
    isr_Cambio_StartEx(INT_Cambio);

    message();
    for(;;)
    {
    }
}