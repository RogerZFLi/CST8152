/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Summer, 2022
* Author: Roger Li, Denys Savaskyi - Paulo Sousa
* Professors: Paulo Sousa
************************************************************
*/

/*
************************************************************
* File name: Buffer.h
* Compiler: MS Visual Studio 2022
* Author: Roger Li, Denys Savaskyi - Paulo Sousa
* Course: CST 8152 – Compilers, Lab Section: 012
* Assignment: A12.
* Date: May 01 2022
* Professor: Paulo Sousa
* Purpose: This file is the main header for Buffer (.h)
************************************************************
*/


#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef BUFFER_H_
#define BUFFER_H_

/*#pragma warning(1:4001) *//*to enforce C89 type comments  - to make //comments an warning */
/*#pragma warning(error:4001)*//* to enforce C89 comments - to make // comments an error */

/* standard header files */
#include <stdio.h>  /* standard input/output */
#include <malloc.h> /* for dynamic memory allocation*/
#include <limits.h> /* implementation-defined data type ranges and limits */

/* CONSTANTS DEFINITION: GENERAL .................................. */

/* Modes (used to create buffer) */
enum BUFFERMODES {
	MODE_FIXED = 'f', /* Fixed mode (constant size) */
	MODE_ADDIT = 'a', /* Additive mode (constant increment to be added) */
	MODE_MULTI = 'm'  /* Multiplicative mode (constant increment to be multiplied) */
};

/* Constants about controls */
#define BUFFER_ERROR (-1)					/* General error message */
#define BUFFER_EOF '\0'						/* General EOF */

/* Check the limit of your buffer */
#define BUFFER_MAX_SIZE	INT_MAX-1	/* maximum capacity */ 

/* CONSTANTS DEFINITION: PREFIXED BY LANGUAGE NAME (SOFIA) .................................. */
#define BUFFER_DEFAULT_SIZE			100		/* default initial buffer capacity */
#define BUFFER_DEFAULT_INCREMENT	10		/* default increment factor */

/* Add your bit-masks constant definitions here - Defined for SOFIA */
/* BITS                                (7654.3210) */
#define BUFFER_DEFAULT_FLAG 0x00 	/* (0000.0000)_2 = (000)_10 */
/* BIT 3: RLB = Relocation - Define masks for SET, RST, CHK */
#define BUFFER_RLB_FLAG 0x08 /* (0000.1000)_2 = (008)_10 */
/*  BIT 2: EOB = EndOfBuffer - Define masks for SET, RST, CHK */
#define BUFFER_EOB_FLAG 0x04 /* (0000.0100)_2 = (004)_10 */
/* BIT 1: FUL = Full - Define masks for SET, RST, CHK */
#define BUFFER_FUL_FLAG 0x02 /* (0000.0010)_2 = (002)_10 */
/* BIT 0: EMP = Empty - Define masks for SET, RST, CHK */
#define BUFFER_EMP_FLAG 0x01 /* (0000.0001)_2 = (001)_10 */

/* STRUCTURES DEFINITION: SUFIXED BY LANGUAGE NAME (ROSALICE) .................................. */

/* Adjust datatypes */

/* Offset declaration */
typedef struct position {
	rsa_int posMark;			/* the offset to the mark position (in chars) */
	rsa_int posRead;			/* the offset to the get a char position (in chars) */
	rsa_int posWrte;			/* the offset to the add chars (in chars) */
} Position;

/* Buffer structure */
typedef struct buffer {
	rsa_chr*	content;		/* pointer to the beginning of character array (character buffer) */
	rsa_int		size;		    /* current dynamic memory size (in bytes) allocated to character buffer */
	rsa_int		increment;		/* character array increment factor */
	rsa_int		mode;			/* operational mode indicator */
	rsa_flg		flags;			/* contains character array reallocation flag and end-of-buffer flag */
	Position	position;		/* Offset / position field */
} Buffer, * BufferPointer;

/* FUNCTIONS DECLARATION:  .................................. */
/* General Operations */
BufferPointer	bufCreate(rsa_int, rsa_int, rsa_int);
BufferPointer	bufAddChar(BufferPointer const, rsa_chr);
rsa_bol			bufClear(BufferPointer const);
rsa_bol			bufDestroy(BufferPointer const);
rsa_bol			bufChkFull(BufferPointer const);
rsa_bol			bufChkEmpty(BufferPointer const);
rsa_bol			bufSetMark(BufferPointer const, rsa_int);
rsa_int			bufPrint(BufferPointer const);
rsa_int			bufLoad(BufferPointer const, FILE* const);
rsa_bol			bufRecover(BufferPointer const);
rsa_bol			bufRetract(BufferPointer const);
rsa_bol			bufRestore(BufferPointer const);
/* Getters */
rsa_chr			bufGetChar(BufferPointer const);
rsa_chr*		bufGetContent(BufferPointer const, rsa_int);
rsa_int			bufGetPosRead(BufferPointer const);
rsa_int			bufGetPosWrte(BufferPointer const);
rsa_int			bufGetPosMark(BufferPointer const);
rsa_int			bufGetSize(BufferPointer const);
rsa_int			bufGetInc(BufferPointer const);
rsa_int			bufGetMode(BufferPointer const);
rsa_flg			bufGetFlags(BufferPointer const);

#endif
