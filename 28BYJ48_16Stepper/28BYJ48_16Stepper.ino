int apin = 8;
int bpin = 9;
int cpin = 10;
int dpin = 11;
int steps = 128; //run 128 steps per revolution
int phrases = 1024; //run 1024 phrases per revolution

void setup() {
  pinMode(apin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(cpin, OUTPUT);
  pinMode(dpin, OUTPUT);
}

void loop() {

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

void run(int phrasesnum){
  switch(phrasesnum){
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
