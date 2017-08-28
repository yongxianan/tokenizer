#ifndef _CREATETOKEN_H
#define _CREATETOKEN_H

#include "token.h"
Token *createInteger(int value,int startColumn,int length,char *str);
Token *createOperator(int startColumn,int length, char *str);
Token *createFloat(double value,int startColumn,int length,char *str);
Token *createIdentifier(int startColumn,int length,char *str);
Tokenizer *createTokenizer(char *str);
int skipwhitespace(char *line,int index);
#endif // _CREATETOKEN_H
