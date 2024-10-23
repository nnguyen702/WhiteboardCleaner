
// motors +ultrasonic sens

// Nema 23 3Nm
const int pulX = 26;
const int dirX = 27;

// Nema23 1.9Nm
const int pulY = 24;
const int dirY = 25;

// Nema17 13Ncm
const int stepZ = 22;
const int dirZ = 23;

const int stepsPerRev = 200;

// ultrasonic sensor WB
const int trigWB = 51;
const int echoWB = A0;

// led whiteboard
const int ledWB = 50;

// Ultrasonic sensor X
const int trigX = 53;
const int echoX = A1;

// Ultrasonic sensor Y
const int trigY = 52;
const int echoY = A2;

// distnce range for X
int X_low = 0;
int X_high = 0;
// distnce range for X
int Y_low = 0;
int Y_high = 0;

// above is defind for arduino mega
// below is the defind fro arduino uno
// motors +ultrasonic sens

// Nema 23 3Nm
// const int pulX = 2;
// const int dirX = 3;

// // Nema23 1.9Nm
// const int pulY = 4;
// const int dirY = 5;

// // Nema17 13Ncm
// //const int stepZ = 22;
// //const int dirZ = 23;

// const int stepsPerRev = 200;

// // ultrasonic sensor WB
// const int trigWB = 12;
// const int echoWB = A0;

// // led whiteboard
// const int ledWB = 13;

// // Ultrasonic sensor X
// const int trigX = 11;
// const int echoX = A1;

// // Ultrasonic sensor Y
// const int trigY = 10;
// const int echoY = A2;



//  distances
int distWB;
int distX;
int distY;
void setup() {
  // put your setup code here, to run once:
  //  Nema 23 3Nm - x-direction
  pinMode(pulX, OUTPUT);
  pinMode(dirX, OUTPUT);

  //  Nema 23 1.9Nm - y-direction
  pinMode(pulY, OUTPUT);
  pinMode(dirY, OUTPUT);

  //  Nema 17 13Ncm - x-direction
  //  pinMode(stepZ, OUTPUT);
  //  pinMode(dirZ, OUTPUT);

  // USSWB
  pinMode(trigWB, OUTPUT);
  pinMode(echoWB, INPUT);
  // LED WB
  pinMode(ledWB, OUTPUT);

  // USSX
  pinMode(trigX, OUTPUT);
  pinMode(echoX, INPUT);

  // USSY
  pinMode(trigY, OUTPUT);
  pinMode(echoY, INPUT);
  // ____________________
  Serial.begin(9600);
  // ____________________
}

// all functions go here:
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

