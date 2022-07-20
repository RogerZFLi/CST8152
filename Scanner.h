/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Spring, 2022
* Author: Svillen Ranev - Paulo Sousa
* Author: Roger Li - Denys Savskyi
* Professors: Paulo Sousa
************************************************************
*/

/*
************************************************************
* File name: Scanner.h
* Compiler: MS Visual Studio 2022
* Author: Paulo Sousa
* Author: Roger Li - Denys Savskyi
* Course: CST 8152 – Compilers, Lab Section: [011, 012, 013]
* Assignment: A22, A32.
* Date: Jul 01 2022
* Purpose: This file is the main header for Scanner (.h)
* Function list: (...).
*************************************************************/

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef SCANNER_H_
#define SCANNER_H_

#ifndef NULL
#include <_null.h> /* NULL pointer constant is defined there */
#endif

/*#pragma warning(1:4001) */	/*to enforce C89 type comments  - to make //comments an warning */

/*#pragma warning(error:4001)*/	/* to enforce C89 comments - to make // comments an error */

/* Constants */
#define VID_LEN 20  /* variable identifier length */
#define ERR_LEN 40  /* error message length */
#define NUM_LEN 5   /* maximum number of digits for IL */

#define RTE_CODE 1  /* Value for run-time error */

/* TO_DO: Define Token codes - Create your token classes */
enum TOKENS {
	ERR_T,		/*  0: Error token */
	MNID_T,		/*  1: Method name identifier token (followed by '(') */
	STR_T,		/*  2: String literal token */
	LPR_T,		/*  3: Left parenthesis token */
	RPR_T,		/*  4: Right parenthesis token */
	LBR_T,		/*  5: Left brace token */
	RBR_T,		/*  6: Right brace token */
	KW_T,		/*  7: Keyword token */
	EOS_T,		/*  8: End of statement (semicolon) */
	RTE_T,		/*  9: Run-time error token */
	SEOF_T,		/* 10: Source end-of-file token */
	VNID_T,		/* 11: Variable name identifier token */
	INL_T,		/* 12: Integer literal token */
	FPL_T,		/* 13: Float point number literal token */
	SCC_OP_T,	/* */
	ASS_OP_T,	/* */
	ART_OP_T,	/* */
	REL_OP_T,	/* */
	LOG_OP_T	/* */

};

/* TO_DO: Operators token attributes */
typedef enum ArithmeticOperators { OP_ADD, OP_SUB, OP_MUL, OP_DIV } AriOperator;
typedef enum RelationalOperators { OP_EQ, OP_NE, OP_GT, OP_LT } RelOperator;
typedef enum LogicalOperators { OP_AND, OP_OR, OP_NOT } LogOperator;
typedef enum SourceEndOfFile { SEOF_0, SEOF_255 } EofOperator;

/* TO_DO: Data structures for declaring the token and its attributes */
typedef union TokenAttribute {
	rsa_int codeType;					/* integer attributes accessor */
	AriOperator arithmeticOperator;		/* arithmetic operator attribute code */
	RelOperator relationalOperator;		/* relational operator attribute code */
	LogOperator logicalOperator;		/* logical operator attribute code */
	EofOperator seofType;				/* source-end-of-file attribute code */
	rsa_int intValue;					/* integer literal attribute (value) */
	rsa_int keywordIndex;				/* keyword index in the keyword table */
	rsa_int contentString;				/* string literal offset from the beginning of the string literal buffer (stringLiteralTable->content) */
	rsa_flt floatValue;					/* floating-point literal attribute (value) */
	rsa_chr idLexeme[VID_LEN + 1];		/* variable identifier token attribute */
	rsa_chr errLexeme[ERR_LEN + 1];		/* error token attribite */
} TokenAttribute;

/* TO_DO: Should be used if no symbol table is implemented */
typedef struct idAttibutes {
	rsa_flg flags;			/* Flags information */
	union {
		rsa_int intValue;				/* Integer value */
		rsa_flt floatValue;			/* Float value */
		rsa_nul* stringContent;		/* String value */
	} values;
} IdAttibutes;

/* Token declaration */
typedef struct Token {
	rsa_int code;				/* token code */
	TokenAttribute attribute;	/* token attribute */
	IdAttibutes   idAttribute;	/* not used in this scanner implementation - for further use */
} Token;

///////////////////////////////////////////////////////////////////////////////////////////////////////
/* boolean definitions */
#define rsa_TRUE 1
#define rsa_FALSE 0
/* EOF definitions */
#define CHARSEOF0 '\0'
#define CHARSEOF255 0xFF

