#include "stm32f0xx.h"
int x;
void delay() //delay function created using do loop
{
  int wait = 0;
  do{
    wait++;
   }while (wait < 100000);
   
} 
void space200()   //function to create 200ms delay
{
   for(x = 0; x < 2; x++)  //represents delay of 200ms
   { 
   delay();
   }
}

void spacebetweenWords()     // function to create 800ms delay
{
  for(x = 0; x < 8; x++) //represents 800ms
   { 
   delay();
   }
}

void spacediffletters()
{
  for(x = 0; x < 4; x++) //represents 400ms
   { 
   delay();
   }
}
 void dot()  //function to create a dot
 {
   GPIOC->ODR |= 0x01 << 8; // turns on LED
   space200();
   GPIOC->ODR &= ~(0x01 << 8); // turns off LED
   space200();  //delay for space after char
 }
 void dash() //function to create a dash
 {
   GPIOC->ODR |= 0x01 << 8; // turns on LED
   for(x = 0; x < 6; x++) //represents 600ms
   { 
   delay();
   }
   GPIOC->ODR &= ~(0x01 << 8); // turns off LED
   space200();  //delay for space after char
 }


void flash(char x[]) {
  for(int i=0; i<strlen(x); i++) {
     if(x[i]=='1') {  //dash
	GPIOC->ODR |= 0x01 << 8; // turns on LED
	 for(int x = 0; x < 6; x++) //holding LED high for this three units(600ms)
         { 
            delay();
         }
	 GPIOC->ODR &= ~(0x01 << 8); // turns off LEDD
      }
	
      else {	//dot
	GPIOC->ODR |= 0x01 << 8; // turns on LED
	for(int x = 0; x < 2; x++)  //holding LED high for one unit(200ms); dots are half as long as da
        { 
          delay();
        }                          
	 GPIOC->ODR &= ~(0x01 << 8); // turns off LEDD
       }
       for(int x = 0; x < 2; x++)  // end of flash
        { 
          delay();
        }              
   }
      spacediffletters(); //400ms delay        
}

int main (void) 
{
RCC->AHBENR |= RCC_AHBENR_GPIOCEN; //GPIOC Periph clock enable
//set LED4 PC8 output
GPIOC-> MODER |= 0x01<< (2*8); 
GPIOC-> OTYPER |= 0x00<< (8); 
GPIOC-> OSPEEDR |= 0x02<< (2*8); 
GPIOC-> PUPDR |= 0x00 << (2*8); 
while (1)
{
  int i = 0;
  char msg[32] = "GabrielFaccoBettinelli 824113076";
  
  int stringsize = strlen(msg);
  for (i = 0; i <stringsize; i++)  //loops through string
  {
   switch(msg[i]) {
				  
				   case ' ' : spacebetweenWords(); break;
				   case 'a' : flash("01"); break;
				   case 'b' : flash("1000"); break;
				   case 'c' : flash("1010"); break;
				   case 'd' : flash("100"); break;
				   case 'e' : flash("0"); break;
				   case 'f' : flash("0010"); break;
				   case 'g' : flash("110"); break;
				   case 'h' : flash("0000"); break;
				   case 'i' : flash("00"); break;
				   case 'j' : flash("0111"); break;
				   case 'k' : flash("101"); break;
				   case 'l' : flash("0100"); break;
				   case 'm' : flash("11"); break;
				   case 'n' : flash("10"); break;
				   case 'o' : flash("111"); break;
				   case 'p' : flash("0110"); break;
				   case 'q' : flash("1101"); break;
				   case 'r' : flash("010"); break;
				   case 's' : flash("000"); break;
				   case 't' : flash("1"); break;
				   case 'u' : flash("001"); break;
				   case 'v' : flash("0001"); break;
				   case 'w' : flash("011"); break;
				   case 'x' : flash("1001"); break;
				   case 'y' : flash("1011"); break;
				   case 'z' : flash("1100"); break;
				   case 'A' : flash("01"); break;
				   case 'B' : flash("1000"); break;
				   case 'C' : flash("1010"); break;
				   case 'D' : flash("100"); break;
				   case 'E' : flash("0"); break;
				   case 'F' : flash("0010"); break;
				   case 'G' : flash("110"); break;
				   case 'H' : flash("0000"); break;
				   case 'I' : flash("00"); break;
				   case 'J' : flash("0111"); break;
				   case 'K' : flash("101"); break;
				   case 'L' : flash("0100"); break;
				   case 'M' : flash("11"); break;
				   case 'N' : flash("10"); break;
				   case 'O' : flash("111"); break;
				   case 'P' : flash("0110"); break;
				   case 'Q' : flash("1011"); break;
				   case 'R' : flash("010"); break;
				   case 'S' : flash("000"); break;
				   case 'T' : flash("1"); break;
				   case 'U' : flash("001"); break;
				   case 'V' : flash("0001"); break;
				   case 'W' : flash("011"); break;
				   case 'X' : flash("1001"); break;
				   case 'Y' : flash("1011"); break;
				   case 'Z' : flash("1100"); break;
				   case '0' : flash("11111"); break;
				   case '1' : flash("01111"); break;
				   case '2' : flash("00111"); break;
				   case '3' : flash("00011"); break;
				   case '4' : flash("00001"); break;
				   case '5' : flash("00000"); break;
				   case '6' : flash("10000"); break;
				   case '7' : flash("11000"); break;
				   case '8' : flash("11100"); break;
				   case '9' : flash("11110"); break;
				   case '.' : flash("010101"); break;
				   case ',' : flash("110011"); break;
				   default  : spacebetweenWords(); break;
			   }
		   }
    }
}

  
  
  

