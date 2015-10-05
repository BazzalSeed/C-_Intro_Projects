
@Peiyun(seed) Zeng
@CSE 332
@zengpeiyun@wustl.edu
Note: 
      (0) in the design, four enums are put into the lab0.h and outside the struct card (global scope).
	   I made this choice because they can be sued for other functions that want to use enums for 
	   other possible functions (though not designed in this lab). 

      (1)in the design, an empty deck won't be considred as an error but only a warning
      (2) a file with all invalid string will not be considred as a bad file (no error retunrs, but only lots of warnings)
      (3) only two errors (1 and 2) are expected: wrong number of arguments and non-existing file
      (4) Warnings are tested seperately from error. if only warning appears, echo should give us 0(since it is not an error)
      
[1] Errors and fixation during compiling

(a) Errors

Error	1	error C2065: 'card' : undeclared identifier	\\warehouse2.seasad.wustl.edu\home\zengpeiyun\winprofile\desktop\lab0_seed_other\lab0_seed\lab0.cpp	21	1	lab0_Seed
Error	2	error C2146: syntax error : missing ';' before identifier 'x'	\\warehouse2.seasad.wustl.edu\home\zengpeiyun\winprofile\desktop\lab0_seed_other\lab0_seed\lab0.cpp	21	1	lab0_Seed
Error	3	error C2065: 'x' : undeclared identifier	\\warehouse2.seasad.wustl.edu\home\zengpeiyun\winprofile\desktop\lab0_seed_other\lab0_seed\lab0.cpp	21	1	lab0_Seed

(b) Fixation
it is an easy fix. The struct (class) name is Card instead of card so after change "card" to "Card", it compiles

1>------ Build started: Project: lab0_Seed, Configuration: Debug Win32 ------
1>  lab0.cpp
1>  lab0_Seed.vcxproj -> \\warehouse2.seasad.wustl.edu\home\zengpeiyun\winprofile\desktop\lab0_Seed_other\Debug\lab0_Seed.exe
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
======================================================================================================================================================================
======================================================================================================================================================================
[2]Runtime Test--Errors and success
*****************************************************************************************************
Tests of successful trials and failure trials due to Errors(instead of warnings)
in this case, there are only two kinds of erros will terminate the program and return non-zero values
(1)	FAILURE_OPENING_FILE = int 1
(2) WRONG_NUMBER_ARGUMENTS = int 2
******************************************************************************************************
Case #1--Successful trial

<1>
input file Card_file.txt is
2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC AC
aD kD qD jD 10D 9D 8D 7D 6D 5D 4D 3D 2D
2h 3h 4h 5h 6h 7h 8h 9h 10h Jh Qh Kh Ah
as ks qs js 10s 9s 8s 7s 6s 5s 4s 3s 2s

Note: this tests all 52 cards 
<2>
typed in commandline: 
lab0_Seed.exe card_file.txt
<3>
Program output:
the size of the deck is 52
Card 1:Two of Clubs
Card 2:Three of Clubs
Card 3:Four of Clubs
Card 4:Five of Clubs
Card 5:Six of Clubs
Card 6:Seven of Clubs
Card 7:Eight of Clubs
Card 8:Nine of Clubs
Card 9:Ten of Clubs
Card 10:Jack of Clubs
Card 11:Queen of Clubs
Card 12:King of Clubs
Card 13:Ace of Clubs
Card 14:Ace of Diamonds
Card 15:King of Diamonds
Card 16:Queen of Diamonds
Card 17:Jack of Diamonds
Card 18:Ten of Diamonds
Card 19:Nine of Diamonds
Card 20:Eight of Diamonds
Card 21:Seven of Diamonds
Card 22:Six of Diamonds
Card 23:Five of Diamonds
Card 24:Four of Diamonds
Card 25:Three of Diamonds
Card 26:Two of Diamonds
Card 27:Two of Hearts
Card 28:Three of Hearts
Card 29:Four of Hearts
Card 30:Five of Hearts
Card 31:Six of Hearts
Card 32:Seven of Hearts
Card 33:Eight of Hearts
Card 34:Nine of Hearts
Card 35:Ten of Hearts
Card 36:Jack of Hearts
Card 37:Queen of Hearts
Card 38:King of Hearts
Card 39:Ace of Hearts
Card 40:Ace of Spades
Card 41:King of Spades
Card 42:Queen of Spades
Card 43:Jack of Spades
Card 44:Ten of Spades
Card 45:Nine of Spades
Card 46:Eight of Spades
Card 47:Seven of Spades
Card 48:Six of Spades
Card 49:Five of Spades
Card 50:Four of Spades
Card 51:Three of Spades
Card 52:Two of Spades

