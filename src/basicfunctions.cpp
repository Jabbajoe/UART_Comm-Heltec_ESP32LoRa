/*
  Recived data in OLED.

  The onboard OLED display is SSD1306 driver and I2C interface. In order to make the
  OLED correctly operation, you should output a high-low-high(1-0-1) signal by soft-
  ware to OLED's reset pin, the low-level signal at least 5ms.

  OLED pins to ESP32 GPIOs via this connecthin:
  OLED_SDA -- GPIO4
  OLED_SCL -- GPIO15
  OLED_RST -- GPIO16
  
  by Aaron.Lee from HelTec AutoMation, ChengDu, China
  成都惠利特自动化科技有限公司
  www.heltec.cn
  
  this project also realess in GitHub:
  https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series
*/

#include "basicfunctions.h"

/**
 * @brief Print on Heltec's display
 * 
 * @param ch 
 */
void PrintOnScreen(String ch) {
  // clear the display
  Heltec.display->clear();

  // set font
  Heltec.display->setFont(ArialMT_Plain_10);

  // The coordinates define the left starting point of the text
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);

  // draw ch
  Heltec.display->drawStringMaxWidth(0, 10, 128, ch);

  // display ch on the screen
  Heltec.display->display();
}

/**
 * @brief 
 * 
 * @param counter 
 */
void drawProgressBar(void) {
  int counter = 0;
  while (counter <= 500) {
    int progress = (counter / 5) % 100;
    // draw the progress bar
    Heltec.display->drawProgressBar(0, 32, 120, 10, progress);

    // draw the percentage as String
    Heltec.display->setTextAlignment(TEXT_ALIGN_CENTER);
    Heltec.display->drawString(64, 15, String(progress) + "%");

    Heltec.display->display();

    counter++;
  }
}

/**
 * @brief 
 * 
 */
void drawLogo(void) {
    // see https://www.online-utility.org/image/convert/to/XBM to convert
    // to xbm
    Heltec.display->drawXbm(34, 14, logo_width, logo_height, logo_bits);

    Heltec.display->display();
}

// Buffer to store received string
String buffer1 = "";

// Store readed character in its position
char buffChar = -1;

/**
 * @brief Receive data from UART_1
 * 
 */
int Serial1receive(void) {
 // Used for DEBUG. counts the number of iterations in the while loop
 int icount = 0;
 buffer1 = "";

  // Read and concat the string
  do { 
    icount++;   
    // Read character
    buffChar = Serial1.read();
    
    // Concatenate in a string
    buffer1.concat(buffChar);

    // Wait a bit, otherwise ESP fails and reboot
    delay(1);

    // Stop when reaches the end of the string
  } while (buffChar != '\0' && icount < 20000);

  return icount;
}