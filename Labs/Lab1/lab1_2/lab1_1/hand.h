#ifndef HAND_H
#define HAND_H
#include <vector>
#include "lab1.h"

/*
Hand Class is designed for solving extra credits
(1) it contains the hand_rank of a hand (enum)
(2) it contains a vector of all the cards in the hand
(3) it has a operator < to compare between ranks of hands 
*/
using namespace std;

enum Hand_rank{
	unranked = 80, one_pair, two_pars, three_of_kind, straight_, flush_,full_house, fourofkind, straight_flush
};
class Hand {

public:
	//The constructor
	Hand(vector<Card> current_hand, Hand_rank current_rank);
	//vecotr of cards in the hand
	vector<Card > hand_;
	//rank of card
	Hand_rank hand_rank;
	// The very important operator oveloard method
	bool operator<(const Hand & another);
	//str method allows me to get the string representation of this hand directly.
	string str();
	string naive_string();
};





#endif