
//***5 Channel IR Sensor Connection***//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
//*****************// 

// Declaraçôes para os enviar para centro de controle
const int controller_moveForward = 13;
const int controller_turnRight = 12;
const int controller_turnLeft = 11;
const int controller_turnMostLeft = 5;
const int controller_turnMostRight = 4;
const int controller_turnLessLeft = 3;
const int controller_turnLessRight = 2;

String direcao = "u";

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo informações dos sensores");

  //Declarando as entradas dos sensores seguidor de linhas
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

  //Declarando os controlles para controle de direção do ADV (comunicação entre informação e controle)
  pinMode(controller_turnRight, OUTPUT);
  pinMode(controller_turnLeft, OUTPUT);
  pinMode(controller_moveForward, OUTPUT);
  pinMode(controller_turnMostLeft, OUTPUT);
  pinMode(controller_turnMostRight, OUTPUT);
  pinMode(controller_turnLessLeft, OUTPUT);
  pinMode(controller_turnLessRight, OUTPUT);
  
}
// -- STRAT VOID LOOP --
void loop() {
  
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

  Serial.println(direcao);

  delay(1000);
/*--------------------------------------------------------------------
 * LÓGICA PARA O ROBÔ SEGUIR A LINHA  
 * 
 * -------------------------------------------------------------------*/

  digitalWrite(controller_turnRight, LOW); //Virar para Direita
  digitalWrite(controller_moveForward, LOW); //Mover para frente
  digitalWrite(controller_turnLeft, LOW); //Virar para Esquerda
  digitalWrite(controller_turnMostLeft, LOW); //Virar mais para Esquerda
  digitalWrite(controller_turnMostRight, LOW); //Virar mais para Direita
  digitalWrite(controller_turnLessLeft, LOW); //Virar mais para Esquerda
  digitalWrite(controller_turnLessRight, LOW); //Virar mais para Direita


  // Se todos os sensores centrais, conseguirem detectar a linha, e a variavel de controle false, então mover o robo para frente
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))

  //s3 != range_sensor && s1 == range_sensor && s5 == range_sensor)
  //s3 < 100 && s1 > 100 && s2 > 100 && s4 > 100 && s5 > 100
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_turnRight, LOW );
        digitalWrite(controller_turnLeft,  LOW );
        digitalWrite(controller_turnMostRight, LOW);
        digitalWrite(controller_turnMostLeft, LOW);
        digitalWrite(controller_turnLessRight, LOW);
        digitalWrite(controller_turnLessLeft, LOW);
        digitalWrite(controller_moveForward, HIGH); //Mover para frente
    
    direcao = "f";
  }


  if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))

  //s3 != range_sensor && s1 == range_sensor && s5 == range_sensor)
  //s3 < 100 && s1 > 100 && s2 > 100 && s4 > 100 && s5 > 100
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_turnRight, LOW );
        digitalWrite(controller_turnLeft,  LOW );
        digitalWrite(controller_turnMostRight, LOW);
        digitalWrite(controller_turnMostLeft, LOW);
        digitalWrite(controller_turnLessRight, LOW);
        digitalWrite(controller_moveForward, LOW);
    //---
     digitalWrite(controller_turnLeft, HIGH); //Mover para frente
    
    direcao = "f";
  }

    // Se todos os sensores centrais, conseguirem detectar a linha, e a variavel de controle false, então mover o robo para frente
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))

  //s3 != range_sensor && s1 == range_sensor && s5 == range_sensor)
  //s3 < 100 && s1 > 100 && s2 > 100 && s4 > 100 && s5 > 100
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnLeft,  LOW );
        digitalWrite(controller_turnMostRight, LOW);
        digitalWrite(controller_turnMostLeft, LOW);
        digitalWrite(controller_turnRight, LOW);
        digitalWrite(controller_turnLessLeft, LOW);
    //---
    digitalWrite(controller_turnLessRight, HIGH); //Virar para Direita
    direcao = "d";
  }

  // Se um dos sensores da esquerda indentificar a linha, então firar para a direita
  if ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnRight,  LOW );
        digitalWrite(controller_turnMostRight, LOW);
        digitalWrite(controller_turnMostLeft, LOW);
        digitalWrite(controller_turnLessRight, LOW);
        digitalWrite(controller_turnLessLeft, LOW);
    //---
    digitalWrite(controller_turnLeft, HIGH); //Viara para Esquerda
    direcao = "e";
    
  }
  
  // Se um dos sensores da esquerda indentificar a linha, então firar para a direita
  if ((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnRight,  LOW );
        digitalWrite(controller_turnMostRight, LOW);
        digitalWrite(controller_turnMostLeft, LOW);
        digitalWrite(controller_turnLessRight, LOW);
        digitalWrite(controller_turnLeft, LOW);
        digitalWrite(controller_turnLessLeft, LOW);
    //---
     //Viara para Esquerda
     digitalWrite(controller_turnLeft, HIGH);
    direcao = "e";
    
  }

  if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
        //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnLeft,  LOW );
        digitalWrite(controller_turnMostRight, LOW);
        digitalWrite(controller_turnMostLeft, LOW);
        digitalWrite(controller_turnLessRight, LOW);
        digitalWrite(controller_turnLessLeft, LOW);
    //---
    digitalWrite(controller_turnRight, HIGH); //Virar para Direita
    direcao = "d";

 
  }

  if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1))
  {
        //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnLeft,  LOW );
        digitalWrite(controller_turnMostRight, LOW);
        digitalWrite(controller_turnMostLeft, LOW);
        digitalWrite(controller_turnRight, LOW);
        digitalWrite(controller_turnLessLeft, LOW);
    //---
    digitalWrite(controller_turnLessRight, HIGH); //Virar para Direita
    direcao = "d";

 
  }

  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnRight,  LOW );
        digitalWrite(controller_turnMostLeft, LOW);
        digitalWrite(controller_turnMostRight, LOW); 
        digitalWrite(controller_turnLessRight, LOW);
        digitalWrite(controller_turnLessLeft, LOW);
    //---
    digitalWrite(controller_turnLeft, HIGH); //Virar para Esquerda
    direcao = "m.e";
  }

  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnMostRight,  LOW );
        digitalWrite(controller_turnLeft, LOW);
        digitalWrite(controller_turnMostLeft, LOW);
        digitalWrite(controller_turnLessRight, LOW);
        digitalWrite(controller_turnLessLeft, LOW);
    //---
    digitalWrite(controller_turnRight, HIGH); //Virar para Esquerda
    direcao = "m.d";
  }

/*
  else if ((s3 == 1) && (s5 == 1) && (s1 == 1) && (s2 == 1) && (s4 == 1))
  {
    digitalWrite(controller_moveForward, LOW );
    digitalWrite(controller_turnLeft,  LOW );
    digitalWrite(controller_turnRight, LOW); //Virar para Direita
    direcao = "p";
  }*/
}
// -- END VOID LOOP --
