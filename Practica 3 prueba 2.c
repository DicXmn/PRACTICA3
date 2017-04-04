#include <18F4620.h>
#include <stdlib.h>
#include <stdio.h>
#fuses XT, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG

#use delay(clock=16000000)

int8 timeCounter100ms=0;
int8 timeCounter500ms=0; 
int8 timeCounter1000ms=0; 
int8 timeCounter1500ms=0;
int8 resultPortA=0;
int8 resultPortB=0;
int8 resultPortC=0;
int8 resultPortD=0;
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
   setup_timer_0(rtcc_internal||rtcc_div_256);   
   enable_interrupts(int_timer0);
   enable_interrupts(global);
   set_tris_a(0x00);
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_d(0x00);
   while(true)
   {
      output_A(resultPortA);      
      output_B(resultPortB);
      output_C(resultPortC);
      output_D(resultPortD);
            
      if(contA>=6)
      { 
         anilloA=anilloA<<1;             
         contA=0;         
      }
      if(contB>=30)
      {
         anilloB=anilloB<<1;
         contB=0;
      }
      if(contC>=61)
      {
         anilloC=anilloC<<1;
         contC=0;
      }
      if(contD>=91)
      {
         anilloD=anilloD<<1;
         contD=0;
      }     
      if(anilloA==64)
         anilloA=1;
      if(anilloB==0)
         anilloB=1;
      if(anilloC==0)
         anilloC=1;
      if(anilloD==0)
         anilloD=1;
   }
}

