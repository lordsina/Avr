#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#define F_CPU = 10000000;
void refreshDisplay(int *display,int *c);
void random_led(int *c);
void shift(int *c);
void finish();
int main(void)
{
	DDRA=0xFF;
	DDRB=0xFF;
	DDRC=0xFF;
	DDRD=0x00;
	PORTA=0b00000000;
	PORTB=0b00000000;
	PORTC=0b00000000;
	int A1 [16]={0};
	/////////////////
	A1[0]=0b00000000;
	A1[1]=0b00000000;
	A1[2]=0b00000000;
	A1[3]=0b00000000;
	A1[4]=0b00000000;
	A1[5]=0b00000000;
	A1[6]=0b00000000;
	A1[7]=0b00000000;
	A1[8]=0b00000000;
	A1[9]=0b00000000;
	A1[10]=0b00000000;
	A1[11]=0b00000000;
	A1[12] =0b00011000;
	A1[13] =0b00111100;
	A1[14] =0b00011000;
	A1[15] =0b00111100;
	//////////////////
    /////////////////
	int c [16]={0};
	c[0]=0b00000000;
	c[1]=0b00000000;
	c[2]=0b00000000;
	c[3]=0b00000000;
	c[4]=0b00000000;
	c[5]=0b00000000;
	c[6]=0b00000000;
	c[7]=0b00000000;
	c[8]=0b00000000;
	c[9]=0b00000000;
	c[10]=0b00000000;
	c[11]=0b00000000;
	c[12]=0b00000000;
	c[13] =0b00000000;
	c[14] =0b00000000;
	c[15] =0b00000000;
	c[16] =0b00000000;
	//////////////////
	int counter=0;
	int time=0;
	int n=8;
	random_led(c);
	bool key1down=false;
	bool key2down=false;
	
	while (1)
	{
		////////////////////////////////////////////////
		if((PIND & 0b00000001) > 0  && !key1down){
			key1down = true;
			if (!(A1[13]&0b00000001)>=1)
			{
				A1[12]=(A1[12]>>1);
				A1[13]=(A1[13]>>1);
				A1[14]=(A1[14]>>1);
				A1[15]=(A1[15]>>1);
			}
			
		}
		if((PIND & 0b00000001) == 0  && key1down){
			key1down = false;
		}
		////////////////////////////////////////////////
		if((PIND & 0b10000000) > 0  && !key2down){
			key2down = true;
			if (!(A1[13]&0b10000000)>=1)
			{
				A1[12]=(A1[12]<<1);
				A1[13]=(A1[13]<<1);
				A1[14]=(A1[14]<<1);
				A1[15]=(A1[15]<<1);
			}
			
		}
		if((PIND & 0b10000000) == 0  && key2down){
			key2down = false;
		}
		////////////////////////////////////////////////
		refreshDisplay(A1,c);
		if (time==n)
		{
			shift(c);
			counter++;
			if(counter==16){
				c[0]=0b00000000;
				random_led(c);
				counter=0;
				if(n==3){
				n=3;
				}else{
					n--;
				}
			}
			time=0;
			
		}else{
			time++;
		}
		
	}
}
void refreshDisplay(int *display,int *c){
	for ( int i = 0; i < 8; i ++){
		PORTB = (1 << i);
		PORTA = ~(display[i]|c[i]);
		for(int d=0; d < 500; d++)	{}
	}
	PORTB = 0x00;
	for ( int i = 8; i < 16; i ++){
		PORTC = (1 << (i - 8));
		if((display[i]&c[i]) >1){finish();}
		PORTA = ~(display[i]|c[i]);
		for(int d=0; d < 500; d++)	{}
	}
	PORTC = 0x00;
}
void random_led(int *c){
	if(rand()%2==0){
		c[0]=0b11110000;
		}else{
		c[0]=0b00001111;
	}
}
void shift(int *c){
	int temp=0;
	for (int g = 15; g >= 1; g--)
	{
		if(g==15){
			temp=c[g];
		}
		c[g]=c[g-1];
	}
	c[0]=temp;
}
void finish(){
	while(1){}
}

