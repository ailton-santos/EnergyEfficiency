// Definir os pinos dos sensores
const int temperaturaPin = A0;
const int luzPin = A1;
const int correntePin = A2;

// Variáveis para armazenar os dados
int temperatura = 0;
int luz = 0;
float corrente = 0.0;

void setup() {
  // Configurar as portas de entrada
  pinMode(temperaturaPin, INPUT);
  pinMode(luzPin, INPUT);
  pinMode(correntePin, INPUT);

  // Inicializar a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Ler os dados dos sensores
  temperatura = analogRead(temperaturaPin);
  luz = analogRead(luzPin);
  corrente = (float)analogRead(correntePin) * 5 / 1024;

  // Calcular a eficiência energética
  float potencia_consumida = corrente * 220;
  float potencia_maxima = 1000; // exemplo
  float eficiencia_energetica = potencia_consumida / potencia_maxima;

  // Exibir resultados
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  Serial.print("Luz: ");
  Serial.println(luz);
  Serial.print("Corrente: ");
  Serial.println(corrente);
  Serial.print("Eficiência Energética: ");
  Serial.println(eficiencia_energetica);

  // Aguardar 1 segundo antes de ler novamente os sensores
  delay(1000);
}
