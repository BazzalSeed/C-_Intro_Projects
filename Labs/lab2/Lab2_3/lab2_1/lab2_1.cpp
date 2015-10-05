// lab2_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Deck.h"
#include "Hand.h"

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
		return left_handrank > right_handrank;
	}
	// if hand rank is the same, there are following cases

	else{
		// if the rank of hands are straihgt, straight flush, flush, or unranked, we simply compared the last card's rank (largest since sorted)
		if (left_handrank == straight_flush || flush_ || straight_ || unranked){
			return lhand.reversecomp( rhand );
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
				
				int another_lastofgroup_index = 0;
			

				//find the last index of the group of four cards for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frquency_fourofakind){
						this_lastofgroup_index = i;
						break;
					}
				}

				

				//find the last index of the group of four cards for another hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frquency_fourofakind){ another_lastofgroup_index = i; }
					break;
				}

			

				// then compare the rank of group of four card, if equal compare the rank of inidivdual card

                return lhand.hand_[this_lastofgroup_index].rank_ > rhand.hand_[another_lastofgroup_index].rank_; 


			}
			// if it is three of a kind 
			// we use the exact same logic
			else if (left_handrank == three_of_kind){
				int this_lastofgroup_index = 0;
				
				int another_lastofgroup_index = 0;
				

				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_threeofakind){ this_lastofgroup_index = i; }
					break;
				}
				
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_threeofakind){ another_lastofgroup_index = i; }
					break;
				}
				
			 return lhand.hand_[this_lastofgroup_index].rank_ > rhand.hand_[another_lastofgroup_index].rank_; 

			}
			// if it is two pairs, we need to get the index of the first pair and the second pair. and the index of the individual card
			else if (left_handrank == two_pars){

				Card left_high_pair;
				Card right_high_pair;
				//ints intiailized for future uses
				int this_lastofgroup_index = 0;
				int this_firstpair_lastofgroup_index = 0;
				
				int another_lastofgroup_index = 0;
			
				int another_firstpair_lastofgroup_index = 0;

				// find the index of the highest pair for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_twopairs){ 
						this_lastofgroup_index = i;
						left_high_pair = lhand.hand_[i];

					}
				}
				
				
				// find the index of the individual card for this hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_twopairs&&lhand.hand_[i]!= left_high_pair){ this_firstpair_lastofgroup_index = i; break; }
				}
				// do same things for another hand
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_twopairs){ another_lastofgroup_index = i;
					right_high_pair = rhand.hand_[i];
					}
				}
				
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_twopairs && rhand.hand_[i]!= right_high_pair){ another_firstpair_lastofgroup_index = i; break; }
				}
				// if first and second pairs are all with same ranks, compare the indivudual card
				// if first pair is the same, compare the second pair's rank
				// if the first pair is different in rank, compare them
				if (lhand.hand_[this_lastofgroup_index] == rhand.hand_[another_lastofgroup_index]){
					return lhand.hand_[this_firstpair_lastofgroup_index] >rhand.hand_[another_firstpair_lastofgroup_index];
				}
				else{
					return lhand.hand_[this_lastofgroup_index] > rhand.hand_[another_lastofgroup_index];

				}
			
			
			}
			//this logic is the same as four of a kind
			else if (left_handrank == full_house){
				int this_lastofgroup_index = 0;
				int this_firstpair_lastofgroup_index = 0;
				int another_lastofgroup_index = 0;
				int another_firstpair_lastofgroup_index = 0;
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_fullhouse_largest){ this_lastofgroup_index = i; break; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_fullhouse_secondlargest){ this_firstpair_lastofgroup_index = i; break; }
				}

				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_fullhouse_largest){ another_lastofgroup_index = i; break; }
				}
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_fullhouse_secondlargest){ another_firstpair_lastofgroup_index = i; break; }
				}


				if (lhand.hand_[this_lastofgroup_index] == rhand.hand_[another_lastofgroup_index]){
					return lhand.hand_[this_firstpair_lastofgroup_index] >rhand.hand_[another_firstpair_lastofgroup_index];
				}
				else{
					return lhand.hand_[this_lastofgroup_index] > rhand.hand_[another_lastofgroup_index];

				}
			}

			// this logic is the same as four of a kind
			else if (left_handrank == one_pair){
				int this_lastofgroup_index = 0;
			
				int another_lastofgroup_index = 0;

				for (int i = 0; i < valid_hand_size; ++i){
					if (lefthand_frequencyTable[i] == frequency_onepair){
						this_lastofgroup_index = i;
						break;
					}
				}
				
				for (int i = 0; i < valid_hand_size; ++i){
					if (righthand_frequencyTable[i] == frequency_onepair){ another_lastofgroup_index = i;
					break;
					}
				}
			

				return lhand.hand_[this_lastofgroup_index] > rhand.hand_[another_lastofgroup_index];
		

			}
		}

	}

}












