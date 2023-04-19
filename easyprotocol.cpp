#include "easyprotocol.h"

#define MAXLENGTH 32
#define DELIMITER ','
#define SEPARATOR '='
#define NEWLINE '\n'
#define CR '\r'

char token[MAXLENGTH + 1] = {0};
char value[MAXLENGTH + 1] = {0};

void (*easyprotocol_fptr_parse)(char *, char *) = NULL;

uint8_t isValue = 0;

uint8_t clearstring(char *str) {
  uint8_t i = 0;
  for (i = 0; i < strlen(str); ++i) {
    str[i] = (char)NULL;
  }
  return i; // Retun the number of cleared characters
}

inline void cleartoken() { clearstring(token); }

inline void clearvalue() { clearstring(value); }

uint8_t easyprotocol_append(char chr) {
  switch (chr) {
  case (CR):
    // ignore
    break;
  case (NEWLINE):
  case (DELIMITER):
    if (easyprotocol_fptr_parse != NULL) {
      (*easyprotocol_fptr_parse)(token, value);
    }

    cleartoken();
    clearvalue();
    isValue = 0;

    return 0;
    break;
  case (SEPARATOR):
    isValue = 1;
    break;
  default:
    // add new character to token or value string
    if (isValue && (strlen(value) < MAXLENGTH)) {
      strncat(value, &chr, 1);
    } else if ((strlen(token) < MAXLENGTH)) {
      strncat(token, &chr, 1);
    }
    break;
  }
  return 0;
}