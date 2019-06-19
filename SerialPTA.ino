int led1=9;
int led2=10;
int led3=11;
int noteDuration;
int pauseBetweenNotes = 0;
int negra;

//Led RGBS
#define ledR 9
#define ledG 10
#define ledB 12

//Led Biasa (White)
#define ledp1 2
#define ledp2 3
#define ledp3 4
#define ledp4 5

//Buzzer
#define bz 6

//LDR
#define ldr A4

//Button
const int btn1 = A0;
const int btn2 = A1;
const int btn3 = A2;

//Potentiometer
const int pot = A5;
int potValue = 0;
int potom = 0;

//Super_Mario
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

// We wish you a merry Christmas
int wish_melody[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

// Santa Claus is coming to town
int santa_melody[] = {
  NOTE_G4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};

int santa_tempo[] = {
  8,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 2,
  4, 4, 4, 4,
  4, 2, 4,
  1
};

void sm()
{
  //sing the tunes
  sing(1);
  sing(1);
  chorus();
  chorus();
//  sing(2);
//  sing(3);
//  sing(4);
//  hb();
}

int song = 0;
 
void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 4) {
    Serial.println(" 'Santa Claus is coming to town'");
    int size = sizeof(santa_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 900 / santa_tempo[thisNote];

      buzz(bz, santa_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(bz, 0, noteDuration);

    }
  } else if (song == 3) {
    Serial.println(" 'We wish you a Merry Christmas'");
    int size = sizeof(wish_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / wish_tempo[thisNote];

      buzz(bz, wish_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(bz, 0, noteDuration);

    }
  } else if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];
      buzz(bz, underworld_melody[thisNote], noteDuration);
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes); 
      // stop the tone playing:
      buzz(bz, 0, noteDuration);
    }
  } else {
    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];
      buzz(bz, melody[thisNote], noteDuration);
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      buzz(bz, 0, noteDuration);
    }
  }
}
 
void buzz(int targetPin, long frequency, long length) {
  ledpOn();
  rgbOn();
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there areelse  two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  ledpOff();
  rgbOff();
}

//Happy_Birthday
int length = 28; // the number of notes
char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };
int tmp = 150;

void playTone(int tone, int duration) {
for (long i = 0; i < duration * 1000L; i += tone * 2) {
   digitalWrite(bz, HIGH);
   ledpOn();
   delayMicroseconds(tone);
   digitalWrite(bz, LOW);
   ledpOff();
   delayMicroseconds(tone);
}
}

void playNote(char note, int duration) {
char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           
                 'c', 'd', 'e', 'f', 'g', 'a', 'b',
                 'x', 'y' };
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
                 956,  834,  765,  593,  468,  346,  224,
                 655 , 715 };
int SPEE = 5;
// play the tone corresponding to the note name
for (int i = 0; i < 17; i++) {
   if (names[i] == note) {
    int newduration = duration/SPEE;
     playTone(tones[i], newduration);
   }
}
}

void hb() {
for (int i = 0; i < length; i++) {
   if (notes[i] == ' ') {
     delay(beats[i] * tmp); // rest
   } else {
     playNote(notes[i], beats[i] * tmp);
     ledpOff();
   }
   // pause between notes
   delay(tmp);
}
}

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
delay(100);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);   
  negra=640;