void moveFW23(int dir, int pul) {
  digitalWrite(dir, LOW);
  digitalWrite(pul, LOW);
  for (int i = 0; i < stepsPerRev; i++) {
    digitalWrite(pul, HIGH);
    delayMicroseconds(1000);
    digitalWrite(pul, LOW);
    delayMicroseconds(1000);
  }
}
void moveBW23(int dir, int pul) {
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
void StartPos_up( int dir_y, int pul_y,  int dist_y) {

  // Vertical Direction
  if ((dist_y >= 74 && dist_y <= 76) ) {
    stopMotor23(dir_y, pul_y);
  } else if (dist_y < 74) {
    moveBW23(dir_y, pul_y);  //  up
  } else if (dist_y > 76) {
    moveFW23(dir_y, pul_y);
  }
}
void StartPos_over(int dir_x, int pul_x, int dist_x){
    // Horizontal Direction
  if ((dist_x <= 272) && (dist_x >= 260)) {
    stopMotor23(dir_x, pul_x);
  } else if (dist_x < 260) {
    moveBW23(dir_x, pul_x);
  } else if (dist_x > 272) {
    moveFW23(dir_x, pul_x);
  }
  }
  bool StartPos_up_bool(int dir_y, int pul_y,  int dist_y) {
  //Vert. Dir
  if (((dist_y >= 74) && (dist_y <= 76))) {
    return true;
  } else {
    return false;
  }
}
bool StartPos_over_bool( int dir_x, int pul_x, int dist_x) {
  //Horiz. Dir
  if (((dist_x <= 272) && (dist_x >= 260))) {
    return true;
  } else {
    return false;
  }
}
void pos1_st_up(int dir_y, int pul_y, int dir_x, int pul_x, int dist_y, int dist_x) {
  //Vert. Dir
  if ((dist_y >= 74) && (dist_y <= 76)) {
    stopMotor23(dir_y, pul_y);
  } else if (dist_y < 74) {
    moveBW23(dir_y, pul_y);  //  up
  } else if (dist_y > 76) {
    moveFW23(dir_y, pul_y);
  }
}
void pos1_st_over(int dir_y, int pul_y, int dir_x, int pul_x, int dist_y, int dist_x){
  //Horiz. Dir.
  if ((dist_x <= 253 && dist_x >= 245)) {
    stopMotor23(dir_x, pul_x);
  } else if (dist_x > 253) {
    moveFW23(dir_x, pul_x);
  } else if (dist_x < 245) {
    moveBW23(dir_x, pul_x);
  }
  Serial.print("moving to the position 1 start");
}
bool pos1_st_up_bool(int dir_y, int pul_y, int dir_x, int pul_x, int dist_y, int dist_x) {
  //Vert. Dir
  if (((dist_y >= 74) && (dist_y <= 76))) {
    return true;
  } else {
    return false;
  }
}
bool pos1_st_over_bool(int dir_y, int pul_y, int dir_x, int pul_x, int dist_y, int dist_x) {
  //Horiz. Dir
  if (((dist_x <= 253) && (dist_x >= 245))) {
    return true;
  } else {
    return false;
  }
}
// steps for cleaning section 1 on the board
bool wipeRight(int dir_x, int pul_x, int dist_x) {
  if (dist_x >= 204) {
    moveFW23(dir_x, pul_x);
    return false;
  } else if (dist_x < 204) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}
bool down1(int dir_y, int pul_y, int dist_y) {

  if (dist_y <= 68) {
    stopMotor23(dir_y, pul_y);
    return true;
  } else if (dist_y > 68) {
    moveFW23(dir_y, pul_y);
    return false;
  }
}
bool wipeLeft(int dir_x, int pul_x, int dist_x) {
  if (dist_x <= 250) {
    moveBW23(dir_x, pul_x);
    return false;
  } else if (dist_x > 250) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}
bool down2(int dir_y, int pul_y, int dist_y) {

  if (dist_y <= 62) {
    stopMotor23(dir_y, pul_y);
    return true;
  } else if (dist_y > 62) {
    moveFW23(dir_y, pul_y);
    return false;
  }
}
bool wipeRight2(int dir_x, int pul_x, int dist_x) {
  if (dist_x >= 204) {
    moveFW23(dir_x, pul_x);
    return false;
  } else if (dist_x < 204) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}

bool down3(int dir_y, int pul_y, int dist_y) {
  if (dist_y <= 56) {
    stopMotor23(dir_y, pul_y);
    return true;
  } else if (dist_y > 56) {
    moveFW23(dir_y, pul_y);
    return false;
  }
}
bool wipeLeft2(int dir_x, int pul_x, int dist_x) {
  if (dist_x <= 250) {
    moveBW23(dir_x, pul_x);
    return false;
  } else if (dist_x > 250) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}

bool down4(int dir_y, int pul_y, int dist_y) {
  if (dist_y <= 50) {
    stopMotor23(dir_y, pul_y);
    return true;
  } else if (dist_y > 50) {
    moveFW23(dir_y, pul_y);
    return false;
  }
}

bool wipeRight3(int dir_x, int pul_x, int dist_x) {
  if (dist_x >= 204) {
    moveFW23(dir_x, pul_x);
    return false;
  } else if (dist_x < 204) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}


bool down5(int dir_y, int pul_y, int dist_y) {
  if (dist_y <= 44) {
    stopMotor23(dir_y, pul_y);
    return true;
  } else if (dist_y > 44) {
    moveFW23(dir_y, pul_y);
    return false;
  }
}

bool wipeLeft3(int dir_x, int pul_x, int dist_x) {
  if (dist_x <= 250) {
    moveBW23(dir_x, pul_x);
    return false;
  } else if (dist_x > 250) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}

// ========================++++++++++++++++++++++++++++++++++++++++++============POSITION 1==+++++++++++++===========+++++++
enum cleaning1_States { START_over,
                        START_up,
                        wait,
                        wipe_right,
                        down_1,
                        wipe_left,
                        down_2,
                        wipe_right2,
                        down_3,
                        wipe_left2,
                        down_4,
                        wipe_right3,
                        down_5,
                        wipe_left3 } State;
int num;
int val = 0;

int clean1_pattern() {

  switch (State) {  //Transitions
    case START_over:
    Serial.print("Start - state - ");
      Serial.println(00000000);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num == 20) {
        State = START_up;  //Initial state
      } else if (num == 0) {
        State = START_over;  //Initial state
      }
      break;
    case START_up:
      Serial.print("Start - state - ");
      Serial.println(00000000);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num == 1) {
        State = wipe_right;  //Initial state
      } else if (num == 0) {
        State = START_up;  //Initial state
      }
      break;
    
    case wipe_right:
      Serial.print("wipeRight - state - ");
      Serial.println(1);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);
      if (num == 2) {
        State = down_1;
      } else if (num == 0) {
        State = wipe_right;  //Initial state
      }

      break;
    case down_1:
      Serial.print("down_1 - state - ");
      Serial.println(2);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num == 3) {
        State = wipe_left;
      } else if (num == 0) {
        State = down_1;  //Initial state
      }

      break;
    case wipe_left:
      Serial.print("wipeLeft- state - ");
      Serial.println(00000000);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num == 4) {
        State = down_2;
      } else if (num == 0) {
        State = wipe_left;  //Initial state
      }
      break;
    case down_2:  // add more down and repeat right\left swipe if needed
      Serial.print("down2- state - ");
      Serial.println(00000000);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num == 5) {
        State = wipe_right2;
      } else if (num == 0) {
        State = down_2;  //Initial state
      }
      break;

    case wipe_right2:
      Serial.print("right2 - state - ");
      Serial.println(2);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num == 6) {
        State = down_3;
      } else if (num == 0) {
        State = wipe_right2;  //Initial state
      }

      break;
    case down_3:
      Serial.print("down3- state - ");
      Serial.println(00000000);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num == 7) {
        State = wipe_left2;
      } else if (num == 0) {
        State = down_3;  //Initial state
      }
      break;
    case wipe_left2:
      Serial.print("wipeLeft2- state - ");
      Serial.println(00000000);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num == 8) {
        State = down_4;
      } else if (num == 0) {
        State = wipe_left2;  //Initial state
      }
      break;

    case down_4:
      Serial.print("down4- state - ");
      Serial.println(00000000);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num == 9) {
        State = wipe_right3;
      } else if (num == 0) {
        State = down_4;  //Initial state
      }
      break;
    case wipe_right3:
      Serial.print("right3 - state - ");
      Serial.println(2);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num == 10) {
        State = down_5;
      } else if (num == 0) {
        State = wipe_right3;  //Initial state
      }
      break;

    case down_5:
      Serial.print("down5- state - ");
      Serial.println(00000000);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num == 11) {
        State = wipe_left3;
      } else if (num == 0) {
        State = down_5;  //Initial state
      }
      break;

    case wipe_left3:
      Serial.print("wipeLeft3- state - ");
      Serial.println(00000000);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num == 12) {
        State = wait;
      } else if (num == 0) {
        State = wipe_left3;  //Initial state
      }
      break;

    case wait:
      return val = 1;
      break;
    default:
      break;
  }


  switch (State) {  //State actions
     case START_over:
      pos1_st_over(dirY, pulY, dirX, pulX, distY, distX);
      distX = getDistance(echoX, trigX);
      distY = getDistance(echoY, trigY);
      if (pos1_st_over_bool(dirY, pulY, dirX, pulX, distY, distX) == true) {
        num = 20;
      } else {
        num = 0;
      }
      break;

    case START_up:
      pos1_st_up(dirY, pulY, dirX, pulX, distY, distX);
      distX = getDistance(echoX, trigX);
      distY = getDistance(echoY, trigY);
      if (pos1_st_up_bool(dirY, pulY, dirX, pulX, distY, distX) == true) {
        num = 1;
      } else {
        num = 0;
      }
      break;
   
    case wipe_right:

      wipeRight(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeRight(dirX, pulX, distX) == true) {
        num = 2;
      } else {
        num = 1;
      }
      break;
    case down_1:

      down1(dirY, pulY, distY);
      distY = getDistance(echoY, trigY);
      if (down1(dirY, pulY, distY) == true) {
        num = 3;
      } else {
        num = 0;
      }
      break;
    case wipe_left:

      wipeLeft(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeLeft(dirX, pulX, distX) == true) {
        num = 4;
      } else {
        num = 0;
      }
      break;
    case down_2:
      down2(dirY, pulY, distY);
      distY = getDistance(echoY, trigY);
      if (down2(dirY, pulY, distY) == true) {
        num = 5;
      } else {
        num = 0;
      }
      break;
    case wipe_right2:
      wipeRight2(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeRight2(dirX, pulX, distX) == true) {
        num = 6;
      } else {
        num = 0;
      }
      break;
    case down_3:
      down3(dirY, pulY, distY);
      distY = getDistance(echoY, trigY);
      if (down3(dirY, pulY, distY) == true) {
        num = 7;
      } else {
        num = 0;
      }
      break;

    case wipe_left2:
      wipeLeft2(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeLeft2(dirX, pulX, distX) == true) {
        num = 8;
      } else {
        num = 0;
      }
      break;

    case down_4:
      down4(dirY, pulY, distY);
      distY = getDistance(echoY, trigY);
      if (down4(dirY, pulY, distY) == true) {
        num = 9;
      } else {
        num = 0;
      }
      break;

    case wipe_right3:
      wipeRight3(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeRight3(dirX, pulX, distX) == true) {
        num = 10;
      } else {
        num = 0;
      }
      break;
    case down_5:
      down5(dirY, pulY, distY);
      distY = getDistance(echoY, trigY);
      if (down5(dirY, pulY, distY) == true) {
        num = 11;
      } else {
        num = 0;
      }
      break;

    case wipe_left3:

      wipeLeft3(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeLeft3(dirX, pulX, distX) == true) {
        num = 12;
      } else {
        num = 0;
      }
      break;

    case wait:
      stopMotor23(dirX, pulX);

      break;

    default:
      break;
  }
}

