/*--------------------------------------------------------------------
   ROBO SEGUINDO A LINHA BRANCA (CONTROLADOR DOS DIVRES DOS MOTORES)
   CENTRO DE CONTROLE (MOVIMENTO DO ROBÔ)

   -------------------------------------------------------------------*/
// Declarações para drivers
const int steppin1 = 8;
const int steppin2 = 7;
const int dirpin1 = 9;
const int dirpin2 = 6;

// Declaraçôes para os ouvidores do centro de informações
const int controller_moveForward = 13;
const int controller_turnRight = 12;
const int controller_turnLeft = 11;
const int controller_turnMostLeft = 5;
const int controller_turnMostRight = 4;
const int controller_turnLessLeft = 3;
const int controller_turnLessRight = 2;


//Variável para o controle do loop for
int x = 0;


void setup() {
  Serial.begin(9600);

  //Declaração de IO, pulso dos dois motores, e a direção dos dois motores
  pinMode(steppin1, OUTPUT);
  pinMode(steppin2, OUTPUT);
  pinMode(dirpin1, OUTPUT);
  pinMode(dirpin2, OUTPUT);

  //Declarando os ouvidores para controle de direção do ADV (comunicação entre informação e controle)
  pinMode(controller_moveForward, INPUT);
  pinMode(controller_turnRight, INPUT);
  pinMode(controller_turnLeft, INPUT);
  pinMode(controller_turnMostLeft, INPUT);
  pinMode(controller_turnMostRight, INPUT);
  pinMode(controller_turnLessLeft, INPUT);
  pinMode(controller_turnLessRight, INPUT);
}

void loop() {
  //Fazendo com que o robo ande, dependendo do controlador que estiver ativado

  if (digitalRead(controller_moveForward))
  {
    Serial.println(digitalRead(controller_moveForward));
    moveForward();
    delay(10);
  }

  if (digitalRead(controller_turnRight))
  {
    turnRight();
    delay(200);
  }

  if ( digitalRead(controller_turnLeft) )
  {
    turnLeft();
    delay(200);
  }

  if ( digitalRead(controller_turnMostLeft) )
  {
    turnMostLeft();
    delay(200);
  }

  if (digitalRead(controller_turnMostRight))
  {
    turnMostRight();
    delay(200);
  }
  if (digitalRead(controller_turnLessLeft))
  {
    turnLessLeft();
    delay(500);
  }
  if (digitalRead(controller_turnLessRight))
  {
    turnLessRight();
    delay(500);
  }
}

/*--------------------------------------------------------------------
   FUNÇÔES PARA FAZER O ROBO SE MOVER EM DIVERSAS DIREÇOES

   -------------------------------------------------------------------*/

//FUNÇÃO PARA ANDAR PARA A FRENTE
void moveForward()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, LOW);
  digitalWrite(dirpin2, HIGH);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for (x = 0; x < 100; x++) {
    digitalWrite(steppin1, HIGH);
    digitalWrite(steppin2, HIGH);
    delayMicroseconds(10000);
    digitalWrite(steppin1, LOW);
    digitalWrite(steppin2, LOW);
    delayMicroseconds(10000);
  }
}

//FUNÇÃO PARA VIRAR A DIREITA
void turnRight()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, LOW);
  digitalWrite(dirpin2, LOW);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for (x = 0; x < 25; x++) {
    digitalWrite(steppin1, HIGH);
    digitalWrite(steppin2, HIGH);
    delayMicroseconds(6000);
    digitalWrite(steppin1, LOW);
    digitalWrite(steppin2, LOW);
    delayMicroseconds(6000);
  }
}

//FUNÇÃO PARA VIRAR A ESQUERDA
void turnLeft()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, HIGH);
  digitalWrite(dirpin2, HIGH);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for (x = 0; x < 25; x++) {
    digitalWrite(steppin1, HIGH);
    digitalWrite(steppin2, HIGH);
    delayMicroseconds(6000);
    digitalWrite(steppin1, LOW);
    digitalWrite(steppin2, LOW);
    delayMicroseconds(6000);
  }
}

//FUNÇÃO PARA VIRAR MAIS A ESQUERDA
void turnMostLeft()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, HIGH);
  digitalWrite(dirpin2, HIGH);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for (x = 0; x < 10; x++) {
    digitalWrite(steppin1, HIGH);
    digitalWrite(steppin2, HIGH);
    delayMicroseconds(6000);
    digitalWrite(steppin1, LOW);
    digitalWrite(steppin2, LOW);
    delayMicroseconds(6000);
  }
}

//FUNÇÃO PARA VIRAR MAIS A DIREITA
void turnMostRight()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, LOW);
  digitalWrite(dirpin2, LOW);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for (x = 0; x < 10; x++) {
    digitalWrite(steppin1, HIGH);
    digitalWrite(steppin2, HIGH);
    delayMicroseconds(6000);
    digitalWrite(steppin1, LOW);
    digitalWrite(steppin2, LOW);
    delayMicroseconds(6000);
  }
}

//FUNÇÃO PARA VIRAR MAIS A DIREITA lentamente
void turnLessRight()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, LOW);
  digitalWrite(dirpin2, LOW);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for (x = 0; x < 10; x++) {
    digitalWrite(steppin1, HIGH);
    digitalWrite(steppin2, HIGH);
    delayMicroseconds(5000);
    digitalWrite(steppin1, LOW);
    digitalWrite(steppin2, LOW);
    delayMicroseconds(5000);
  }
}

//FUNÇÃO PARA VIRAR MAIS A ESQUERDA lentamente
void turnLessLeft()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, HIGH);
  digitalWrite(dirpin2, HIGH);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for (x = 0; x < 10; x++) {
    digitalWrite(steppin1, HIGH);
    digitalWrite(steppin2, HIGH);
    delayMicroseconds(5000);
    digitalWrite(steppin1, LOW);
    digitalWrite(steppin2, LOW);
    delayMicroseconds(5000);
  }
}
