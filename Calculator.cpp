#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
void RefreshDisplay();
bool chk_input(long b);
////////////////////////////////////////
long number1=0;
long number2=0;
int opr=0;
bool sum=false;
bool min=false;
bool mul=false;
bool div=false;
int digit[] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11110110};
bool key0down = false;
bool key1down = false;
bool key2down = false;
bool key3down = false;
bool key4down = false;
bool key5down = false;
bool key6down = false;
bool key7down = false;
bool key8down = false;
bool key9down = false;
bool key10down = false;
bool key11down = false;
bool key12down = false;
bool key13down = false;
bool key14down = false;
bool key15down = false;
bool getnumber=false;
bool state=false;
int input[8]={};

int main(void)
{
	DDRD = 0b11111111;
	DDRC = 0b11111111;
	PORTC=0b00000000;
	input[0]=digit[0];
	input[1]=digit[0];
	input[2]=digit[0];
	input[3]=digit[0];
	input[4]=digit[0];
	input[5]=digit[0];
	input[6]=digit[0];
	input[7]=digit[0];
	while (1)
	{
		
		
		
		
		//______________________________________________________________________________________________ KeyBorad
		////////////////////////////////////////// Number0
		if((PINA & 0b00000001) > 0  && !key0down){
			key0down = true;
		}
		if((PINA & 0b00000001) == 0  && key0down){
			key0down = false;
			if(getnumber==0){
				if(chk_input(number1)==false){
					number1=number1*10;
					state=true;
				}
				}else{
				if(chk_input(number2)==false){
					number2=number2*10;
					state=true;
				}
			}
		}
		/////////////////////////////////////////// Number 1
		if((PINA & 0b00000010) > 0 && !key1down){
			key1down = true;

		}
		if((PINA & 0b00000010) == 0  && key1down){
			key1down = false;
			if(getnumber==0){
				if(chk_input(number1)==false){
					number1=number1*10+1;
					state=true;
				}
				}else{
				if(chk_input(number2)==false){
					number2=number2*10+1;
					state=true;
				}
			}
		}
		////////////////////////////////////////// Number 2
		if((PINA & 0b00000100) > 0 && !key2down){
			key2down = true;
		}
		if((PINA & 0b00000100) == 0  && key2down){
			key2down = false;
			if(getnumber==0){
				if(chk_input(number1)==false){
					number1=number1*10+2;
					state=true;
				}
				}else{
				if(chk_input(number2)==false){
					number2=number2*10+2;
					state=true;
				}
			}
		}
		////////////////////////////////////////// Number 3
		if((PINA & 0b00001000) > 0 && !key3down){
			key3down = true;
		}
		if((PINA & 0b00001000) == 0  && key3down){
			key3down = false;
			if(getnumber==0){
				if(chk_input(number1)==false){
					number1=number1*10+3;
					state=true;
				}
				}else{
				if(chk_input(number2)==false){
					number2=number2*10+3;
					state=true;
				}
			}
		}
		////////////////////////////////////////// Number 4
		if((PINA & 0b00010000) > 0 && !key4down){
			key4down = true;
		}
		if((PINA & 0b00010000) == 0  && key4down){
			key4down = false;
			if(getnumber==0){
				if(chk_input(number1)==false){
					number1=number1*10+4;
					state=true;
				}
				}else{
				if(chk_input(number2)==false){
					number2=number2*10+4;
					state=true;
				}
			}
		}
		////////////////////////////////////////// Number 5
		if((PINA & 0b00100000) > 0 && !key5down){
			key5down = true;
		}
		if((PINA & 0b00100000) == 0  && key5down){
			key5down = false;
			if(getnumber==0){
				if(chk_input(number1)==false){
					number1=number1*10+5;
					state=true;
				}
				}else{
				if(chk_input(number2)==false){
					number2=number2*10+5;
					state=true;
				}
			}
		}
		////////////////////////////////////////// Number 6
		if((PINA & 0b01000000) > 0 && !key6down){
			key6down = true;
		}
		if((PINA & 0b01000000) == 0  && key6down){
			key6down = false;
			if(getnumber==0){
				if(chk_input(number1)==false){
					number1=number1*10+6;
					state=true;
				}
				}else{
				if(chk_input(number2)==false){
					number2=number2*10+6;
					state=true;
				}
			}
		}
		////////////////////////////////////////// Number 7
		if((PINA & 0b10000000) > 0 && !key7down){
			key7down = true;
		}
		if((PINA & 0b10000000) == 0  && key7down){
			key7down = false;
			if(getnumber==0){
				if(chk_input(number1)==false){
					number1=number1*10+7;
					state=true;
				}
				}else{
				if(chk_input(number2)==false){
					number2=number2*10+7;
					state=true;
				}
			}
		}
		////////////////////////////////////////// Number 8
		if((PINB & 0b00000001) > 0 && !key8down){
			key8down = true;
		}
		if((PINB & 0b00000001) == 0  && key8down){
			key8down = false;
			if(getnumber==0){
				if(chk_input(number1)==false){
					number1=number1*10+8;
					state=true;
				}
				}else{
				if(chk_input(number2)==false){
					number2=number2*10+8;
					state=true;
				}
			}
		}
		////////////////////////////////////////// Number 9
		if((PINB & 0b00000010) > 0 && !key9down){
			key9down = true;
		}
		if((PINB & 0b00000010) == 0  && key9down){
			key9down = false;
			if(getnumber==0){
				if(chk_input(number1)==false){
					number1=number1*10+9;
					state=true;
				}
				}else{
				if(chk_input(number2)==false){
					number2=number2*10+9;
					state=true;
				}
			}
		}
		////////////////////////////////////////// OPR +
		if((PINB & 0b00000100) > 0 && !key10down){
			key10down = true;
		}
		if((PINB & 0b00000100) == 0  && key10down){
			key10down = false;
			opr=1;
			sum=true;
		}
		////////////////////////////////////////// OPR -
		if((PINB & 0b00001000) > 0 && !key11down){
			key11down = true;
		}
		if((PINB & 0b00001000) == 0  && key11down){
			key11down = false;
			opr=2;
			min=true;
		}
		////////////////////////////////////////// OPR *
		if((PINB & 0b00010000) > 0 && !key12down){
			key12down = true;
		}
		if((PINB & 0b00010000) == 0  && key12down){
			key12down = false;
			opr=3;
			mul=true;
		}
		////////////////////////////////////////// OPR /
		if((PINB & 0b00100000) > 0 && !key13down){
			key13down = true;
		}
		if((PINB & 0b00100000) == 0  && key13down){
			key13down = false;
			opr=4;
			div=true;
		}
		////////////////////////////////////////// opr c
		if((PINB & 0b01000000) > 0 && !key14down){
			key14down = true;
		}
		if((PINB & 0b01000000) == 0  && key14down){
			key14down = false;
			opr=5;
		}
		////////////////////////////////////////// opr =
		if((PINB & 0b10000000) > 0 && !key15down){
			key15down = true;
		}
		if((PINB & 0b10000000) == 0  && key15down){
			key15down = false;
			opr=6;
		}
		//______________________________________________________________________________________________ KeyBorad
		
		if(opr==5){
			number1=0;
			number2=0;
			opr=0;
			input[0]=digit[0];
			input[1]=digit[0];
			input[2]=digit[0];
			input[3]=digit[0];
			input[4]=digit[0];
			input[5]=digit[0];
			input[6]=digit[0];
			input[7]=digit[0];
		}
		if(opr==1){
			opr=0;
			input[0]=digit[0];
			input[1]=digit[0];
			input[2]=digit[0];
			input[3]=digit[0];
			input[4]=digit[0];
			input[5]=digit[0];
			input[6]=digit[0];
			input[7]=digit[0];
			getnumber=true;
		}
		if(opr==2){
			opr=0;
			input[0]=digit[0];
			input[1]=digit[0];
			input[2]=digit[0];
			input[3]=digit[0];
			input[4]=digit[0];
			input[5]=digit[0];
			input[6]=digit[0];
			input[7]=digit[0];
			getnumber=true;
		}
		if(opr==3){
			opr=0;
			input[0]=digit[0];
			input[1]=digit[0];
			input[2]=digit[0];
			input[3]=digit[0];
			input[4]=digit[0];
			input[5]=digit[0];
			input[6]=digit[0];
			input[7]=digit[0];
			getnumber=true;
		}
		if(opr==4){
			opr=0;
			input[0]=digit[0];
			input[1]=digit[0];
			input[2]=digit[0];
			input[3]=digit[0];
			input[4]=digit[0];
			input[5]=digit[0];
			input[6]=digit[0];
			input[7]=digit[0];
			getnumber=true;
		}
		if(opr==6){
			input[0]=digit[0];
			input[1]=digit[0];
			input[2]=digit[0];
			input[3]=digit[0];
			input[4]=digit[0];
			input[5]=digit[0];
			input[6]=digit[0];
			input[7]=digit[0];
			if(sum==true){
				number1=number1+number2;
				getnumber=false;
				state=true;
				number2=0;
				opr=0;
				sum=false;
			}

			if(min==true){
				number1=number1-number2;
				getnumber=false;
				state=true;
				number2=0;
				opr=0;
				min=false;
			}
			
			if(mul==true){
				number1=number1*number2;
				getnumber=false;
				state=true;
				number2=0;
				opr=0;
				mul=false;
			}
			
			if(div==true){
				number1=number1/number2;
				getnumber=false;
				state=true;
				number2=0;
				opr=0;
				div=false;
			}
			
		}
		
		////////////////////
		
		
		if(state==true){
			
			
			if(getnumber==false){
				long temp=number1;
				int counter=0;
				while(temp>0){
					input[counter]=digit[temp%10];
					temp=temp/10;
					counter++;
					state=false;
				}

				}else{
				long temp=number2;
				int counter=0;
				while(temp>0){
					input[counter]=digit[temp%10];
					temp=temp/10;
					counter++;
					state=false;
				}
				
			}
			
		}
		
		RefreshDisplay();
		
	}//while
}//main

void RefreshDisplay(){
	for (int i = 0; i < 8; i++)
	{
		PORTD = 0x00;
		PORTC = ~(0b00000001 << i);
		PORTD = input[i];
		_delay_us(150);
	}
}
bool chk_input(long number){
	long temp = 0;
	temp = number;
	int counter = 0;
	while (temp > 0)
	{
		temp = temp / 10;
		counter++;
	}
	if (counter == 8)
	{
		return true;
	}
	else
	{
		return false;
	}
}






