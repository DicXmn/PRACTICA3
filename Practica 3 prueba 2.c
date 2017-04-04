#include <18F4620.h>
#include <stdlib.h>
#include <stdio.h>
#fuses XT, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG

#use delay(clock=16000000)

int contA=0, contB=0, contC=0, contD=0;
int anilloA=1, anilloB=1, anilloC=1, anilloD=1;
#int_timer0
void timer_0()
{
   contA++;  
   contB++;
   contC++;
   contD++; 
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
      output_a(anilloA);      
      output_b(anilloB);
      output_c(anilloC);
      output_d(anilloD);
            
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

