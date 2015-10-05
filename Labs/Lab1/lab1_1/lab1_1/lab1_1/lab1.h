#ifndef LAB1_H
#define LAB1_H
#include <vector>

using namespace std;
// Enumeration that defines all possible ranks
enum Rank{ two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
//Enumeration that defines all possible suites, notice that it starts from 14 to avoid conflict when translate back to string
enum Suite{ clubs = 14, diamonds, hearts, spades };

// enumeration defines the location of possible strings in argv (name and one other argument passed into the program)
enum names{
	Program_name,
	command_name

};

// enumeration that defines all possible return values
// notcie that Null_deck is not consirded as an error here

enum Result{
	SUCCESS,
	FAILURE_OPENING_FILE,
	WRONG_NUMBER_ARGUMENTS

};

// Declare the Card Struct
// it has two instance varabiles rank_ and suite_ to hold rank and suite info for one CARD

struct Card
{

	Rank rank_;
	Suite suit_;
	bool operator<(const Card & another){
		if (this->rank_ == another.rank_){
			return this->suit_ < another.suit_;
		}
		else
		{
			return this->rank_ < another.rank_;
		}
	}
	//bool rank_equal(const Card& another);
	//bool suite_equal(const Card& another);

};



// Declarations for all three functions 
int ParseFile_hand(vector<Card>& deck, char * name);
int usage_message(char* filename);
int print_vector(const vector<Card> & deck);
#endif