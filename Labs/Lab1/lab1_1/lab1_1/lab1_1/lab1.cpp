#include "stdafx.h"
#include "hand.h"
#include <iostream>
#include "lab1.h"
#include <fstream>
#include<string>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include<algorithm>


using namespace std;




int ParseFile_hand(vector<Card> &deck, char * FileName)
/*Function to parse a file (for example card_file.txt) containing text (character) strings that define different playing cards (we'll call these "card definition strings").
pre: pass in two parameters, (alias) vector of card objects and a string (filename)
post: update the passed in vector (by pushing in valid card objects)

*/
{

	// mymap is a dictionary to translate the string found in "card file" to Rank type and Suite type (int defined by enumrations)
	map<string, int> mymap;
	mymap["2"] = two;
	mymap["3"] = three;
	mymap["4"] = four;
	mymap["5"] = five;
	mymap["6"] = six;
	mymap["7"] = seven;
	mymap["8"] = eight;
	mymap["9"] = nine;
	mymap["10"] = ten;
	mymap["J"] = jack;
	mymap["Q"] = queen;
	mymap["K"] = king;
	mymap["A"] = ace;
	mymap["j"] = jack;
	mymap["q"] = queen;
	mymap["k"] = king;
	mymap["a"] = ace;
	mymap["C"] = clubs;
	mymap["S"] = spades;
	mymap["H"] = hearts;
	mymap["D"] = diamonds;
	mymap["c"] = clubs;
	mymap["s"] = spades;
	mymap["h"] = hearts;
	mymap["d"] = diamonds;

	// open file
	string line, word,test;
	ifstream infile;
	infile.open(FileName);
	//CHeck for Eroor
	if (infile.fail()){
		cerr << "ERROR OPENING YOUR FILE BRO" << endl;
		return FAILURE_OPENING_FILE;
	}
	// Process for parsing process




	while (infile.good()){
		// This outer while loop first check whether we reach the last line
		// if not, variable line will hold the current line ( a string)
		getline(infile, line);
		istringstream current(line);
		istringstream test_line(line);
		//check for the number of valid card strings
		int line_counter = 0;
		
		//////////////////////////////////////////////////////////////////////////////
		//Testing the validty of the line
		
		while (test_line >> test){
			//cout << test << endl;
			
			if (test == "//"){ break; }
			int test_size = test.size();
			//cout << "my size:" << test_size << endl;
			string srank_test, ssuite_test;
			if (test_size != 3 && test_size != 2){
				continue;
			}
			else if (test_size==3) {
				srank_test = test.substr(0, 2);
				ssuite_test = test[2];

				// CHeck whether the suit and rank are valid ( weahter in our dictionary mymap)
				// notify the user using warning and move on
				if (mymap.find(ssuite_test) == mymap.end()){
					//cerr << "Warning!!! Push onto deck: invalid string element: invalid suite and rank" << endl;
					continue;
				}
				if (mymap.find(srank_test) == mymap.end()){

					//cerr << "Warning!!! Push onto deck: invalid string element: invalid rank" << endl;
					continue;
				}
				if (mymap.find(ssuite_test) == mymap.end()){
					//cerr << "Warning!!! Push onto deck: invalid string element: invalid suite" << endl;
					continue;
				}
				line_counter++;

			}
			else{
				srank_test = test[0];
				ssuite_test = test[1];
				// check weather suit and rank are valid
				if (mymap.find(srank_test) == mymap.end()){
					//cerr << "Warning!!! Push onto deck: invalid string element type 3_a" << endl;
					continue;
				}
				if (mymap.find(ssuite_test) == mymap.end()){
					//cerr << "Warning!!! Push onto deck: invalid string element type 3_b" << endl;
					continue;
				}
				line_counter++;
			}
			
		}
		/////////////////////////////////////////////////////////////////////////////////
		

		
		
		if (line_counter == 5){
			
			
			while (current >> word){
				if (word == "//"){
					break;
				}

				// the inner loop go through each line
				string srank, ssuite;
				int this_rank, this_suite;
				int temp = word.size();
				//Check weather it is a valid card string
				// it is valid if it is either 3 or 2 characters long
				if (temp != 3 && temp != 2){
					// notify the user if it is not a valid card string
					cerr << "Warning!!!Push onto deck: invalid string element type: invalid length" << endl;
					// after notification, move on
					continue;
				}
				// Now, there are two cases for valid card string, length 2 ( with rank 10 card) and length 3

				else if (temp == 3){
					// if length is three
					// get the corresponding rank and suites
					srank = word.substr(0, 2);
					ssuite = word[2];

					// CHeck whether the suit and rank are valid ( weahter in our dictionary mymap)
					// notify the user using warning and move on
					if (mymap.find(ssuite) == mymap.end()){
						cerr << "Warning!!! Push onto deck: invalid string element: invalid suite and rank" << endl;
						continue;
					}
					if (mymap.find(srank) == mymap.end()){

						cerr << "Warning!!! Push onto deck: invalid string element: invalid rank" << endl;
						continue;
					}
					if (mymap.find(ssuite) == mymap.end()){
						cerr << "Warning!!! Push onto deck: invalid string element: invalid suite" << endl;
						continue;
					}
					// update the correct rank and suite info
					this_rank = mymap[srank];
					this_suite = mymap[ssuite];
				}
				// the case for length 2 card string
				else{
					srank = word[0];
					ssuite = word[1];
					// check weather suit and rank are valid
					if (mymap.find(srank) == mymap.end()){
						cerr << "Warning!!! Push onto deck: invalid string element type 3_a" << endl;
						continue;
					}
					if (mymap.find(ssuite) == mymap.end()){
						cerr << "Warning!!! Push onto deck: invalid string element type 3_b" << endl;
						continue;
					}
					// update the correct rank and suite info
					this_rank = mymap[srank];
					this_suite = mymap[ssuite];
				}
				// create the correct card object use correct suite and rank info
				// push it to the deck
				Card this_card = { Rank(this_rank), Suite(this_suite) };
				deck.push_back(this_card);
			}

			
		}
		continue;
		
	}
	// this will notify the user about how many card are created and stored for the given file after parsing
	cout << "the size of the deck is " << deck.size() << endl;
	infile.close();
	return SUCCESS;

}


