========================================================================
                     CSE332        Lab4
========================================================================

/////////////////////////////////////////////////////////////////////////////
                            Lab4 Info
/////////////////////////////////////////////////////////////////////////////
(1) Team
    Jing Lu
	Seed(Peiyun) Zeng

(2) Files submitted
    Card.h and Card.cpp: Card class header and implementation
	Hand.h and Hand.cpp: Hand class header and implementation
	Deck.h and Deck.cpp: Deck class header and implementation
	Player.h and Player.cpp: Player header and implementation
	Game.h and Game.cpp: Game header and implementation
	FiveCardDraw.h and FiveCardDraw.cpp: FiveCardDraw header and implementation
	SevenCardStud.h and SevenCardStud.cpp: SevenCardStud header and implementation
	TexasHoldEm.h and TexasHoldEm.cpp: TexasHoldEm header and implementation
	Error.h: define different error level
	Functions.h and Functions.cpp: utility functions
	PlayerState.h: define different player status
	lab4.cpp: main function


(3) Usage
    Type:  lab4.exe FiveCardDraw <p1's name> <p2's name> ....
	    or lab4.exe SevenCardStud <p1's name> <p2's name> ....
		or lab4.exe TexasHoldEm <p1's name> <p2's name> ....

	Note that
	    (1) Command line arguments need to contain at least two players to start the game
		(2) Game name should contains "FiveCardDraw", "SevenCardStud", or "TexasHoldEm"
		(3) If run on Linux, comment out #include "stdax.h" 

(4) Compile and Execution
    No errors or warnings found

(5) Extra Credit
    Please see TexasHoldEm.h and TexasHoldEm.cpp




/////////////////////////////////////////////////////////////////////////////
                       Modification
/////////////////////////////////////////////////////////////////////////////
Card: add member variable faceup and isShared for SevenCardStud and TexasHoldEm
Hand: add methods related to adding cards to hand
Game: recognize SevenCardStud and TexasHoldEm game
Functions: add utility functions in functions.h
PlayerState: define player's different status
FiveCardDraw: add betting feature to the game
SevenCardStud: implement SevenCardStud game
TexasHoldEm: implement TexasHoldEm game


/////////////////////////////////////////////////////////////////////////////
                        Some Design Ideas
/////////////////////////////////////////////////////////////////////////////
(1) Notice that sometimes chips in the pot cannot be split into integer values. So we take the floor of the value
if it cannot be divided into integer value. So the pot cannot be divided into integer value, after spliting the chips in
pot to winners. we reset the number of chips in pot to zero

(2) In the SevenCardStud game, player's own cards will be visible to him. If other players have any facedown cards,
those cards will be displayed as "**"

(3) In the TexasHoldEm game, player will see his own cards in his own turn but he cannot see other player's private cards.
In his turn, he will see shared cards by all players.

(4) When a round of current game ends, after some players leave the game, if number of remaining players is less than 2, then the program
stops the current game and ask if user wants to create a new game or quit the program 

/////////////////////////////////////////////////////////////////////////////
                       Some notes about usage
/////////////////////////////////////////////////////////////////////////////

(1) About discarding the card: 

When the program asks if the player wants to discard cards, user can enter multiple positions of card
(position starting from 0, NOT 1). 


If user enters some invalid input(such as invalid position, non-numerical values),
only invalid input will be ignored and other inputs will still be processed.

If user inputs are all invalid, program will prompt the user again

If user does not want to discard any card, just enter "Enter"

(2) About joining and leaving the game:

When the program asks if the player wants to join or leave the game, user can enter multiple player names 
and those names will all be processed.
If no one wants to join or leave the room, type "no"


(3) About exiting the game:

When there is only one player left in the game, the program automatically saves that player's statistics to a file
and end the game


/////////////////////////////////////////////////////////////////////////////
                       Testing on FiveCardDraw
/////////////////////////////////////////////////////////////////////////////



*************************** Test 1 ******************************
********************* Test normal case(bet, call, etc) *********
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------

Z:\jinglu\winprofile\desktop\lab4_Comment&&Readme\Debug>lab4 FiveCardDraw jing s
eed
// First betting phase  //
-------------- Betting Start -----------
Here is your hand babe
2C 3H 8D JD KD
seed: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
2
---------- Someone bets ---------------
Chips in pot: 2
Current bet value 2
----------------- Player jing Start--------------------
-------------------Game status before making decision --------------------------
-
Current chips in the pot: 2
Current bet value: 2
Player's bet so far:  0
your hand is:
2D 5C 6C JC QD
jing: Do you want to fold, call or raise ?
raise
Amount to raiase:
2
-------------------Game status after making decision ---------------------------

Current chips in the pot: 2
Current bet value: 4
Player's bet so far:  4
Player's chip count: 19
----------------- Player jing End --------------------

