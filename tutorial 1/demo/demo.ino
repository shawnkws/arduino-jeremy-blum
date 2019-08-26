// arduino demo

int led_pin13 = 13;

void setup() {
  pinMode (led_pin13, OUTPUT);
}

void loop() {
  digitalWrite(led_pin13, HIGH);
  delay (5000);
  digitalWrite(led_pin13, LOW);
  delay (5000);
}
