// Importa as bibliotecas necessárias de rede e web
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

//led verde e vermelho usados para sinalização
#define LED1 10
#define LED2 9

// Credenciais da minha rede
const char* ssid = "minharedewifi";
const char* password = "minharedewifi";

//valores simples definidos para serem retomados nas próximas funções
const int output = 2;

String valorIn = "0";

// Propriedades da modulação
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

const char* PARAM_INPUT = "value";

// Cria uma servidor AsyncWebServer com porta 80
AsyncWebServer server(80);


//O jogo escolhido foi o pedra, papel e tesoura, utilizando bastante de condicionais if
//Método para uma inserção organizada de código WEB no IDE
const char index_html[] PROGMEM = R"rawliteral(


<!DOCTYPE html>
<script>

    while(true){
        jogador1 = prompt('Jogador 1: Digite pedra, papel ou tesoura');
        jogador2 = prompt('Jogador 2: Digite pedra, papel ou tesoura');

        if (jogador1 == 'pedra') {
            if (jogador2 == 'tesoura') {
                alert ('Pedra quebra tesoura, jogador 1 ganhou!');
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/slider?value="+1, true);
                xhr.send();
            } else if (jogador2 == 'papel'){
                alert ('Papel envolve a Pedra, jogador 2 ganhou!');
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/slider?value="+2, true);
                xhr.send();
            } else if (jogador2 == 'pedra') {
                alert ('Empate');
            }

        }
        else if (jogador1 == 'tesoura') {
            if (jogador2 == 'pedra') {
                alert ('Pedra quebra tesoura, jogador 1 ganhou!');
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/slider?value="+1, true);
                xhr.send();
            } else if (jogador2 == papel){
                alert ('tesoura corta papel, jogador 2 ganhou!');
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/slider?value="+2, true);
                xhr.send();
            } else if (jogadoe2 == 'tesoura') {
                alert ('Empate');
            }
        }

        else if (jogador1 == 'papel'){
            if (jogador2 == 'pedra') {
                alert ('Papel envolve pedra, jogador 1 ganhou!');
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/slider?value="+1, true);
                xhr.send();
            }else if (jogador2 == 'tesoura') {
                alert ('Tesoura corta papel, jogador 2 ganhou!');
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/slider?value="+2, true);
                xhr.send();
            }else if (jogador2 == 'papel')  {
                alert ('Empate');
            }

        }

    }

</script>




)rawliteral";

// Cria uma seção de botão na página web
String processor(const String& var){
  
//retorna a string criada anteriomente contendo o valor genérico
  if (var == "VALORIN"){
    return valorIn;
  }
  return String();
}

void setup(){

  pinMode(LED1, OUTPUT); //Led verde
  pinMode(LED2, OUTPUT); //Led vermelho

  //configura frequencias do led
  ledcSetup(ledChannel, freq, resolution);
  
  // associa um canal para controle das leds
  ledcAttachPin(output, ledChannel);
  
  ledcWrite(ledChannel, valorIn.toInt());

  // Conexao ao WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Mostra o endereço IP do ESP32
  Serial.println(WiFi.localIP());

  // Roteador da página web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Envia a requisição GET
  server.on("/slider", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // Imputa a requisição GET
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      valorIn = inputMessage;
      Serial.println(inputMessage);
     
      //Condicional que define qual lede vai ligar conforme o jogador vencedor
      if (valorIn == "1"){
      digitalWrite(LED1, HIGH);
      } else if (valorIn == "2"){
      digitalWrite(LED2, HIGH);
      }

     //Comando para ligar o led conforme valor lido
      ledcWrite(ledChannel, valorIn.toInt());
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });
  
  // Inicia o servidor
  server.begin();
}
  
void loop() {
  
}