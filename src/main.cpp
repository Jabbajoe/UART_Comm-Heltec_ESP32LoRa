#include <Arduino.h>
#include <heltec.h> 

#include "basicfunctions.h"

// If debug information needed
#define __DEBUG__

// For debug purpose
#ifdef __DEBUG__
  int msg_pre1 = 0;
  int msg_pre2 = 0;
  int msg_pos = 0;
  int DEBUGCOUNT = 0;
  int printflag = 0;
#endif


// Setup
void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);

  // Configuring UARTs
  Serial.begin(115200); // UART 0
  Serial1.begin(115200, SERIAL_8N1, 2, 17); // UART 1

  // Reserve 200 bytes for the InputString:
  //inputString.reserve(200);

  // Clear screen
  Heltec.display->clear();

  // Show logo
  drawLogo();

  //wait a bit
  delay(5000);

  // Show progress bar in screen
  drawProgressBar();
}

// Loop
void loop() {

    if (Serial1.available()) {
                                                                  #ifdef __DEBUG__
                                                                    msg_pre1 = Serial1.available();
                                                                    Serial.print("msg_pre: ");
                                                                    Serial.println(msg_pre1);
                                                                    msg_pre2 = 0;
                                                                    Serial.println("AHAA!!!");
                                                                    msg_pre2 = Serial1.available();

                                                                    // Receive data from UART 1
                                                                    DEBUGCOUNT = Serial1receive();
                                                                  #endif

                                                                  #ifndef __DEBUG__
      // Receive data from UART 1
      // (void) used to ignore returned value
      (void) Serial1receive();
                                                                  #endif

                                                                  #ifdef __DEBUG__
                                                                    msg_pos = Serial1.available();
                                                                    printflag = 1;
                                                                  #endif
    }

    // print on ESP32 screen
    PrintOnScreen(buffer1);
                                                                  #ifdef __DEBUG__
                                                                    if(printflag){
                                                                      Serial.print("msg_pre2: ");
                                                                      Serial.println(msg_pre2);
                                                                      Serial.print("DEBUG COUNT: ");
                                                                      Serial.println(DEBUGCOUNT);
                                                                      Serial.print("msg_pos: ");
                                                                      Serial.println(msg_pos);
                                                                    }
                                                                    printflag = 0;
                                                                  #endif
}