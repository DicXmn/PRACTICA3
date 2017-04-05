#include <18F4620.h>
#include <stdlib.h>
#include <stdio.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG

#use delay(clock=16000000)

int8 timeCounter100ms=0;
int8 timeCounter500ms=0; 
int8 timeCounter1000ms=0; 
int8 timeCounter1500ms=0;
int8 resultPortA=1;
int8 resultPortB=1;
int8 resultPortC=1;
int8 resultPortD=1;
#int_timer0
void timer_0()
{
   timeCounter100ms++;
   timeCounter500ms++; 
   timeCounter1000ms++;
   timeCounter1500ms++;
}

void main()
{
   setup_timer_0(rtcc_internal|rtcc_div_256|rtcc_8_bit);   
   enable_interrupts(int_timer0);
   enable_interrupts(global);
   set_tris_A(0x00);
   set_tris_B(0x00);
   set_tris_C(0x00);
   set_tris_D(0x00);
   while(true)
   {
      output_A(resultPortA);      
      output_B(resultPortB);
      output_C(resultPortC);
      output_D(resultPortD);
            
      if(timeCounter100ms>=6)
      { 
         resultPortA=resultPortA<<1;             
         timeCounter100ms=0;         
      }
      if(timeCounter500ms>=30)
      {
         resultPortB=resultPortB<<1;
         timeCounter500ms=0;
      }
      if(timeCounter1000ms>=61)
      {
         resultPortC=resultPortC<<1;
         timeCounter1000ms=0;
      }
      if(timeCounter1500ms>=91)
      {
         resultPortD=resultPortD<<1;
         timeCounter1500ms=0;
      }     
      if(resultPortA>=64)
         resultPortA=1;
      if(resultPortB==0)
         resultPortB=1;
      if(resultPortC==0)
         resultPortC=1;
      if(resultPortD==0)
         resultPortD=1;
   }
}

