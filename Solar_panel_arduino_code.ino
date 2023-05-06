#define ldrTr A4 
#define ldrTl A1
#define ldrBl A2
#define ldrBr A3
#define pot A0 //ENCODER (POTENTIOMETER)
#define m1 5    //vertical 
#define m2 6    //vertical
#define m3 9    //horizontal
#define m4 10    //horizontal

int top, bottom, left, right, encoderValue;

int ldr_limit=50;
void setup(){
  Serial.begin(9600);  
  pinMode(ldrTl,INPUT);
  pinMode(ldrTr,INPUT);
  pinMode(ldrBl,INPUT);
  pinMode(ldrBr,INPUT);

  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(pot,INPUT);
//  delay(1000);?
}
void loop(){
  ReadSensors();
  Serial.print(top);
  Serial.print(" ");
  Serial.print(bottom);
  Serial.print(" ");
  Serial.print(left);
  Serial.print(" ");
  Serial.print(right);
  Serial.println(" ");
//      analogWrite(m3,80);
//      analogWrite(m4,0);

  if(abs(top-bottom)> ldr_limit){
    
    if(top>bottom && encoderValue <750){
      analogWrite(m3,0);
      analogWrite(m4,80);
      Serial.println("fsadf");
    } else if (top<bottom && encoderValue >100){
      analogWrite(m3,80);
      analogWrite(m4,0);
      
    } else {
      analogWrite(m3,0);
      analogWrite(m4,0);
    }
  } 
  if(abs(right-left)> ldr_limit){
    if(left>right){
      analogWrite(m1,40);
      analogWrite(m2,0);
    } else if (left<right){
      analogWrite(m1,0);
      analogWrite(m2,40);
    } else {
      analogWrite(m1,0);
      analogWrite(m2,0);
    }
  } 
  delay(100);
}

void ReadSensors(){
  int bottomright=analogRead(ldrBr);
  int topright=analogRead(ldrTr);
  int topleft=analogRead(ldrTl);
  int bottomleft=analogRead(ldrBl);
  encoderValue=analogRead(pot);
  
//  Serial.print(topright);
//  Serial.print(" ");
//  Serial.print(topleft);
//  Serial.print(" ");
//  Serial.print(bottomleft);
//  Serial.print(" ");
//  Serial.print(bottomright);
//  Serial.println(" ");
  
  
  topright = map(topright, 550, 775, 100, 900);
  topleft = map(topleft, 65, 260, 100, 900);
  bottomleft = map(bottomleft, 200, 470, 100, 900);
  bottomright = map(bottomright, 50, 300, 100, 900);
  
//  Serial.print(topright);
//  Serial.print(" ");
//  Serial.print(topleft);
//  Serial.print(" ");
//  Serial.print(bottomleft);
//  Serial.print(" ");
//  Serial.print(bottomright);
//  Serial.println(" ");
  Serial.print(encoderValue);
  Serial.println(" ");

  top=(topleft+topright)/2;
  bottom=(bottomleft+bottomright)/2;
  left=(topleft+bottomleft)/2;
  right=(topright+bottomright)/2;
  
}