// =============================================================_________________________POSITION 2________________________++
void pos2_st_up(int dir_y, int pul_y, int dir_x, int pul_x, int dist_y, int dist_x) {
  //Vert. Dir

  if ((dist_y >= 74) && (dist_y <= 76)) {
    stopMotor23(dir_y, pul_y);
  } else if (dist_y < 74) {
    moveBW23(dir_y, pul_y);  //  up
  } else if (dist_y > 76) {
    moveFW23(dir_y, pul_y);
  }
}

void pos2_st_over(int dir_y, int pul_y, int dir_x, int pul_x, int dist_y, int dist_x){
  //Horiz. Dir.
  if ((dist_x <= 206 && dist_x >= 204)) {
    stopMotor23(dir_x, pul_x);
  } else if (dist_x > 206) {
    moveFW23(dir_x, pul_x);
  } else if (dist_x < 204) {
    moveBW23(dir_x, pul_x);
  }
  Serial.print("moving to the position 2 start");
}
bool pos2_st_up_bool(int dir_y, int pul_y, int dir_x, int pul_x, int dist_y, int dist_x) {
  //Vert. Dir
  if (((dist_y >= 74) && (dist_y <= 76))) {
    return true;
  } else {
    return false;
  }
}
bool pos2_st_over_bool(int dir_y, int pul_y, int dir_x, int pul_x, int dist_y, int dist_x) {
  //Vert. Dir
  if (((dist_x <= 206) && (dist_x >= 204))) {
    return true;
  } else {
    return false;
  }
}

