#ifndef HAND_H
#define HAND_H
#include <vector>
#include "Deck.h"
enum Hand_rank{
	unranked = 80, one_pair, two_pars, three_of_kind, straight_, flush_, full_house, fourofkind, straight_flush
};



class Hand{

public:
	Hand(vector<Card> vec_hand);
	Hand(const Hand&otherhand);
	Hand();
	~Hand();

	Hand& operator =(const Hand& otherhand);
	bool operator ==(const Hand& otherhand) const ;
	int size() const;
	bool operator < (const Hand& otherhand) const;
	string asstring() const;
	
	Hand_rank rank() const;
	friend ostream& operator << (ostream &  out, const Hand & hand);
	friend void  operator << (Hand & hand, Deck & deck);
	friend bool poker_rank(const Hand & hand_, const Hand &another);
	
private:
	vector<Card> hand_;





};












#endif
