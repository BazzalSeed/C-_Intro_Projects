// lab2_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Deck.h"
#include "Hand.h"
#
using namespace std;




bool poker_rank(const Hand & lhand, const Hand & rhand){
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

	Hand_rank left_handrank = lhand.rank();
	Hand_rank right_handrank = rhand.rank();



	//this->hand_.size() -1 gives the index of the largest element (since sorted ascendingly)
	//the other ints are initialized with the same reason
	int max_index = (lhand).size() - 1;
	int second_largest_index = (lhand).size() - 2;
	int third_largest_index = (lhand).size() - 3;
	int fourth_largest_index = (lhand).size() - 4;
	int fifth_largest_index = (lhand).size() - 5;
	//Compares the rank of hands
	if (left_handrank != right_handrank){
		return left_handrank < right_handrank;
	}
	// if hand rank is the same, there are following cases

	else{
		// if the rank of hands are straihgt, straight flush, flush, or unranked, we simply compared the last card's rank (largest since sorted)
		if (left_handrank == straight_flush || flush_ || straight_ || unranked){
			return ((lhand.hand_[max_index]) < rhand.hand_[max_index]);
		}
		// if not one of above, we initialize a frequency table for this hand and another hand
		else{
			vector<int> lefthand_frequencyTable(lhand.size());

			//create frequency table for this hand
			for (int i = 0; i < valid_hand_size; i++){
				int leading_count = 1;

				for (int j = i + 1; j < valid_hand_size; j++){


					if (lhand.hand_[i].rank_ == lhand.hand_[j].rank_) {

						leading_count++;
					}
				}
				lefthand_frequencyTable[i] = leading_count;
			}

			vector<int> righthand_frequencyTable(rhand.size());

			//create frequency table for another hand
			for (int i = 0; i < valid_hand_size; i++){
				int leading_count = 1;

				for (int j = i + 1; j < valid_hand_size; j++){


					if (rhand.hand_[i].rank_ == rhand.hand_[j].rank_) {

						leading_count++;
					}
				}
				righthand_frequencyTable[i] = leading_count;
			}


			//for four of a kind, we find the last index of the group of fourcard and the index of the individual card
			// then compare the rank of group of four card, if equal compare the rank of inidivdual card
			if (left_handrank == fourofkind){

				// initialize intergers gonna be sued
				int this_lastofgroup_index = 0;
				int this_thehighestindividual_index = 0;
				int another_lastofgroup_index = 0;
				int another_thehighestindividual_index = 0;

				//find the last index of the group of four cards for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frquency_fourofakind){
						this_lastofgroup_index = i;
					}
				}

				//find the index of individual card for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_none){
						this_thehighestindividual_index = i;
						break;
					}
				}

				//find the last index of the group of four cards for another hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frquency_fourofakind){ another_lastofgroup_index = i; }
				}

				//find the index of individual card for another hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_none){
						another_thehighestindividual_index = i;
						break;
					}
				}

				// then compare the rank of group of four card, if equal compare the rank of inidivdual card

				if( lhand.hand_[this_lastofgroup_index].rank_ == rhand.hand_[another_lastofgroup_index].rank_){ return lhand.hand_[this_thehighestindividual_index].rank_ < rhand.hand_[another_thehighestindividual_index].rank_; }
				else{ return lhand.hand_[this_lastofgroup_index].rank_ < rhand.hand_[another_lastofgroup_index].rank_; }


			}
			// if it is three of a kind 
			// we use the exact same logic
			if (left_handrank == three_of_kind){
				int this_lastofgroup_index = 0;
				int this_thehighestindividual_index = 0;
				int another_lastofgroup_index = 0;
				int another_thehighestindividual_index = 0;

				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_threeofakind){ this_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_none){ this_thehighestindividual_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_threeofakind){ another_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_none){ another_thehighestindividual_index = i; }
				}
				if (lhand.hand_[this_lastofgroup_index].rank_ == rhand.hand_[another_lastofgroup_index].rank_){ return lhand.hand_[this_thehighestindividual_index].rank_ < rhand.hand_[another_thehighestindividual_index].rank_; }
				else{ return lhand.hand_[this_lastofgroup_index].rank_ < rhand.hand_[another_lastofgroup_index].rank_; }

			}
			// if it is two pairs, we need to get the index of the first pair and the second pair. and the index of the individual card
			if (left_handrank == two_pars){

				//ints intiailized for future uses
				int this_lastofgroup_index = 0;
				int this_firstpair_lastofgroup_index = 0;
				int this_thehighestindividual_index = 0;
				int another_lastofgroup_index = 0;
				int another_thehighestindividual_index = 0;
				int another_firstpair_lastofgroup_index = 0;

				// find the index of the highest pair for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_twopairs){ this_lastofgroup_index = i; }
				}
				//find the index of the second pair for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_none){ this_thehighestindividual_index = i; }
				}
				// find the index of the individual card for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_none){ this_firstpair_lastofgroup_index = i; break; }
				}
				// do same things for another hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_twopairs){ another_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_none){ another_thehighestindividual_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_none){ another_firstpair_lastofgroup_index = i; break; }
				}
				// if first and second pairs are all with same ranks, compare the indivudual card
				// if first pair is the same, compare the second pair's rank
				// if the first pair is different in rank, compare them
				if (lhand.hand_[this_lastofgroup_index].rank_ == rhand.hand_[another_lastofgroup_index].rank_){
					if (lhand.hand_[this_firstpair_lastofgroup_index].rank_ == rhand.hand_[another_firstpair_lastofgroup_index].rank_){ return (lhand.hand_[this_thehighestindividual_index].rank_ < rhand.hand_[another_thehighestindividual_index].rank_); }
					return  lhand.hand_[this_firstpair_lastofgroup_index].rank_ < rhand.hand_[another_firstpair_lastofgroup_index].rank_;
				}
				else{ return lhand.hand_[this_thehighestindividual_index].rank_ < rhand.hand_[another_thehighestindividual_index].rank_; }
			}
			//this logic is the same as four of a kind
			if (left_handrank == full_house){
				int this_lastofgroup_index = 0;
				int this_firstpair_lastofgroup_index = 0;
				int another_lastofgroup_index = 0;
				int another_firstpair_lastofgroup_index = 0;
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_fullhouse_largest){ this_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_fullhouse_secondlargest){ this_firstpair_lastofgroup_index = i; }
				}

				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_fullhouse_largest){ another_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_fullhouse_secondlargest){ another_firstpair_lastofgroup_index = i; }
				}
				if (lhand.hand_[this_lastofgroup_index].rank_ == rhand.hand_[another_lastofgroup_index].rank_){ return lhand.hand_[this_firstpair_lastofgroup_index].rank_ < rhand.hand_[another_firstpair_lastofgroup_index].rank_; }
				else{ return lhand.hand_[this_lastofgroup_index].rank_ < rhand.hand_[another_lastofgroup_index].rank_; }
			}

			// this logic is the same as four of a kind
			if (left_handrank == one_pair){
				int this_lastofgroup_index = 0;
				int this_thehighestindividual_index = 0;
				int another_lastofgroup_index = 0;
				int another_thehighestindividual_index = 0;
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_onepair){
						this_lastofgroup_index = i;
					}
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_none){
						this_thehighestindividual_index = i;
						break;
					}
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_onepair){ another_lastofgroup_index = i; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_none){
						another_thehighestindividual_index = i;
						break;
					}
				}

				if (lhand.hand_[this_lastofgroup_index].rank_ == rhand.hand_[another_lastofgroup_index].rank_){ return lhand.hand_[this_thehighestindividual_index].rank_ < rhand.hand_[another_thehighestindividual_index].rank_; }
				else{ return lhand.hand_[this_lastofgroup_index].rank_ < rhand.hand_[another_lastofgroup_index].rank_; }


			}
		}

	}

}












