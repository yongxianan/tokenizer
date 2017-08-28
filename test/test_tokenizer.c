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



/*
void test_create_tokenizer(void){
   Tokenizer *tokenizer=createTokenizer(" 2345 67abcf 0x45 4.5678 3.4e+56e ");
   printf("test output:%s\n",tokenizer->str);
   printf("test output:%d\n",tokenizer->index);
}*/

void test_get_tokenizer(void){
   Tokenizer *tokenizer=createTokenizer(" 2345 67abcf 0x45 4.5678 3.4e+56e ");
   Token *token=getToken(tokenizer);
   TEST_ASSERT_NOT_NULL(token);
   TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE, token->type);
   TEST_ASSERT_EQUAL(2345, ((IntegerToken *)token)->value);
   TEST_ASSERT_EQUAL(4, token->length);
   TEST_ASSERT_EQUAL(1, token->startColumn);
   TEST_ASSERT_EQUAL_STRING("2345", token->str);
   TEST_ASSERT_EQUAL_STRING(" 2345 67abcf 0x45 4.5678 3.4e+56e ", token->originalstr);
}



void test_get_tokenizer_second_column(void){
   Tokenizer *tokenizer=createTokenizer(" 2345 5678 0x45 4.5678 3.4e+56e ");
   Token *token1=getToken(tokenizer);
   Token *token=getToken(tokenizer);
   TEST_ASSERT_NOT_NULL(token);
   TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE, token->type);
   TEST_ASSERT_EQUAL(5678, ((IntegerToken *)token)->value);
   TEST_ASSERT_EQUAL(4, token->length);
   TEST_ASSERT_EQUAL(6, token->startColumn);
   TEST_ASSERT_EQUAL_STRING("5678", token->str);
   TEST_ASSERT_EQUAL_STRING(" 2345 5678 0x45 4.5678 3.4e+56e ", token->originalstr);
   TEST_ASSERT_EQUAL(10, tokenizer->index);
   TEST_ASSERT_EQUAL(1, token1->startColumn);
}

void test_get_tokenizer_second_column_with_float(void){
   Tokenizer *tokenizer=createTokenizer(" 2345 56.78 0x45 4.5678 3.4e+56e ");
   Token *token1=getToken(tokenizer);
   Token *token=getToken(tokenizer);
   TEST_ASSERT_NOT_NULL(token);
   TEST_ASSERT_EQUAL(TOKEN_FLOAT_TYPE, token->type);
   TEST_ASSERT_EQUAL(56.78, ((FloatToken *)token)->value);
   TEST_ASSERT_EQUAL(5, token->length);
   TEST_ASSERT_EQUAL(6, token->startColumn);
   TEST_ASSERT_EQUAL_STRING("56.78", token->str);
   TEST_ASSERT_EQUAL_STRING(" 2345 56.78 0x45 4.5678 3.4e+56e ", token->originalstr);
   TEST_ASSERT_EQUAL(11, tokenizer->index);
}

void test_get_tokenizer_third_column_with_hexa(void){
   Tokenizer *tokenizer=createTokenizer(" 2345 56.78 0x45 4.5678 3.4e+56e ");
   Token *token1=getToken(tokenizer);
   Token *token2=getToken(tokenizer);
   Token *token=getToken(tokenizer);
   TEST_ASSERT_NOT_NULL(token);
   TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE, token->type);
   TEST_ASSERT_EQUAL_HEX16(0x45, ((IntegerToken *)token)->value);
   TEST_ASSERT_EQUAL(4, token->length);
   TEST_ASSERT_EQUAL(12, token->startColumn);
   TEST_ASSERT_EQUAL_STRING("0x45", token->str);
   TEST_ASSERT_EQUAL_STRING(" 2345 56.78 0x45 4.5678 3.4e+56e ", token->originalstr);
   TEST_ASSERT_EQUAL(16, tokenizer->index);
}

void test_get_tokenizer_fourth_column_with_alphabet(void){
   Tokenizer *tokenizer=createTokenizer(" 2345 56.78 0x45 abc123 3.4e+56e ");
   Token *token1=getToken(tokenizer);
   Token *token2=getToken(tokenizer);
   Token *token3=getToken(tokenizer);
   Token *token=getToken(tokenizer);
   TEST_ASSERT_NOT_NULL(token);
   TEST_ASSERT_EQUAL(TOKEN_IDENTIFIER_TYPE, token->type);
   TEST_ASSERT_EQUAL(6, token->length);
   TEST_ASSERT_EQUAL(17, token->startColumn);
   TEST_ASSERT_EQUAL_STRING("abc123", token->str);
   TEST_ASSERT_EQUAL_STRING(" 2345 56.78 0x45 abc123 3.4e+56e ", token->originalstr);
   TEST_ASSERT_EQUAL(23, tokenizer->index);
}

void test_get_tokenizer_fifth_column_with_int_op_hex_(void){
   Tokenizer *tokenizer=createTokenizer(" 2345 56.78 0x45 abc123 3.4+56 ");
   Token *token1=getToken(tokenizer);
   Token *token2=getToken(tokenizer);
   Token *token3=getToken(tokenizer);
   Token *token4=getToken(tokenizer);
   Token *token_d=getToken(tokenizer);
   Token *token_op=getToken(tokenizer);
   Token *token_int=getToken(tokenizer);
   TEST_ASSERT_NOT_NULL(token_d);
   TEST_ASSERT_NOT_NULL(token_op);
   TEST_ASSERT_NOT_NULL(token_int);
   TEST_ASSERT_EQUAL(TOKEN_FLOAT_TYPE, token_d->type);
   TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE, token_op->type);
   TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE, token_int->type);
   TEST_ASSERT_EQUAL(3, token_d->length);
   TEST_ASSERT_EQUAL(24, token_d->startColumn);
   TEST_ASSERT_EQUAL(3.4, ((FloatToken *)token_d)->value);
   TEST_ASSERT_EQUAL_STRING("3.4", token_d->str);
   TEST_ASSERT_EQUAL_STRING(" 2345 56.78 0x45 abc123 3.4+56 ", token_d->originalstr);
   TEST_ASSERT_EQUAL(1, token_op->length);
   TEST_ASSERT_EQUAL(27, token_op->startColumn);
   TEST_ASSERT_EQUAL_STRING("+", token_op->str);
   TEST_ASSERT_EQUAL_STRING(" 2345 56.78 0x45 abc123 3.4+56 ", token_op->originalstr);
   TEST_ASSERT_EQUAL(2, token_int->length);
   TEST_ASSERT_EQUAL(28, token_int->startColumn);
   TEST_ASSERT_EQUAL(56, ((IntegerToken *)token_int)->value);
   TEST_ASSERT_EQUAL_STRING("56", token_int->str);
   TEST_ASSERT_EQUAL_STRING(" 2345 56.78 0x45 abc123 3.4+56 ", token_int->originalstr);
   TEST_ASSERT_EQUAL(30, tokenizer->index);
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