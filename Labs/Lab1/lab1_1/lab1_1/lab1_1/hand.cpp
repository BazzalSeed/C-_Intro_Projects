#include "stdafx.h"
#include "hand.h"
#include <vector>
#include <string>
#include<iostream>
#include<sstream>
#include<fstream>


using namespace std;

Hand::Hand(vector<Card> current_hand, Hand_rank current_rank){

	hand_ = current_hand;
	hand_rank = current_rank;
}
bool Hand::operator< (const Hand & another){

	if (this->hand_rank != another.hand_rank){
		return this->hand_rank < another.hand_rank;
	}
	else{
		return ((this->hand_)[4] < another.hand_[4]);
	}
}

string Hand::str(){
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
	///////////////////////////////////////////////////////////
	map<Hand_rank, string> trans_hand;
	trans_hand[unranked] = "Unranked";
	trans_hand[one_pair] = "One Pair";
	trans_hand[two_pars] = "Two pairs";
	trans_hand[three_of_kind] = "Three of a kind";
	trans_hand[full_house] = "Full House";
	trans_hand[fourofkind] = "Four of a kind";
	trans_hand[straight_] = "Straight";
	trans_hand[flush_] = "Flush";
	trans_hand[straight_flush] = "Straight Flush";
	ostringstream msg;
	if (hand_rank == unranked){
		string leading_card = trans[this->hand_[4].rank_] + " "+ "of"+" " + trans[this->hand_[4].suit_];
		msg << "This hand is a " << trans_hand[hand_rank] <<" with leading Card"<<leading_card<<endl;
	}

	else{ msg << "This hand is a " << trans_hand[hand_rank] << endl; }
	msg << "////////////////////////" << endl;
	ostringstream allcard;
	for (int i = 0; i < 5; i++){
		allcard << trans[this->hand_[i].rank_] << " of " <<trans[ this->hand_[i].suit_ ]<< endl;
	}
	string msgg = msg.str() + allcard.str();
	return msgg;
}