pinMode(ldr, INPUT);
pinMode(pot, INPUT);
pinMode(btn1, INPUT_PULLUP);
pinMode(btn2, INPUT_PULLUP);
pinMode(btn3, INPUT_PULLUP);
pinMode(bz, OUTPUT);
pinMode(ledR, OUTPUT);
pinMode(ledG, OUTPUT);
pinMode(ledB, OUTPUT);
pinMode(ledp1, OUTPUT);
pinMode(ledp2, OUTPUT);
pinMode(ledp3, OUTPUT);
pinMode(ledp4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int ldrValue = analogRead(ldr);
potValue = analogRead(pot);
potom = map(potValue, 0, 1023, 0 ,255);
const int btn1Value = analogRead(btn1);
const int btn2Value = analogRead(btn2);
const int btn3Value = analogRead(btn3);
Serial.print("ldr : ");
Serial.print(ldrValue);
Serial.print(" | ");
Serial.print("pot : ");
Serial.print(potom);
Serial.print(" |");
Serial.print("| ");
Serial.print(btn1Value);
Serial.print(" ");
Serial.print(btn2Value);
Serial.print(" ");
Serial.println(btn3Value);
delay(100);

while(Serial.available()){
  int data = Serial.read();
    if (data == '1'){
      ledpOn();
    }
    if (data == '2'){
      ledpOff();
    }
    if (data == '3'){
      rgbOn();
    }
    if (data == '4'){
      rgbOff();
    }
    if (data == '5'){
      chorus(); sm(); chorus();
    }  
  }
  if (btn1Value < 512){
    ledpOn();
    delay(500);
    ledpOff();
    delay(500);
    ledp1on();
    delay(100);
    ledp2on();
    delay(100);
    ledp3on();
    delay(100);
    ledp4on();
    delay(100);
    ledp3on();
    delay(100);
    ledp2on();
    delay(100);
    ledp1on();
    delay(100);
    ledp2on();
    delay(100);
    ledp3on();
    delay(100);
    ledp4on();
    delay(100);
    ledp3on();
    delay(100);
    ledp2on();
    delay(100);
    ledp1on();
    delay(500);
    ledpOn();
    delay(100);
    ledpOff();
    ledpOn();
    delay(50);
    ledpOff();
    delay(50);
    ledpOn();
    delay(50);
    ledpOff();
  }
   if (btn2Value < 512){
    rgbOn();
    delay(500);
    rgbOff();
    delay(500);
    rgbRon();
    delay(100);
    rgbGon();
    delay(100);
    rgbBon();
    delay(100);
    rgbGon();
    delay(100);
    rgbRon();
    delay(100);
    rgbGon();
    delay(100);
    rgbBon();
    delay(100);
    rgbGon();
    delay(100);
    rgbRon();
    delay(100);
    rgbGon();
    delay(100);
    rgbBon();
    delay(500);
    rgbOn();
    delay(100);
    rgbOff();
    rgbOn();
    delay(50);
    rgbOff();
    delay(50);
    rgbOn();
    delay(50);
    rgbOff();
  }
  if (btn3Value < 512){
    sm();
  }
}

void bz100(){
tone(bz, 100, 10);
}

void bz1000(){
tone(bz, 1000, 10);
}

void bz10000(){
tone(bz, 10000, 10);
}

void bz65000(){
tone(bz, 65000, 10);
}

void ledpOn(){
digitalWrite(ledp1, HIGH);  
digitalWrite(ledp2, HIGH);
digitalWrite(ledp3, HIGH);
digitalWrite(ledp4, HIGH);
}

void ledpOff(){
digitalWrite(ledp1, LOW);  
digitalWrite(ledp2, LOW);
digitalWrite(ledp3, LOW);
digitalWrite(ledp4, LOW);
}

void ledp1on(){
digitalWrite(ledp1, HIGH);  
digitalWrite(ledp2, LOW);
digitalWrite(ledp3, LOW);
digitalWrite(ledp4, LOW);
}

void ledp2on(){
digitalWrite(ledp1, LOW);  
digitalWrite(ledp2, HIGH);
digitalWrite(ledp3, LOW);
digitalWrite(ledp4, LOW);
}

void ledp3on(){
digitalWrite(ledp1, LOW);  
digitalWrite(ledp2, LOW);
digitalWrite(ledp3, HIGH);
digitalWrite(ledp4, LOW);
}

void ledp4on(){
digitalWrite(ledp1, LOW);  
digitalWrite(ledp2, LOW);
digitalWrite(ledp3, LOW);
digitalWrite(ledp4, HIGH);
}

void rgbOn(){
digitalWrite(ledR, HIGH);
digitalWrite(ledG, HIGH);
digitalWrite(ledB, HIGH); 
}

void rgbOff(){
digitalWrite(ledR, LOW);
digitalWrite(ledG, LOW);
digitalWrite(ledB, LOW);  
}

void rgbRon(){
digitalWrite(ledR, HIGH);
digitalWrite(ledG, LOW);
digitalWrite(ledB, LOW); 
}

void rgbGon(){
digitalWrite(ledR, LOW);
digitalWrite(ledG, HIGH);
digitalWrite(ledB, LOW);  
}

void rgbBon(){
digitalWrite(ledR, LOW);
digitalWrite(ledG, LOW);
digitalWrite(ledB, HIGH); 
}