// steps for cleaning section 1 on the board
bool wipeRight_p2(int dir_x, int pul_x, int dist_x) {
  if (dist_x >= 167) {
    moveFW23(dir_x, pul_x);
    return false;
  } else if (dist_x < 167) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}
//  down1 same
bool wipeLeft_p2(int dir_x, int pul_x, int dist_x) {
  if (dist_x <= 204) {
    moveBW23(dir_x, pul_x);
    return false;
  } else if (dist_x > 204) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}
// down 2 same
bool wipeRight2_p2(int dir_x, int pul_x, int dist_x) {
  if (dist_x >= 167) {
    moveFW23(dir_x, pul_x);
    return false;
  } else if (dist_x < 167) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}

//  down 3 smae
bool wipeLeft2_p2(int dir_x, int pul_x, int dist_x) {
  if (dist_x <= 204) {
    moveBW23(dir_x, pul_x);
    Serial.print("wipeLeft2_p2: false");
    return false;
  } else if (dist_x > 204) {
    stopMotor23(dir_x, pul_x);
    Serial.print("wipeLeft2_p2: true");
    return true;
  }
}

// down 4 same

bool wipeRight3_p2(int dir_x, int pul_x, int dist_x) {
  if (dist_x >= 167) {
    moveFW23(dir_x, pul_x);
    return false;
  } else if (dist_x < 167) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}
