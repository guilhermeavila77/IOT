#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Declaração das informações da rede WIFI que o ESP está conectado
const char *ssid = "nomeDaRede" const char *pas = "senhaDaRede"

    // Pino do modulo que controla o relé
    const int relayPin = D1; // Pino GPIO

// Mesma porta do site
ESP8266WebServer server(3000);

void
{
    Serial.begin(115200)

        // Realizando a conexão com a rede
        WiFi.begin(ssid, pas);

    while (WiFi.status() != WL_CONECTED)
    {
        delay(1000);
        Serial.println("Conectando ao Wi-Fi. Aguarde!");
    }

    Serial.println("ESP8266 conectado a rede Wi-Fi!");

    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, LOW); // Inicialmente, o relé está desligado

    server.on("/ligar", handleLigar);       // Rota para ligar o relé
    server.on("/desligar", handleDesligar); // Rota para desligar o relé

    //Tem que ver se criar o server pelo express já é necessario
    //server.begin();
    //Serial.println("Servidor iniciado!");
}
void loop
{
    //Função de core do <ESP8266WebServer.h>
    //Serve como listening das rotas do server
    //Caso entre em uma rota de ação 
    server.handleClient();
}

// Função para lidar com o comando de ligar o relé
void handleLigar() {
  digitalWrite(relayPin, HIGH); // Nível lógico alto para ligar o relé
  server.send(200, "text/plain", "Relé ligado!");
}

// Função para lidar com o comando de desligar o relé
void handleDesligar() {
  digitalWrite(relayPin, LOW); // Nível lógico baixo para desligar o relé
  server.send(200, "text/plain", "Relé desligado!");
}
