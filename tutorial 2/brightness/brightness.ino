// pin initialization
int switch_pin8 = 8;
int led_pin13 =11;

// variables
boolean btnState = LOW;
int ledLvl = 0;
boolean currentBtn = LOW;

// debounce function to handle jumping switch
boolean debounce(boolean last) {
  
  boolean current = digitalRead(switch_pin8);

  if (last != current){
    delay(5);
    current = digitalRead(switch_pin8);
  }

  return current;
}

void setup() {
  pinMode(switch_pin8, INPUT);
  pinMode(led_pin13, OUTPUT);
}

void loop() { 

  currentBtn = debounce(btnState);
  
  if (currentBtn == HIGH && btnState == LOW) {
    ledLvl = ledLvl + 51;
  }
  
  btnState = currentBtn;

  if (ledLvl > 255) {
    ledLvl = 0;
  }

  analogWrite(led_pin13, ledLvl);
}
