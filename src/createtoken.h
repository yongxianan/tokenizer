#ifndef _CREATETOKEN_H
#define _CREATETOKEN_H

#include "token.h"
Token *createInteger(int value);
//Token *createOperator(char *symbol);
//Token *createFloat(double value);
//Token *createIdentifier(double value);
Tokenizer *createTokenizer(char *str);
#endif // _CREATETOKEN_H
