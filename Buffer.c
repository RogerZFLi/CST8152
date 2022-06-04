/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Summer, 2022
* Author: Roger Li, Denys Savaskyi - Paulo Sousa
* Professors: Paulo Sousa
************************************************************
*/

/*
***********************************************************
* File name: buffer.c
* Compiler: MS Visual Studio 2022
* Author: Paulo Sousa
* Course: CST 8152 – Compilers, Lab Section: [011, 012, 013]
* Assignment: A12.
* Date: May 01 2022
* Professor: Paulo Sousa
* Purpose: This file is the main code for Buffer (A12)
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
#include "Buffer.h"
#endif

/*
***********************************************************
* Function name: bCreate
* Purpose: Creates the buffer according to capacity, increment
	factor and operational mode ('f', 'a', 'm')
* Author: Roger Li, Denys Savaskyi / Paulo Sousa
* History/Versions: S22
* Called functions: calloc(), malloc()
* Parameters:
*   size = initial capacity
*   increment = increment factor
*   mode = operational mode
* Return value: bPointer (pointer to Buffer)
* Algorithm: Allocation of memory according to inicial (default) values.
* TODO ...................................................... 
*	- Adjust datatypes for your LANGUAGE.
*   - Use defensive programming
*	- Check boundary conditions
*	- Check flags.
*************************************************************
*/

BufferPointer bufCreate(rsa_int size, rsa_int increment, rsa_int mode) {
	BufferPointer b;
	/* TODO: Defensive programming: check validity of parameters */
	if (!size) {
		size = BUFFER_DEFAULT_SIZE;
		increment = BUFFER_DEFAULT_INCREMENT;
	}
	/* TODO: When there is no increment, mode: fixed */
	b = (BufferPointer)calloc(1, sizeof(Buffer));
	/* TODO: Defensive programming */
	if (b) {
		b->content = (rsa_chr*)malloc(size);
		b->size = size;
	}
	/* TODO: Defensive programming */
	/* TODO: Update buffer properties (mode, increment, flags) */
	return b;
}


/*
***********************************************************
* Function name: bAddChar
* Purpose: Adds a char to buffer
* Parameters:
*   pBuffer = pointer to Buffer Entity
*   ch = char to be added
* Return value:
*	bPointer (pointer to Buffer)
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/

BufferPointer bufAddChar(BufferPointer pBuffer, rsa_chr ch) {
	rsa_chr* tempbuf = NULL;
	rsa_int newSize = 0;
	/* TODO: Defensive programming */
	/* TODO: Reset Realocation */
	/* TODO: Check if it is possible to be increased */
	/* TODO: Check if buffer is full */
	if (pBuffer->position.posWrte * (rsa_int)sizeof(rsa_chr) >= pBuffer->size) {
		switch (pBuffer->mode) {
		case MODE_FIXED:
			return NULL;
		case MODE_ADDIT:
			/* TODO: Adjust new size for Additive increment */
			/* TODO: Test with defensive programming */
			return pBuffer;
			
		case MODE_MULTI:
			/* TODO: Adjust new size for Additive increment */
			/* TODO: Test with defensive programming */
			break;
		default:
			return NULL;
		}
	}
	/* TODO: Realloc the size for new buffer */
	/* TODO: Check the realocation by Defensive programming */
	/* TODO: If allowed, adjust the new buffer content */
	pBuffer->content[pBuffer->position.posWrte++] = ch;
	return pBuffer;
}

/*
***********************************************************
* Function name: bClear
* Purpose: Clears the buffer
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_bol bufClear(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Clear the buffer reseting all positions and flags */
	return RSA_TRUE;
}

/*
***********************************************************
* Function name: bDestroy
* Purpose: Releases the buffer address
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_bol bufDestroy(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Free the buffer (content and struct) */
	return RSA_TRUE;
}

/*
***********************************************************
* Function name: bIsFull
* Purpose: Checks if buffer is full
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_bol bufChkFull(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Check flag if buffer is FUL and return correct value */
	return RSA_TRUE;
}


/*
***********************************************************
* Function name: bIsEmpty
* Purpose: Checks if buffer is empty.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_bol bufChkEmpty(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Check if it is empty */
	return RSA_TRUE;
}


