:: ---------------------------------------------------------------------
:: COMPILERS COURSE - SCRIPT
:: SCRIPT A22 - CST8152 - Summer 2022
:: ---------------------------------------------------------------------

CLS
SET COMPILER=Compiler.exe

SET FILE1=RoSAlice_Empty
SET FILE2=RoSAlice_Hello
SET FILE3=RoSAlice_Volume
SET FILE4=RoSAlice_Factorial
SET FILE5=RoSAlice_Datatypes
SET FILE6=RoSAlice_General

SET EXTENSION=rsa
SET OUTPUT=out
SET ERROR=err

SET PARAM=2

:: ---------------------------------------------------------------------
:: Begin of Tests (A22 - S22) ------------------------------------------
:: ---------------------------------------------------------------------

del *.OUTPUT
del *.ERROR
ren *.exe %COMPILER%

::
:: BASIC TESTS  ----------------------------------------------------------
::
:: Basic Tests (A22 - S22) - - - - - - - - - - - - - - - - - - - - - -

%COMPILER% %PARAM% %FILE1%.%EXTENSION%	> %FILE1%.%OUTPUT%	2> %FILE1%.%ERROR%
%COMPILER% %PARAM% %FILE2%.%EXTENSION%	> %FILE2%.%OUTPUT%	2> %FILE2%.%ERROR%
%COMPILER% %PARAM% %FILE3%.%EXTENSION%	> %FILE3%.%OUTPUT%	2> %FILE3%.%ERROR%
%COMPILER% %PARAM% %FILE4%.%EXTENSION%	> %FILE4%.%OUTPUT%	2> %FILE4%.%ERROR%
%COMPILER% %PARAM% %FILE5%.%EXTENSION%	> %FILE5%.%OUTPUT%	2> %FILE5%.%ERROR%
%COMPILER% %PARAM% %FILE6%.%EXTENSION%	> %FILE6%.%OUTPUT%	2> %FILE6%.%ERROR%

:: SHOW OUTPUTS - - - - - - - - - - - - - - - - - - - - - - - - - - -
DIR *.OUT
DIR *.ERR

:: ---------------------------------------------------------------------
:: End of Tests (A22 - S22) --------------------------------------------
:: ---------------------------------------------------------------------
