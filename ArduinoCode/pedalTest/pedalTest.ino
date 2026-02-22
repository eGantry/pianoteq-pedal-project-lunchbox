void setup() {
  Serial.begin(115200);

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
}

void loop() {
  Serial.print("A0="); Serial.print(digitalRead(A0));
  Serial.print(" A1="); Serial.print(digitalRead(A1));
  Serial.print(" A2="); Serial.print(digitalRead(A2));
  Serial.print(" A3="); Serial.println(digitalRead(A3));

  delay(100);
}