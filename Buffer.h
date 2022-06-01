/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Summer, 2022
* Author: Svillen Ranev - Paulo Sousa
* Professors: Paulo Sousa
************************************************************
*/

/*
************************************************************
* File name: Buffer.h
* Compiler: MS Visual Studio 2022
* Author: Paulo Sousa
* Course: CST 8152 – Compilers, Lab Section: [011, 012, 013]
* Assignment: A12.
* Date: May 01 2022
* Professor: Paulo Sousa
* Purpose: This file is the main header for Buffer (.h)
************************************************************
*/

/*
 *.............................................................................
 * MAIN ADVICE:
 * - Please check the "TODO" labels to develop your activity.
 * - Review the functions to use "Defensive Programming".
 *.............................................................................
 */

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef BUFFER_H_
#define BUFFER_H_

/* TIP: Do not change pragmas, unless necessary .......................................*/
/*#pragma warning(1:4001) *//*to enforce C89 type comments  - to make //comments an warning */
/*#pragma warning(error:4001)*//* to enforce C89 comments - to make // comments an error */

/* standard header files */
#include <stdio.h>  /* standard input/output */
#include <malloc.h> /* for dynamic memory allocation*/
#include <limits.h> /* implementation-defined data type ranges and limits */

/* CONSTANTS DEFINITION: GENERAL (NOT LANGUAGE DEPENDENT) .................................. */

/* Modes (used to create buffer) */
enum BUFFERMODES {
	MODE_FIXED = 'f', /* Fixed mode (constant size) */
	MODE_ADDIT = 'a', /* Additive mode (constant increment to be added) */
	MODE_MULTI = 'm'  /* Multiplicative mode (constant increment to be multiplied) */
};

/* Constants about controls (not need to change) */
#define BUFFER_ERROR (-1)					/* General error message */
#define BUFFER_EOF '\0'						/* General EOF */

/* TODO: Check the limit of your buffer */
#define BUFFER_MAX_SIZE	INT_MAX-1	/* maximum capacity */ 

/* CONSTANTS DEFINITION: PREFIXED BY LANGUAGE NAME (SOFIA) .................................. */
#define BUFFER_DEFAULT_SIZE			100		/* default initial buffer capacity */
#define BUFFER_DEFAULT_INCREMENT	10		/* default increment factor */

/* Add your bit-masks constant definitions here - Defined for SOFIA */
/* BITS                                (7654.3210) */
#define BUFFER_DEFAULT_FLAG 0x00 	/* (0000.0000)_2 = (000)_10 */
/* TODO: BIT 3: RLB = Relocation - Define masks for SET, RST, CHK */
/* TODO: BIT 2: EOB = EndOfBuffer - Define masks for SET, RST, CHK */
/* TODO: BIT 1: FUL = Full - Define masks for SET, RST, CHK */
/* TODO: BIT 0: EMP = Empty - Define masks for SET, RST, CHK */

/* STRUCTURES DEFINITION: SUFIXED BY LANGUAGE NAME (SOFIA) .................................. */

/* TODO: Adjust datatypes */

/* Offset declaration */
typedef struct position {
	sofia_int posMark;			/* the offset to the mark position (in chars) */
	sofia_int posRead;			/* the offset to the get a char position (in chars) */
	sofia_int posWrte;			/* the offset to the add chars (in chars) */
} Position;

/* Buffer structure */
typedef struct buffer {
	sofia_chr*	content;		/* pointer to the beginning of character array (character buffer) */
	sofia_int	size;		    /* current dynamic memory size (in bytes) allocated to character buffer */
	sofia_int	increment;		/* character array increment factor */
	sofia_int	mode;			/* operational mode indicator */
	sofia_flg	flags;			/* contains character array reallocation flag and end-of-buffer flag */
	Position	position;		/* Offset / position field */
} Buffer, * BufferPointer;

/* FUNCTIONS DECLARATION:  .................................. */
/* General Operations */
BufferPointer	bufCreate(sofia_int, sofia_int, sofia_int);
BufferPointer	bufAddChar(BufferPointer const, sofia_chr);
sofia_bol		bufClear(BufferPointer const);
sofia_bol		bufDestroy(BufferPointer const);
sofia_bol		bufChkFull(BufferPointer const);
sofia_bol		bufChkEmpty(BufferPointer const);
sofia_bol		bufSetMark(BufferPointer const, sofia_int);
sofia_int		bufPrint(BufferPointer const);
sofia_int		bufLoad(BufferPointer const, FILE* const);
sofia_bol		bufRecover(BufferPointer const);
sofia_bol		bufRetract(BufferPointer const);
sofia_bol		bufRestore(BufferPointer const);
/* Getters */
sofia_chr		bufGetChar(BufferPointer const);
sofia_chr*		bufGetContent(BufferPointer const, sofia_int);
sofia_int		bufGetPosRead(BufferPointer const);
sofia_int		bufGetPosWrte(BufferPointer const);
sofia_int		bufGetPosMark(BufferPointer const);
sofia_int		bufGetSize(BufferPointer const);
sofia_int		bufGetInc(BufferPointer const);
sofia_int		bufGetMode(BufferPointer const);
sofia_flg		bufGetFlags(BufferPointer const);

#endif
