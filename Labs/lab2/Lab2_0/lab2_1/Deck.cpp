#include "stdafx.h"
#include "Deck.h"
using namespace std;


Deck::Deck(char * FileName){
	int loading_result = load(this->deck_, FileName);
	if (loading_result != SUCCESS){
		throw loading_result;
	}
}
// empty destructor (since we donot dynamically allocate anything)
Deck::~Deck(){}
void Deck::shuffle(){
	random_shuffle(deck_.begin(), deck_.end());
}

int Deck::size() const{
	return deck_.size();
}


int Deck::load(vector<Card> &deck, char * FileName)
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
	// this will notify the user about how many card are created and stored for the given file after parsing
	cout << "the size of the deck is " << deck.size() << endl;
	infile.close();
	return SUCCESS;

}



ostream& operator << (ostream &  out, const Deck & deck){
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

	

	// iterate through the deck (vector) and print out the card
	out << "test" << endl;
	//cout << "This deck contains " << deck.size() << " cards in total" << endl;
	if (deck.deck_.size() == 0){
		out << "Empty Deck";
	}
	for (unsigned int x = 0; x < deck.size(); ++x){
		// use map trans to translate suite and type to meaningful strings
		string rank = trans[deck.deck_[x].rank_];
		string suit = trans[deck.deck_[x].suit_];

	out << rank << suit << endl;
	}
	return  out;
}