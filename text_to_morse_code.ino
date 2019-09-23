
int ledPins[] = {2,3,4,5,6,7,8,9,10,11,12,13};

String morseCodeAlphabet[] ={".-","-...","-.-.","-..",".","..-.","--.","....",".."
,".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-"
,"...-",".--","-..-","-.--","--.."};


/*
Assume dot length= 100ms;
Dash length = Dot length x 3

Pause between elements = Dot length

Pause between characters =Dot length x 3

Pause between words = Dot length x 7


**/


void setup() {
  // put your setup code here, to run once:
  int index;
for(index = 0; index <12; index++)

{

pinMode(ledPins[index],OUTPUT);

}

TranslateToMorseCode("today is your third anniversary");
}


void loop() {
  // put your main code here, to run repeatedly:

}

void TranslateToMorseCode(String message)

{

int delayTime = 100; 
//Turns on all LEDs 
 for(int j=0; j<message.length(); j++ ){

 char letter = message.charAt(j);
 if(!isSpace(letter)){

 //dalay between letters
 for(int i = 0; i <12; i++){
digitalWrite(ledPins[i], LOW); 
}
delay(delayTime*3); //wait delayTime milliseconds



 String morseCode = letterToCode(letter);
 for(int k=0;k<morseCode.length();k++){
   char code = morseCode.charAt(k);
   int  codeTime=1;
   if(code=='-'){
    codeTime=3;
    }else{
       codeTime=1;
      }
for(int i = 0; i <12; i++){
digitalWrite(ledPins[i], HIGH); 
}
delay(delayTime*codeTime); //wait delayTime milliseconds

// turn all the LEDs off:

for(int i = 0; i <12; i++){
digitalWrite(ledPins[i], LOW); 
}
delay(delayTime); //wait delayTime milliseconds
}
 
 }else{
  // new word dalay 
  
for(int i = 0; i <12; i++){
digitalWrite(ledPins[i], LOW); 
}
delay(delayTime*7); //wait delayTime milliseconds
  }

}// end message for loop
}


String letterToCode(char letter){
  return morseCodeAlphabet[letter-97];
  }
