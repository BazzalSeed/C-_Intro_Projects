
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

using namespace std;

class Hand;
enum lengths{
	regularstringlength = 2, correct_number_of_arguments = 2, maxstringlength = 3, valid_hand_size = 5
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

	frequency_none = 0, frquency_fourofakind = 4, frequency_threeofakind = 3, frequency_onepair = 1, frequency_twopairs = 2, frequency_fullhouse_largest = 3, frequency_fullhouse_secondlargest = 2, frequency_fullhouse_thirdlargest = 2
};

struct Card
{

	Rank rank_;
	Suite suit_;
	bool operator<(const Card & another) const{
		if (rank_ == another.rank_){
			return suit_ < another.suit_;
		}
		else
		{
			return rank_ < another.rank_;
		}
	}
	bool operator == (const Card& another) const{
		return (rank_ == another.rank_ &&suit_ == another.suit_);
	}
	bool operator != (const Card& another) const{
		return (rank_ != another.rank_ ||suit_ != another.suit_);
	}

};
class Deck
{

	
public:
	Deck(char * FileName);
	~Deck();
	void shuffle();
	int size() const;
	friend ostream& operator << (ostream &  out, const Deck & deck);
	friend void  operator << (Hand & hand,  Deck & deck);
	int load(vector<Card> &deck, char * FileName);
	
	
private:
	vector<Card>deck_;

};


#endif