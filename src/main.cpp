#include <heltec.h>
#include <SPI.h>

#include "basicfunctions.h"

// If debug information needed
//#define __DEBUG__

// For debug purpose
#ifdef __DEBUG__
  // TO DO
#endif

// Frequência do rádio - exemplo : 433E6, 868E6, 915E6
#define BAND 893000000 // 893 MHz  aka  893*10^6 Hz  aka  893E6

// Contador que irá servir como o dados que o Slave irá enviar
int count = 0;

//Constante para informar ao Slave que queremos os dados
const String GETDATA = "getdata";
//Constante que o Slave retorna junto com os dados para o Master
const String SETDATA = "setdata=";


/**
 * @brief Função onde se faz a leitura dos dados que queira enviar
 * 
 * 
 */
String readData(){
  return String(count++);
}


// Setup
void setup() {
  // Initialize ESP32
  // Heltec.begin(Display Enable, LoRa Enable, Serial Enable, PABOOST, BAND)
  Heltec.begin(true, true, true, true, BAND);

  // Initial configuration display
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);

  // Clear screen
  Heltec.display->clear();

  // Show logo
  drawLogo();

  //wait a bit
  delay(5000);

  // Show progress bar in screen
  drawProgressBar();

  // Ativa o crc do LoRa
  LoRa.enableCrc();

  // Ativa o recebimento de pacotes LoRa
  LoRa.receive();
}

// Loop  
void loop() {
  // Tenta ler o pacote
  int packetSize = LoRa.parsePacket();

  //Verifica se o pacote possui a quantidade de caracteres que esperamos
  if (packetSize == GETDATA.length()) {
    String received = "";

    //Armazena os dados do pacote em uma string
    while(LoRa.available()) {
      received += (char) LoRa.read();
    }

    if(received.equals(GETDATA)) {
      //Simula a leitura dos dados
      String data = readData();
      Serial.println("Criando pacote para envio");

      //Cria o pacote para envio
      LoRa.beginPacket();
      LoRa.print(SETDATA + data);

      //Finaliza e envia o pacote
      LoRa.endPacket();

      //Mostra no display
      Heltec.display->clear();
      Heltec.display->drawString(0, 0, "Enviou: " + String(data));
      Heltec.display->display();
    }
  }
}