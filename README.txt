
                        ///////// SOURCE CODE FOR Heltec ESP32 WiFi LoRa (V2) /////////
                                           (IDE: VS Code + PlatformIO)    

***********
HARDWARE: 
***********
    HELTEC ESP32 WiFi LoRa 32 (V2)
        LoRa band: 868 MHz (nominal)
        Schematics: https://resource.heltec.cn/download/WiFi_LoRa_32/V2.1/WIFI_LoRa_32_V2.1(868-915).PDF
        Site: https://heltec.org/project/wifi-lora-32/
        Docs:
              https://heltec-automation-docs.readthedocs.io/en/latest/esp32/distance_test.html
              https://heltec.org/project/wifi-lora-32/
              https://resource.heltec.cn/download/WiFi_LoRa_32/V2/WIFI_LoRa_32_V2(868-915).PDF
              https://resource.heltec.cn/download/WiFi_LoRa_32/WIFI_LoRa_32_V2.pdf
              https://github.com/HelTecAutomation/Heltec_ESP32


***********
SOFTWARE:
***********
    Heltec_ESP32 Library
        Site: https://github.com/HelTecAutomation/Heltec_ESP32
    


******************************************************************************************************************
UART Communication Project: Serial --> Serial communication using (Tiva TM4C123G lauchpad) and (Heltec's ESP32 
WiFi LoRa (V2) )



                                ********                                  
  Transmitter/Receiver  ------> * UART * ------> Receiver/Transmitter
       (TM4C123G)               ********              (ESP32)
  



TM4C123G lauchpad: https://www.ti.com/lit/ug/spmu296/spmu296.pdf?ts=1617185733555&ref_url=https%253A%252F%252Fdev.ti.com%252F
Ebyte's E32-868T20D: https://www.ebyte.com/en/product-view-news.aspx?id=132
ESP 32 WiFi LoRa (V2): https://heltec.org/project/wifi-lora-32/
