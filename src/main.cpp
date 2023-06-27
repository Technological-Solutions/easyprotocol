#include <Arduino.h>

#include <easyprotocol.h>

// cmdparse() gets called for every token-value pair read
void cmdparse(char *token, char *value) {
  Serial.print("> token: ");
  Serial.print(token);
  Serial.print(", value: ");
  Serial.println(value);
}

void setup() {
  Serial.begin(9600);
  Serial.println("easyprotocol demo");
  easyprotocol_callback = &cmdparse; // Set cmdparse as THE callback function. Both two arguments (char *token, char *value) are cstrings.
}

void loop() {
  while (Serial.available() > 0) {
    easyprotocol_append(Serial.read()); // Add characters to buffer
  }
}