int sorthand_vector(const vector<Card>&deck){
	map<int, string> trans;
	trans[two] = "Two";
	trans[three] = "Three";
	trans[four] = "Four";
	trans[five] = "Five";
	trans[six] = "Six";
	trans[seven] = "Seven";
	trans[eight] = "Eight";
	trans[nine] = "Nine";
	trans[ten] = "Ten";
	trans[jack] = "Jack";
	trans[queen] = "Queen";
	trans[king] = "King";
	trans[ace] = "Ace";
	trans[clubs] = "Clubs";
	trans[spades] = "Spades";
	trans[hearts] = "Hearts";
	trans[diamonds] = "Diamonds";
	int deck_size = deck.size();
	int end_index = 0;
	int start_index = -5;
	vector<Hand> sort_hand;
	while (end_index < deck_size){

		start_index = start_index + 5;
		end_index = end_index + 5;
		cout << start_index << endl;
		/*
		cout << "////////////////////////////" << endl;
		cout << start_index << endl;
		cout << "/////////////////////////" << endl;
		*/
		//temp holder
		vector<Card> hand_deck(deck.begin() + start_index, deck.begin() + start_index + 5);

		//helper vector:intialize with five zero

		vector<int> helper(5, 0);
		sort(hand_deck.begin(), hand_deck.end());

		for (int i = 0; i < 5; i++){
			int leading_count = 0;

			for (int j = i + 1; j < 5; j++){


				if (hand_deck[i].rank_ == hand_deck[j].rank_) {

					leading_count++;
				}
			}
			helper[i] = leading_count;
		}

		sort(helper.begin(), helper.end());






		//Check for four of a kind
		if (helper[4] == 3)
		{
			Hand_rank temp = fourofkind;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
			continue;

		}

		if (helper[4] == 2){
			//Check for full house
			if (helper[3] == 1 && helper[2] == 1){
				Hand_rank temp = full_house;
				Hand this_hand(hand_deck, temp);
				sort_hand.push_back(this_hand);
				continue;
			}
			// check for three of a kind
			Hand_rank temp = three_of_kind;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
			continue;
		}
		
		if (helper[4] == 1){
			//check for two pairs
			if (helper[3] == 1){
				Hand_rank temp = two_pars;
				Hand this_hand(hand_deck, temp);
				sort_hand.push_back(this_hand);
				continue;
				
			}
			Hand_rank temp = one_pair;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
			
			continue;
		}


		//check flush (but wait for checking straight flush)
		bool isflush = false;
		for (int fit = 0; fit < 5; fit++){
			isflush = hand_deck[0].suit_ == hand_deck[fit].suit_;
		
		}

		//check straight ((but wait for checking straight flush)
		bool isstraight = false;
		for (int sit = 0; sit < 4; sit++){
			isstraight = hand_deck[sit + 1].rank_ == hand_deck[sit].rank_ + 1;
		}

		//check straight flush
		if ((isstraight&&isflush)){
			Hand_rank temp = straight_flush;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
			continue;
		}
		if (isflush){
			Hand_rank temp = flush_;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
		
			continue;
		}
		if (isstraight){
			Hand_rank temp = straight_;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
			continue;
			
		}
		Hand_rank temp = unranked;
		Hand this_hand(hand_deck, temp);
		sort_hand.push_back(this_hand);
		continue;

	}
	sort(sort_hand.rbegin(), sort_hand.rend());
	for (unsigned int i = 0; i < sort_hand.size(); i++){
		cout << sort_hand[i].str() << endl;
	}
	
	return SUCCESS;
}
int hand_vector(const vector<Card>&deck){
	map<int, string> trans;
	trans[two] = "Two";
	trans[three] = "Three";
	trans[four] = "Four";
	trans[five] = "Five";
	trans[six] = "Six";
	trans[seven] = "Seven";
	trans[eight] = "Eight";
	trans[nine] = "Nine";
	trans[ten] = "Ten";
	trans[jack] = "Jack";
	trans[queen] = "Queen";
	trans[king] = "King";
	trans[ace] = "Ace";
	trans[clubs] = "Clubs";
	trans[spades] = "Spades";
	trans[hearts] = "Hearts";
	trans[diamonds] = "Diamonds";
	int deck_size = deck.size();
	int end_index = 0;
	int start_index = -5;

	while (end_index < deck_size){

		start_index = start_index + 5;
		end_index = end_index + 5;

		cout << "////////////////////////////" << endl;
		cout << start_index << endl;
		cout << "/////////////////////////" << endl;
		//temp holder
		vector<Card> hand_deck(deck.begin() + start_index, deck.begin() + start_index+5);

		//helper vector:intialize with five zero
		
		vector<int> helper(5, 0);
		sort(hand_deck.begin(), hand_deck.end());

		for (int i = 0; i < 5; i++){
			int leading_count=0;
			
			for (int j = i+1; j < 5; j++){
				
				
				if (hand_deck[i].rank_ == hand_deck[j].rank_) {
					
					leading_count++; 
				}
			}
			helper[i] = leading_count;
		}
		
		sort(helper.begin(), helper.end());






		//Check for four of a kind
		if (helper[4]==3)
		{
			std::cout << start_index << " to " << end_index << " : " << "is four of a kind" << endl;
			continue;

		}

		if (helper[4] == 2){
			//Check for full house
			if (helper[3] == 1&&helper[2]==1){ cout << start_index << " to " << end_index << " : " << "is a full house" << endl; continue; }
			// check for four of a kind
			cout << start_index << " to " << end_index << " : " << "is three of a kind" << endl;
			continue; 
		}

		if (helper[4] == 1){
			if (helper[3] == 1){ cout << start_index << " to " << end_index << " : " << "is two pairs" << endl; continue; }
			cout << start_index << " to " << end_index << " : " << "is one pair" << endl;
			continue;
		}
		
		
		//check flush (but wait for checking straight flush)
		bool isflush=false;
		for (int fit = 0; fit < 5; fit++){
		 isflush = hand_deck[0].suit_ == hand_deck[fit].suit_;
		 continue;
		}
		
		//check straight ((but wait for checking straight flush)
		bool isstraight=false;
		for (int sit = 0; sit < 4; sit++){
			isstraight = hand_deck[sit + 1].rank_ == hand_deck[sit].rank_ + 1;
			continue;
		}

		//check straight flush
		if ( (isstraight&&isflush) ){
			cout << start_index << " to " << end_index << " : " << "is straight flush" << endl;
			continue;
		}
		if (isflush){
			cout << start_index << " to " << end_index << " : " << "is  flush" << endl;
			continue;
		}
		if (isstraight){
			cout << start_index << " to " << end_index << " : " << "is  straight" << endl;
			continue;
		}
		string rank = trans[hand_deck[4].rank_];
		string suit = trans[hand_deck[4].suit_];
			cout << start_index << " to " << end_index << " : " << "No rank. The leading card is: " << rank<<" of "<<suit<< endl;
	
	}

	return SUCCESS;
}
int print_vector(const vector<Card> & deck){
	/*
	Note: in the design, an empty deck won't be considred as an error but only a warning
	a function for printing out a vector of card structs to the standard output stream.
	pre:take a reference to a const vector of card structs (of type const vector<Card> &) as its only parameter
	post: print out valid card definition strings (with each string on its own line) for each of the card struct instances contained in the passed vector
	*/
	string rank, suit, word;
	//map trans is a dictionary that translates rank and suit type (int defined by enum) to the corresponding name eg. hearts (int) to "Hearts" (string) 
	map<int, string> trans;
	trans[two] = "Two";
	trans[three] = "Three";
	trans[four] = "Four";
	trans[five] = "Five";
	trans[six] = "Six";
	trans[seven] = "Seven";
	trans[eight] = "Eight";
	trans[nine] = "Nine";
	trans[ten] = "Ten";
	trans[jack] = "Jack";
	trans[queen] = "Queen";
	trans[king] = "King";
	trans[ace] = "Ace";
	trans[clubs] = "Clubs";
	trans[spades] = "Spades";
	trans[hearts] = "Hearts";
	trans[diamonds] = "Diamonds";

	// check if it is a empty deck
	// if empty, print out a warning and return NULL_DECK(int 3)
	if (deck.size() == 0){
		cerr << "Warning!!! printing deck: the deck is empty" << endl;
	}
	// iterate through the deck (vector) and print out the card

	for (unsigned int x = 0; x != deck.size(); ++x){
		// use map trans to translate suite and type to meaningful strings
		rank = trans[deck[x].rank_];
		suit = trans[deck[x].suit_];

		std::cout << "Card " << x + 1 << ":" << rank << " of " << suit << endl;
	}
	return SUCCESS;
}
//////////////////////////////////////////////////////////////////
int usage_message(char* filename){
	/*
	usage message" function that (1) prints out (to the program's standard output stream) the program's name followed by a helpful usage message
	telling the user how to run the program correctly (with the name of the program and the name of a file to read, e.g., lab0 card_file.txt),
	and (2) returns a non-zero value (int 2).*/
	cerr << "usage: " << filename << " <input_file_name>" << "is incorrect" << endl;
	cerr << "plesae enter a valid file name (file must be at the same directory) directly follow the program name using the command line" << endl;
	cerr << "for example: " << "lab0_Seed.exe card_file.txt" << endl;
	// return int 2
	return WRONG_NUMBER_ARGUMENTS;
}