So we can see easily, this program works correctly for all 52 cards of all ranks and suites

Calling echo %errorlevel% output:
0
<4>
Conclusion:
Thus program works as expected



**************************************************************************************************************************************************************
Case#2-- Wrong Number of Arguments
<1>
Input File: None
<2>
Typed in commandline:
 "lab0_Seed.exe"
<3>
Program Output:
usage: lab0_Seed.exe <input_file_name>is incorrect
plesae enter a valid file name (file must be at the same directory) directly follow the program name using the command line
for example: lab0_Seed.exe card_file.txt

Calling echo %errorlevel% output:
2

<4>
Conclusion:

So the program works as expected. 
Since we did not put right number of arguments in the command line, we get a useful message teaches us how to use the program
when the echo %errorlevel% is called, it shows the program returned 2, which is WRONG_NUMBER_ARGUMENT defiend in our enumeration
***********************************************************************************************************************************************************************
Case #3 -- ERROR oppneing the file

<1>
Input File: None
<2>
Typed in commandline:
 "lab0_Seed.exe Seed"
<3>
Program Output:
ERROR OPENING YOUR FILE BRO
Warning!!! printing deck: the deck is empty (this is from our warning section, we will discuss later)

Calling echo %errorlevel% output:
1

<4>
Conclusion:

So the program works as expected. 
Since Seed is not a valid filename (at current directory), the program tells us it cannot (find) open that file correctly. 
The echo %errorlevel% tells us the program returns 3, which is FAILURE_OPENING_FILE defiend in our enumeration
======================================================================================================================================================================
======================================================================================================================================================================
[3] Runtime Test--Warnings
***************************************************************************
This tests for warnings that the program should print out to notify the user when
(1)Detecting a invalid card string in the file
(2)Decteting the deck that tries to print out is empty
***************************************************************************
Case #1-- Warning from parsing file
<1>
Input file:
Card.txt
4D  100D 8D  12C
15C 11D  10E JC
<2>
Typed in Command:
"lab0_Seed.exe Card.txt"

<3>
Program output:
Warning!!!Push onto deck: invalid string element type: invalid length
Warning!!! Push onto deck: invalid string element: invalid rank
Warning!!! Push onto deck: invalid string element: invalid rank
Warning!!! Push onto deck: invalid string element: invalid rank
Warning!!! Push onto deck: invalid string element: invalid suite and rank
the size of the deck is 3
Card 1:Four of Diamonds
Card 2:Eight of Diamonds
Card 3:Jack of Clubs

Calling echo %errorlevel% output:
0

<4>
Conclusion:

The program works as expcted.
For the input file, there are only 3 valid card strings
the other strings are not pushed due to (1) invalid length (2) invalid rank (3) invalid suite
the program detects them and notfied the user and then move on to find all valid card strings.
then it correctly prints out the final updated deck (vector)

The program should return 0 since no "errors"(none-zero values) has been retunred agrees with our echo command
***************************************************************************************************
Case #2-- Warning from print vector

<1>
Input file:
card.txt
EMPTY. i mean it literally empty

<2>
Typed in Command:
"lab0_Seed.exe Card.txt"

<3>
Program output:
the size of the deck is 0
Warning!!! printing deck: the deck is empty


Calling echo %errorlevel% output:
0
<4>
Conclusion:
The program works as expcted.
Since nothing is pushed to the deck, the program will notify the user that the deck is empty and prints out nothing (of the deck)

