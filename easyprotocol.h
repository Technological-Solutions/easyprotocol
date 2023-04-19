#ifndef EASYPROTOCOL_H
#define EASYPROTOCOL_H

#include <inttypes.h>
#include <string.h>

// function pointer
extern void (*easyprotocol_fptr_parse)(char *, char *);

uint8_t easyprotocol_append(char chr);

#endif