----------------- Player seed Start--------------------
-------------------Game status before making decision --------------------------
-
Current chips in the pot: 2
Current bet value: 4
Player's bet so far:  2
your hand is:
2C 3H 8D JD KD
seed: Do you want to fold, call or raise ?
call
-------------------Game status after making decision ---------------------------

Current chips in the pot: 2
Current bet value: 4
Player's bet so far:  4
Player's chip count: 19
----------------- Player seed End --------------------

-------------- Betting End -----------
seed 2C 3H 8D JD KD
Please give positions of cards you want to discard
0
jing 2D 5C 6C JC QD
Please give positions of cards you want to discard
1
seed 3H 8D 9H JD KD
jing 2D 5H 6C JC QD
// second betting phase  //
-------------- Betting Start -----------
Here is your hand babe
2D 5H 6C JC QD
jing: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
1
---------- Someone bets ---------------
Chips in pot: 10
Current bet value 1
----------------- Player seed Start--------------------
-------------------Game status before making decision --------------------------
-
Current chips in the pot: 10
Current bet value: 1
Player's bet so far:  0
your hand is:
3H 8D 9H JD KD
seed: Do you want to fold, call or raise ?
raise
Amount to raiase:
1
-------------------Game status after making decision ---------------------------

Current chips in the pot: 10
Current bet value: 2
Player's bet so far:  2
Player's chip count: 15
----------------- Player seed End --------------------

----------------- Player jing Start--------------------
-------------------Game status before making decision --------------------------
-
Current chips in the pot: 10
Current bet value: 2
Player's bet so far:  1
your hand is:
2D 5H 6C JC QD
jing: Do you want to fold, call or raise ?
call
-------------------Game status after making decision ---------------------------

Current chips in the pot: 10
Current bet value: 2
Player's bet so far:  2
Player's chip count: 15
----------------- Player jing End --------------------

-------------- Betting End -----------

////////////////////////////////////////
------------Game Results---------------
winner: seed
------------
seed 1 0 15

3H 8D 9H JD KD
------------
------------
jing 0 1 15

2D 5H 6C JC QD
------------

//////////////////////////////////////////////////
------------ --- Betting Stats ----------
----------------------
Player Name: jing
Win: 0
Loss: 1
Chip Count: 13
Chip Bet: 2
Player Hand: 2D 5H 6C JC QD
//////////////////////////////////////////////
----------------------
Player Name: seed
Win: 1
Loss: 0
Chip Count: 27
Chip Bet: 2
Player Hand: 3H 8D 9H JD KD
//////////////////////////////////////////////
Anyone wants to leave?

----- game ends here -----


----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------
Before betting, jing and seed each puts one chip into the pot and chips count in pot is 2.
Both seed's and jing's chip count is 19.

During first betting phase, seed first bets 2, then jing raises the bet by 2(i.e current bet is 4).
Then seed calls and this betting phase ends. Now jing and seed each puts 4 chips into the pot and
pot has 2+4+4=10 chips after first betting. So jing's chip count is 15 and seed's chip count is 15.

Then seed discards card at position 0 and jing discarads card at position 1.

During the second betting phase, jing first bets 1, and seed raises by 1(i.e current bet is 2).
Then seed calls and this betting phase ends. Now jing and seed each puts 2 chips into the pot and
pot has 10+2+2=14 chips after second betting .So jing's chip count is 13 and seed's chip count is 13.

At the end of the round, seed wins the game. So seed gets 13+14=27 chips and jing gets 13 chips.

************************** Test 1 End********************************



*************************** Test 2 *********************************
*********************** Test fold  operation  *************************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------
Z:\jinglu\winprofile\desktop\lab4_Comment&&Readme\Debug>lab4 FiveCardDraw jing
eed
// First betting phase  //
-------------- Betting Start -----------
Here is your hand babe
3C 4C 6D 9H 10H
seed: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
1
---------- Someone bets ---------------
Chips in pot: 2
Current bet value 1
----------------- Player jing Start--------------------
-------------------Game status before making decision -------------------------
-
Current chips in the pot: 2
Current bet value: 1
Player's bet so far:  0
your hand is:
2H 8H 10C QH KH
jing: Do you want to fold, call or raise ?
fold
-------------------Game status after making decision --------------------------

Current chips in the pot: 2
Current bet value: 1
Player's bet so far:  0
Player's chip count: 19
----------------- Player jing End --------------------

Result: all players except one decide to fold; entire pot is awarded to the rem
ining player
seed 3C 4C 6D 9H 10H
jing 2H 8H 10C QH KH
// second betting phase  //
-------------- Betting Start -----------
Here is your hand babe
3C 4C 6D 9H 10H
seed: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
1
---------- Someone bets ---------------
Chips in pot: 0
Current bet value 1
-------------- Betting End -----------

