char data = 0;

// Init PINS
int plasmaPin = 8;


// Define motor control pins
const int motor1_forward = 13;
const int motor1_backward = 12;
const int motor2_forward = 11;
const int motor2_backward = 10;

const int motor_extra = 9; // Third motor control pin


void setup()
{
  Serial.begin(9600); // Start serial communication at 9600 baud rate

  // Set Plasma Lither
  pinMode(plasmaPin, OUTPUT);
  digitalWrite(plasmaPin, LOW);

  // Set motor control pins as output
  pinMode(motor1_forward, OUTPUT);
  pinMode(motor1_backward, OUTPUT);
  pinMode(motor2_forward, OUTPUT);
  pinMode(motor2_backward, OUTPUT);
  pinMode(motor_extra, OUTPUT);

}


void loop()
{
  if(Serial.available() > 0)
  {
    data = Serial.read(); // Read received data

      // Print Test
      Serial.print(data);
      Serial.print("\n");

    // Control Commands
    switch (data) {
      case 'X': // Stop The Fire
        digitalWrite(plasmaPin, HIGH);
        digitalWrite(motor_extra, LOW);
        break;
      case 'P':// Start the Fire
        digitalWrite(plasmaPin, LOW);
        digitalWrite(motor_extra, HIGH);
        break;
       case 'F': // Move Forward
        digitalWrite(motor1_forward, HIGH);
        digitalWrite(motor1_backward, LOW);
        digitalWrite(motor2_forward, HIGH);
        digitalWrite(motor2_backward, LOW);
        break;
      case 'B': // Move Backward
        digitalWrite(motor1_forward, LOW);
        digitalWrite(motor1_backward, HIGH);
        digitalWrite(motor2_forward, LOW);
        digitalWrite(motor2_backward, HIGH);
        break;
      case 'R': // Turn Left
        digitalWrite(motor1_forward, HIGH);
        digitalWrite(motor1_backward, LOW);
        digitalWrite(motor2_forward, LOW);
        digitalWrite(motor2_backward, LOW);
        break;
      case 'L': // Turn Right
        digitalWrite(motor1_forward, LOW);
        digitalWrite(motor1_backward, LOW);
        digitalWrite(motor2_forward, HIGH);
        digitalWrite(motor2_backward, LOW);
        break;
      case 'S': // Stop
        digitalWrite(motor1_forward, LOW);
        digitalWrite(motor1_backward, LOW);
        digitalWrite(motor2_forward, LOW);
        digitalWrite(motor2_backward, LOW);
        break;
      case 'M': // Turn on extra motor via Bluetooth
        digitalWrite(motor_extra, HIGH);
        break;
    }
  }
}