int main(int argc, char* argv[])
/*
the main functions carries out three tasks
(1): check that exactly one argument has been passed to the program.If not, the program  calls the usage message function and return the value returned from that call.
(2): create a vecotr
(3): parse the given file and store cards to the vector
(4): print out the updated vector
*/
{
///////////////////////////////////
	/* 
	Card card1 = { Rank(5), Suite(14) };
	Card card2 = { Rank(6), Suite(14) };
	Card card3 = { Rank(5), Suite(18) };
	cout <<( card1 < card2 )<< endl;
	cout << (card1 < card3) << endl;
	cout << true << endl;
	*/
////////////////////////////////////

	
	if (argc != 2)
	{
		// if not, usage_message called to print out guidance for user and return the corresponding error type (int)
		int error = usage_message(argv[Program_name]);
		return error;
	}

	//the user passed in correct number of arguments
	else{
		vector<Card> deck;
		// parse the file and print out the updated vector ( and returing the corresponding error/sucess (int) )
		int i = ParseFile_hand(deck, argv[command_name]);
		//print_vector(deck);
		sorthand_vector(deck);
		std::cout << "///////////////////////////////////" << endl;
		std::cout << "Finish Recoganizing hands" << endl;
		std::cout << "///////////////////////////////////" << endl;
		sort(deck.begin(), deck.end());
		//print_vector(deck);
		return 0;
	}
	
}

