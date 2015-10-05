#ifndef HAND_H
#define HAND_H
#include <vector>
#include "Deck.h"

//The hand-rank enum
enum Hand_rank{
	unranked = 80, one_pair, two_pars, three_of_kind, straight_, flush_, full_house, fourofkind, straight_flush
};



class Hand{

public:
	//Constructor
	Hand(vector<Card> vec_hand);
	//Copy Constructor
	Hand(const Hand&otherhand);
	//default constructor (donot really use it)
	Hand();
	// Destructor
	~Hand();

	//Assaign method overload
	Hand& operator =(const Hand& otherhand);
	//equivalence overload
	bool operator ==(const Hand& otherhand) const ;
	// less than overload
	bool operator < (const Hand& otherhand) const;
	//size method
	int size() const;
	//as string method
	string asstring() const;

	friend ostream& operator << (ostream &  out, const Hand & hand);
	friend void  operator << (Hand & hand, Deck & deck);
	friend bool poker_rank(const Hand & hand_, const Hand &another);
	
	//TheFollowing are for use of my poker_rank method
	// rank method to recognize the rank of a hand
	Hand_rank rank() const;

	//reversecomp for usign in the poker_rank method
	bool reversecomp(const Hand& otherhand) const;
	//Isnotfull used for poker_rank method
	bool isnotfull();
private:

	vector<Card> hand_;





};












#endif
