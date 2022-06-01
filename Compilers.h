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
* File name: compilers.h
* Compiler: MS Visual Studio 2022
* Author: Paulo Sousa
* Course: CST 8152 – Compilers, Lab Section: [011, 012, 013]
* Assignment: A12, A22, A32.
* Date: May 01 2022
* Professor: Paulo Sousa
* Purpose: This file defines the functions called by main function.
* Function list: mainBuffer(), mainScanner(), mainParser().
*************************************************************/

#ifndef COMPILERS_H_
#define COMPILERS_H_

#define DEBUG 0

/*
 * ............................................................................
 * ADVICE 1:
 * Please check the "TODO" labels to develop your activity.
 *
 * ADVICE 2: This file must be updated according to each assignment
 * (see the progression: buffer > scanner > parser).
 * ............................................................................
 */

/* TODO: Logical constants - adapt for your language */
#define SOFIA_TRUE	1
#define SOFIA_FALSE 0

/*
------------------------------------------------------------
Data types definitions
NOTE: Some types may not be directly used by your language,
		but they can be necessary for conversions. 
------------------------------------------------------------
*/

/* TODO: Define your typedefs */
typedef char			sofia_chr;
typedef int				sofia_int;
typedef float			sofia_flt;
typedef void			sofia_nul;

typedef unsigned char	sofia_bol;
typedef unsigned char	sofia_flg;

typedef long			sofia_lng;
typedef double			sofia_dbl;

/*
------------------------------------------------------------
Programs:
1: Buffer - invokes MainBuffer code
2: Scanner - invokes MainScanner code
3: Parser - invokes MainParser code
------------------------------------------------------------
*/
enum PROGRAMS {
	PGM_BUFFER	= '1',
	PGM_SCANNER = '2',
	PGM_PARSER	= '3'
};

/*
------------------------------------------------------------
Main functions signatures
(Code will be updated during next assignments)
------------------------------------------------------------
*/
sofia_int mainBuffer	(sofia_int argc, sofia_chr** argv);
/*
sofia_int mainScanner	(sofia_int argc, sofia_chr** argv);
sofia_int mainParser	(sofia_int argc, sofia_chr** argv);
*/

#endif
