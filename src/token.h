#ifndef _TOKEN_H
#define _TOKEN_H

#include <stdint.h>

typedef enum {
  TOKEN_UNKNOWN_TYPE,
  TOKEN_INTEGER_TYPE,
  TOKEN_OPERATOR_TYPE,
  TOKEN_FLOAT_TYPE,
  TOKEN_STRING_TYPE,
  TOKEN_IDENTIFIER_TYPE,
} TokenType;
/*
typedef enum {
  NO_AFFIX,
  PREFIX,
  INFIX,
  POSTFIX,
} Affix;

typedef enum {
  NO_ASSOCIATIVITY,
  LEFT_TO_RIGHT,
  RIGHT_TO_LEFT,
} Associativity;
*/
typedef struct {
  TokenType type;
  uint32_t startColumn;
  uint32_t length;
  char *originalstr;
  char *str;
} Token;

typedef struct {
  TokenType type;
  uint32_t startColumn;
  uint32_t length;
  char *originalstr;
  char *str;
  int value;
} IntegerToken;

typedef struct {
  TokenType type;
  uint32_t startColumn;
  uint32_t length;
  char *originalstr;
  char *str;
  double value;
} FloatToken;

typedef struct {
  TokenType type;
  uint32_t startColumn;
  uint32_t length;
  char *originalstr;
  char *str;
} IdentifierToken, StringToken, CharConstToken;

typedef struct {
  TokenType type;
  uint32_t startColumn;
  uint32_t length;
  char *originalstr;
  char *str;
  Token *token[0];
} OperatorToken;

typedef struct {
	char *str;
	int index;
	Token *currentToken;
} Tokenizer;

#endif // _TOKEN_H
