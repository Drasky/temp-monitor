#include <iostream>
#include <cstdio>
#include <wiringPi.h>
#include <mcp23017.h>
#include <lcd.h>

using namespace std;

int fd;

void right(){
	lcdPutchar(fd,'r');
}

int main(){
	int r;
	r=wiringPiSetup();
	if( r==0 ){
		mcp23017Setup(100,32);
		fd=lcdInit(2,16,8, 109,108, 100,101,102,103,104,105,106,107);
		pinMode(110,INPUT);
		//wiringPiISR(110,INT_EDGE_FALLING,right);
		wiringPiI2CWriteReg8 (fd, MCP23x17_IOCON, 0x00) ;
		wiringPiI2CWriteReg8 (fd, MCP23x17_IODIRB, 0x1f) ;
		wiringPiI2CWriteReg8 (fd, MCP23x17_INTCONB, 0x1f) ;
		wiringPiI2CWriteReg8 (fd, MCP23x17_DEFVALB, 0x1f) ;
		wiringPiI2CWriteReg8 (fd, MCP23x17_GPINTENB, 0x1f) ;
		wiringPiI2CWriteReg8 (fd, MCP23x17_GPPUB, 0x1f) ;
		wiringPiI2CReadReg8 (fd, MCP23x17_INTCAPB ); // clear interrupt flag
		pinMode(111,INPUT);
		pinMode(112,INPUT);
		pinMode(113,INPUT);
		lcdClear(fd);
		lcdHome(fd);
		lcdPuts(fd,"Hello World!");
		lcdPosition(fd,0,1);
	}else{
		printf("wiringPiSetup() returned %d\n",r);
	}
	printf("Finished!\n");
	return 0;
}