////////////////////////////////////////
------------Game Results---------------
winner: jing
------------
jing 1 0 19

2H 8H 10C QH KH
------------
------------
seed 0 1 21

3C 4C 6D 9H 10H
------------

//////////////////////////////////////////////////
------------ --- Betting Stats ----------
----------------------
Player Name: jing
Win: 1
Loss: 0
Chip Count: 19
Chip Bet: 0
Player Hand: player folded without showing down their hand
//////////////////////////////////////////////
----------------------
Player Name: seed
Win: 0
Loss: 1
Chip Count: 21
Chip Bet: 1
Player Hand: 3C 4C 6D 9H 10H
//////////////////////////////////////////////
Anyone wants to leave?

----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------
Before betting, jing and seed each puts one chip into the pot and chips count in pot is 2.
Both seed's and jing's chip count is 19.

During first betting phase, seed first bets 1, then jing decides to fold and therefore is out of
this round. Since all players except seed do not fold, all chips(2 chips) in the pot will be given to seed
no matter whatever the result is. 

The second phase ends immediately after seed bets something(final result won't change)

Notice that jing has higher rank than seed, but seed gets 2 chips in the pot because jing decides to fold.
In the end, seed has 19+2=21 chips and jing has 19 chips.

************************** Test 2 End********************************





*************************** Test 3 *********************************
*********************** Test check operation  *************************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------
Z:\jinglu\winprofile\desktop\lab4_Comment&&Readme\Debug>lab4 FiveCardDraw jing s
eed
// First betting phase  //
-------------- Betting Start -----------
Here is your hand babe
3H 6D 6H 7C 9D
seed: do you want to check or bet ?
check
Here is your hand babe
2H 3C 3D 5D 8D
jing: do you want to check or bet ?
check
-------------- Betting End -----------
seed 3H 6D 6H 7C 9D
Please give positions of cards you want to discard
0
jing 2H 3C 3D 5D 8D
Please give positions of cards you want to discard
1
seed 6C 6D 6H 7C 9D
jing 2H 3D 5D 8D JC
// second betting phase  //
-------------- Betting Start -----------
Here is your hand babe
6C 6D 6H 7C 9D
seed: do you want to check or bet ?
check
Here is your hand babe
2H 3D 5D 8D JC
jing: do you want to check or bet ?
check
-------------- Betting End -----------

////////////////////////////////////////
------------Game Results---------------
winner: seed
------------
seed 1 0 19

6C 6D 6H 7C 9D
------------
------------
jing 0 1 19

2H 3D 5D 8D JC
------------

//////////////////////////////////////////////////
------------ --- Betting Stats ----------
----------------------
Player Name: jing
Win: 0
Loss: 1
Chip Count: 19
Chip Bet: 0
Player Hand: 2H 3D 5D 8D JC
//////////////////////////////////////////////
----------------------
Player Name: seed
Win: 1
Loss: 0
Chip Count: 21
Chip Bet: 0
Player Hand: 6C 6D 6H 7C 9D
//////////////////////////////////////////////
Anyone wants to leave?
----- game ends ------


----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------
Before betting, jing and seed each puts one chip into the pot and chips count in pot is 2.
Both seed's and jing's chip count is 19.

During the first betting phase, both seed and jing decide to check without risking any chips.
During the second betting phase, both seed and jing decide to check.

In the end, seed has higher rank than jing. So seed gets chips from the pot and therefore gets
19+2=21 chips. Jing gets 19 chips.

************************** Test 3 End********************************



*************************** Test 4 *********************************
****************** Test zero chip count from file  *************************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------
Z:\jinglu\winprofile\desktop\lab4_Comment&&Readme\Debug>lab4 FiveCardDraw jing s
eed
jing: Your chip count is 0
jing: Do you want to reset chip count or quit?
reset
// First betting phase  //
-------------- Betting Start -----------
Here is your hand babe
3C 4H 5C 6H 10D
seed: do you want to check or bet ?
check
Here is your hand babe
2D 6C 8C 9H QD
jing: do you want to check or bet ?
check
-------------- Betting End -----------
seed 3C 4H 5C 6H 10D
Please give positions of cards you want to discard
0
jing 2D 6C 8C 9H QD
Please give positions of cards you want to discard
0
seed 4D 4H 5C 6H 10D
jing 6C 8C 9H 10C QD
// second betting phase  //
-------------- Betting Start -----------
Here is your hand babe
4D 4H 5C 6H 10D
seed: do you want to check or bet ?
check
Here is your hand babe
6C 8C 9H 10C QD
jing: do you want to check or bet ?
check
-------------- Betting End -----------

////////////////////////////////////////
------------Game Results---------------
winner: seed
------------
seed 1 0 19

4D 4H 5C 6H 10D
------------
------------
jing 0 1 19

6C 8C 9H 10C QD
------------

//////////////////////////////////////////////////
------------ --- Betting Stats ----------
----------------------
Player Name: jing
Win: 0
Loss: 1
Chip Count: 19
Chip Bet: 0
Player Hand: 6C 8C 9H 10C QD
//////////////////////////////////////////////
----------------------
Player Name: seed
Win: 1
Loss: 0
Chip Count: 21
Chip Bet: 0
Player Hand: 4D 4H 5C 6H 10D
//////////////////////////////////////////////
Anyone wants to leave?



----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------
For this test, we have a file called jing.txt in which jing has 0 win, 0 loss and 0 chip.
The game will load jing's data from this file.

When jing joins the game, the program asks if jing wants to reset his chip count to 20 or
quit the game. After jing chooses to reset his chip count, everything works correctly as before.

************************** Test 4 End********************************




*************************** Test 5 *********************************
****************** Test zero chip count after a round  *************************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------
Z:\jinglu\winprofile\desktop\lab4_Comment&&Readme\Debug>lab4 FiveCardDraw jing s
eed
// First betting phase  //
-------------- Betting Start -----------
Here is your hand babe
2D 4C 9D JH KC
seed: do you want to check or bet ?
check
Here is your hand babe
5H 9H 10D JD QC
jing: do you want to check or bet ?
check
-------------- Betting End -----------
seed 2D 4C 9D JH KC
Please give positions of cards you want to discard
0
jing 5H 9H 10D JD QC
Please give positions of cards you want to discard
1
seed 2C 4C 9D JH KC
jing 5H 7D 10D JD QC
// second betting phase  //
-------------- Betting Start -----------
Here is your hand babe
2C 4C 9D JH KC
seed: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
1
---------- Someone bets ---------------
Chips in pot: 2
Current bet value 1
----------------- Player jing Start--------------------
-------------------Game status before making decision --------------------------
-
Current chips in the pot: 2
Current bet value: 1
Player's bet so far:  0
your hand is:
5H 7D 10D JD QC
jing: Do you want to fold, call or raise ?
call
-------------------Game status after making decision ---------------------------

Current chips in the pot: 2
Current bet value: 1
Player's bet so far:  1
Player's chip count: 1
----------------- Player jing End --------------------

-------------- Betting End -----------

////////////////////////////////////////
------------Game Results---------------
winner: seed
------------
seed 1 0 19

2C 4C 9D JH KC
------------
------------
jing 0 1 1

5H 7D 10D JD QC
------------

//////////////////////////////////////////////////
------------ --- Betting Stats ----------
----------------------
Player Name: jing
Win: 0
Loss: 1
Chip Count: 0
Chip Bet: 1
Player Hand: 5H 7D 10D JD QC
//////////////////////////////////////////////
----------------------
Player Name: seed
Win: 1
Loss: 0
Chip Count: 22
Chip Bet: 1
Player Hand: 2C 4C 9D JH KC
//////////////////////////////////////////////
jing: your chip count is 0
Do you want to quit the game or reset chip count to 20 and keep playing
Please enter quit or reset
reset
Anyone wants to leave?
---- game ends -------

----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------
For this test, we have a file called jing.txt in which jing has 0 win, 0 loss, 2 chips.
The game will load jing's data from this file.


Before betting, jing and seed each puts one chip into the pot and chips count in pot is 2.
Both seed's chip count is 19 and jing's chip count is 2-1=1.

During first betting phase, both seed and jing decide to check without risking any more chips.

During second betting phase, seed bets 1 and jing calls. So they both put 1 chip to the pot.
Now seed has 18 chips and jing has 0 chips. Now the pot has 2+2=4 chips.

In the end, seed has higher rank than jing and therefore gets 18+4=22 chips. Jing has 0 chips.

Notice that after this round, the program asks if jing wants to reset his chip count to 20 or quit the game.
After jing chooses to reset, game will continue as before.

************************** Test 5 End********************************






/////////////////////////////////////////////////////////////////////////////
                       Testing on SevenCardStud
/////////////////////////////////////////////////////////////////////////////

*************************** Test 1 *********************************
********************* Test normal case *****************************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------
Z:\jinglu\winprofile\desktop\lab4_Comment&&Readme\Debug>lab4 SevenCardStud se
jing
Begin First Phase--Calling first turn on players-----
End First Phase--Calling first turn on players-----
// First betting phase  //
-------------- Betting Start -----------
-------------------Players's cards ---------------------------
seed's cards: 2D 5D **
Your Card: ^_^
jing's cards: 8D QD 6H
--------------------------------------------------------------
jing: do you want to check or bet ?
check
-------------------Players's cards ---------------------------
jing's cards: 8D QD **
Your Card: ^_^
seed's cards: 2D 5D QH
--------------------------------------------------------------
seed: do you want to check or bet ?
check
------------ all players check -----------------
-------------- Betting End -----------
Begin Second Phase--Calling Second turn on players-----
End Second Phase--Calling Second turn on players-----
// Second betting phase  //
-------------- Betting Start -----------
-------------------Players's cards ---------------------------
seed's cards: 2D 5D ** 6D
Your Card: ^_^
jing's cards: 8D QD 6H 7D
--------------------------------------------------------------
jing: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
1
---------- Someone bets ---------------
Chips in pot: 2
Current bet value 1
----------------- Player seed Start--------------------
-------------------Players's cards ---------------------------
jing's cards: 8D QD ** 7D
Your Card: ^_^
seed's cards: 2D 5D QH 6D
--------------------------------------------------------------
-------------------Game status before making decision -----------------------
-
Current chips in the pot: 2
Current bet value: 1
Player's bet so far:  0
your status 0
seed: Do you want to fold, call or raise ?
call
-------------------Game status after making decision ------------------------

Current chips in the pot: 2
Current bet value: 1
Player's bet so far:  1
Player's chip count: 19
----------------- Player seed End --------------------

-------------- Betting End -----------
Begin Second Phase--Calling Second turn on players-----
End Second Phase--Calling Second turn on players-----
// Second betting phase  //
-------------- Betting Start -----------
-------------------Players's cards ---------------------------
seed's cards: 2D 5D ** 6D 7C
Your Card: ^_^
jing's cards: 8D QD 6H 7D 3C
--------------------------------------------------------------
jing: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
1
---------- Someone bets ---------------
Chips in pot: 4
Current bet value 1
----------------- Player seed Start--------------------
-------------------Players's cards ---------------------------
jing's cards: 8D QD ** 7D 3C
Your Card: ^_^
seed's cards: 2D 5D QH 6D 7C
--------------------------------------------------------------
-------------------Game status before making decision -----------------------
-
Current chips in the pot: 4
Current bet value: 1
Player's bet so far:  0
your status 0
seed: Do you want to fold, call or raise ?
call
-------------------Game status after making decision ------------------------

Current chips in the pot: 4
Current bet value: 1
Player's bet so far:  1
Player's chip count: 18
----------------- Player seed End --------------------

-------------- Betting End -----------
Begin Second Phase--Calling Second turn on players-----
End Second Phase--Calling Second turn on players-----
// Second betting phase  //
-------------- Betting Start -----------
-------------------Players's cards ---------------------------
seed's cards: 2D 5D ** 6D 7C 5C
Your Card: ^_^
jing's cards: 8D QD 6H 7D 3C KH
--------------------------------------------------------------
jing: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
1
---------- Someone bets ---------------
Chips in pot: 6
Current bet value 1
----------------- Player seed Start--------------------
-------------------Players's cards ---------------------------
jing's cards: 8D QD ** 7D 3C KH
Your Card: ^_^
seed's cards: 2D 5D QH 6D 7C 5C
--------------------------------------------------------------
-------------------Game status before making decision -----------------------
-
Current chips in the pot: 6
Current bet value: 1
Player's bet so far:  0
your status 0
seed: Do you want to fold, call or raise ?
call
-------------------Game status after making decision ------------------------

Current chips in the pot: 6
Current bet value: 1
Player's bet so far:  1
Player's chip count: 17
----------------- Player seed End --------------------

-------------- Betting End -----------
Begin Final Phase--Calling Second turn on players-----
// Final betting phase  //
-------------- Betting Start -----------
-------------------Players's cards ---------------------------
seed's cards: 2D 5D ** 6D 7C 5C **
Your Card: ^_^
jing's cards: 8D QD 6H 7D 3C KH 4H
--------------------------------------------------------------
jing: do you want to check or bet ?
check
-------------------Players's cards ---------------------------
jing's cards: 8D QD ** 7D 3C KH **
Your Card: ^_^
seed's cards: 2D 5D QH 6D 7C 5C 2H
--------------------------------------------------------------
seed: do you want to check or bet ?
check
------------ all players check -----------------
-------------- Betting End -----------
---------------Round Ends----------------


----------------------------Round Summary----------------------
/////////////////////////////////////////////
----------Player's original hands vs. best five cards ---------------
seed's original seven cards: 2D 5D QH 6D 7C 5C 2H
seed's best five cards: 2D 2H 5C 5D QH
jing's original seven cards: 8D QD 6H 7D 3C KH 4H
jing's best five cards: 6H 7D 8D QD KH
/////////////////////////////////////////////////////
///////////////////////////////////////////////
--------------Game Results------------
after loop
after sort
winner: seed
------------
seed 1 0 16

2D 5D QH 6D 7C 5C 2H
------------
------------
jing 0 1 16

8D QD 6H 7D 3C KH 4H
------------
split value 8
chips in pot: 8
////////////////////////////////////////////////
--------------Betting Stats ----------------------
----------------------
Player Name: seed
Win: 1
Loss: 0
Chip Count: 24
Chip Bet: 0
Player Hand:
2D 2H 5C 5D QH
////////////////////////////////////////////////
----------------------
Player Name: jing
Win: 0
Loss: 1
Chip Count: 16
Chip Bet: 0
Player Hand:
6H 7D 8D QD KH
////////////////////////////////////////////////
Anyone wants to leave?
------game ends---------


----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------
Before betting, jing and seed each puts one chip into the pot and chips count in pot is 2.
Both seed's and jing's chip count is 19.

In first turn, both players choose to check without adding more chips to the pot.

In second, third and fourth turn, one player chooses to bet 1 and another player will call.
So in each turn, each player will add 1 chip to the pot.
At the end of fourth turn, seed's and jing's chip count is both 19-1-1-1=16.
The pot has 2+(1+1+1)+(1+1+1)=8 chips.

In the final turn, both players choose to check without adding more chips to the pot.

In the end, seed's best five cards rank higher than jing. So seed gets 16+8=24 chips and jing gets 16 chips.

Notice that in the round summary, we print player's original cards and his best five cards.

************************** Test 1 End********************************




*************************** Test 2 *********************************
*********************  Test choosing five best cards ************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------

----------Player's original hands vs. best five cards ---------------
seed's original seven cards: 2D 5D QH 6D 7C 5C 2H
seed's best five cards: 2D 2H 5C 5D QH
jing's original seven cards: 8D QD 6H 7D 3C KH 4H
jing's best five cards: 6H 7D 8D QD KH
/////////////////////////////////////////////////////


----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------
For this test, we use the same program output in test1 but only focus on the choice of 
best five cards printed in the round summary section in the program output.

From seed's seven cards, it is best to choose two pairs.
From jing's seven cards, it is impossible to generate a combination of any higher ranking
combination than unrank.

************************** Test 2 End********************************


*************************** Test 3 *********************************
********************* Test displaying cards **********************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------
-------------- Betting Start -----------
-------------------Players's cards ---------------------------
seed's cards: 2D 5D **
Your Card: ^_^
jing's cards: 8D QD 6H
--------------------------------------------------------------
jing: do you want to check or bet ?
check
-------------------Players's cards ---------------------------
jing's cards: 8D QD **
Your Card: ^_^
seed's cards: 2D 5D QH
--------------------------------------------------------------
seed: do you want to check or bet ?
check

----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------
For this test, we choose the part(first turn) of the program output as in test 1.

Note that jing's turn, he is able to see all his cards but his cannot see seed's facedown cards.
Seed's facedown cards are displayed as ** to jing  

************************** Test 3 End********************************




*************************** Test 4 *********************************
******************** Test other operations ****************************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------
Please see program outputs in FiveCardDraw

----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------
As for testing other betting operations, the program output should be similar to FiveCardDraw.
This is because the betting implementation in SevenCardStud is the same as FiveCardDraw.

************************** Test 4 End********************************






----------------------------------------------------------------------------
                            Extra Credit
-----------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
                       Testing on TexasHoldEm
/////////////////////////////////////////////////////////////////////////////

*************************** Test 1 *********************************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------


Begin First Phase--Calling first turn on players-----
End First Phase--Calling first turn on players-----
// First betting phase  //
-------------- Betting Start -----------
after particpate
************  Shared Cards *********************

-------------------Players's cards ---------------------------
Your Card: ^_^
seed's cards: 9C 9D
--------------------------------------------------------------
seed: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
2
---------- Someone bets ---------------
Chips in pot: 2
Current bet value 2
after betting
----------------- Player jing Start--------------------
************  Shared Cards *********************

-------------------Players's cards ---------------------------
Your Card: ^_^
jing's cards: KC QH
--------------------------------------------------------------
-------------------Game status before making decision --------------------------
-
Current chips in the pot: 2
Current bet value: 2
Player's bet so far:  0
your status 0
jing: Do you want to fold, call or raise ?
call
-------------------Game status after making decision ---------------------------

Current chips in the pot: 2
Current bet value: 2
Player's bet so far:  2
Player's chip count: 19
----------------- Player jing End --------------------

-------------- Betting End -----------
Begin Second Phase--Calling Second turn on players-----
End Second Phase--Calling Second turn on players-----
// Second betting phase  //
-------------- Betting Start -----------
************  Shared Cards *********************
4C 8C 10C 10H JC QC
-------------------Players's cards ---------------------------
Your Card: ^_^
seed's cards: 9C 9D
--------------------------------------------------------------
seed: do you want to check or bet ?
check
************  Shared Cards *********************
4C 8C 10C 10H JC QC
-------------------Players's cards ---------------------------
Your Card: ^_^
jing's cards: KC QH
--------------------------------------------------------------
jing: do you want to check or bet ?
check
------------ all players check -----------------
-------------- Betting End -----------
Begin Final Phase--Calling Second turn on players-----
// Final betting phase  //
-------------- Betting Start -----------
************  Shared Cards *********************
4C 4D 4H 8C 10C 10H JC QC
-------------------Players's cards ---------------------------
Your Card: ^_^
seed's cards: 9C 9D
--------------------------------------------------------------
seed: do you want to check or bet ?
check
************  Shared Cards *********************
4C 4D 4H 8C 10C 10H JC QC
-------------------Players's cards ---------------------------
Your Card: ^_^
jing's cards: KC QH
--------------------------------------------------------------
jing: do you want to check or bet ?
check
------------ all players check -----------------
-------------- Betting End -----------
Begin Final Phase--Calling Second turn on players-----
// Final betting phase  //
-------------- Betting Start -----------
************  Shared Cards *********************
3D 4C 4D 4H 8C 10C 10H JC QC KH
-------------------Players's cards ---------------------------
Your Card: ^_^
seed's cards: 9C 9D
--------------------------------------------------------------
seed: do you want to check or bet ?
check
************  Shared Cards *********************
3D 4C 4D 4H 8C 10C 10H JC QC KH
-------------------Players's cards ---------------------------
Your Card: ^_^
jing's cards: KC QH
--------------------------------------------------------------
jing: do you want to check or bet ?
check
------------ all players check -----------------
-------------- Betting End -----------
---------------Round Ends----------------


----------------------------Round Summary----------------------
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////
--------------------------- Player's original hands vs. best five cards --------
-------------------------
jing's original seven cards: KC QH 10C 4C 10H 4H 3D
jing's best five cards: 4C 4H 10C 10H KC
seed's original seven cards: 9C 9D 8C QC JC 4D KH
seed's best five cards: 9C 9D JC QC KH
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////

///////////////////////////////////////////////
-----------------------Game Results----------------
winner: jing
------------
jing 1 0 17

KC QH 10C 4C 10H 4H 3D
------------
------------
seed 0 1 17

9C 9D 8C QC JC 4D KH
------------
split value 6
chips in pot: 6
///////////////////////////////////////////
------------- Betting Stats --------------
----------------------
Player Name: jing
Win: 1
Loss: 0
Chip Count: 23
Chip Bet: 0
Player Hand:
4C 4H 10C 10H KC
/////////////////////////////////////////////
----------------------
Player Name: seed
Win: 0
Loss: 1
Chip Count: 17
Chip Bet: 0
Player Hand:
9C 9D JC QC KH
/////////////////////////////////////////////
Anyone wants to leave?


----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------

seed goes first and choose to bet. Notice that when aksing user to bet, the shared cards are printed out. then jin check, fist phase ends. then two
players check for middle phase and final phse. then game ends. Jing win since he has two pairs. you can see that 
(1) Best five is selected correctly from the 7 cards
(2) the best five correctly decided the final result of the game

************************** Test 1 End********************************






*************************** Test 2 *********************************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------
g seed
Begin First Phase--Calling first turn on players-----
End First Phase--Calling first turn on players-----
// First betting phase  //
-------------- Betting Start -----------
after particpate
************  Shared Cards *********************

-------------------Players's cards ---------------------------
Your Card: ^_^
seed's cards: 2D 5C
--------------------------------------------------------------
seed: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
2
---------- Someone bets ---------------
Chips in pot: 2
Current bet value 2
after betting
----------------- Player jing Start--------------------
************  Shared Cards *********************

-------------------Players's cards ---------------------------
Your Card: ^_^
jing's cards: 4D 7D
--------------------------------------------------------------
-------------------Game status before making decision --------------------------
-
Current chips in the pot: 2
Current bet value: 2
Player's bet so far:  0
your status 0
jing: Do you want to fold, call or raise ?
fold
-------------------Game status after making decision ---------------------------

Current chips in the pot: 2
Current bet value: 2
Player's bet so far:  0
Player's chip count: 19
----------------- Player jing End --------------------

Result: all players except one decide to fold; entire pot is awarded to the rema
ining player
Error info: 20
---------------Round Ends----------------


----------------------------Round Summary----------------------
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////
--------------------------- Player's original hands vs. best five cards --------
-------------------------
jing's original seven cards:
jing's best five cards: 4D 7D
seed's original seven cards:
seed's best five cards: 2D 5C
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////

///////////////////////////////////////////////
-----------------------Game Results----------------
winner: jing
winner: seed
------------
jing 1 0 19


------------
------------
seed 1 0 21


------------
Result: all players except one decide to fold; entire pot is awarded to the rema
ining player
///////////////////////////////////////////
------------- Betting Stats --------------
----------------------
Player Name: seed
Win: 1
Loss: 0
Chip Count: 21
Chip Bet: 0
Player Hand:
2D 5C
/////////////////////////////////////////////
----------------------
Player Name: jing
Win: 1
Loss: 0
Chip Count: 19
Chip Bet: 0
Player Hand: player folded without showing down their hand
/////////////////////////////////////////////
Anyone wants to leave?


----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------
Seed first bet 2. Jing fold. Game ends as expcted
since jing fold. all the chips in the pot are awraed to awesome seed.
you can see all info printed correctly
************************** Test 2 End********************************








*************************** Test 3 *********************************
----------------------------------------------------------------------
                       Program Output
----------------------------------------------------------------------
Begin First Phase--Calling first turn on players-----
End First Phase--Calling first turn on players-----
// First betting phase  //
-------------- Betting Start -----------
after particpate
************  Shared Cards *********************

-------------------Players's cards ---------------------------
Your Card: ^_^
seed's cards: 8D 2H
--------------------------------------------------------------
seed: do you want to check or bet ?
check
************  Shared Cards *********************

-------------------Players's cards ---------------------------
Your Card: ^_^
jing's cards: 6C 6H
--------------------------------------------------------------
jing: do you want to check or bet ?
check
------------ all players check -----------------
after betting
-------------- Betting End -----------
Begin Second Phase--Calling Second turn on players-----
End Second Phase--Calling Second turn on players-----
// Second betting phase  //
-------------- Betting Start -----------
************  Shared Cards *********************
5H 9D 10C 10H JC QD
-------------------Players's cards ---------------------------
Your Card: ^_^
seed's cards: 8D 2H
--------------------------------------------------------------
seed: do you want to check or bet ?
bet
Do you want to bet 1 or 2 ?
2
---------- Someone bets ---------------
Chips in pot: 2
Current bet value 2
----------------- Player jing Start--------------------
************  Shared Cards *********************
5H 9D 10C 10H JC QD
-------------------Players's cards ---------------------------
Your Card: ^_^
jing's cards: 6C 6H
--------------------------------------------------------------
-------------------Game status before making decision --------------------------
-
Current chips in the pot: 2
Current bet value: 2
Player's bet so far:  0
your status 0
jing: Do you want to fold, call or raise ?
raise
Amount to raiase:
2
-------------------Game status after making decision ---------------------------

Current chips in the pot: 2
Current bet value: 4
Player's bet so far:  4
Player's chip count: 19
----------------- Player jing End --------------------

----------------- Player seed Start--------------------
************  Shared Cards *********************
5H 9D 10C 10H JC QD
-------------------Players's cards ---------------------------
Your Card: ^_^
seed's cards: 8D 2H
--------------------------------------------------------------
-------------------Game status before making decision --------------------------
-
Current chips in the pot: 2
Current bet value: 4
Player's bet so far:  2
your status 0
seed: Do you want to fold, call or raise ?
fold
-------------------Game status after making decision ---------------------------

Current chips in the pot: 4
Current bet value: 4
Player's bet so far:  2
Player's chip count: 17
----------------- Player seed End --------------------

Result: all players except one decide to fold; entire pot is awarded to the rema
ining player
Error info: 20
---------------Round Ends----------------


----------------------------Round Summary----------------------
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////
--------------------------- Player's original hands vs. best five cards --------
-------------------------
jing's original seven cards:
jing's best five cards: 6C 6H JC 5H QD
seed's original seven cards:
seed's best five cards: 8D 2H 9D 10C 10H
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////

///////////////////////////////////////////////
-----------------------Game Results----------------
winner: seed
------------
seed 1 0 17


------------
------------
jing 0 1 23


------------
Result: all players except one decide to fold; entire pot is awarded to the rema
ining player
///////////////////////////////////////////
------------- Betting Stats --------------
----------------------
Player Name: jing
Win: 0
Loss: 1
Chip Count: 23
Chip Bet: 0
Player Hand:
6C 6H JC 5H QD
/////////////////////////////////////////////
----------------------
Player Name: seed
Win: 1
Loss: 0
Chip Count: 17
Chip Bet: 2
Player Hand: player folded without showing down their hand
/////////////////////////////////////////////
Anyone wants to leave?



----------------------------------------------------------------------
                            Analysis
----------------------------------------------------------------------

Jing and Seed both check for first betting pahse.
Then in the middle phase. Jing bet and Seed raise 2. Then in final phase Jing fold
So Seed wins the game. Notice all info prined out correctly.
************************** Test 3 End********************************