int usage_message(char* argv[], int number_of_argument, bool & will_be_shuffled, int & file_name_index){
	/*
	usage message" function that (1) prints out (to the program's standard output stream) the program's name followed by a helpful usage message
	telling the user how to run the program correctly (with the name of the program and the name of a file to read, e.g., lab0 card_file.txt),
	and (2) returns a non-zero value (int 2).*/
	will_be_shuffled = false;
	file_name_index = first_avaialbe_position;
	if (number_of_argument > max_command_line_length){
		cout << "more than 2 command line arguments are given" << endl;
		cout << "plesae enter a valid file name (file must be at the same directory) directly follow the program name using the command line or one more optional -shuffle argument (-shuffle and file name can be in either order)" << endl;
		cout << "for example: " << "lab2_1.exe card_file.txt -shuffle" << endl;
		return morethantwo_argument;
	}
	else if (number_of_argument == not_valid_commandline_length){
		cout << "no command line arguments are given " << endl;
		cout << "plesae enter a valid file name (file must be at the same directory) directly follow the program name using the command line or one more optional -shuffle argument (-shuffle and file name can be in either order)" << endl;
		cout << "for example: " << "lab2_1.exe card_file.txt -shuffle" << endl;
		return no_argument;
	}

	else if (number_of_argument == minimum_command_line_length){
		string cppstring(argv[first_avaialbe_position]);
		if (cppstring == "-shuffle"){
			cout << "only one command line argument is given but it contains  - shuffle.  " << endl;
			cout << "plesae enter a valid file name (file must be at the same directory) directly follow the program name using the command line or one more optional -shuffle argument (-shuffle and file name can be in either order)" << endl;
			cout << "for example: " << "lab2_1.exe card_file.txt -shuffle" << endl;
			return onlyone_is_shuffle;
		}
		will_be_shuffled = false;
		file_name_index = first_avaialbe_position;
		return Success_commandline;
	}
	else {
		int count_shuffle = 0;
		int index_of_shuffle = second_avaiable_position;
		for (int i = 0; i < number_of_argument; ++i){
			string cppstring(argv[i]);
			if (cppstring == "-shuffle"){
		
				will_be_shuffled = true;
				count_shuffle = count_shuffle+1;
				index_of_shuffle = i;
				
			}
		}

	
		if (count_shuffle == 2){
			
			cout << "two command line arguments are given but both are - shuffle.   " << endl;
			cout << "plesae enter a valid file name (file must be at the same directory) directly follow the program name using the command line or one more optional -shuffle argument (-shuffle and file name can be in either order)" << endl;
			cout << "for example: " << "lab2_1.exe card_file.txt -shuffle" << endl;
			return two_both_shuffle;
		}
		if (index_of_shuffle == second_avaiable_position){
			file_name_index = first_avaialbe_position;
		}
		if (index_of_shuffle == first_avaialbe_position){
			file_name_index = second_avaiable_position;
		}
		if (!will_be_shuffled){
			cout << "two command line arguments are given but neither one contains - shuffle.   " << endl;
			cout << "plesae enter a valid file name (file must be at the same directory) directly follow the program name using the command line or one more optional -shuffle argument (-shuffle and file name can be in either order)" << endl;
			cout << "for example: " << "lab2_1.exe card_file.txt -shuffle" << endl;
			return two_neither_shuffle;
		}
		return Success_commandline;
	}
    
}

