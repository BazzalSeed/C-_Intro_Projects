@Lab 2
@CSE332
@Peiyun Zeng/ 曾培耘

Notes:
(1) Extra credit is accomplished
(2) This program's poker_rank function leverages the design of the extra credit part of lab1 (which is checked as full credit by Dr.Miller)
 

I. Design and Method

(1)Deck class
Deck class is implemented as instructed
(2)Hand Class
Hand class is implemented as instructed

(3)Poker_rank function
Use int hand_vector(const vector<Card>&deck) to implement it. This function will iterate through the passed in vector(deck of cards) with a step of valid_hand_size(5 in this case). Notice that 
since we are only passing in the vector we created using ParseFile_hand, our indexing will never encounter Error of index overflow.

******************** Begin Mechanism for recognizing hand******************
in each iteration, hand_vector will create a temp vector called hand_deck to hold current valid_hand_size of cards(5 in this case). Then we sort hand_deck. 
Now, we will create a frequency table for the sorted hand_deck. In frequency table, each index position check repetitions of its own rank to the right of its position.
finally we sort the frequency table. Each hand rank has a distinctive frequency table. Based on this, we can determine our rank for hand (except for straight, flush and straight flush)
Note: 
(a).frequency count starts at 1 instead of 0
(b).the frequency table is sorted ascendingly 

One pair: 
(a) Frequencytalbe[last_index] = 2
(b) Frequencytable[Secondlast_index]!= 2
two pairs
(a) Frequencytalbe[last_index] = 2
(b) Frequencytable[Secondlast_index]= 2

three of a kind
(a) Frequencytalbe[last_index] = 3
(b) Frequencytable[Secondlast_index]= 2
(c) Frequencytable[thirdlast_index] != 2

Full House
(a) Frequencytalbe[last_index] = 3
(b) Frequencytable[Secondlast_index]= 2
(c) Frequencytable[thirdlast_index] = 2

Four of kind
(a) Frequencytalbe[last_index] = 4

For straight, we simply iterate through the whole hand_deck to see whether the rank of card at next position = the rank of card at current position +1
For flush, we simpy iterate through the whole hand_deck to see whether all cards have the same suit
If a hand_deck statisefies both, it is staright flush

if a hand_deck satisefies none of these above, it is a unranked.
******************************* End Mechanism for recognizing hand ***************************************

(4)int usage_message(char* argv[], int number_of_argument, bool & will_be_shuffled, int & file_name_index)
In this lab, the function is used to accomplish the task of helping us distinquish from the following cases
(a) only one command line argument is given but it contains "-shuffle".
(b) two command line arguments are given but neither one contains "-shuffle".
(c) no command line arguments are given
(d) more than 2 command line arguments are given
and obviously, Dr.Gill missed one mroe invliad case
(e) two command line arguments are given but both "-shuffle"



II. Compiling errors and fixes

No compiliing errors are encountered this time.


III. Tests

(1) command-line failure recoganiction

case#1--no command line arguments are given
1）command-line input and output
C:\Users\Seed\Dropbox\Spring 2015\C++332\Labs\lab2\Lab2_3\Debug>lab2_1.exe
no command line arguments are given
plesae enter a valid file name (file must be at the same directory) directly fol
low the program name using the command line or one more optional -shuffle argume
nt (-shuffle and file name can be in either order)
for example: lab2_1.exe card_file.txt -shuffle

2） echo return value
12 (no argument)

#case 2-- only one command line argument is given but it contains "-shuffle".
1) comman-line arguments and output
only one command line argument is given but it contains  - shuffle.
plesae enter a valid file name (file must be at the same directory) directly fol
low the program name using the command line or one more optional -shuffle argume
nt (-shuffle and file name can be in either order)
for example: lab2_1.exe card_file.txt -shuffle

2) echo return value
10(onlyone_shuffle)


#case 3 --two command line arguments are given but neither one contains "-shuffle".

1) intput/ outputs
two command line arguments are given but neither one contains - shuffle.
plesae enter a valid file name (file must be at the same directory) directly fol
low the program name using the command line or one more optional -shuffle argume
nt (-shuffle and file name can be in either order)
for example: lab2_1.exe card_file.txt -shuffle
2) echo return value
echo return value
11


#case4  --more than 2 command line arguments are given
1) intputs/outputs
C:\Users\Seed\Dropbox\Spring 2015\C++332\Labs\lab2\Lab2_3\Debug>lab2_1.exe card_
file.txt card_3.txt haha
more than 2 command line arguments are given
plesae enter a valid file name (file must be at the same directory) directly fol
low the program name using the command line or one more optional -shuffle argume
nt (-shuffle and file name can be in either order)
for example: lab2_1.exe card_file.txt -shuffle
2)
echo return value
13



#case5  -- two command line arguments are both "-shuffle"

1) inputs/outputs
two command line arguments are given but both are - shuffle.
plesae enter a valid file name (file must be at the same directory) directly fol
low the program name using the command line or one more optional -shuffle argume
nt (-shuffle and file name can be in either order)
for example: lab2_1.exe card_file.txt -shuffle
2) echo return value
17


(2) wokring command-line

#case 1-- not shuffled

Printing out the deck after initial construction
2C
3C
4C
5C
6C
7C
8C
9C
10C
JC
QC
KC
AC
AD
KD
QD
JD
10D
9D
8D
7D
6D
5D
4D
3D
2D
2H
3H
4H
5H
6H
7H
8H
9H
10H
JH
QH
KH
AH
AS
KS
QS
JS
10S
9S

