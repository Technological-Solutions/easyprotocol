#include <easyprotocol.h>

// myCallbackFunc() gets called for every token-value pair read
void myCallbackFunc(char *token, char *value) {
  if (!strcmp(token, "myToken1")) {
    Serial.print(token);
    Serial.print(': ')
    Serial.println(value);
  }
}

void setup() {
  easyprotocol_fptr_parse = &myCallbackFunc; // Set myCallbackFunc as THE callback function. Both two arguments (char *token, char *value) are cstrings.
}

void loop() {
  while (Serial.available() > 0) {
    easyprotocol_append(Serial.read()); // Add characters to buffer
  }
}