#include "mbed.h"

I2C LM75BD(p28,p27); // SDA SCL     Creating an I2C Master interface,connected to the specified pins
Serial pc(USBTX,USBRX);
const int address= 0x90;    // TX ,RX
char register[2];
char temp_read[2];
float temp;


int main(){
        //the sensor has register
        //internal memory ,
        // LM75DB Registers:
        register[0] = 0x01; // config register, to modify the precision for example 
        register[1] = 0x00; // Data register
        
        LM75BD.write(address,register,2); 
        register[0] = 0x00;
        
        LM75BD.write(address,register,1); // la sélection est une écriture
        while(1) {
            wait(3);
            LM75BD.read(address,temp_read,2);
            temp = 0.0625 * (((temp_read[0] <<8 ) + temp_read[1]) >> 4);
            pc.printf("Temp = %.2ff degC\n\r",temp);
        }

