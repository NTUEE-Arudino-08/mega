#define RL1 14
#define RL2 15
#define RL3 16
#define RL4 17
#define RL5 18

int PWMA=34;
int AIN2=35;
int AIN1=36;
int STBY=37;
int BIN1=38;
int BIN2=39;
int PWMB=40;

void MotorWriting(double vL, double vR);
void MotorCheck();
void Calculate();
void setup() {
    Serial.begin(9600);
    
    pinMode(RL1, INPUT);
    pinMode(RL2, INPUT);
    pinMode(RL3, INPUT);
    pinMode(RL4, INPUT);
    pinMode(RL5, INPUT);
    
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(STBY, OUTPUT);     // stand by 
    pinMode(LED_BUILTIN, OUTPUT);
    
}

void loop() {
   Calculate();
       // turn the LED on (HIGH is the voltage level)
    if (digitalRead(RL3) == HIGH && digitalRead(RL1) == LOW && digitalRead(RL5) == LOW) {
            MotorWriting(150, 150);    
}

    if (digitalRead(RL2) == HIGH && digitalRead(RL3) == HIGH && digitalRead(RL4) == HIGH) {
        MotorWriting(255, -255);
        delay(600);
        MotorWriting(0, 0);
    }
    if (digitalRead(RL1) == LOW && digitalRead(RL2) == LOW && digitalRead(RL3) == LOW && digitalRead(RL4) == LOW && digitalRead(RL5) == LOW) {
        MotorWriting(0, 0);
        delay(1000);
   }
}
void Calculate() {
    int IR1 = digitalRead(RL1);
    int IR2 = digitalRead(RL2);
    int IR3 = digitalRead(RL3);
    int IR4 = digitalRead(RL4);
    int IR5 = digitalRead(RL5);
    int bar_l = 0;
    if ((IR1 == 1 || IR2 == 1) && IR5 == 0) {
        bar_l = (IR1*50+IR2*25)/(IR1+IR2);
    }
    int bar_r = 0;
    if ((IR5 == 1 || IR4 == 1) && IR1 == 0) {
        bar_r = (IR5*50+IR4*25)/(IR5+IR4);
    }
     
    double wl = 150-bar_l;
    double wr = 150-bar_r;
    MotorWriting(wr, wl);
}
void MotorWriting(double vL, double vR) {
    digitalWrite(STBY, HIGH);
    if(vR >= 0) {
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        analogWrite(PWMA, vR);
       } 
    else {
        digitalWrite(AIN2, HIGH);
        digitalWrite(AIN1, LOW);
        analogWrite(PWMA, -vR);
    }
    if (vL >= 0) {
        digitalWrite(BIN2, HIGH);
        digitalWrite(BIN1, LOW);
        analogWrite(PWMB, vL);
        }    
    else {
        digitalWrite(BIN2, LOW);
        digitalWrite(BIN1, HIGH);
        analogWrite(PWMB, -vL);
    }
}
void MotorCheck() {
    MotorWriting(255, 255);
    delay(2000);
    MotorWriting(-255, -255);
    delay(2000);
    MotorWriting(-255, 255);
    delay(2000);
    MotorWriting(255, -255);
    delay(2000);
    MotorWriting(0, 0);
}
// matt
