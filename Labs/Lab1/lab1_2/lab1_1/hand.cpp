#include "stdafx.h"
#include "hand.h"
#include "lab1.h"


using namespace std;

// The constructor
Hand::Hand(vector<Card> current_hand, Hand_rank current_rank){

	hand_ = current_hand;
	hand_rank = current_rank;
}

//The < overload
bool Hand::operator< (const Hand & another){

	//this->hand_.size() -1 gives the index of the largest element (since sorted ascendingly)
	//the other ints are initialized with the same reason
	int max_index = (this->hand_).size()-1;
	int second_largest_index = (this->hand_).size() - 2;
	int third_largest_index = (this->hand_).size() - 3;
	int fourth_largest_index = (this->hand_).size() - 4;
	int fifth_largest_index = (this->hand_).size() - 5;
	//Compares the rank of hands
	if (this->hand_rank != another.hand_rank){
		return this->hand_rank < another.hand_rank;
	}
	// if hand rank is the same, there are following cases

	else{
		// if the rank of hands are straihgt, straight flush, flush, or unranked, we simply compared the last card's rank (largest since sorted)
		if (hand_rank== straight_flush||flush_||straight_||unranked){
			return ((this->hand_[max_index]) < another.hand_[max_index]);}
		// if not one of above, we initialize a frequency table for this hand and another hand
		else{
			vector<int> this_frequencyTable(hand_.size());

			//create frequency table for this hand
			for (int i = 0; i < valid_hand_size; i++){
				int leading_count = 1;

				for (int j = i + 1; j < valid_hand_size; j++){


					if (hand_[i].rank_ == hand_[j].rank_) {

						leading_count++;
					}
				}
				this_frequencyTable[i] = leading_count;
			}

			vector<int> another_frequencyTable(hand_.size());

			//create frequency table for another hand
			for (int i = 0; i < valid_hand_size; i++){
				int leading_count = 1;

				for (int j = i + 1; j < valid_hand_size; j++){


					if (hand_[i].rank_ == hand_[j].rank_) {

						leading_count++;
					}
				}
				another_frequencyTable[i] = leading_count;
			}


			//for four of a kind, we find the last index of the group of fourcard and the index of the individual card
			// then compare the rank of group of four card, if equal compare the rank of inidivdual card
			if (hand_rank == fourofkind){

				// initialize intergers gonna be sued
				int this_lastofgroup_index = 0;
				int this_thehighestindividual_index = 0;
				int another_lastofgroup_index = 0;
				int another_thehighestindividual_index = 0;

				//find the last index of the group of four cards for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (this_frequencyTable[i] == frquency_fourofakind){
						this_lastofgroup_index = i;
					}
				}

				//find the index of individual card for this hand
					for (int i = 0; i < valid_hand_size; ++i){
						if (this_frequencyTable[i] == frequency_none){
							this_thehighestindividual_index = i;
							break;
						}
					}

					//find the last index of the group of four cards for another hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frquency_fourofakind){ another_lastofgroup_index = i; } }

				//find the index of individual card for another hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frequency_none){
						another_thehighestindividual_index = i;
						break;
					}
				}

				// then compare the rank of group of four card, if equal compare the rank of inidivdual card
			
				if (hand_[this_lastofgroup_index].rank_ == another.hand_[another_lastofgroup_index].rank_){ return hand_[this_thehighestindividual_index].rank_ < another.hand_[another_thehighestindividual_index].rank_;  }
				else{ return hand_[this_lastofgroup_index].rank_ < another.hand_[another_lastofgroup_index].rank_; }

				
			}
			// if it is three of a kind 
			// we use the exact same logic
			if (hand_rank == three_of_kind){
				int this_lastofgroup_index = 0;
				int this_thehighestindividual_index = 0;
				int another_lastofgroup_index = 0;
				int another_thehighestindividual_index = 0;

				for (int i = 0; i < valid_hand_size; ++i){
					if (this_frequencyTable[i] == frequency_threeofakind){ this_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (this_frequencyTable[i] == frequency_none){ this_thehighestindividual_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frequency_threeofakind){ another_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frequency_none){ another_thehighestindividual_index = i; }
				}
				if (hand_[this_lastofgroup_index].rank_ == another.hand_[another_lastofgroup_index].rank_){ return hand_[this_thehighestindividual_index].rank_ < another.hand_[another_thehighestindividual_index].rank_; }
				else{ return hand_[this_lastofgroup_index].rank_ < another.hand_[another_lastofgroup_index].rank_; }

			}
			// if it is two pairs, we need to get the index of the first pair and the second pair. and the index of the individual card
			if (hand_rank == two_pars){

				//ints intiailized for future uses
				int this_lastofgroup_index = 0;
				int this_firstpair_lastofgroup_index = 0;
				int this_thehighestindividual_index = 0;
				int another_lastofgroup_index = 0;
				int another_thehighestindividual_index = 0;
				int another_firstpair_lastofgroup_index = 0;

				// find the index of the highest pair for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (this_frequencyTable[i] == frequency_twopairs){ this_lastofgroup_index = i; }
				}
				//find the index of the second pair for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (this_frequencyTable[i] == frequency_none){ this_thehighestindividual_index = i; }
				}
				// find the index of the individual card for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (this_frequencyTable[i] == frequency_none){ this_firstpair_lastofgroup_index = i; break; }
				}
				// do same things for another hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frequency_twopairs){ another_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frequency_none){ another_thehighestindividual_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frequency_none){ another_firstpair_lastofgroup_index = i; break; }
				}
				// if first and second pairs are all with same ranks, compare the indivudual card
				// if first pair is the same, compare the second pair's rank
				// if the first pair is different in rank, compare them
				if (hand_[this_lastofgroup_index].rank_ == another.hand_[another_lastofgroup_index].rank_){
					if (hand_[this_firstpair_lastofgroup_index].rank_ == another.hand_[another_firstpair_lastofgroup_index].rank_){ return (hand_[this_thehighestindividual_index].rank_ < another.hand_[another_thehighestindividual_index].rank_); }
					return  hand_[this_firstpair_lastofgroup_index].rank_ < another.hand_[another_firstpair_lastofgroup_index].rank_;
				}
				else{ return hand_[this_thehighestindividual_index].rank_ < another.hand_[another_thehighestindividual_index].rank_; }
			}
			//this logic is the same as four of a kind
			if (hand_rank == full_house){
				int this_lastofgroup_index = 0;
				int this_firstpair_lastofgroup_index = 0;
				int another_lastofgroup_index = 0;
				int another_firstpair_lastofgroup_index = 0;
				for (int i = 0; i < valid_hand_size; ++i){
					if (this_frequencyTable[i] == frequency_fullhouse_largest){ this_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (this_frequencyTable[i] == frequency_fullhouse_secondlargest){ this_firstpair_lastofgroup_index = i; }
				}

				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frequency_fullhouse_largest){ another_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frequency_fullhouse_secondlargest){ another_firstpair_lastofgroup_index = i; }
				}
				if (hand_[this_lastofgroup_index].rank_ == another.hand_[another_lastofgroup_index].rank_){ return hand_[this_firstpair_lastofgroup_index].rank_ < another.hand_[another_firstpair_lastofgroup_index].rank_; }
				else{ return hand_[this_lastofgroup_index].rank_ < another.hand_[another_lastofgroup_index].rank_; }
			}

			// this logic is the same as four of a kind
			if (hand_rank == one_pair){
				int this_lastofgroup_index = 0;
				int this_thehighestindividual_index = 0;
				int another_lastofgroup_index = 0;
				int another_thehighestindividual_index = 0;
				for (int i = 0; i < valid_hand_size; ++i){
					if (this_frequencyTable[i] == frequency_onepair){
						this_lastofgroup_index = i;
					}
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (this_frequencyTable[i] == frequency_none){
						this_thehighestindividual_index = i;
						break;
					}
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frequency_onepair){ another_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (another_frequencyTable[i] == frequency_none){
						another_thehighestindividual_index = i;
						break;
					}
				}

				if (hand_[this_lastofgroup_index].rank_ == another.hand_[another_lastofgroup_index].rank_){ return hand_[this_thehighestindividual_index].rank_ < another.hand_[another_thehighestindividual_index].rank_; }
				else{ return hand_[this_lastofgroup_index].rank_ < another.hand_[another_lastofgroup_index].rank_; }


			}
		}

	}

}

