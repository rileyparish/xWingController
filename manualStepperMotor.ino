// code to manually drive stepper motors by sequentially energizing the coils

int aPlusPin = 1;
int aMinusPin = 2;
int bPlusPin = 3;
int bMinusPin = 4;

int STEPS_PER_REV = 20;
int revs = 5;
int coilChargeDur = 2000;   // how long the coil should be charged in microseconds; delayMicroseconds()

void setup() {
  // put your setup code here, to run once:
  pinMode(aPlusPin, OUTPUT);
  pinMode(aMinusPin, OUTPUT);
  pinMode(bPlusPin, OUTPUT);
  pinMode(bMinusPin, OUTPUT);
}

void loop() {
  
    Serial.println("Moving forward.");
    for(int i = 0; i < STEPS_PER_REV * revs; i++) {
    // move the motor one step in the forward direction
        stepForward();
    }
    delay(1000);    // delay one second in between powering the motor

    Serial.println("Moving backward.");
    for(int i = 0; i < STEPS_PER_REV * revs; i++) {
    // move the motor one step in the backward direction
        stepBackward();
    }
    delay(1000);
}


void stepForward(){
    execSeq1();
    execSeq2();
    execSeq3();
    execSeq4();
}

void stepBackward(){
    execSeq4();
    execSeq3();
    execSeq2();
    execSeq1();
}

void execSeq1(){
    digitalWrite(aPlusPin, HIGH);
    digitalWrite(bPlusPin, HIGH);
    delayMicroseconds(coilChargeDur);
    digitalWrite(aPlusPin, LOW);
    digitalWrite(bPlusPin, LOW);
}

void execSeq2(){
    digitalWrite(aMinusPin, HIGH);
    digitalWrite(bPlusPin, HIGH);
    delayMicroseconds(coilChargeDur);
    digitalWrite(aMinusPin, LOW);
    digitalWrite(bPlusPin, LOW);
}

void execSeq3(){
    digitalWrite(aMinusPin, HIGH);
    digitalWrite(bMinusPin, HIGH);
    delayMicroseconds(coilChargeDur);
    digitalWrite(aMinusPin, LOW);
    digitalWrite(bMinusPin, LOW);
}

void execSeq4(){
    digitalWrite(aPlusPin, HIGH);
    digitalWrite(bMinusPin, HIGH);
    delayMicroseconds(coilChargeDur);
    digitalWrite(aPlusPin, LOW);
    digitalWrite(bMinusPin, LOW);
}

