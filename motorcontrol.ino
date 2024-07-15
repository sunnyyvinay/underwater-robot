// JOYSTICKS
// Joystick 1 (forward, back, left, right)
int x_key = A0;
int y_key = A1;
int x_pos;
int y_pos;

// Joystick 2 (up and down)
int x_key2 = A2;
int y_key2 = A3;
int x_pos2;
int y_pos2;


// MOTORS
// Motor A (front left)
int EN_A = 11;     
int IN1 = 22;
int IN2 = 24;       

// Motor B (front right)
int IN3 = 26;        
int IN4 = 28;        
int EN_B = 10;      

// Motor C (left)
int EN_C = 9;      
int IN5 = 30;      
int IN6 = 32;      

// Motor D (right)
int IN7 = 34;      
int IN8 = 36;      
int EN_D = 8;      

// Motor E (back left)
int IN9 = 38;      
int IN10 = 40;       
int EN_E= 7;     

// Motor F (back right)
int IN11 = 42;       
int IN12 = 44;      
int EN_F = 6;     


void setup() {
  Serial.begin (9600); //Starting the serial communication at 9600 baud rate
  
  //Initializing the motor pins as output
  pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN_B, OUTPUT);
  
  pinMode(EN_C, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(EN_D, OUTPUT);

  pinMode(EN_E, OUTPUT);
  pinMode(IN9, OUTPUT);
  pinMode(IN10, OUTPUT);
  pinMode(IN11, OUTPUT);
  pinMode(IN12, OUTPUT);
  pinMode(EN_F, OUTPUT);
  
  //Initializing the joystick pins as input
  pinMode (x_key, INPUT);
  pinMode (y_key, INPUT);
  pinMode (x_key2, INPUT);
  pinMode (y_key2, INPUT);
}

void loop() {
  x_pos = analogRead (x_key);  // Reading the horizontal movement value
  y_pos = analogRead (y_key);  // Reading the vertical movement value
  x_pos2 = analogRead(x_key2);
  y_pos2 = analogRead(y_key2);

  int motor_speed;
  int motor_speed1;
  int motor_speed2;

  if (y_pos>=400 && y_pos <=600 && x_pos>=400 && x_pos<=600) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(IN9, LOW);
    digitalWrite(IN10, LOW);
    digitalWrite(IN11, LOW);
    digitalWrite(IN12, LOW);
  }

  if (y_pos > 600) {                                // BACKWARD: A/B counterclockwise, E/F clockwise
    motor_speed1 = map(y_pos, 600, 1023, 0, 255);
    Serial.print("backward: ");
    Serial.println(motor_speed1);
    
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN_A, motor_speed1);
    analogWrite(EN_B, motor_speed1);
    
    digitalWrite(IN9, HIGH);
    digitalWrite(IN10, LOW);
    digitalWrite(IN11, HIGH);
    digitalWrite(IN12, LOW);
    analogWrite(EN_E, motor_speed1);
    analogWrite(EN_F, motor_speed1);
  } else if (y_pos < 400){                          // FORWARD: A/B clockwise, E/F counterclockwise
    motor_speed1 = map(y_pos, 400, 0, 0, 255);
    Serial.print("forward: ");
    Serial.println(motor_speed1);
   
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN_A, motor_speed1);
    analogWrite(EN_B, motor_speed1);
    

    digitalWrite(IN9, HIGH);
    digitalWrite(IN10, LOW);
    digitalWrite(IN11, HIGH);
    digitalWrite(IN12, LOW);
    analogWrite(EN_E, motor_speed1);
    analogWrite(EN_F, motor_speed1);
  }
  
  if (x_pos > 600) {                                // LEFT: A/E counterclockwise, B/F clockwise
    motor_speed = map(x_pos, 600, 1023, 0, 255);  
    Serial.print("left: ");
    Serial.println(motor_speed);
    
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN9, HIGH);
    digitalWrite(IN10, LOW);
    analogWrite(EN_A, motor_speed);
    analogWrite(EN_E, motor_speed);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN11, LOW);
    digitalWrite(IN12, HIGH);
    analogWrite(EN_B, motor_speed);
    analogWrite(EN_F, motor_speed);
  } else if (x_pos < 400) {                         // RIGHT: A/E clockwise, B/F counterclockwise
    motor_speed = map(x_pos, 400, 0, 0, 255);
    Serial.print("right: ");
    Serial.println(motor_speed);
    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN9, LOW);
    digitalWrite(IN10, HIGH);
    analogWrite(EN_A, motor_speed);
    analogWrite(EN_E, motor_speed);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN11, HIGH);
    digitalWrite(IN12, LOW);
    analogWrite(EN_B, motor_speed);
    analogWrite(EN_F, motor_speed);
  }

  
  if (y_pos2 > 600) {                               // DOWN, C/D counterclockwise
    motor_speed2 = map(y_pos2, 600, 1023, 0, 255);
    Serial.print("down: ");
    Serial.println(motor_speed2);
    
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
    analogWrite(EN_C, motor_speed2);
    analogWrite(EN_D, motor_speed2);    
  } else if (y_pos2>400 && y_pos2<600) {
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);
  } else if (y_pos2 < 400) {                         // UP, C/D clockwise
    Serial.print("up");
    motor_speed2 = map(y_pos2, 400, 0, 0, 255);
    Serial.print("up: ");
    Serial.println(motor_speed2);
    
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
    analogWrite(EN_C, motor_speed2);
    analogWrite(EN_D, motor_speed2);      
  }
}