// down 5 same

bool wipeLeft3_p2(int dir_x, int pul_x, int dist_x) {
  if (dist_x <= 204) {
    moveBW23(dir_x, pul_x);
    return false;
  } else if (dist_x > 204) {
    stopMotor23(dir_x, pul_x);
    return true;
  }
}


enum cleaning2_States { START_p2_over,
                        START_p2_up,
                        wipe_right_p2,
                        down_1_p2,
                        wipe_left_p2,
                        down_2_p2,
                        wipe_right2_p2,
                        down_3_p2,
                        wipe_left2_p2,
                        down_4_p2,
                        wipe_right3_p2,
                        down_5_p2,
                        wipe_left3_p2,
                        wait_p2,
                        origin_over,
                        origin_up} State_p2;
int num_p2;

int clean2_pattern() {

  switch (State_p2) {  //Transitions

  case START_p2_over:
    Serial.print("Start_over - state - ");
      Serial.println(0);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);
// 
      if (num_p2 == 20) {
        State_p2 = START_p2_up;  
      } else if (num_p2 == 0) {
        State_p2 = START_p2_over;  //Initial state
      }
      break;
    case START_p2_up:
      Serial.print("Start_up - state - ");
      Serial.println(0);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num_p2 == 1) {
        State_p2 = wipe_right_p2;  //Next state
      } else if (num_p2 == 0) {
        State_p2 = START_p2_up;  //Initial state
      }
      break;
    
    
    case wipe_right_p2:
      Serial.print("wipeRight_p2 - state - ");
      Serial.println(1);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);
      if (num_p2 == 2) {
        State_p2 = down_1_p2;
      } else if (num_p2 == 0) {
        State_p2 = wipe_right_p2;  //Initial state
      }

      break;
    case down_1_p2:
      Serial.print("down_1 - state - ");
      Serial.println(2);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num_p2 == 3) {
        State_p2 = wipe_left_p2;
      } else if (num == 0) {
        State_p2 = down_1_p2;  //Initial state
      }

      break;
    case wipe_left_p2:
      Serial.print("wipeLeft- state - ");
      Serial.println(00000000);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num_p2 == 4) {
        State_p2 = down_2_p2;
      } else if (num == 0) {
        State_p2 = wipe_left_p2;  //Initial state
      }
      break;
    case down_2_p2:  // add more down and repeat right\left swipe if needed
      Serial.print("down2- state - ");
      Serial.println(00000000);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num_p2 == 5) {
        State_p2 = wipe_right2_p2;
      } else if (num == 0) {
        State_p2 = down_2_p2;  //Initial state
      }
      break;

    case wipe_right2_p2:
      Serial.print("right2 - state - ");
      Serial.println(2);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num_p2 == 6) {
        State_p2 = down_3_p2;
      } else if (num == 0) {
        State_p2 = wipe_right2_p2;  //Initial state
      }

      break;
    case down_3_p2:
      Serial.print("down3- state - ");
      Serial.println(00000000);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num_p2 == 7) {
        State_p2 = wipe_left2_p2;
      } else if (num_p2 == 0) {
        State_p2 = down_3_p2;  //Initial state
      }
      break;
    case wipe_left2_p2:
      Serial.print("wipeLeft2- state - ");
      Serial.println(00000000);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num_p2 == 8) {
        State_p2 = down_4_p2;
      } else if (num_p2 == 0) {
        State_p2 = wipe_left2_p2;  //Initial state
      }
      break;

    case down_4_p2:
      Serial.print("down4- state - ");
      Serial.println(00000000);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num_p2 == 9) {
        State_p2 = wipe_right3_p2;
      } else if (num_p2 == 0) {
        State_p2 = down_4_p2;  //Initial state
      }
      break;
    case wipe_right3_p2:
      Serial.print("right3 - state - ");
      Serial.println(2);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num_p2 == 10) {
        State_p2 = down_5_p2;
      } else if (num_p2 == 0) {
        State_p2 = wipe_right3_p2;  //Initial state
      }
      break;

    case down_5_p2:
      Serial.print("down5- state - ");
      Serial.println(00000000);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - Y - ");
      Serial.println(distY);

      if (num_p2 == 11) {
        State_p2 = wipe_left3_p2;
      } else if (num_p2 == 0) {
        State_p2 = down_5_p2;  //Initial state
      }
      break;

    case wipe_left3_p2:
      Serial.print("wipeLeft3- state - ");
      Serial.println(00000000);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num_p2 == 12) {
        State_p2 = origin_over;
      } else if (num_p2 == 0) {
        State_p2 = wipe_left3_p2;  //Initial state
      }
      break;
    case origin_over:
    Serial.print("origin_over- state - ");
      Serial.println(00000000);
      distX = getDistance(echoX, trigX);
      Serial.print("Distance - X - ");
      Serial.println(distX);

      if (num_p2 == 13) {
        State_p2 = origin_up;
      } else if (num_p2 == 0) {
        State_p2 = origin_over;  //Initial state
      }
      break;
    
    case origin_up:
    Serial.print("origin_up- state - ");
      Serial.println(00000000);
      distY = getDistance(echoY, trigY);
      Serial.print("Distance - X - ");
      Serial.println(distY);

      if (num_p2 == 14) {
        State_p2 = wait_p2;
      } else if (num_p2 == 0) {
        State_p2 = origin_up;  //Initial state
      }
      break;
    case wait_p2:
      return val = 2;
      break;
    default:
      break;
  }


  switch (State_p2) {  //State actions
    case START_p2_over:
    pos2_st_over(dirY, pulY, dirX, pulX, distY, distX);
      distX = getDistance(echoX, trigX);
      distY = getDistance(echoY, trigY);
      if (pos2_st_over_bool(dirY, pulY, dirX, pulX, distY, distX) == true) {
        num_p2 = 20;
      } else {
        num_p2 = 0;
      }
      break;

    case START_p2_up:
      pos2_st_up(dirY, pulY, dirX, pulX, distY, distX);
      distX = getDistance(echoX, trigX);
      distY = getDistance(echoY, trigY);
      if (pos2_st_up_bool(dirY, pulY, dirX, pulX, distY, distX) == true) {
        num_p2 = 1;
      } else {
        num_p2 = 0;
      }
      break;

    case wipe_right_p2:

      wipeRight_p2(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeRight_p2(dirX, pulX, distX) == true) {
        num_p2 = 2;
      } else {
        num_p2 = 1;
      }
      break;
    case down_1_p2:

      down1(dirY, pulY, distY);
      distY = getDistance(echoY, trigY);
      if (down1(dirY, pulY, distY) == true) {
        num_p2 = 3;
      } else {
        num_p2 = 0;
      }
      break;
    case wipe_left_p2:

      wipeLeft_p2(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeLeft_p2(dirX, pulX, distX) == true) {
        num_p2 = 4;
      } else {
        num_p2 = 0;
      }
      break;
    case down_2_p2:
      down2(dirY, pulY, distY);
      distY = getDistance(echoY, trigY);
      if (down2(dirY, pulY, distY) == true) {
        num_p2 = 5;
      } else {
        num_p2 = 0;
      }
      break;
    case wipe_right2_p2:
      wipeRight2_p2(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeRight2_p2(dirX, pulX, distX) == true) {
        num_p2 = 6;
      } else {
        num_p2 = 0;
      }
      break;
    case down_3_p2:
      down3(dirY, pulY, distY);
      distY = getDistance(echoY, trigY);
      if (down3(dirY, pulY, distY) == true) {
        num_p2 = 7;
      } else {
        num_p2 = 0;
      }
      break;

    case wipe_left2_p2:
      wipeLeft2_p2(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeLeft2_p2(dirX, pulX, distX) == true) {
        num_p2 = 8;
      } else {
        num_p2 = 0;
      }
      break;

    case down_4_p2:
      down4(dirY, pulY, distY);
      distY = getDistance(echoY, trigY);
      if (down4(dirY, pulY, distY) == true) {
        num_p2 = 9;
      } else {
        num_p2 = 0;
      }
      break;

    case wipe_right3_p2:
      wipeRight3_p2(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeRight3_p2(dirX, pulX, distX) == true) {
        num_p2 = 10;
      } else {
        num_p2 = 0;
      }
      break;
    case down_5_p2:
      down5(dirY, pulY, distY);
      distY = getDistance(echoY, trigY);
      if (down5(dirY, pulY, distY) == true) {
        num_p2 = 11;
      } else {
        num_p2 = 0;
      }
      break;

    case wipe_left3_p2:

      wipeLeft3_p2(dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (wipeLeft3_p2(dirX, pulX, distX) == true) {
        num_p2 = 12;
      } else {
        num_p2 = 0;
      }
      break;
    case origin_over:
      
      StartPos_over( dirX, pulX, distX);
      distX = getDistance(echoX, trigX);
      if (StartPos_over_bool( dirX, pulX, distX) == true) {
        num_p2 = 13;
      } else {
        num_p2 = 0;
      }
      break;
      case origin_up:
      
      StartPos_up( dirY, pulY, distY);
      distX = getDistance(echoX, trigX);
      if (StartPos_up_bool(dirY, pulY, distY) == true) {
        num_p2 = 14;
      } else {
        num_p2 = 0;
      }
      break;
    case wait_p2:
      stopMotor23(dirX, pulX);
      stopMotor23(dirY, pulY);

      break;

    default:
      break;
  }
}
void loop() {

  digitalWrite(ledWB, LOW);
  distWB = getDistance(echoWB, trigWB);
  Serial.print("Distance - WB - ");
  Serial.println(distWB);
  if (distWB < 60) {
    digitalWrite(ledWB, HIGH);
  }

  //StartPos(dirY, pulY, dirX, pulX, distY, distX);
  //pos1_st(dirY, pulY, dirX, pulX, distY, distX);

  //wipeRight(dirX, pulX,distX);
  //down1(dirY, pulY,distY);
  //wipeLeft(dirX, pulX,distX);
  //State =START;
  if (val == 0) {
    clean1_pattern();
    Serial.print("val ====");
    Serial.println(val);

  } else if (val == 1) {
    clean2_pattern();

    Serial.print("val ====");
    Serial.println(val);
  }

//
}
