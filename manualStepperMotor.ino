// code to manually drive stepper motors by sequentially energizing the coils

int aPlusPin = 2;
int aMinusPin = 3;
int bPlusPin = 4;
int bMinusPin = 5;

int extendPin = 10;
int retractPin = 11;

int STEPS_PER_REV = 20;
int revs = 4;
int coilChargeDur = 2000;   // how long the coil should be charged in microseconds; delayMicroseconds()
int debugDelay = 20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(aPlusPin, OUTPUT);
  pinMode(aMinusPin, OUTPUT);
  pinMode(bPlusPin, OUTPUT);
  pinMode(bMinusPin, OUTPUT);

  pinMode(extendPin, INPUT_PULLUP);
  pinMode(retractPin, INPUT_PULLUP);
}

void loop() {

    if(digitalRead(extendPin) == LOW){
        Serial.println("Extending motor.");
        for(int i = 0; i < STEPS_PER_REV * revs; i++) {
            // move the motor one step in the backward direction
            stepBackward();
        }
    }
    if(digitalRead(retractPin) == LOW){
        Serial.println("Retracting motor.");
        for(int i = 0; i < STEPS_PER_REV * revs; i++) {
            // move the motor one step in the forward direction
            stepForward();
        }
    }
}


void stepForward(){
    // forward moves the plate toward the motor (retracts)
    execSeq1();
    execSeq2();
    execSeq3();
    execSeq4();
    delay(debugDelay);
}

void stepBackward(){
    // backward moves the plate further from the motor (extends)
    execSeq4();
    execSeq3();
    execSeq2();
    execSeq1();
    delay(debugDelay);
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