int main(int argc, char* argv[])
{    	
	// check weather the commandline arugments are valid (length 2)
	bool will_be_shuffled = false;
	int file_name_index = 1;
	int commandline_usermsg_result;
	commandline_usermsg_result = usage_message(argv, argc, will_be_shuffled, file_name_index);
	
	//termiante the program, if commandline does not hvae a success result.
	if (commandline_usermsg_result != Success_commandline){ return commandline_usermsg_result; }
	try{


		Deck deck(argv[file_name_index]); 
		//The program should then push back nine empty hand objects into an STL container (e.g., of type vector<Hand> or list<Hand>). 
		cout << "Printing out the deck after initial construction" << endl;
		cout << deck << endl;
		cout << "<----------------------------------------------------------------------------->" << endl;
		if (will_be_shuffled){
			deck.Shuffle();
			cout << "Printing out the deck after shuffle" << endl;
			cout << deck << endl;
		}
		Hand hand;
		vector<Hand> Nine_hands(number_of_hands_inContainer, hand);
		//The program should then use the insertion operator you defined above to "deal" one card at a time from the deck to each of the nine hands in the container in turn, repeating the rotation until each of the hands has five cards. 

		// since we are having a vector holding nine hand, we have to have at least 45 cards in the deck
		if (deck.size() < minimum_cardsindeck_todealcards){
			cout << "Deck does not have at least 45 cards. Cannot start dealing cards process" << endl;
			return deck_not_atleast45cards;
		}

		// Use insertion to insert card from loaded deck to each hand

		bool not_allhands_full = true;

		while (deck.size() != 0 && not_allhands_full){

			for (unsigned int i = 0; i < Nine_hands.size(); ++i){
				Nine_hands[i] << deck;

			}

			for (unsigned int j = 0; j < Nine_hands.size(); ++j){
				if (Nine_hands[j].isnotfull()){
					not_allhands_full = true;
					break;
				}
				not_allhands_full = false;
			}


		}


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
		//The program should then print out the contents of the deck object and the contents of each of the hand objects to which the cards were dealt. 
		
		cout << "Remaining Deck contents after Insertion" << endl;
		cout << deck << endl;
		cout << "<----------------------------------------------------------------------------->" << endl;
		cout << "Each hand contents after Insertion" << endl;
		for (size_t i = 0; i < Nine_hands.size(); i++)
		{
			cout << Nine_hands[i] << endl;

		}
		cout << "<----------------------------------------------------------------------------->" << endl;
		cout << "After Sorting using member-method operator<" << endl;
		sort(Nine_hands.begin(), Nine_hands.end());
		for (size_t i = 0; i < Nine_hands.size(); i++)
		{
			
			cout << Nine_hands[i] << endl;
			

		}
		cout << "<----------------------------------------------------------------------------->" << endl;
		cout << "After using custom parse_rank function" << endl;
		sort(Nine_hands.begin(), Nine_hands.end(), poker_rank);
		for (size_t i = 0; i < Nine_hands.size(); i++)
		{
			// can print out the rank by the hand
			//but Dr.GIll does not like it :(
			//cout << trans_hand[Nine_hands[i].rank()] << endl;
			cout << Nine_hands[i] << endl;
			//cout << "<-------------->" << endl;

		}
	
	
	
	}
	catch (int i){
		return i;
	}
    

	
	return SUCCESS;

}


