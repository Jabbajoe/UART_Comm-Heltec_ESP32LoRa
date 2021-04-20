
                        ///////// SOURCE CODE FOR Heltec ESP32 WiFi LoRa (V2) /////////
                                           (IDE: VS Code + PlatformIO)    

***********
HARDWARE: 
***********
    HELTEC ESP32 WiFi LoRa 32 (V2)
        LoRa band: 868 MHz (nominal)
        Schematics: https://resource.heltec.cn/download/WiFi_LoRa_32/V2.1/WIFI_LoRa_32_V2.1(868-915).PDF
        Site: https://heltec.org/project/wifi-lora-32/
    Antena Tecnosol (similar to Wavelink)
        Gain: 5 dbi
        Type: Omnidirecional
        Max. range: 5 km ??
        Max. data rate: 100 kbps  ??
        Site: https://produto.mercadolivre.com.br/MLB-1735200088-antena-omni-5dbi-915mhz-lora-lorawan-2-unidades-_JM?quantity=1


***********
SOFTWARE:
***********
    Heltec_ESP32 Library
        Site: https://github.com/HelTecAutomation/Heltec_ESP32



******************************************************************************************************************
Connectivity Project: Serial->LoRa->Serial communication using (Tiva TM4C123G lauchpad + Ebyte's E32-868T20D LoRa 
module) and Heltec's ESP32 WiFi LoRa (V2)



                   ********                                         ********                          ********                                         
 Actuator -------> * GPIO * <------> Transmitter/Receiver  <------> * UART * <------> Module <------> * LoRa * <----
(TM4C123G          ********               (TM4C123G)                ********       (E32-868T20D)      ********     -
  Button)             -                                                                                            -
                      -                                                                                            -
 Actuator <------------                                                                                            - 
(TM4C123G                                                                                                          -
 red LED)                                                                                                          -
                                                                                                                   -
--------------------------------------------------------------------------------------------------------------------
-                                    
-                                    ********  
---->  Receiver/Transmitter <------> * UART * <------> Computer       
             (ESP32)           -     ********         (notebook)
                               -
                               -     *******
                               ----> * I²C * --------> OLED 
                                     *******         (SSD1306)


TM4C123G lauchpad: https://www.ti.com/lit/ug/spmu296/spmu296.pdf?ts=1617185733555&ref_url=https%253A%252F%252Fdev.ti.com%252F
Ebyte's E32-868T20D: https://www.ebyte.com/en/product-view-news.aspx?id=132
ESP 32 WiFi LoRa (V2): https://heltec.org/project/wifi-lora-32/