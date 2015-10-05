
#ifndef DECK_H
#define DECK_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<ostream>
#include<sstream>
#include<fstream>
#include<string>
#include<iterator>
#include <random>
#include <chrono>       // for std::chrono::system_clock

using namespace std;

class Hand;
enum command_line_errors{
	Success_commandline=0, onlyone_is_shuffle =10 , two_neither_shuffle, no_argument, morethantwo_argument, deck_not_mutipleof5 = 16, two_both_shuffle=17, deck_not_atleast45cards = 18
};

enum lengths{
	regularstringlength = 2, correct_number_of_arguments = 2, maxstringlength = 3, valid_hand_size = 5, minimum_cardsindeck_todealcards = 45,number_of_hands_inContainer = 9,no_remainder=0

	,reverse_iteration_end_index = -1
};
enum index{
	regularcardstring_rankIndex = 0, regularcardstring_suitIndex = 1, maxlengthcardstring_rankStartIndex = 0, maxlengthcardstring_rankEndIndex = 2, maxlengthcardstring_suitIndex = 2
};
enum Rank{ two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
//Enumeration that defines all possible suites, notice that it starts from 14 to avoid conflict when translate back to string
enum Suite{ clubs = 14, diamonds, hearts, spades };

enum names{
	Program_name,
	command_name

};

// enumeration that defines all possible return values
// notcie that Null_deck is not consirded as an error here
enum Excpetion{
	all_equal_card_inhand
};
enum Result{
	SUCCESS,
	FAILURE_OPENING_FILE,
	WRONG_NUMBER_ARGUMENTS

};


enum FrequencyTable{

	frequency_none = 0, frquency_fourofakind = 4, frequency_threeofakind = 3, frequency_onepair = 2, frequency_twopairs = 2, frequency_fullhouse_largest = 3, frequency_fullhouse_secondlargest = 2, frequency_fullhouse_thirdlargest = 2
};

enum commandline_length_and_index{
	not_valid_commandline_length = 1, max_command_line_length = 3, minimum_command_line_length = 2, first_avaialbe_position = 1, second_avaiable_position = 2
};
// simple Card Struct
struct Card
{

	Rank rank_;
	Suite suit_;
	//overload <
	bool operator<(const Card & another) const{
		if (rank_ == another.rank_){
			return suit_ < another.suit_;
		}
		else
		{
			return rank_ < another.rank_;
		}
	}

	//overload >
	bool operator > (const Card & another) const{
		if (rank_ == another.rank_){
			return suit_ > another.suit_;
		}
		else
		{
			return rank_ > another.rank_;
		}
	}
	// overlaod ==
	bool operator == (const Card& another) const{
		return (rank_ == another.rank_ &&suit_ == another.suit_);
	}
	// overlaod !=
	bool operator != (const Card& another) const{
		return (rank_ != another.rank_ ||suit_ != another.suit_);
	}

};


//Deck class delcaration
/*notice that default constructor is provided by the compiler, and since vector container does the memberwise copy correctly and we are not utilizing any pointer here. 
 the default constructor provided by the compiler is enough for the job*/
class Deck
{

	
public:
	//constructor
	Deck(char * FileName);
	//Destructor, donot really to define it since no dynamic allocation here. i do it just for fun
	~Deck();
	//shuflfle method
	void Shuffle();
	// size method 
	int size() const;
	// non-member insertion method to allow ostream to get an string representation of deck
	friend ostream& operator << (ostream &  out, const Deck & deck);
	// friend the non-insertion method to allow the insertion from deck to hand to be properly defined in hand class
	friend void  operator << (Hand & hand, Deck & deck); 
	// The load method to be called by constructor
	int load(vector<Card> &deck, char * FileName);
	
	
private:
	// The private container to hold all the cards
	vector<Card>deck_;

};


#endif