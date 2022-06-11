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
* File name: mainBuffer.c
* Compiler: MS Visual Studio 2022
* Author: Roger Li, Denys Savaskyi - Paulo Sousa
* Course: CST 8152 – Compilers, Lab Section: 012
* Assignment: A12
* Date: May 01 2022
* Professor: Paulo Sousa
* Purpose: This file is the main code for Buffer (A12)
* Function list: rsa_nul bErrorPrint(rsa_chr* fmt, ...);
	rsa_nul displayBuffer(Buffer* ptr_Buffer);
	rsa_lng getFileSize(rsa_chr* fname);
	rsa_int isNumber(const rsa_chr* ns);
	rsa_nul startBuffer(rsa_chr*, rsa_chr*, rsa_chr, rsa_int, rsa_int);
*************************************************************/

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef BUFFER_H_
#include "Buffer.h"
#endif

 /* Check for ANSI C compliancy */
#define ANSI_C 0
#if defined(__STDC__)
#undef ANSI_C
#define ANSI_C 1
#endif

/*
 * changed all datatypes to your language definitions
 */

/*
 * -------------------------------------------------------------
 *  Function declarations
 * -------------------------------------------------------------
 */
rsa_nul bErrorPrint(rsa_chr* fmt, ...);
rsa_nul displayBuffer(Buffer* ptr_Buffer);
rsa_lng getFileSize(rsa_chr* fname);
rsa_int isNumber(const rsa_chr* ns);
rsa_nul startBuffer(rsa_chr*, rsa_chr*, rsa_chr, rsa_int, rsa_int);

/*
************************************************************
* Main function from Buffer
* Parameters:
*   argc / argv = Parameters from command prompt
* Return value:
*	Success operation.
************************************************************
*/

rsa_int mainBuffer(rsa_int argc, rsa_chr** argv) {

	/* Create source input buffer */
	rsa_chr* program = argv[0];
	rsa_chr* input = argv[2];
	rsa_chr mode = MODE_FIXED;
	rsa_int size = 0, increment = 0, wrongNumber = 0;

	/* Missing file name or/and mode parameter */
	if (argc <= 2) {
		bErrorPrint("\nDate: %s  Time: %s", __DATE__, __TIME__);
		bErrorPrint("\nRuntime error at line %d in file %s\n", __LINE__, __FILE__);
		bErrorPrint("%s\b\b\b\b%s%s", argv[0], ": ", "Missing parameters.");
		bErrorPrint("Usage: <Option=0> <SourceFile> [<Mode>]");
		exit(EXIT_FAILURE);
	}

	if (argc == 4) {
		mode = *argv[3];
		switch (mode) {
		case MODE_FIXED: case MODE_ADDIT: case MODE_MULTI: break;
		default:
			bErrorPrint("%s%s%c%s%c%s%c%s", program, ": Wrong mode - choose: ",
				MODE_FIXED, ", ", MODE_ADDIT, ", ", MODE_MULTI, ".");
			exit(EXIT_FAILURE);
		}
	}
	/* Read additional parameters, if any */
	if (argc == 6) {
		mode = *argv[3];
		if (isNumber(argv[4]))size = (short)atoi(argv[4]); else wrongNumber = 1;
		if (isNumber(argv[5]))increment = (short)atoi(argv[5]); else wrongNumber = 1;
		if (wrongNumber) {
			bErrorPrint("\nDate: %s  Time: %s", __DATE__, __TIME__);
			bErrorPrint("\nRuntime error at line %d in file %s\n", __LINE__, __FILE__);
			bErrorPrint("%s\b\b\b\b%s", argv[0], ": Missing or wrong number parameters.");
			bErrorPrint("Usage: <Option=0> <SourceFile> [<Mode> <Size> <Increment>]");
			exit(EXIT_FAILURE);
		}
	}

	/* Starts the buffer process */
	startBuffer(program, input, mode, size, increment);

	/* Return success */
	return (EXIT_SUCCESS);
}

