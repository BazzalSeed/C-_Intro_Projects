#ifndef HAND_H
#define HAND_H
#include <vector>
#include "lab1.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;

enum Hand_rank{
	unranked=80,one_pair ,two_pars,three_of_kind,full_house,fourofkind, straight_,flush_,straight_flush
};
class Hand {

public:
	Hand(vector<Card> current_hand, Hand_rank current_rank);
	vector<Card > hand_;
	Hand_rank hand_rank;
	bool operator<(const Hand & another);
	string str();
};





#endif