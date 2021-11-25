// arduino code

#define MOTOR_EN_1  10      // define motor pin location, subject to change
#define MOTOR_IN1 	        // motor 1
#define MOTOR_IN2           // motor 2

#define slow 64             // define speeds
#define normal 128
#define fast 255
 
int Speed;                  // define variable speed
 
void Forward_Rev(void){                     // forward revolution (usually clockwise)
  analogWrite(MOTOR_EN_1, Speed);
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
}
 
void Backward_Rev(void){                    // reverse revolution (anticlockwise)
  analogWrite(MOTOR_EN_1, Speed);
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
}
 
void Brake(void){                           // stop 
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, HIGH);
}
 
void setup() {                              // main function
  
  Serial.begin(9600);
  Serial.println("L293D DC motor test");
 
  pinMode(MOTOR_EN_1, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}
 
void loop() {                               // loops main func until all commands are run
                                            // customize this section to fit our needs
  Speed=normal;                             // Normal Speed - 128 speed as defined above
 
  Backward_Rev(); 
  delay(1000);                              // delay() is basically wait() in other languages
  Brake();
  delay(500);
  Forward_Rev(); 
  delay(1000);
  Brake();
  delay(500);

}
