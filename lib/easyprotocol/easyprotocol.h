#ifndef EASYPROTOCOL_H
#define EASYPROTOCOL_H

#include <inttypes.h>
#include <string.h>

extern void (*easyprotocol_callback)(char *, char *); // args: (char *) token, (char *) value

uint8_t easyprotocol_append(char chr);

#endif