#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  // Establishes a connection between the Arduino pins and the LCD

int redLED = 3;
int blueLED = 23;
int greenLED = 2;
int yellowLED = 26;
int whiteLED = 24;

int redbutton = 36;
int bluebutton = 30;
int greenbutton = 37;
int yellowbutton = 28;
int whitebutton = 29;

int buzzer = 13;

int LED[] = { redLED, blueLED, greenLED, yellowLED, whiteLED };
int buttons[] = { redbutton, bluebutton, greenbutton, yellowbutton, whitebutton };

int total_score = 0;
int gameRound = 1;
bool gameEnded = false;

//User-defined function prototypes
void playVictorySound();
void playLossSound();
void playFinalVictorySound();


void setup() {

  pinMode(buzzer, OUTPUT);

  for (int i = 0; i < 5; i++) {
    pinMode(LED[i], OUTPUT);
  }
  for (int i = 0; i < 5; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  randomSeed(analogRead(A0));

  lcd.begin(16, 2);

  Serial.begin(9600);
}

void loop() {

  if (gameEnded == false) {  // The main code inside loop() stops executing when gameEnded becomes true ( ie. either the whole game is won or any round is lost.)

    int LEDseq[5] = {};
    int USERseq[5] = {};

    // MENU SCREEN

    lcd.setCursor(0, 0);
    lcd.print("ROUND ");

    lcd.setCursor(6, 0);
    lcd.print(gameRound);

    tone(buzzer, 400, 900);
    delay(1000);

    lcd.clear();
    delay(350);

    lcd.setCursor(0, 0);
    lcd.print("Ready to start?");

    lcd.setCursor(0, 1);
    lcd.print("Press a button");

    int start = 0;
    while (start == 0) {  //to ensure that the game waits for user to press button, after which it runs countdown and exits menu screen.

      if ((digitalRead(redbutton) == LOW) || (digitalRead(bluebutton) == LOW) || (digitalRead(greenbutton) == LOW) || (digitalRead(yellowbutton) == LOW) || (digitalRead(whitebutton) == LOW)) {

        lcd.clear();
        delay(500);

        //countdown!!
        for (int i = 3; i > 0; i--) {
          lcd.setCursor(0, 0);

          lcd.print(i);
          tone(buzzer, 740);
          delay(350);

          lcd.clear();
          noTone(buzzer);
          delay(350);
        }

        tone(buzzer, 988);
        delay(800);

        noTone(buzzer);
        delay(500);

        start = 1;  // exits the MENU screen
      }
    }


    // ROUND START

    // generates the random sequence as expected (3 difficulty levels depending on delay times)

    if (total_score < 3) {  //EASY MODE

      for (int i = 0; i < 5; i++) {

        int pin = random(0, 5);  //generates random index number
        LEDseq[i] = LED[pin];    //adds the randomized LED color to the LED's sequence array, one after the other.
        digitalWrite(LED[pin], HIGH);
        delay(420);
        digitalWrite(LED[pin], LOW);
        delay(370);
      }

    }


    else if (total_score >= 3 && total_score < 6) {

      for (int i = 0; i < 5; i++) {  //MEDIUM MODE
        int pin = random(0, 5);
        LEDseq[i] = LED[pin];
        digitalWrite(LED[pin], HIGH);
        delay(300);
        digitalWrite(LED[pin], LOW);
        delay(250);
      }

    }

    else {

      for (int i = 0; i < 5; i++) {  //HARD MODE
        int pin = random(0, 5);
        LEDseq[i] = LED[pin];
        digitalWrite(LED[pin], HIGH);
        delay(230);
        digitalWrite(LED[pin], LOW);
        delay(180);
      }
    }

    delay(750);
    tone(buzzer, 988);
    lcd.setCursor(0, 0);
    lcd.print("GO!");
    delay(750);
    noTone(buzzer);
    lcd.clear();


    //user's turn to copy sequence

    int count = 0;
    int pos = 0;

    while (count < 5) {  //accepts exactly 5 user inputs


      if (digitalRead(redbutton) == LOW) {

        digitalWrite(redLED, HIGH);
        USERseq[pos] = redLED;  //copies user choice to array
        tone(buzzer, 880);
        delay(200);
        noTone(buzzer);
        digitalWrite(redLED, LOW);

        count += 1;
        pos += 1;  // deals with index incrementation for the arrays

        // This makes sure that accidental long presses register as a single press ONLY.
        while (digitalRead(redbutton) == LOW) {

          continue;
        }
      }

      else if (digitalRead(bluebutton) == LOW) {

        digitalWrite(blueLED, HIGH);
        USERseq[pos] = blueLED;
        tone(buzzer, 880);
        delay(200);
        noTone(buzzer);
        digitalWrite(blueLED, LOW);

        count += 1;
        pos += 1;

        while (digitalRead(bluebutton) == LOW) {

          continue;
        }


      }


      else if (digitalRead(greenbutton) == LOW) {

        digitalWrite(greenLED, HIGH);
        USERseq[pos] = greenLED;
        tone(buzzer, 880);
        delay(200);
        noTone(buzzer);
        digitalWrite(greenLED, LOW);

        count += 1;
        pos += 1;

        while (digitalRead(greenbutton) == LOW) {

          continue;
        }

      }


      else if (digitalRead(yellowbutton) == LOW) {
        digitalWrite(yellowLED, HIGH);
        USERseq[pos] = yellowLED;
        tone(buzzer, 880);
        delay(200);
        noTone(buzzer);
        digitalWrite(yellowLED, LOW);

        count += 1;
        pos += 1;

        while (digitalRead(yellowbutton) == LOW) {

          continue;
        }

      }

      else if (digitalRead(whitebutton) == LOW) {
        digitalWrite(whiteLED, HIGH);
        USERseq[pos] = whiteLED;
        tone(buzzer, 880);
        delay(200);
        noTone(buzzer);
        digitalWrite(whiteLED, LOW);

        count += 1;
        pos += 1;

        while (digitalRead(whitebutton) == LOW) {

          continue;
        }
      }
    }

    delay(1000);

    //resetting values for the next round
    count = 0;
    pos = 0;


    // (DEBUGGING) uses display monitor to verify valid inputs and solve technical issues
    for (int i = 0; i < 5; i++) {

      Serial.print(LEDseq[i]);
      Serial.print("  ");
      Serial.println(USERseq[i]);
    }

    int round_score = 0;

    //round score calculation
    for (int i = 0; i < 5; i++) {
      if (USERseq[i] == LEDseq[i]) {
        round_score += 1;
      }

      else {
        continue;
      }
    }

    // round result!

    if (round_score == 5) {

      lcd.setCursor(0, 0);
      lcd.print("U WON THE ROUND!");
      lcd.setCursor(0, 1);
      lcd.print("CONGRATS!!!");
      playVictorySound();

      total_score += 1; //adds a point to the user's total score

      lcd.clear();
      delay(500);

      lcd.setCursor(0, 0);
      lcd.print("Current score: ");
      lcd.setCursor(0, 1);
      lcd.print(total_score);

      delay(2000);
      lcd.clear();

      delay(1000);

      gameRound += 1;

      // warns user about increase in difficulty level after round 3
      if (total_score == 3) {

        tone(buzzer, 700);
        lcd.setCursor(0, 0);
        lcd.print("HARDER!");
        delay(1000);

        noTone(buzzer);
        lcd.clear();
        delay(1200);
      }

      // warns user about further increase in difficulty level after round 6
      if (total_score == 6) {

        tone(buzzer, 1000);
        lcd.setCursor(0, 0);
        lcd.print("EVEN HARDER !!!");
        delay(1000);

        noTone(buzzer);
        lcd.clear();
        delay(1200);
      }


      if (total_score == 9) { //indicates that user has passed all levels

        gameEnded = true; //stops the game from going to the next level

        lcd.setCursor(0, 0);
        lcd.print("GAME VICTORY!!!");

        lcd.setCursor(0, 1);
        lcd.print("Thx for playing!");

        playFinalVictorySound();
      }

    }

    else {

      lcd.setCursor(0, 0);
      lcd.print("sorry.. you lost");

      lcd.setCursor(0, 1);
      lcd.print("GAME OVER!!!");

      playLossSound();

      lcd.clear();
      delay(500);

      lcd.setCursor(0, 0);
      lcd.print("Final score: ");

      lcd.setCursor(0, 1);
      lcd.print(total_score);

      delay(3000);
      lcd.clear();

      gameEnded = true; //stops the game from going to the next level
    }
  }
}






// FUNCTION DEFINITIONS
void playVictorySound() {
  tone(buzzer, 261);
  delay(100);
  tone(buzzer, 330);
  delay(100);
  tone(buzzer, 392);
  delay(100);
  tone(buzzer, 523);
  delay(500);
  noTone(buzzer);
}

void playLossSound() {
  tone(buzzer, 261);
  delay(200);
  tone(buzzer, 247);
  delay(200);
  tone(buzzer, 233);
  delay(200);
  tone(buzzer, 208);
  delay(600);
  noTone(buzzer);
}

void playFinalVictorySound() {
  tone(buzzer, 523);  
  delay(120);
  tone(buzzer, 659);  
  delay(120);
  tone(buzzer, 784);  
  delay(120);
  tone(buzzer, 1047);  
  delay(180);
  tone(buzzer, 1319);  
  delay(500);
  noTone(buzzer);
}
