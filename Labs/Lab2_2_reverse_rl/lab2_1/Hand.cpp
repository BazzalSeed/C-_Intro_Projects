#include"stdafx.h"
#include "Hand.h"


Hand::Hand(vector<Card> vec_hand){
	hand_ = vec_hand;
}
int Hand:: size() const{
	return hand_.size();
}
//actually donot need it since the vector does memberwise copy
Hand::Hand(const Hand&otherhand){
	hand_ = otherhand.hand_;
}
//Destructor, donot need to define anything since no dynamic allocation
Hand::~Hand(){

}

// default constructor
Hand::Hand(){

}

// definition of assaign method
Hand& Hand:: operator =(const Hand& otherhand){
	if (*this==otherhand){
		return *this;
	}
	else{
		hand_ = otherhand.hand_;
		return *this;
	}
	
}


//equivalence operator definition
bool Hand::operator ==(const Hand& otherhand) const{
	return hand_ == otherhand.hand_;
}
// isnotfull method definition
//return true if hand not full (<= valid_hand_size)
bool Hand::isnotfull(){
	if (hand_.size() < valid_hand_size){
		return true;
	}
	return false;
}
bool Hand:: operator < (const Hand& otherhand) const{
	for (unsigned int i = 0; i <hand_.size()&&i< otherhand.size(); i++){
		if (hand_[i] != otherhand.hand_[i]){
			return hand_[i] < otherhand.hand_[i];
		}
		if (this->size() < otherhand.size()){
			return true;
		}
	}
	return false;
}

// compare the hand from the last index of the hand vector
// same logic as operator < 
bool Hand:: reversecomp(const Hand& otherhand) const{
	for (unsigned int i = hand_.size() - 1; i != reverse_iteration_end_index; --i){
		if (hand_[i] != otherhand.hand_[i]){
			return hand_[i] > otherhand.hand_[i];
		}
	}
	return false;
}
void operator << (Hand & hand,  Deck & deck){
	int back_of_deck = deck.deck_.size() - 1;
	Card temp = deck.deck_[back_of_deck];
	hand.hand_.push_back(temp);
	deck.deck_.pop_back();

	sort(hand.hand_.begin(), hand.hand_.end());
	
}

string Hand::asstring() const{

	// dictionary to convert suit and rank to naive card string 
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
	///////////////////////////////////////////////////////////
	
	ostringstream msg;
	
	if (hand_.size() == 0){
		return "Empty Hand";
	}

	for (unsigned int i = 0; i < hand_.size(); i++){
		msg << trans[this->hand_[i].rank_] << trans[this->hand_[i].suit_] <<" ";
	}
	
	return msg.str();
}

ostream& operator << (ostream &  out, const Hand & hand){

	out << hand.asstring();
	return out;
}

Hand_rank Hand::rank() const{
	Hand_rank hand_rank;
	vector<int> lefthand_frequencyTable(valid_hand_size);
	for (unsigned int i = 0; i <lefthand_frequencyTable.size(); ++i){

		int leading_count = 1;
		for (unsigned int j = i + 1; j < lefthand_frequencyTable.size(); ++j){


			if (hand_[i].rank_ == hand_[j].rank_) {

				++leading_count;
			}
		}
		lefthand_frequencyTable[i] = leading_count;
	}
	sort(lefthand_frequencyTable.begin(), lefthand_frequencyTable.end());



	// index info gonna be used later
	int max_index = lefthand_frequencyTable.size() - 1;
	int secondlargest_index = lefthand_frequencyTable.size() - 2;
	int thirdlargest_index = lefthand_frequencyTable.size() - 3;


	if (lefthand_frequencyTable[max_index] == frquency_fourofakind)
	{
		hand_rank = fourofkind;
		return hand_rank;

	}

	else if (lefthand_frequencyTable[max_index] == frequency_fullhouse_largest){
		//Check for full house
		if (lefthand_frequencyTable[secondlargest_index] == frequency_fullhouse_secondlargest && lefthand_frequencyTable[thirdlargest_index] == frequency_fullhouse_thirdlargest){
			hand_rank = full_house;
			return hand_rank;
		}
		// check for three of a kind
		hand_rank = three_of_kind;
		return hand_rank;
	}

	else if (lefthand_frequencyTable[max_index] == frequency_twopairs){
		//check for two pairs
		if (lefthand_frequencyTable[secondlargest_index] == frequency_twopairs){
			hand_rank = two_pars;
			return hand_rank;

		}
		//check for one pair
		hand_rank = one_pair;
		return hand_rank;
	}


		//check flush (but wait for checking straight flush)
		bool isflush = false;
		vector<bool> flush_testing;
		for (unsigned int fit = 0; fit < hand_.size(); fit++){
			flush_testing.push_back(hand_[0].suit_ == hand_[fit].suit_);

		}
		
		vector<bool>::iterator flush_it;
		flush_it = find(flush_testing.begin(), flush_testing.end(), false);
		if (flush_it == flush_testing.end()){
			isflush = true;
		}


		//check straight ((but wait for checking straight flush)
		bool isstraight = false;
		vector<bool>straight_testing;
		for (unsigned int sit = 0; sit < hand_.size() - 1; sit++){
			straight_testing.push_back( (hand_[sit + 1].rank_ == hand_[sit].rank_ + 1));
		}
		vector<bool>::iterator it;
		it = find(straight_testing.begin(), straight_testing.end(), false);
		if (it==straight_testing.end())
		{
			isstraight = true;
		}
		//check straight flush
		if ((isstraight&&isflush)){
			hand_rank = straight_flush;
			return hand_rank;

		}
		//check for flush
		else if (isflush){
			hand_rank = flush_;
			return hand_rank;

		}
		//check for straight
		if (isstraight){

			hand_rank = straight_;
			return hand_rank;

		}
		hand_rank = unranked;
		return hand_rank;

}

