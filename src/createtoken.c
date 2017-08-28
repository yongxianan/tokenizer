#include "createtoken.h"
#include "token.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

Token *createInteger(int value,int startColumn,int length,char *str) {
  IntegerToken *intToken = malloc(sizeof(IntegerToken));
  intToken->originalstr=malloc(100);
  intToken->str=malloc(length+1);
  intToken->type = TOKEN_INTEGER_TYPE;
  intToken->value = value;
  intToken->length = length;
  intToken->startColumn = startColumn;
  strcpy(intToken->originalstr,str);
  strncpy(intToken->str,str+startColumn,(length));
  return (Token *)intToken;
}

Token *createFloat(double value,int startColumn,int length,char *str) {
  FloatToken *floatToken = malloc(sizeof(FloatToken));
  floatToken->originalstr=malloc(100);
  floatToken->str=malloc(length+1);
  floatToken->type = TOKEN_FLOAT_TYPE;
  floatToken->value = value;
  floatToken->length = length;
  floatToken->startColumn = startColumn;
  strcpy(floatToken->originalstr,str);
  strncpy(floatToken->str,str+startColumn,(length));
  return (Token *)floatToken;
}


Token *createOperator(int startColumn,int length, char *str) {
  OperatorToken *opToken = malloc(sizeof(OperatorToken) + sizeof(Token *) * 2);
  opToken->originalstr=malloc(100);
  opToken->str=malloc(length+1);
  opToken->type = TOKEN_OPERATOR_TYPE;
  opToken->length = length;
  opToken->startColumn = startColumn;
  strcpy(opToken->originalstr,str);
  strncpy(opToken->str,str+startColumn,(length)); 
  return (Token *)opToken;
}


Token *createIdentifier(int startColumn,int length, char *str) {
  IdentifierToken *IdenToken = malloc(sizeof(IdentifierToken));
  IdenToken->originalstr=malloc(100);
  IdenToken->str=malloc(length+1);
  IdenToken->type = TOKEN_IDENTIFIER_TYPE;
  IdenToken->length = length;
  IdenToken->startColumn = startColumn;
  strcpy(IdenToken->originalstr,str);
  strncpy(IdenToken->str,str+startColumn,(length));
  return (Token *)IdenToken;
}


Tokenizer *createTokenizer(char *str) {
  Tokenizer *initToken = malloc(sizeof(Tokenizer));
  initToken->str = str;
  initToken->index =0;
  return (Tokenizer *)initToken;
}

int skipwhitespace(char *line,int index){
	int i=index;
	while(*line==' '){
		line=line+1;
		i++;
	}
	return i;	
}
/*
int printf_error_string(int startColumn, char *str)
{
	length=0;
	char *str1;
	while(tokenizer->str[startColumn+length]!=' ')
	{
		length=length+1;
	}
	strncpy(str1,str+startColumn,(length));
	printf("%s\n",str1);
	return length;
}
*/	
	
	
	