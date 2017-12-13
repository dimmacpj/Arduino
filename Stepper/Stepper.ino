int apin = 8;
int bpin = 9;
int cpin = 10;
int dpin = 11;

void setup() {
  // put your setup code here, to run once: 
  pinMode(apin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(cpin, OUTPUT);
  pinMode(dpin, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  //singlePhrase();

  //single();
  //delay(1);
  
  //twofour();
  //delay(1);

  //twoeight();
  //delay(1);
  int steps = 128; //run 128 steps per revolution
  int phrases = 1024; //run 1024 phrases per revolution
  /*
  while(steps > 0){
    //single();
    twoeight();
    delay(1000);
    steps--;
  }
  delay(5000);
  */
  int spin_speed_phrase = 1;
  int spin_speed_step = 1;
  int total_steps = 10;
  int current_phrase = 0;
  int spin_direction = 0;// initial spin direciont to 0 ( 0 means counterclockwise
                         // 1 means clockwise)
  int total_phrases = abs(total_steps) * 8;  //change steps to phrases
  //change direction
  if(total_steps > 0){
    spin_direction = 1;
  }
  else{
    spin_direction = 0;
  }

  while(total_phrases > 0){   //start spinning
    
    if(current_phrase % 8 == 0){   // stop half second every 8 phrases
      delay(spin_speed_step);    //also means stop half second every step
    }
    if(spin_direction == 1){
      run(current_phrase % 8);
      current_phrase ++;
      if(current_phrase == phrases){   //reset current phrase every revolution
        current_phrase = 0;
      }
    }
    else if(spin_direction == 0){
      if(current_phrase == 0){
        current_phrase = phrases;
      }
      run(current_phrase % 8);
      current_phrase --;
    }
    
    delay(spin_speed_phrase);
    total_phrases--;
  }
  delay(1000);
  
}

void run(int stepsnum){
  switch(stepsnum){
    case 0:
      digitalWrite(dpin,LOW);
      digitalWrite(apin,HIGH);//a
      break;
    case 1:
      digitalWrite(bpin,HIGH);//ab
      break;
    case 2:
      digitalWrite(apin,LOW);//b
      break;
    case 3:
      digitalWrite(cpin,HIGH);//bc
      break;
    case 4:
      digitalWrite(bpin,LOW);//c
      break;
    case 5:
      digitalWrite(dpin,HIGH);//cd
      break;
    case 6:
      digitalWrite(cpin,LOW);//d
      break;
    case 7:
      digitalWrite(apin,HIGH);//da
      break;
    default:
      digitalWrite(apin,LOW);
      digitalWrite(bpin,LOW);
      digitalWrite(cpin,LOW);
      digitalWrite(dpin,LOW);
      break;
  }
}

void twoeight(){
  digitalWrite(dpin,LOW);
  digitalWrite(apin,HIGH);//a
  delay(500);
  digitalWrite(bpin,HIGH);//ab
  delay(500);
  digitalWrite(apin,LOW);//b
  delay(500);
  digitalWrite(cpin,HIGH);//bc
  delay(500);
  digitalWrite(bpin,LOW);//c
  delay(500);
  digitalWrite(dpin,HIGH);//cd
  delay(500);
  digitalWrite(cpin,LOW);//d
  delay(500);
  digitalWrite(apin,HIGH);//da
  delay(500);
  
}

void twofour(){
  digitalWrite(dpin,LOW);
  digitalWrite(apin,HIGH);
  digitalWrite(bpin,HIGH);//AB
  delay(10);
  digitalWrite(apin,LOW);
  digitalWrite(cpin,HIGH);//BC
  delay(10);
  digitalWrite(bpin,LOW);
  digitalWrite(dpin,HIGH);//CD
  delay(10);
  digitalWrite(cpin,LOW);
  digitalWrite(apin,HIGH);//DA
  delay(10);
  
}

void single(){
  digitalWrite(dpin,LOW);
  digitalWrite(apin, HIGH);
  delay(50);
  digitalWrite(apin,LOW);
  digitalWrite(bpin, HIGH);
  delay(50);
  digitalWrite(bpin,LOW);
  digitalWrite(cpin, HIGH);
  delay(50);
  digitalWrite(cpin,LOW);
  digitalWrite(dpin, HIGH);
  delay(50);
}

void singlePhrase(){
  for(int i = 0 ; i < 64 ; i ++){
    digitalWrite(dpin,LOW);
    digitalWrite(cpin, HIGH);
    delay(10);
    digitalWrite(cpin,LOW);
    digitalWrite(bpin, HIGH);
    delay(10);
    digitalWrite(bpin,LOW);
    digitalWrite(apin, HIGH);
    delay(10);
    digitalWrite(apin,LOW);
    digitalWrite(dpin, HIGH);
    delay(10);
  }
  
  delay(500);

  for(int i = 0 ; i < 64 ; i ++){
    digitalWrite(dpin,LOW);
    digitalWrite(apin, HIGH);
    delay(10);
    digitalWrite(apin,LOW);
    digitalWrite(bpin, HIGH);
    delay(10);
    digitalWrite(bpin,LOW);
    digitalWrite(cpin, HIGH);
    delay(10);
    digitalWrite(cpin,LOW);
    digitalWrite(dpin, HIGH);
    delay(10);
  }

  delay(500);
}

