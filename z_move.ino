
// // *******MEGA**************
// Ultras sonic Z
const int trigZ = 48;
const int echoZ = A3;

// nema 17 Z motor
const int stepZ = 22;
const int dirZ = 23;
//******************************

// **********UNO***************
// // Ultras sonic Z
// const int trigZ = 3;
// const int echoZ = A3;

// nema 17 Z motor
// const int stepZ = 8;
// const int dirZ = 7;


// // dir HIGH - in
// // dir LOW - out


const int stepsPerRev = 200;


int distZ;


void setup() {
  // put your setup code here, to run once:
  pinMode(stepZ, OUTPUT);
  pinMode(dirZ, OUTPUT);

  pinMode(trigZ, OUTPUT);
  pinMode(echoZ, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  // moveFW23(dirZ, stepZ);

  // moveBW23(dirZ, stepZ);
  distZ = getDistance(echoZ, trigZ);
  Serial.print("distZ - ");
  Serial.println(distZ);

// move fw - out
// move bw - out
  // distance 3-4 - all the way in

  // move out dist: ...

  // move to board........................
  // if(distZ >= 11){
  //   moveFW23(dirZ, stepZ);
  // }else if(distZ <= 8){
  //   stopMotor23(dirZ, stepZ);
  // }
  // moveFW23(dirZ, stepZ);


// move into the board.....................
move_in(dirZ,stepZ, distZ);
delay(5000);
move_out(dirZ, stepZ, distZ);
delay(5000);
}
void move_in(int dir_z, int step_z, int dist_z){
 if (dist_z>5)
 moveFW23(dir_z,step_z);
 else if (dist_z <= 5)
 {
   stopMotor23(dir_z, step_z);
 }
}

void move_out(int dir_z, int step_z, int dist_z){
   if (dist_z <= 12)
 moveBW23(dir_z,step_z);
 else if (dist_z > 10)
 {
   stopMotor23(dir_z, step_z);
 }
}

int getDistance(int echo, int trig) {
  // func has inputs echo and triger from the ultrasonic sensors
  // and returns the calculated distance in cm
  long duration;
  int distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  // distance in cm
  distance = duration * 0.034 / 2;
  return distance;
}

void moveFW23(int dir, int pul) {//////
  digitalWrite(dir, LOW);
  digitalWrite(pul, LOW);
  for (int i = 0; i < stepsPerRev; i++) {
    digitalWrite(pul, HIGH);
    delayMicroseconds(1000);
    digitalWrite(pul, LOW);
    delayMicroseconds(1000);
  }
}
void moveBW23(int dir, int pul) {///
  digitalWrite(dir, HIGH);
  for (int i = 0; i < stepsPerRev; i++) {
    digitalWrite(pul, HIGH);
    delayMicroseconds(1000);
    digitalWrite(pul, LOW);
    delayMicroseconds(1000);
  }
}

void stopMotor23(int dir, int pul) {
  digitalWrite(dir, LOW);
  digitalWrite(pul, LOW);
  delayMicroseconds(2000);
}
