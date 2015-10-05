#include "stdafx.h"

#include <iostream>
#include "lab0.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>

using std::vector;
using namespace std;

int ParseFile(vector<Card> &deck, char * FileName)
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
	string line, word;
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

		while (current >> word){
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
				if (mymap.find(ssuite)==mymap.end()){
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
	// this will notify the user about how many card are created and stored for the given file after parsing
	cout << "the size of the deck is " << deck.size() << endl;
	infile.close();
	return SUCCESS;

}

int print_vector(const vector<Card> & deck){
	/* 
    Note: in the design, an empty deck won't be considred as an error but only a warning
	a function for printing out a vector of card structs to the standard output stream.
	pre:take a reference to a const vector of card structs (of type const vector<Card> &) as its only parameter
	post: print out valid card definition strings (with each string on its own line) for each of the card struct instances contained in the passed vector
	*/
	string rank,suit,word;
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

		cout << "Card " << x+1 << ":" << rank << " of "<< suit << endl;
	}
	return SUCCESS;
}
//////////////////////////////////////////////////////////////////
int usage_message(char* filename){
	/*
	usage message" function that (1) prints out (to the program's standard output stream) the program's name followed by a helpful usage message 
	telling the user how to run the program correctly (with the name of the program and the name of a file to read, e.g., lab0 card_file.txt), 
	and (2) returns a non-zero value (int 2).*/
	cerr << "usage: " << filename<< " <input_file_name>" <<"is incorrect"<< endl;
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

	// check weather the commandline arugments are valid (length 2)
	if (argc != 2)
	{
		// if not, usage_message called to print out guidance for user and return the corresponding error type (int)
		int error = usage_message(argv[Program_name]);
		return error;
	}

	//the user passed in correct number of arguments
	else{
		
	   // create vector deck
		vector<Card> deck;
		// parse the file and print out the updated vector ( and returing the corresponding error/sucess (int) )
	    int i = ParseFile(deck, argv[command_name]);
		 print_vector(deck);
		 return i;

	}
	
	
}

