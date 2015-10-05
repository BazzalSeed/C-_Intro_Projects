#include "stdafx.h"
#include "hand.h"
#include "lab1.h"


using namespace std;




int ParseFile_hand(vector<Card> &deck, char * FileName)
/*Function to parse a file (for example card_file.txt) containing text (character) strings that define different playing cards
(1)reads a line at a time from the file,

(2)reads card definition strings from that line until it either reaches the end of the line or it sees a // (comment symbol) in the line,

(3)prints a warning message for any invalid card definition strings it sees but still continues processing the line if so,

(4)checks whether or not it read exactly 5 valid card definition strings from the line(if not move on)

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
	//CHeck for Eroor of opening the error
	if (infile.fail()){
		cerr << "ERROR OPENING YOUR FILE BRO" << endl;
		return FAILURE_OPENING_FILE;
	}
	// this counter is for indicating which line we are currently scanning, when printing out warning, we know which line we are at
	int lineindicator = 0;


	while (infile.good()){
		// This outer while loop first check whether we reach the last line
		// if not, variable line will hold the current line ( a string)
		lineindicator = lineindicator + 1;
		getline(infile, line);
		istringstream current(line);
		istringstream test_line(line);
		
		
		
		
		//this counter check for the number of valid card strings
		int line_counter = 0;
		


		//////////////////////////////////////////////////////////////////////////////
		//Testing the validty of the line
		// This while loop is for checking whether the line is valid. AFter going through
		
		while (test_line >> test){
			//cout << test << endl;
			
			if (test == "//"){ break; }
			int test_size = test.size();
			//cout << "my size:" << test_size << endl;
			string srank_test, ssuite_test;
			if (test_size != maxstringlength && test_size != regularstringlength){
				continue;
			}
			else if (test_size==maxstringlength) {
				srank_test = test.substr(maxlengthcardstring_rankStartIndex, maxlengthcardstring_rankEndIndex);
				ssuite_test = test[maxlengthcardstring_suitIndex];

				// CHeck whether the suit and rank are valid ( weahter in our dictionary mymap)
				// the warnings are commented out since we are gonna produce the warning when we are actually doing the parsining in the next section
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
				srank_test = test[regularcardstring_rankIndex];
				ssuite_test = test[regularcardstring_suitIndex];
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
		
//Now the line_counter is number of valid strings for the current line. If it is not equal to valid_hand_size(5), print out the warning
		
		if (line_counter != valid_hand_size){
			cerr <<"Line " <<lineindicator<<":  "<< "Warning!!! This line does not contain correct number of valid card definition strings" << endl;
			continue;
		}
		
		else{ 
			while (current >> word){
			// if we reach "//" we move to the next line immediately
				if (word == "//"){
					break;
				}

				// the inner loop go through each line
				string srank, ssuite;
				int this_rank, this_suite;
				int temp = word.size();
				//Check weather it is a valid card string
				// it is valid if it is either 3 or 2 characters long
				if (temp != maxstringlength && temp != regularstringlength){
					// notify the user if it is not a valid card string
					cerr << "Warning!!!Push onto deck: invalid string element type: invalid length" << endl;
					// after notification, move on
					continue;
				}
				// Now, there are two cases for valid card string, length 2 ( with rank 10 card) and length 3

				else if (temp == maxstringlength){
					// if length is three
					// get the corresponding rank and suites
					srank = word.substr(maxlengthcardstring_rankStartIndex, maxlengthcardstring_rankEndIndex);
					ssuite = word[maxlengthcardstring_suitIndex];

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
					srank = word[regularcardstring_rankIndex];
					ssuite = word[regularcardstring_suitIndex];
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
	/*This Function is for the extra credit
	(1): it recoganize the hand, create a hand object and store it in a vector
	(2): then it utlizie the operator< defiend for hand object(not card object) to sort all the hands
	(3): when it prints out the hand rank, it will also print out what are the cards contained in the hand.
	*/
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

	//get the size of the deck
	int deck_size = deck.size();
	//the end_index is 0 and the start_index is (-)valid_hand_size (5) because we increment one step at the beining of the loop
	int end_index = 0;
	int start_index = 0- valid_hand_size;

	vector<Hand> sort_hand;
	while (end_index < deck_size){

		//step valid_hand_size cards ahead
		start_index = start_index + valid_hand_size;
		end_index = end_index + valid_hand_size;
		
		//hand_deck temp holder
		vector<Card> hand_deck(deck.begin() + start_index, deck.begin() + start_index + valid_hand_size);

	

		vector<int> frquencyTable(valid_hand_size);
		sort(hand_deck.begin(), hand_deck.end());
		//frquencyTable vector:This is the key for recognizing the hand
       
		
		
		// The following region is where the magic of recoganizing hands happens. The theory behind is explained in the ReadMe.txt
		
		//Construcitng the frequency table for the current hand
		for (unsigned int i = 0; i < frquencyTable.size(); ++i){
			
			int leading_count = 1;
			for (unsigned int j = i + 1; j < frquencyTable.size(); ++j){


				if (hand_deck[i].rank_ == hand_deck[j].rank_) {

					++leading_count;
				}
			}
			frquencyTable[i] = leading_count;
		}

		sort(frquencyTable.begin(), frquencyTable.end());




		

		// index info gonna be used later
		int max_index = frquencyTable.size() - 1;
		int secondlargest_index = frquencyTable.size() - 2;
		int thirdlargest_index = frquencyTable.size() - 3;
		
		//Check for four of a kind
		if (frquencyTable[max_index] == frquency_fourofakind)
		{   
			Hand_rank temp = fourofkind;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
			continue;

		}

		if (frquencyTable[max_index] == frequency_fullhouse_largest){
			//Check for full house
			if (frquencyTable[secondlargest_index] == frequency_fullhouse_secondlargest && frquencyTable[thirdlargest_index] == frequency_fullhouse_thirdlargest){
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
		
		if (frquencyTable[max_index] == frequency_twopairs){
			//check for two pairs
			if (frquencyTable[secondlargest_index] == frequency_twopairs){
				Hand_rank temp = two_pars;
				Hand this_hand(hand_deck, temp);
				sort_hand.push_back(this_hand);
				continue;
				
			}
			//check for one pair
			Hand_rank temp = one_pair;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
			
			continue;
		}


		//check flush (but wait for checking straight flush)
		bool isflush = false;
		for (unsigned int fit = 0; fit < hand_deck.size(); fit++){
			isflush = hand_deck[0].suit_ == hand_deck[fit].suit_;
		
		}

		//check straight ((but wait for checking straight flush)
		bool isstraight = false;
		for (unsigned int sit = 0; sit < hand_deck.size()-1; sit++){
			isstraight = hand_deck[sit + 1].rank_ == hand_deck[sit].rank_ + 1;
		}

		//check straight flush
		if ((isstraight&&isflush)){
			Hand_rank temp = straight_flush;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
			continue;
		}
		//check for flush
		if (isflush){
			Hand_rank temp = flush_;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
		
			continue;
		}
		//check for straight
		if (isstraight){
			Hand_rank temp = straight_;
			Hand this_hand(hand_deck, temp);
			sort_hand.push_back(this_hand);
			continue;
			
		}
		//If the hand is none of above, it is unranked.
		Hand_rank temp = unranked;
		Hand this_hand(hand_deck, temp);
		sort_hand.push_back(this_hand);
		continue;

	}
	sort(sort_hand.rbegin(), sort_hand.rend());
	cout << "<----------Printing out the sorted hands in Dr.Gill's way-------->" << endl;
	for (unsigned int i = 0; i < sort_hand.size(); i++){
		cout << sort_hand[i].naive_string() << endl;
	}
	cout << "<----------Printing out the sorted hands in more illustrative way-------->" << endl;
	for (unsigned int i = 0; i < sort_hand.size(); i++){
		cout << sort_hand[i].str() << endl;
	}
	
	return SUCCESS;
}
int hand_vector(const vector<Card>&deck){
	/*
	This function takes a reference to a const vector of cards as a parameter (for example of type const vector<Card> &) 
	and taking five cards at a time in the vector (i.e., cards in positions 0-4, and then 5-9, etc. in the vector)
	prints out the poker hand rank of that group of cards: 
	*/
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
	//get the size of the deck
	int deck_size = deck.size();
	//the end_index is 0 and the start_index is (-)valid_hand_size (5) because we increment one step at the beining of the loop
	int end_index = 0;
	int start_index = 0-valid_hand_size;

	while (end_index < deck_size){

		//step valid_hand_size cards ahead
		start_index = start_index + valid_hand_size;
		end_index = end_index + valid_hand_size;

	
		//hand_deck temp holder
		vector<Card> hand_deck(deck.begin() + start_index, deck.begin() + start_index+valid_hand_size);

		//frquencyTable vector:This is the key for recognizing the hand
		// The theory behind is explained in the ReadMe.txt
		//Construcitng the frequency table for the current hand

		vector<int> frquencyTable(valid_hand_size);
		sort(hand_deck.begin(), hand_deck.end());

		for (int i = 0; i < valid_hand_size; i++){
			int leading_count=1;
			
			for (int j = i+1; j < valid_hand_size; j++){
				
				
				if (hand_deck[i].rank_ == hand_deck[j].rank_) {
					
					leading_count++; 
				}
			}
			frquencyTable[i] = leading_count;
		}
		
		sort(frquencyTable.begin(), frquencyTable.end());




		// index info gonna be used later
		int max_index = frquencyTable.size() - 1;
		int secondlargest_index = frquencyTable.size() - 2;
		int thirdlargest_index = frquencyTable.size() - 3;
		// the end_index for printing out//it is end_index-1 because we want 0-4, 5-9 instead of 1-5 ,6-10
		int printing_end = end_index - 1;
		
		//Check for four of a kind
		if (frquencyTable[max_index] == frquency_fourofakind)
		{   
			std::cout << start_index << " to " << printing_end<< " : " << "is four of a kind" << endl;
			continue;

		}

		if (frquencyTable[max_index] == frequency_fullhouse_largest){
			//Check for full house
			if (frquencyTable[secondlargest_index] == frequency_fullhouse_secondlargest&&frquencyTable[thirdlargest_index]==frequency_fullhouse_thirdlargest)
			{ cout << start_index << " to " << printing_end << " : " << "is a full house" << endl; continue; }
			// check for three of a kind
			cout << start_index << " to " << printing_end << " : " << "is three of a kind" << endl;
			continue; 
		}

		if (frquencyTable[max_index] == frequency_twopairs){
			//check for two pairs
			if (frquencyTable[secondlargest_index] == frequency_twopairs){ cout << start_index << " to " << printing_end << " : " << "is two pairs" << endl; continue; }
			//check for one pair
			cout << start_index << " to " << printing_end << " : " << "is one pair" << endl;
			continue;
		}
		
		
		//check flush (but wait for checking straight flush)
		bool isflush=false;
		for (int fit = 0; fit < valid_hand_size; fit++){
		 isflush = hand_deck[0].suit_ == hand_deck[fit].suit_;
		 continue;
		}
		
		//check straight ((but wait for checking straight flush)
		bool isstraight=false;
		// the boundary is valid_hand_size -1 because we donot want to go beyond the last index
		for (int sit = 0; sit < valid_hand_size-1; sit++){
			isstraight = hand_deck[sit + 1].rank_ == hand_deck[sit].rank_ + 1;
			continue;
		}

		//check straight flush
		if ( (isstraight&&isflush) ){
			cout << start_index << " to " << printing_end<< " : " << "is straight flush" << endl;
			continue;
		}

		//check flush
		if (isflush){
			cout << start_index << " to " << printing_end << " : " << "is  flush" << endl;
			continue;
		}

		//check straight
		if (isstraight){
			cout << start_index << " to " << printing_end << " : " << "is  straight" << endl;
			continue;
		}
		//If the hand is none of above, it is unranked.
		string rank = trans[hand_deck[max_index].rank_];
		string suit = trans[hand_deck[max_index].suit_];
			cout << start_index << " to " << printing_end << " : " << "No rank. The leading card is: " << rank<<" of "<<suit<< endl;
	
	}

	return SUCCESS;
}
int naive_print_vector(const vector<Card> & deck){
/* Naive_print_vector is basically the same as print_vector. Only difference is Naive_print_vector will print out the cards in the deck accroding to
Dr.Gill's requirments. Eg. King of Diamonds is KD
*/
	map<int, string> trans;
	trans[two] = "2";
	trans[three] = "3";
	trans[four] = "4";
	trans[five] = "5";
	trans[six] = "6";
	trans[seven] = "7";
	trans[eight] = "8";
	trans[nine] = "9";
	trans[ten] = "10";
	trans[jack] = "J";
	trans[queen] = "Q";
	trans[king] = "K";
	trans[ace] = "A";
	trans[clubs] = "C";
	trans[spades] = "S";
	trans[hearts] = "H";
	trans[diamonds] = "D";
	if (deck.size() == 0){
		cerr << "Warning!!! printing deck: the deck is empty" << endl;
		return SUCCESS;
	}
	// iterate through the deck (vector) and print out the card
	
	cout << "This deck contains " << deck.size() << " cards in total" << endl;
	for (unsigned int x = 0; x != deck.size(); ++x){
		// use map trans to translate suite and type to meaningful strings

		string rank = trans[deck[x].rank_];
		string suit = trans[deck[x].suit_];

		std::cout  << rank  << suit << endl;
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


	
	if (argc != correct_number_of_arguments)
	{
		// if not, usage_message called to print out guidance for user and return the corresponding error type (int)
		int error = usage_message(argv[Program_name]);
		return error;
	}

	//the user passed in correct number of arguments
	else{
		vector<Card> deck;
		// parse the file and print out the updated vector ( and returing the corresponding error/sucess (int) )
	
		cout << "----------------------------Begin Parsing File---------------------------- " << endl;
		int i = ParseFile_hand(deck, argv[command_name]);
		if (i != SUCCESS){
			return FAILURE_OPENING_FILE;
		}
		
		cout << "-------------------------End Parsing File---------------------------- " << endl;
		cout << "------------------------Begin Recognizing Hand---------------------- " << endl;
		hand_vector(deck);
		cout << "----------------------End Recoganizing Hand------------------------- " << endl;
		cout << "------------------------Begin Extra Credit-------------------------" << endl;
		sorthand_vector(deck);
		std::cout << "///////////////////////////////////" << endl;
		std::cout << "Finish Recoganizing hands" << endl;
		std::cout << "///////////////////////////////////" << endl;
		cout << "-----------------------------End Extra Credit--------------------------" << endl;
		cout << "---------------------Begin Printing out sorted vector----------------------" << endl;
		cout << "******Printing out the sorted vector in DR.Gill's prefered way*********" << endl;
		sort(deck.begin(), deck.end());
		naive_print_vector(deck);
		cout << "********Printing out the sorted vector in a more illustritrative way*********" << endl;
		print_vector(deck);
		cout << "-------------------End Printing out sorted vector------------------------- " << endl;
	}
	
	return SUCCESS;
}

