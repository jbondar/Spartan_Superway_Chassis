/******************************************************************************************************************
 ** TITLE: Vesc_Uart                                                                                         **
 ** AUTHOR: Carlos Ortega & Lucas Lim & Logan Fansler                                                             **
 ** CREATED: 2020-09-21                                                                                          **
 ** REVISED: 2020-09-29                                                                                          **
 ** DESCRIPTION: This file contains the code to communicate to the VESC 6 through UART.                      **
 ******************************************************************************************************************/

#include <Arduino.h>
#include <VescUart.h>
// Creat VescUart object to provide access to
// the class functions

VescUart UART;
VescUart UART1;
HardwareSerial* serialPort = &Serial2;
HardwareSerial* serialPort1 = &Serial1;

float duty = 0.3;
float duty2 = 0.6;
// hello world this is a useless commit for useless boys

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200, SERIAL_8N1, 16, 17);
  Serial2.begin(115200, SERIAL_8N1, 23, 22);
  while (!Serial2 && !Serial1) {;}
  UART.setSerialPort(serialPort);
  UART1.setSerialPort(serialPort1);
}

void loop()
{
  if (UART.getVescValues()) 
  {    
    UART.setDuty(duty);      
    Serial.println("Printing Vesc  1 Values: ");
    Serial.println(UART.data.avgMotorCurrent);
    Serial.println(UART.getVescValues.Current)
    
    T.data.avgInputCurrent);
    Serial.println(UART.data.rpm);
    Serial.println(UART.data.inpVoltage);
    Serial.println(UART.data.ampHours);
    Serial.println(UART.data.tachometerAbs);
    Serial.println("Finished Vesc  1 Values: ");       
  }
  else
  {
    Serial.println("Failed to get data!");
  }

  if(UART1.getVescValues())
  {
    UART1.setDuty(duty2);
    Serial.println("Printing Vesc  2 Values: ");
    Serial.println(UART1.data.avgMotorCurrent);
    Serial.println(UART1.data.avgInputCurrent);
    Serial.println(UART1.data.rpm);
    Serial.println(UART1.data.inpVoltage);
    Serial.println(UART1.data.ampHours);
    Serial.println(UART1.data.tachometerAbs);
    Serial.println("Finished Vesc  2 Values: "); 
  }
  else
  {
    Serial.println("Failed to get data!");
  }

}