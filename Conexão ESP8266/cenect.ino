#include <ESP8266WiFi.h>

//Declaração das informações da rede WIFI que o ESP está conectado
const char* ssid = "nomeDaRede"
const char* pas = "senhaDaRede"

void{
    Serial.begin(115200)

    //Realizando a conexão com a rede
    WiFi.begin(ssid, pas);

    while (WiFi.status() != WL_CONECTED)
    {
        delay(1000);
        Serial.println("Conectando ao Wi-Fi. Aguarde!");
    }

    Serial.println("ESP8266 conectado a rede Wi-Fi!");
    
}
void loop{
    //Add funcionalidade
}