// the string method for hand returns a string representation of the hand
string Hand::str(){
	// dictionary fto translate enum for rank and suits to strings
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
	//dictionary for converting rank of hands(enum) to strings
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
	// if rank is unranked, we want to also return information about the leading card
	if (hand_rank == unranked){
		string leading_card = trans[this->hand_[(this->hand_).size() - 1].rank_] + " " + "of" + " " + trans[this->hand_[(this->hand_).size() - 1].suit_];
		msg << "This hand is a " << trans_hand[hand_rank] <<" with leading Card "<<leading_card<<endl;
	}

	else{ msg << "This hand is a " << trans_hand[hand_rank] << endl; }
	msg << "////////////////////////" << endl;
	ostringstream allcard;

	//Get the string of cards in the hand
	for (unsigned int i = 0; i < (this->hand_).size(); i++){
		allcard << trans[this->hand_[i].rank_] << " of " <<trans[ this->hand_[i].suit_ ]<< endl;
	}
	string msgg = msg.str() + allcard.str();
	return msgg;
}

string Hand::naive_string(){
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
	//dictionary for converting rank of hands(enum) to strings
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
	// if rank is unranked, we want to also return information about the leading card
	if (hand_rank == unranked){
		string leading_card = trans[this->hand_[(this->hand_).size() - 1].rank_] + " " + "of" + " " + trans[this->hand_[(this->hand_).size() - 1].suit_];
		msg << "This hand is a " << trans_hand[hand_rank] << " with leading Card " << leading_card << endl;
	}


	else{ msg << "This hand is a " << trans_hand[hand_rank] << endl; }
	msg << "////////////////////////" << endl;
	ostringstream allcard;
	//Get the string of cards in the hand
	for (unsigned int i = 0; i < (this->hand_).size(); i++){
		allcard << trans[this->hand_[i].rank_] <<  trans[this->hand_[i].suit_] << endl;
	}
	string msgg = msg.str() + allcard.str();
	return msgg;
}