/*
************************************************************
* Buffer starting method
* Params:
*	- Program: Name of the program
*	- Input: Filename
*	- Mode: Operational mode
*	- Size: Buffer capacity
*	- Increment: buffer increment.
************************************************************
*/
rsa_nul startBuffer(rsa_chr* program, rsa_chr* input, rsa_chr mode, rsa_int size, rsa_int increment) {

	BufferPointer bufferp;		/* pointer to Buffer structure */
	FILE* fileHandler;			/* input file handle */
	rsa_int loadSize = 0;		/* the size of the file loaded in the buffer */
	rsa_chr symbol;				/* symbol read from input file */

	/* Create buffer */
	bufferp = bufCreate(size, (char)increment, mode);

	if (bufferp == NULL) {
		bErrorPrint("%s%s", program,
			": Cannot allocate buffer - Use: buffer <input> <mode> <size> <increment>.");
		bErrorPrint("Filename: %s %c %d %d\n", input, mode, size, increment);
		exit(1);
	}

	/* Open source file */
	if ((fileHandler = fopen(input, "r")) == NULL) {
		bErrorPrint("%s%s%s", program, ": Cannot open file: ", input);
		exit(1);
	}

	/* Load source file into input buffer  */
	printf("Reading file %s ....Please wait\n", input);
	loadSize = bufLoad(bufferp, fileHandler);

	/* If the input file has not been completely loaded, find the file size and print the last symbol loaded */
	if (loadSize == BUFFER_ERROR) {
		printf("The input file %s %s\n", input, "has not been completely loaded.");
		printf("Current size of buffer: %d.\n", bufGetSize(bufferp));
		symbol = (char)fgetc(fileHandler);
		printf("Last character read from the input file is: %c %d\n", symbol, symbol);
		printf("Input file size: %ld\n", getFileSize(input));
	}

	/* Close source file */
	fclose(fileHandler);

	/* Finishes the buffer: add end of file character (EOF) to the buffer display again */
	if ((loadSize != BUFFER_ERROR) && (loadSize != 0)) {
		if (!bufAddChar(bufferp, BUFFER_EOF)) {
			bErrorPrint("%s%s%s", program, ": ", "Error in compacting buffer.");
		}
	}

	/* Prints the buffer property and content */
	displayBuffer(bufferp);

	/* Free the dynamic memory used by the buffer */
	bufDestroy(bufferp);
	bufferp = NULL;
}

/*
************************************************************
* Error printing function with variable number of arguments
* Params: Variable arguments, using formats from C language.
*	- Internal vars use list of arguments and types from stdarg.h
*   - NOTE: The format is using signature from C Language
************************************************************
*/

rsa_nul bErrorPrint(rsa_chr* fmt, ...) {
	/* Initialize variable list */
	va_list ap;
	va_start(ap, fmt);

	(rsa_nul)vfprintf(stderr, fmt, ap);
	va_end(ap);

	/* Move to new line */
	if (strchr(fmt, '\n') == NULL)
		fprintf(stderr, "\n");
}

/*
************************************************************
* Print function
*	- Params: buffer to print all properties.
************************************************************
*/

rsa_nul displayBuffer(Buffer* ptr_Buffer) {
	printf("\nPrinting buffer parameters:\n\n");
	printf("The capacity of the buffer is:  %d\n",
		bufGetSize(ptr_Buffer));
	printf("The current size of the buffer is:  %d\n",
		bufGetPosWrte(ptr_Buffer));
	printf("The operational mode of the buffer is: %c\n",
		bufGetMode(ptr_Buffer));
	printf("The increment factor of the buffer is:  %lu\n",
		bufGetInc(ptr_Buffer));
	printf("The first symbol in the buffer is:  %c\n",
		bufGetPosWrte(ptr_Buffer) ? *bufGetContent(ptr_Buffer, 0) : ' ');
	printf("The value of the flags field is: %02hX\n",
		bufGetFlags(ptr_Buffer));
	printf("\nPrinting buffer contents:\n\n");
	bufRecover(ptr_Buffer);
	if (!bufPrint(ptr_Buffer))
		printf("Empty buffer\n");
}

/*
************************************************************
* Get buffer size
* Params:
*	- Filename: Name of the file
************************************************************
*/

rsa_lng getFileSize(rsa_chr* fname) {
	FILE* input;
	rsa_lng flength;
	input = fopen(fname, "r");
	if (input == NULL) {
		bErrorPrint("%s%s", "Cannot open file: ", fname);
		return 0;
	}
	fseek(input, 0L, SEEK_END);
	flength = ftell(input);
	fclose(input);
	return flength;
}

/*
************************************************************
 * Tests for decimal-digit character string
 * Params:
 *		- String to be evaluated as numeric
 * Return:
 *		- Number value: Returns nonzero (true) if ns is a number; 0 (False) otherwise
************************************************************
*/

rsa_int isNumber(const rsa_chr* ns) {
	rsa_chr c; rsa_int i = 0;
	if (ns == NULL) return 0;
	while ((c = ns[i++]) == 0) {
		if (!isdigit(c)) return 0;
	}
	return 1;
}
