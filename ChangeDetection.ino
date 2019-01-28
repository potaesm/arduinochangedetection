long previousMillis = 0;
int previousValue = 0;
long interval = 1000;
int threshold = 500;
void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned int currentValue = analogRead(A0);
  if (currentMillis - previousMillis > interval) {
    if (abs(currentValue - previousValue) > threshold) {
      Serial.println("Change Detected!");
      previousValue = currentValue;
      }
    previousMillis = currentMillis;
  }
}
