#include "tokenizer.h"
/*
char *createsubstring(char *str, int startcolumn, int length){
	char *substring=malloc();
	return substring;
}
*/
Token *getToken(Tokenizer *tokenizer){
	Token *token= malloc(sizeof(Token));
	char *str;
	char *eptr;
	int result2;
	result2 = strtol(tokenizer->str, &eptr, 10);
	token=createInteger(result2);
	return token;
}
/*
Token *getToken(Tokenizer *tokenizer){
	Token *token= malloc(sizeof(Token));
	char *str;
	double result1;
	char *pEnd;
	char *eptr;
	int result2;
	str=tokenizer->str;
	while (*eptr!=NULL){
		if(*str < '0' || *str > '9'){
			result1 = strtod (str,&pEnd);
			if(*pEnd!='.'){
				token=createInteger(result1);
				eptr=pEnd;
			}
			else{
				result2 = strtol(str, &eptr, 10);
				token=createFloat(result2);
			}
		}
	}
}
*/
/*
		else if(isalpha(*str)){
			
			token=createIdentifier(result);
			}
		else if(
		*/	
		
		
		