int usage_message(char* filename){
	/*
	usage message" function that (1) prints out (to the program's standard output stream) the program's name followed by a helpful usage message
	telling the user how to run the program correctly (with the name of the program and the name of a file to read, e.g., lab0 card_file.txt),
	and (2) returns a non-zero value (int 2).*/
	cerr << "usage: " << filename << " <input_file_name>" << "is incorrect" << endl;
	cerr << "plesae enter a valid file name (file must be at the same directory) directly follow the program name using the command line" << endl;
	cerr << "for example: " << "lab0_Seed.exe card_file.txt" << endl;
	// return int 2
	return WRONG_NUMBER_ARGUMENTS;
}

int main(int argc, char* argv[])
{    	// check weather the commandline arugments are valid (length 2)
	/*
	if (argc != correct_number_of_arguments)
	{
	// if not, usage_message called to print out guidance for user and return the corresponding error type (int)
	int error = usage_message(argv[Program_name]);
	return error;
	}

	//the user passed in correct number of arguments
	else{

	Deck test_deck(argv[command_name]);

	cout << test_deck;
	}
	return SUCCESS;
	*/

	Card n1{ Rank(two), Suite(clubs) };
	Card n2{ Rank(two), Suite(clubs) };
	Card n3{ Rank(two), Suite(clubs) };
	Card n4{ Rank(two), Suite(clubs) };
	Card n5{ Rank(three), Suite(clubs) };
	vector<Card> load = { n1, n2, n3,n4,n5 };
	Hand test_hand1 = Hand(load);  
	Hand test_hand2;
	cout << test_hand1 << endl;
	cout << (test_hand2 == test_hand1) << endl;
	test_hand2 = test_hand1;
	cout << test_hand2 << endl;
	cout << test_hand2.rank() << endl;

}

