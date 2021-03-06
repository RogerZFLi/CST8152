:: COMPILERS COURSE - SCRIPT ---------------------------------------------
:: SCRIPT A12 - CST8152 - Spring 2022

CLS
SET COMPILER=Compiler.exe

SET FILE1=RoSAlice_Empty
SET FILE2=RoSAlice_Hello
SET FILE3=RoSAlice_Volume
SET FILE4=RoSAlice_Factorial
SET FILE5=RoSAlice_Datatypes
SET FILE6=RoSAlice_General
SET FILE7=RoSAlice_Big

SET EXTENSION=rsa
SET OUTPUT=out
SET ERROR=err

SET PARAM=1

:: ---------------------------------------------------------------------
:: Begin of Tests (A12 - W22) ------------------------------------------
:: ---------------------------------------------------------------------

ren *.exe %COMPILER%

::
:: BASIC TESTS  ----------------------------------------------------------
::
:: Basic Tests (A12 - W22) - - - - - - - - - - - - - - - - - - - - - -

%COMPILER% %PARAM% %FILE1%.%EXTENSION%	> %FILE1%.%OUTPUT%	2> %FILE1%.%ERROR%
%COMPILER% %PARAM% %FILE2%.%EXTENSION%	> %FILE2%.%OUTPUT%	2> %FILE2%.%ERROR%
%COMPILER% %PARAM% %FILE3%.%EXTENSION%	> %FILE3%.%OUTPUT%	2> %FILE3%.%ERROR%
%COMPILER% %PARAM% %FILE4%.%EXTENSION%	> %FILE4%.%OUTPUT%	2> %FILE4%.%ERROR%
%COMPILER% %PARAM% %FILE5%.%EXTENSION%	> %FILE5%.%OUTPUT%	2> %FILE5%.%ERROR%
%COMPILER% %PARAM% %FILE6%.%EXTENSION%	> %FILE6%.%OUTPUT%	2> %FILE6%.%ERROR%

::
:: ADVANCED TESTS  -------------------------------------------------------
::
:: Advanced Tests (A12 - W22) - - - - - - - - -- - - - - - - - - - - -

%COMPILER% %PARAM% %FILE7%.%EXTENSION%	f 100 10	> %FILE7%-f-100-10.%OUTPUT%	2> %FILE7%-f-100-10.%ERROR%
%COMPILER% %PARAM% %FILE7%.%EXTENSION%	a 100 10	> %FILE7%-a-100-10.%OUTPUT%	2> %FILE7%-a-100-10.%ERROR%
%COMPILER% %PARAM% %FILE7%.%EXTENSION%	m 100 10	> %FILE7%-m-100-10.%OUTPUT%	2> %FILE7%-m-100-10.%ERROR%

:: SHOW OUTPUTS - - - - - - - - - - - - - - - - - - - - - - - - - - -
DIR *.OUT
DIR *.ERR

:: ---------------------------------------------------------------------
:: End of Tests (A12 - W22) --------------------------------------------
:: ---------------------------------------------------------------------