<----------------------------------------------------------------------------->
Remaining Deck contents after Insertion
Empty Deck
<----------------------------------------------------------------------------->
Each hand contents after Insertion
2H 9S 10C 10D JH
2D 9C 10H 10S JD
3D 8C 9H JS QD
4D 7C 8H QS KD
5D 6C 7H KS AD
5C 6D 6H AC AS
4C 5H 7D KC AH
3C 4H 8D QC KH
2C 3H 9D JC QH
<----------------------------------------------------------------------------->
After Sorting using member-method operator<
2C 3H 9D JC QH
2D 9C 10H 10S JD
2H 9S 10C 10D JH
3C 4H 8D QC KH
3D 8C 9H JS QD
4C 5H 7D KC AH
4D 7C 8H QS KD
5C 6D 6H AC AS
5D 6C 7H KS AD
<----------------------------------------------------------------------------->
After using custom parse_rank function
5C 6D 6H AC AS
2H 9S 10C 10D JH
2D 9C 10H 10S JD
4C 5H 7D KC AH
5D 6C 7H KS AD
3C 4H 8D QC KH
4D 7C 8H QS KD
2C 3H 9D JC QH
3D 8C 9H JS QD


case#2-- Shuffled first position
Printing out the deck after shuffle
QD
8D
3D
7C
KD
JD
KH
9H
QC
7D
10S
2D
KS
9D
4H
6C
AS
10C
9C
10D
5C
7H
2C
5H
AD
4C
4D
6D
9S
AC
JC
6H
QH
8C
QS
5D
2H
KC
JH
3C
3H
AH
10H
JS
8H

Remaining Deck contents after Insertion
Empty Deck
<-----------------------------------------------------------------------------
Each hand contents after Insertion
4D 5D 8H 10C QC
4C 9H JS QS AS
6C 8C 10H KH AD
4H 5H JD QH AH
2C 3H 6H 9D KD
3C 7C 7H JC KS
2D 3D 5C JH AC
8D 9S 10D 10S KC
2H 6D 7D 9C QD
<-----------------------------------------------------------------------------
After Sorting using member-method operator<
2C 3H 6H 9D KD
2D 3D 5C JH AC
2H 6D 7D 9C QD
3C 7C 7H JC KS
4C 9H JS QS AS
4D 5D 8H 10C QC
4H 5H JD QH AH
6C 8C 10H KH AD
8D 9S 10D 10S KC
<-----------------------------------------------------------------------------
After using custom parse_rank function
3C 7C 7H JC KS
8D 9S 10D 10S KC
4C 9H JS QS AS
4H 5H JD QH AH
6C 8C 10H KH AD
2D 3D 5C JH AC
2C 3H 6H 9D KD
2H 6D 7D 9C QD
4D 5D 8H 10C QC

#case 3 --shuffle at second position
Printing out the deck after initial construction
2C
3C
4C
5C
6C
7C
8C
9C
10C
JC
QC
KC
AC
AD
KD
QD
JD
10D
9D
8D
7D
6D
5D
4D
3D
2D
2H
3H
4H
5H
6H
7H
8H
9H
10H
JH
QH
KH
AH
AS
KS
QS
JS
10S
9S

<----------------------------------------------------------------------------->
Printing out the deck after shuffle
10S
4D
3C
QC
2H
AC
8D
6C
7D
9C
7C
KD
4C
9H
10H
5C
2D
KC
QD
5H
JD
QH
9S
KH
9D
JH
QS
2C
5D
AH
8H
JS
7H
6H
3D
3H
AD
4H
KS
10C
8C
6D
AS
10D
JC

Remaining Deck contents after Insertion
Empty Deck
<----------------------------------------------------------------------------->
Each hand contents after Insertion
3H 7D JC QS KC
2D 3D 6C 10D JH
5C 6H 8D 9D AS
6D 7H 10H KH AC
2H 8C 9H 9S JS
4C 8H 10C QC QH
3C JD KD KS AH
4D 4H 5D 5H 7C
2C 9C 10S QD AD
<----------------------------------------------------------------------------->
After Sorting using member-method operator<
2C 9C 10S QD AD
2D 3D 6C 10D JH
2H 8C 9H 9S JS
3C JD KD KS AH
3H 7D JC QS KC
4C 8H 10C QC QH
4D 4H 5D 5H 7C
5C 6H 8D 9D AS
6D 7H 10H KH AC
<----------------------------------------------------------------------------->
After using custom parse_rank function
4D 4H 5D 5H 7C
3C JD KD KS AH
4C 8H 10C QC QH
2H 8C 9H 9S JS
5C 6H 8D 9D AS
2C 9C 10S QD AD
6D 7H 10H KH AC
3H 7D JC QS KC
2D 3D 6C 10D JH


#Case4--Catch the error in load
1) command line input/outputs
C:\Users\Seed\Dropbox\Spring 2015\C++332\Labs\lab2\Lab2_3\Debug>lab2_1.exe haha
ERROR OPENING YOUR FILE BRO
2) echo return value
C:\Users\Seed\Dropbox\Spring 2015\C++332\Labs\lab2\Lab2_3\Debug>echo %errorlevel
%
1

so our excpetion is correctly cahugt and eventaully 1 is returned by the main function

===============================================================================================================================

Extra Credit