void chorus(){
     notars(negra, NOTE_D5);
     notars(negra, NOTE_CS5);
     digitalWrite(led1, HIGH); 
     digitalWrite(led3, HIGH);
     digitalWrite(led2, LOW);// (1)
     notars(negra/2, NOTE_B4);
     notars(negra/4, NOTE_FS4);
     digitalWrite(led1, LOW); 
     digitalWrite(led3, LOW);
     digitalWrite(led2, HIGH);// (2)
     delay(negra/4); 
     digitalWrite(led3, HIGH);
     digitalWrite(led1, HIGH);
     digitalWrite(led2, LOW);// (3)
     notars(negra/4, NOTE_FS4);
     notars(negra/4, NOTE_FS4);
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);// (4)
     notars(negra/4, NOTE_FS4);
     notars(negra/4, NOTE_FS4);
     digitalWrite(led1, HIGH);   //  (1) 
     digitalWrite(led2, HIGH);
     digitalWrite(led3, LOW);
     notars(negra/4, NOTE_FS4);
     notars(negra/4, NOTE_B4);
     notars(negra/4, NOTE_B4);
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);//  (2) 
     notars(negra/4, NOTE_B4);
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, LOW);//  (3)  
     notars(negra/2, NOTE_B4);
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);//  (4)   
     notars(negra/4, NOTE_A4); 
     notars(negra/4, NOTE_B4);
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, LOW);//  (1) 
     delay(negra/4); 
     delay(negra/4); 
     notars(negra/4, NOTE_G4);  
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);//  (2) 
     delay(negra/4);
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);//  (3) 
//......
     notars(negra/4, NOTE_G4);  
     notars(negra/4, NOTE_G4);
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);//  (4)   
     notars(negra/4, NOTE_G4);  
     notars(negra/4, NOTE_G4);
     digitalWrite(led2, HIGH);
     digitalWrite(led1, LOW);
     digitalWrite(led3, LOW);//  (1)   
     notars(negra/4, NOTE_G4);  
     notars(negra/4, NOTE_B4);  
     notars(negra/4, NOTE_B4);  
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);//  (2) 
     notars(negra/4, NOTE_B4);
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, LOW);//  (3) 
     notars(negra/2, NOTE_B4);
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);//  (4) 
     notars(negra/4, NOTE_CS5);
     notars(negra/4, NOTE_D5);
     digitalWrite(led1, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led2, LOW);//  (1) 
     delay(negra/4);
     delay(negra/4);
     notars(negra/4, NOTE_A4);
     digitalWrite(led1, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led2, HIGH);//  (2)      
     delay(negra/4);
     digitalWrite(led1, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led2, LOW);//  (3) 
     notars(negra/4, NOTE_A4);     
     notars(negra/4, NOTE_A4);
     digitalWrite(led1, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led2, HIGH);//  (4)           
     notars(negra/4, NOTE_A4);               
     notars(negra/4, NOTE_A4);
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, LOW);//  (1)                
     notars(negra/4, NOTE_D5);          
     notars(negra/4, NOTE_CS5);               
     notars(negra/4, NOTE_D5);
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);//  (2)           
     notars(negra/4, NOTE_CS5);
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, LOW);//  (3)          
     notars(negra/2, NOTE_D5);
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);//  (4)                
     //
     notars(negra/4, NOTE_E5);
     notars_jai(negra/2, NOTE_E5,negra/4);  // (1)
//     notars(negra/2, NOTE_E5);  
    //-----------------------------------------------
      tone(6,NOTE_CS5 ,negra*3/4);
    //-----------------------------------------------
      delay(negra/4);
      delay(negra/4);
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);//  (2)                     
      delay(negra/4);
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, LOW);//  (3)                     
     noTone(6);
     delay(negra/4);
     //--------------
     delay(negra/4);
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);//  (4) 
     delay(negra/4);
     delay(negra/4);
     digitalWrite(led3, LOW);       
}

void notars(int noteDuration,int LaNota ){
    //noteDuration=negra/4;
  tone(6,LaNota ,noteDuration*0.9);
//      pauseBetweenNotes = noteDuration * 1.30;
      pauseBetweenNotes = noteDuration * 1.1;
      delay(pauseBetweenNotes);
      noTone(6);  
}

void notars_jai(int noteDuration,int LaNota ,int Desfase){
    //noteDuration=negra/4;
  tone(6,LaNota ,noteDuration*0.9);
//      pauseBetweenNotes = noteDuration * 1.30;
      pauseBetweenNotes = noteDuration * 1.1;
      delay(Desfase);
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, HIGH);//  (1)   
        delay(pauseBetweenNotes-Desfase);
      noTone(6);  
}
