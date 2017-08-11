#include "unity.h"
#include "tokenizer.h"
#include "createtoken.h"
#include "token.h"
#include <string.h>
#include <stdio.h>
void setUp(void)
{
}

void tearDown(void)
{
}




void test_create_tokenizer(void){
   Tokenizer *tokenizer=createTokenizer(" 2345 67abcf 0x45 4.5678 3.4e+56e ");
   printf("test output:%s\n",tokenizer->str);
   printf("test output:%d\n",tokenizer->index);
}
void test_get_tokenizer(void){
   Tokenizer *tokenizer=createTokenizer(" 2345 67abcf 0x45 4.5678 3.4e+56e ");
   Token *token=getToken(tokenizer);
   printf("test output:%s\n",token->str);
   //printf("test output:%\n",token->type);
}
/*
void test_tokenizer_NeedToImplement(void)
{
	char value;
   Tokenizer *tokenizer=createTokenizer(" 2345 67abcf 0x45 4.5678 3.4e+56e ");
   //Token *token=getToken(tokenizer);
  
   
   TEST_ASSERT_NOT_NULL(token);
   TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE, token->type);
   TEST_ASSERT_EQUAL(2345, ((IntegerToken *)token)->value);
   
   
   Try{
	   token=getToken(tokenizer);
	   TEST_FAIL_MESSAGE("Expect EXCEPTION_NOT_A_NUMBER exception to be thrown, but none received.")
	   }
   Catch(ex){
	   TEST_ASSERT_EQUAL(EXCEPTION_NOT_A_NUMBER, ex->id);
	   }
	token=getToken(tokenizer);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE, token->type);
	TEST_ASSERT_EQUAL(0x45, ((IntegerToken *)token)->value);
	
	token=getToken(tokenizer);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(TOKEN_FLOAT_TYPE, token->type);
	TEST_ASSERT_DOUBLE_WITHIN(0.00001, 4.5678,((FloatToken*)token)->value);
	
	Try{
		token=getToken(tokenizer);
		TEST_FAIL_MESSAGE("Expect EXCEPTION_NOT_FLOAT_NUMBER exception to be thrown, but none received.")
		}
	Catch(ex){
		TEST_ASSERT_EQUAL(EXCEPTION_NOT_FLOAT_NUMBER, ex->id);
		TEST_ASSERT_EQUAL(26, ex->startcolumn);
		TEST_ASSERT_EQUAL(?, ex->length);
		}
	
}
*/