

#include "stdafx.h"
#include <iostream>
#include "Lab0.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>

using std::vector;
using namespace std;

int ParseFile(vector<Card> &deck, char * FileName)
{
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

	
	string line, word;
	ifstream infile;
	infile.open(FileName);
	//CHeck for Eroor
	if (infile.fail()){
		cerr << "ERROR OPENING YOUR FILE BRO" << endl;
		exit(EXIT_FAILURE);
		return WRONG_NUMBER_ARGUMENTS;
	}
	while (infile.good()){
		getline(infile, line);
		istringstream current(line);
		cout << "the outter while" << endl;
		while (current >> word){
			cout << "the inner while" << endl;
			string srank, ssuite;
			int this_rank, this_suite;
			int temp = word.size();
			if (temp != 3 && temp != 2){
				cerr << "Push onto deck: invalid string element type 1" << endl;
				break;
			}
			if (temp == 3){
				srank = word.substr(0, 2);
				ssuite = word[2];
				if (mymap.find(srank) == mymap.end()){
					cerr << "ERROR Push onto deck: invalid string element type 2_a" << endl;
					break;
				}
				if (mymap.find(ssuite) == mymap.end()){
					cerr << "ERROR Push onto deck: invalid string element type 2_b" << endl;
					break;
				}
				this_rank = mymap[srank];
				this_suite = mymap[ssuite];
			}
			else{
				srank = word[0];
				ssuite = word[1];
				if (mymap.find(srank) == mymap.end()){
					cerr << "ERROR Push onto deck: invalid string element type 3_a" << endl;
					break;
				}
				if (mymap.find(ssuite) == mymap.end()){
					cerr << "ERROR Push onto deck: invalid string element type 3_b" << endl;
					break;
				}
				this_rank = mymap[srank];
				this_suite = mymap[ssuite];
			}

			Card this_card = { Rank(this_rank), Suite(this_suite) };
			deck.push_back(this_card);
		}



	}
	cout << "the size of the deck is " << deck.size() << endl;
	infile.close();
	return 0;

}

int print_vector(const vector<Card> & deck){

	string rank,suit,word;
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
	if (deck.size() == 0){
		cerr << "printing deck: the deck is empty" << endl;
		return NULL_DECK;
	}
	for (int x = 0; x != deck.size(); ++x){
		rank = trans[deck[x].rank_];
		suit = trans[deck[x].suit_];

		cout << "Card " << x+1 << ":" << rank << " of "<< suit << endl;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////
int usage_message(char* filename){
	cerr << "usage: " << filename<< " <input_file_name>" <<"is incorrect"<< endl;
	cerr << "plesae enter a valid file name (file must be at the same directory) directly follow the program name using the command line" << endl;
	cerr << "for example: " << "lab0_Seed.exe card_file.txt" << endl;
	return WRONG_NUMBER_ARGUMENTS;
}
int main(int argc, char* argv[])
{


	if (argc != 2)
	{
		int error = usage_message(argv[0]);
		return error;
	}
	else{
		vector<Card> d;
		ParseFile(d, argv[1]);
		return print_vector(d);

	}

	return 0;
}