/*  Special case tokens processed separately one by one in the token-driven part of the scanner
 *  '=' , ' ' , '(' , ')' , '{' , '}' , == , <> , '>' , '<' , ';', 
 *  white space, @comment@ , ',' , ';' , '-' , '+' , '*' , '/', ## , 
 *  .&., .|. , .!. , SEOF.
 */

/* TO_DO: Error states and illegal state */
#define ES  8		/* Error state with no retract */
#define ER  9		/* Error state with retract */
#define IS -1		/* Illegal state */

 /* TO_DO: State transition table definition */
#define TABLE_COLUMNS 7

/* TO_DO: Define lexeme FIXED classes */
/* These constants will be used on nextClass */
#define CHRCOL2 '_'
#define CHRCOL3 '&'
#define CHRCOL4 '\"'

/* These constants will be used on VID / MID function */
#define MNIDPREFIX '&'

/* TO_DO: Transition table - type of states defined in separate table */
static rsa_int transitionTable[][TABLE_COLUMNS] = {
/*   [A-z] , [0-9],    _,    &,    ", SEOF, other
	   L(0),  D(1), U(2), M(3), Q(4), E(5),  O(6) */
	{     1,    ES,   ES,   ES,    4,   ER,   ES}, // S0: NOAS
	{     1,     1,    1,    2,   ES,   ER,    3}, // S1: NOAS
	{    IS,    IS,   IS,   IS,   IS,   IS,   IS}, // S2: ASNR (MVID)
	{    IS,    IS,   IS,   IS,   IS,   IS,   IS}, // S3: ASWR (KEY)
	{     4,     4,    4,    4,    5,   ER,    4}, // S4: NOAS
	{    IS,    IS,   IS,   IS,   IS,   IS,   IS}, // S5: ASNR (SL)
	{    IS,    IS,   IS,   IS,   IS,   IS,   IS}, // S6: ASNR (ES)
	{    IS,    IS,   IS,   IS,   IS,   IS,   IS}  // S7: ASWR (ER)
};

/* Define accepting states types */
#define NOAS	0		/* not accepting state */
#define ASNR	1		/* accepting state with no retract */
#define ASWR	2		/* accepting state with retract */


/* TO_DO: Define list of acceptable states */
static rsa_int stateType[] = {
	NOAS, /* 00 */
	NOAS, /* 01 */
	ASNR, /* 02 (MID) - Methods */
	ASWR, /* 03 (KEY) */
	NOAS, /* 04 */
	ASNR, /* 05 (SL) */
	ASNR, /* 06 (Err1 - no retract) */
	ASWR  /* 07 (Err2 - retract) */
};

/*
-------------------------------------------------
TO_DO: Adjust your functions'definitions
-------------------------------------------------
*/

/* Static (local) function  prototypes */
rsa_int startScanner(BufferPointer psc_buf);
static rsa_int nextClass(rsa_chr c);			/* character class function */
static rsa_int nextState(rsa_int, rsa_chr);		/* state machine function */

/*
-------------------------------------------------
Automata definitions
-------------------------------------------------
*/

/* TO_DO: Pointer to function (of one char * argument) returning Token */
typedef Token(*PTR_ACCFUN)(rsa_chr* lexeme);

/* Declare accepting states functions */
Token funcSL	(rsa_chr lexeme[]);
Token funcID	(rsa_chr lexeme[]);
Token funcKEY	(rsa_chr lexeme[]);
Token funcErr	(rsa_chr lexeme[]);

/* 
 * Accepting function (action) callback table (array) definition 
 * If you do not want to use the typedef, the equvalent declaration is:
 */

/* TO_DO: Define final state table */
static PTR_ACCFUN finalStateTable[] = {
	NULL,		/* -    [00] */
	NULL,		/* -    [01] */
	funcID,		/* MNID	[02] */
	funcKEY,	/* KEY  [03] */
	NULL,		/* -    [04] */
	funcSL,		/* SL   [05] */
	funcErr,	/* ERR1 [06] */
	funcErr		/* ERR2 [07] */
};

/*
-------------------------------------------------
Language keywords
-------------------------------------------------
*/

/* TO_DO: Define the number of Keywords from the language */
#define KWT_SIZE 18

/* TO_DO: Define the list of keywords */
static rsa_chr* keywordTable[KWT_SIZE] = {
	"void",
	"public",
	"private",
	"protected",
	"this",
	"if",
	"else",
	"for",
	"while",
	"do",
	"switch", 
	"case",
	"int",
	"float",
	"string",
	"char",
	"boolean",
	"null"
};

#endif
