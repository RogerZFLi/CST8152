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
#define RSA_TRUE	1
#define RSA_FALSE 0

/*
------------------------------------------------------------
Data types definitions
NOTE: Some types may not be directly used by your language,
		but they can be necessary for conversions. 
------------------------------------------------------------
*/

/* TODO: Define your typedefs */
typedef char			rsa_chr;
typedef int				rsa_int;
typedef float			rsa_flt;
typedef void			rsa_nul;

typedef unsigned char	rsa_bol;
typedef unsigned char	rsa_flg;

typedef long			rsa_lng;
typedef double			rsa_dbl;

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
rsa_int mainBuffer	(rsa_int argc, rsa_chr** argv);
/*
rsa_int mainScanner	(rsa_int argc, rsa_chr** argv);
rsa_int mainParser	(rsa_int argc, rsa_chr** argv);
*/

#endif