/*
***********************************************************
* Function name: bSetMark
* Purpose: Adjust the position of mark in the buffer
* Parameters:
*   pBuffer = pointer to Buffer Entity
*   mark = mark position for char
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_bol bufSetMark(BufferPointer const pBuffer, rsa_int mark) {
	/* TODO: Defensive programming */
	/* TODO: Adjust mark position */
	return RSA_TRUE;
}


/*
***********************************************************
* Function name: bPrint
* Purpose: Prints the string in the buffer.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Number of chars printed.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_int bufPrint(BufferPointer const pBuffer) {
	rsa_int cont = 0;
	rsa_chr c;
	/* TODO: Defensive programming */
	c = bufGetChar(pBuffer);
	/* TODO: Print all chars */
	while (cont<pBuffer->position.posWrte) {
		cont++;
		printf("%c", c);
		c = bufGetChar(pBuffer);
	}
	return cont;
}

/*
***********************************************************
* Function name: bLoad
* Purpose: Loads the string in the buffer with the content of
	an specific file.
* Parameters:
*   pBuffer = pointer to Buffer Entity
*   fi = pointer to file descriptor
* Return value:
*	Number of chars read and put in buffer.
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_int bufLoad(BufferPointer const pBuffer, FILE* const fi) {
	rsa_int size = 0;
	rsa_chr c;
	/* TODO: Defensive programming */
	c = (rsa_chr)fgetc(fi);
	while (!feof(fi)) {
		if (!bufAddChar(pBuffer, c)) {
			ungetc(c, fi);
			return BUFFER_ERROR;
		}
		c = (char)fgetc(fi);
		size++;
	}
	/* TODO: Defensive programming */
	return size;
}


/*
***********************************************************
* Function name: bRecover
* Purpose: Rewinds the buffer.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_bol bufRecover(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Reinitialize read and mark positions */
	return RSA_TRUE;
}


/*
***********************************************************
* Function name: bRetract
* Purpose: Retracts the buffer to put back the char in buffer.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_bol bufRetract(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Check boundary conditions */
	/* TODO: Retract (return 1 pos read) */
	return RSA_TRUE;
}


/*
***********************************************************
* Function name: bRestore
* Purpose: Resets the buffer.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_bol bufRestore(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Return read position to mark position */
	return RSA_TRUE;
}

/*
***********************************************************
* Function name: bGetChar
* Purpose: Returns the char in the getC position.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Char in the getC position.
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_chr bufGetChar(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Adjust EOB if necessary */
	return pBuffer->content[pBuffer->position.posRead++];
}


/*
***********************************************************
* Function name: bGetContent
* Purpose: Returns the pointer to String.
* Parameters:
*   pBuffer = pointer to Buffer Entity
*   pos = position to get the pointer
* Return value:
*	Position of string char.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_chr* bufGetContent(BufferPointer const pBuffer, rsa_int pos) {
	/* TODO: Defensive programming */
	/* TODO: Return the pointer to content given by pos */
	return NULL;
}


/*
***********************************************************
* Function name: bGetReadPos
* Purpose: Returns the value of getCPosition.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	The readPos offset.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_int bufGetPosRead(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Return read position */
	return 0;
}


/*
***********************************************************
* Function name: bGetWritePos
* Purpose: Returns the position of char to be added
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	addcPosition value
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_int bufGetPosWrte(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Return the expected (write position) */
	return 0;
}


/*
***********************************************************
* Function name: bGetMarkPos
* Purpose: Returns the position of mark in the buffer
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	mark offset.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_int bufGetPosMark(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Return mark position */
	return 0;
}

/*
***********************************************************
* Function name: bGetSize
* Purpose: Returns the current buffer capacity
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Size of buffer.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_int bufGetSize(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Return buffer size */
	return 0;
}


/*
***********************************************************
* Function name: bGetIncrement
* Purpose: Returns the buffer increment.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	The Buffer increment.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_int bufGetInc(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Return increment */
	return 0;
}


/*
***********************************************************
* Function name: bGetMode
* Purpose: Returns the operational mode
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	operational mode.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_int bufGetMode(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Return buffer mode */
	return 0;
}


/*
***********************************************************
* Function name: bGetFlags
* Purpose: Returns the entire flags of Buffer.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Flags from Buffer.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
rsa_flg bufGetFlags(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Return flags */
	return 0;
}

