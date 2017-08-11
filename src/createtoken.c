#include "createtoken.h"
#include "token.h"
#include <malloc.h>
#include <stdio.h>

Token *createInteger(int value) {
  IntegerToken *intToken = malloc(sizeof(IntegerToken));
  intToken->type = TOKEN_INTEGER_TYPE;
  sprintf(intToken->str,value);
  intToken->value = value;
  return (Token *)intToken;
}

/*
Token *createOperator(char symbol) {
  OperatorToken *opToken = malloc(sizeof(OperatorToken) + sizeof(Token *) * 2);
  opToken->type = TOKEN_OPERATOR_TYPE;
  opToken->*str = symbol;
  return (Token *)opToken;
}
*/
/*
Token *createFloat(double value) {
  FloatToken *floatToken = malloc(sizeof(FloatToken));
  floatToken->type = TOKEN_FLOAT_TYPE;
  sprintf(floatToken->str,value);
  floatToken->value = value;
  return (Token *)floatToken;
}
*/
/*
Token *createIdentifier(char iden) {
  IdentifierToken *IdenToken = malloc(sizeof(IdentifierToken));
  IdenToken->type = TOKEN_IDENTIFIER_TYPE;
  IdenToken->*str = iden;
  return (Token *)IdenToken;
}
*/

Tokenizer *createTokenizer(char *str) {
  Tokenizer *initToken = malloc(sizeof(Tokenizer));
  printf("hello\n");
  initToken->str = str;
  initToken->index =0;
  return (Tokenizer *)initToken;
}

/*

int skipwhitespace(char *line){
	int i=0;
	while(*line==' '){
		line=line+1
		i++;
	}
	return i;
}
*/	
	
	
	
	