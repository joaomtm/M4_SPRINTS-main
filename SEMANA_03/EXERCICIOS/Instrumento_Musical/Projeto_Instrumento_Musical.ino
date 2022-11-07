//Leds principais que serão usados para contagem em binário
#define led1 15
#define led2 16
#define led3 17
#define led4 18

//Leds utilizados como sinalizadores dos pushers
#define led5 3
#define led6 5

//O buzzer e seu pino
#define buz 13

#define LDR 4

//Os pushers
#define b1 9
#define b2 10

//variáveis apenas para conferência de estado
bool estadoled = 0;
bool estadoled2 = 0;

//Array que será utilizada para armazenamento
int luzes[4] = {};
int l = 0;

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  pinMode(buz, OUTPUT);

  pinMode(LDR, INPUT);

  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);

  Serial.begin(9600);

  Serial.println("Instrumento Musical");

}

 
void loop() {
  reader();
  remember();  
  delay(1000);
}

void reader() {
  //Variável para armazenar o valor que o fotoresistor captar 
  int valor_sensor = analogRead(LDR);

//Comando para limitar os números coletados em apenas 16
  valor_sensor = map(valor_sensor, 0, 4095, 0, 15);
  
//Essa condição transforma o valor já transformado do LDR em binário
//Tanto os leds quanto o buzzer reagem conforme o valor coletado
  if (valor_sensor == 0) {
    valor_sensor = 1111;
    digitalWrite(led1, LOW);//Leds deligadas
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    noTone(buz)//Reprodução do buzzer (nula)

//Essa segunda condição serve para salvar o binário que está sendo lido no momento em uma array
  if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED (Led utilizado apenas para conferir responsividade do pusher)
    luzes[l] = 1111; //Salva binário na array]
    l++;
    Serial.println(luzes[0]);//Mostra como está constitúida a array
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }
  }
//Essa condições são extendidas para cada uma das 16 possibilidaes
  if (valor_sensor == 1) {
    valor_sensor = 1112;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    tone(buz, 200);
  if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 1112;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }    
  }

  if (valor_sensor == 2) {
    valor_sensor = 1121;
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW); 
    tone(buz, 400);
  if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 1121;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }            
  }

  if (valor_sensor == 3) {
    valor_sensor = 1122;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    tone(buz, 600);
  if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 1122;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }     
  }

  if (valor_sensor == 4) {
    valor_sensor = 1211;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buz, 800);
       
  }if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 1211;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }

  if (valor_sensor == 5) {  
    valor_sensor = 1212;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buz, 1000);

    if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 1212;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  } 
  }

  if (valor_sensor == 6) {
    valor_sensor = 1221;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buz, 1200);

if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 1221;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }    

  }

  if (valor_sensor == 7) {
    valor_sensor = 1222;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buz, 1400);
    
if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 1222;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }      
  }

  if (valor_sensor == 8) {
    valor_sensor = 2111;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    tone(buz, 1600);

    if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 2111;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }   
  }

  if (valor_sensor == 9) {
    valor_sensor = 2112; 
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    tone(buz, 1800);
    
if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 2112;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }       
  }

  if (valor_sensor == 10) {
  valor_sensor = 2121;
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    tone(buz, 2000);

    if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 2121;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }   
  }

  if (valor_sensor == 11) {
  valor_sensor = 2122; 
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    tone(buz, 2200);

    if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 2122;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }
  }

  if (valor_sensor == 12) {
  valor_sensor = 2211;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    tone(buz, 2400);

    if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 2211;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  } 
  }

  if (valor_sensor == 13) {
  valor_sensor = 2212; 
   digitalWrite(led1, HIGH);
   digitalWrite(led2, LOW);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);
   tone(buz, 2600);

  if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 2212;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }   
  }

  if (valor_sensor == 14) {
  valor_sensor = 2221;
   digitalWrite(led1, LOW);
   digitalWrite(led2, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);
   tone(buz, 2800);

   if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 2221;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  }  
  }

  if (valor_sensor == 15) {
  valor_sensor = 2222;
   digitalWrite(led1, HIGH);
   digitalWrite(led2, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);
   tone(buz, 3000);

  if (digitalRead(b1) == LOW) // Se o botão for pressionado
  {
    estadoled = !estadoled; // troca o estado do LED
    luzes[l] = 2222;
    l++;

    Serial.println(luzes[0]);
    Serial.println(luzes[1]);
    Serial.println(luzes[2]);
    Serial.println(luzes[3]);
    digitalWrite(led5, estadoled);
    Serial.println("Pusher pressionado com sucesso");
    while (digitalRead(b1) == LOW);
    delay(100);
  } 
  }

  //Retorna no terminal o valor lido pelo LDR
  Serial.println(valor_sensor);
}



//Função para retomar os valores armazenados na array (em forma técnica mostra erros)
void remember() {
  
//Funcionalidade técnica do pusher 
  if (digitalRead(b2) == LOW) // Se o botão for pressionado
  {
    estadoled2 = !estadoled2;
    digitalWrite(led6, estadoled2) //Led apenas para conferência de ação
    Serial.println("Botao 2 apertado");
        
  int i;
  //Loop para passar por toda array
  for (i = 0; i < 4; i++) {
    
  int p = 0;
 
 //Caso o elemento da array se encontre em alguma das condições, ele será repetido fisicamente   
  if (luzes[p] = 1111) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    noTone(buz);
    luzes[p] = {0}//Esvazia o lugar da array que foi percorrido
    p++;           
  }
  //Conferência das 16 possibilidades das arrays;
  if (luzes[p] = 1112) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    tone(buz, 200);   
  }

  if (luzes[p] = 1121) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    tone(buz, 400);
  }
  
  if (luzes[p] = 1122) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    tone(buz, 600);    
  }

  if (luzes[p] = 1211) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buz, 800);
    luzes[p] = {0};
    p++;        
  }

  if (luzes[p] == 1212) {  
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buz, 1000);
    luzes[p] = {0};
    p++; 
  }

  if (luzes[p] = 1221) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buz, 1200);
    luzes[p] = {0};
    p++; 

  } 

  if (luzes[p] = 1222) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buz, 1400);
    luzes[p] = {0};
    p++;  
  }

  if (luzes[p] = 2111) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    tone(buz, 1600);
    luzes[p] = {0};
    p++;         
  }

  if (luzes[p] = 2112) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    luzes[p] = {0};
    p++;        
  }

  if (luzes[p] = 2211) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    luzes[p] = {0};
    p++;  
  }
  if (luzes[p]  = 2212) { 
   digitalWrite(led1, HIGH);
   digitalWrite(led2, LOW);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);
   luzes[p] = {0};
   p++;

  }

  if (luzes[p] = 2221) {
   digitalWrite(led1, LOW);
   digitalWrite(led2, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);
   luzes[p] = {0};
   p++;  
  }

  if (luzes[p] = 2222) {
   digitalWrite(led1, HIGH);
   digitalWrite(led2, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);
   luzes[p] = {0};
   p++; 
  }      
    while (digitalRead(b2) == LOW) {
    delay(100);//Delay para evitar desorganização ou travamentos
    }
   }
  }