The program should return 0 since no "errors"(none-zero values) has been retunred agrees with our echo command

======================================================================================================================================================================
======================================================================================================================================================================
======================================================================================================================================================================

EXTRA CREDIT

1. Linux Command Prompt: zengpeiyun@shell ~]$ 

2. one error occurs saying 
g++ -o lab0 -DUNIX   -Wall -W -g -pedantic lab0.cpp -lnsl
lab0.cpp:1:21: fatal error: stdafx.h: No such file or directory
  #include "stdafx.h"

The fixation is easy, visual studio does stupid thing to create an extra stdafx.h file which is not needed needed, so comment out #include "stdafx.h"
it successfuly compiles


3. Running Program in Linux using command ./lab0 "filename"
*******************************************************************************************************************
The results are essentially identical to the results we got. so here i will just show the output
The input and analysis and other information can be found correspondingly by checking the previous documentation
********************************************************************************************************************

Test Error/Succes section

[zengpeiyun@shell lab0]$ ./lab0 card_file.txt
Case#1
the size of the deck is 52
Card 1:Two of Clubs
Card 2:Three of Clubs
Card 3:Four of Clubs
Card 4:Five of Clubs
Card 5:Six of Clubs
Card 6:Seven of Clubs
Card 7:Eight of Clubs
Card 8:Nine of Clubs
Card 9:Ten of Clubs
Card 10:Clubs of Clubs
Card 11:Diamonds of Clubs
Card 12:Hearts of Clubs
Card 13:Spades of Clubs
Card 14:Spades of Diamonds
Card 15:Hearts of Diamonds
Card 16:Diamonds of Diamonds
Card 17:Clubs of Diamonds
Card 18:Ten of Diamonds
Card 19:Nine of Diamonds
Card 20:Eight of Diamonds
Card 21:Seven of Diamonds
Card 22:Six of Diamonds
Card 23:Five of Diamonds
Card 24:Four of Diamonds
Card 25:Three of Diamonds
Card 26:Two of Diamonds
Card 27:Two of Hearts
Card 28:Three of Hearts
Card 29:Four of Hearts
Card 30:Five of Hearts
Card 31:Six of Hearts
Card 32:Seven of Hearts
Card 33:Eight of Hearts
Card 34:Nine of Hearts
Card 35:Ten of Hearts
Card 36:Clubs of Hearts
Card 37:Diamonds of Hearts
Card 38:Hearts of Hearts
Card 39:Spades of Hearts
Card 40:Spades of Spades
Card 41:Hearts of Spades
Card 42:Diamonds of Spades
Card 43:Clubs of Spades
Card 44:Ten of Spades
Card 45:Nine of Spades
Card 46:Eight of Spades
Card 47:Seven of Spades
Card 48:Six of Spades
Card 49:Five of Spades
Card 50:Four of Spades
Card 51:Three of Spades
Card 52:Two of Spades

case #2
[zengpeiyun@shell lab0]$ ./lab0 
usage: ./lab0 <input_file_name>is incorrect
plesae enter a valid file name (file must be at the same directory) directly follow the program name using the command line
for example: lab0_Seed.exe card_file.txt

case #3
[zengpeiyun@shell lab0]$ ./lab0 haha
ERROR OPENING YOUR FILE BRO
Warning!!! printing deck: the deck is empty
***********************************************************************************************************************************
Test Warning section

Case #1
[zengpeiyun@shell lab0]$ ./lab0 card.txt
Warning!!!Push onto deck: invalid string element type: invalid length
Warning!!! Push onto deck: invalid string element: invalid rank
Warning!!! Push onto deck: invalid string element: invalid rank
Warning!!! Push onto deck: invalid string element: invalid rank
Warning!!! Push onto deck: invalid string element: invalid suite and rank
the size of the deck is 3
Card 1:Four of Diamonds
Card 2:Eight of Diamonds
Card 3:Clubs of Clubs

Case #2

[zengpeiyun@shell lab0]$ ./lab0 card.txt
the size of the deck is 0
Warning!!! printing deck: the deck is empty
