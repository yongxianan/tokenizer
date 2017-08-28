#include "tokenizer.h"
#include "createtoken.h"
#include <stdio.h>
#include <ctype.h>
/*
char *createsubstring(char *str, int startcolumn, int length){
	char *substring=malloc();
	return substring;
}
*/

Token *getToken(Tokenizer *tokenizer)
{
	Token *token= malloc(sizeof(Token));
	char *eptr_test=NULL;
	char *eptr;
	char *hptr;
	int result,result_test;
	double result_d;
	int startColumn;
	int length=0;	
	
	
	startColumn=skipwhitespace(tokenizer->str+(tokenizer->index),tokenizer->index);
	hptr=&tokenizer->str[startColumn];
	
	if(isdigit(tokenizer->str[startColumn]))
	{
		result_test = strtol(tokenizer->str+(tokenizer->index),&eptr_test,10);
		if(*eptr_test=='.')
		{
			/*result_d = strtod(tokenizer->str+(tokenizer->index),&eptr);
			if(*eptr==' ')
			{*/
				length=eptr-hptr;
				token=createFloat(result_d,startColumn,length,tokenizer->str);
			/*}
			else
			{
				length=printf_error_string(startColumn,tokenizer->str);
				printf("this is invalid floating point number.");
			}*/
		}
		else if ((tokenizer->str[startColumn])=='0' && (*eptr_test=='x'))
		{
			/*result = strtol(tokenizer->str+(tokenizer->index),&eptr,16);
			if(*eptr==' ')
			{*/
				length=eptr-hptr;
				token=createInteger(result,startColumn,length,tokenizer->str);
			/*}
			else
			{
				length=printf_error_string(startColumn,tokenizer->str);
				
			}*/
			
		}
		else if(*eptr_test==' ')
		{
			result = strtol(tokenizer->str+(tokenizer->index),&eptr,10);
			length=eptr-hptr;
			token=createInteger(result,startColumn,length,tokenizer->str);
		}
		/*else
		{
			length=printf_error_string(startColumn,tokenizer->str);
			
		}*/
	}
	else if (isalpha(tokenizer->str[startColumn]))
	{
		while(tokenizer->str[startColumn+length]!=' ')
		{
			length=length+1;
		}
		token=createIdentifier(startColumn,length,tokenizer->str);
	}
	else if (ispunct(tokenizer->str[startColumn]))
	{
		length=1;
		token=createOperator(startColumn,length,tokenizer->str);
	}
	else
	{
		printf("failed\n");
	}
	tokenizer->index=length+startColumn;
	return token;
}
		
		
		