#include "stdafx.h"
#include "FiveCardDraw.h"
#include "Game.h"
#include "Deck.h"
#include <Math.h>
//#include "PlayerState.h"


using  namespace std;

////////////////////////////////////////
// Utility Functions                 ///
////////////////////////////////////////

//different hand ranks
static const std::string handRanks[] = { "no_rank", "one_pair", "two_pairs", "three_kind", "straight", "flush", "full_house", "four_kind", "straight_flush" };

//parse response and return a vector of valid positions for discarding player's cards
//NOTE: vector[0] used to store number of invalid positions that user entered
bool is_anumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	//traverse the string until a character is not a digit
	while (it != s.end() && isdigit(*it)) {
		++it;
	}
	return !s.empty() && it == s.end();
}


vector<int> valid_input_positions(string response, unsigned int hand_size){

	istringstream ss(response);
	vector<int> user_inputs;
	user_inputs.push_back(0);
	string temp;

	while (ss >> temp){
		//convert string to numerical value
		if (!is_anumber(temp)){ cout << "Detecting non-numeric position value from user input" << endl; ++user_inputs[0]; continue; }
		size_t check = stoi(temp);

		//valid positions
		if (check >= 0 && check < hand_size){
			user_inputs.push_back(check);
		}
		else{
			cout << "detecting invliad position from user" << ": " << check << endl;
			//increment the counter for invalid positions
			++user_inputs[0];
		}
	}



	return user_inputs;
}



//get information if hand rank is two pairs
std::vector<int> getTwoPairsInfo(const std::vector<Card> &cardsInHand){
	//twoPairsInfo[0] = rank of highest pair
	//twoPairsInfo[1] = rank of second highest pair
	//twoPairsInfo[2] = rank of fifth card
	std::vector<int> twoPairsInfo;
	if (cardsInHand[3].rank == cardsInHand[4].rank){
		twoPairsInfo.push_back(cardsInHand[4].rank);
		if (cardsInHand[1].rank == cardsInHand[2].rank){
			twoPairsInfo.push_back(cardsInHand[2].rank);
			twoPairsInfo.push_back(cardsInHand[0].rank);
		}
		else{
			twoPairsInfo.push_back(cardsInHand[0].rank);
			twoPairsInfo.push_back(cardsInHand[2].rank);
		}
	}
	else{
		twoPairsInfo.push_back(cardsInHand[2].rank);
		twoPairsInfo.push_back(cardsInHand[0].rank);
		twoPairsInfo.push_back(cardsInHand[4].rank);
	}
	return twoPairsInfo;
}

//get information if hand rank is one pair
std::vector<int> getOnePairInfo(const std::vector<Card> &cardsInHand){
	//onePairInfo[0] = rank of the pair
	//onePairInfo[1] = highest rank of unpaired card
	//onePairInfo[2] = next highest rank of unpaired card
	//onePairInfo[3] = next highest rank of unpaired card
	std::vector<int> onePairInfo;
	if (cardsInHand[0].rank == cardsInHand[1].rank){
		onePairInfo.push_back(cardsInHand[0].rank);
		onePairInfo.push_back(cardsInHand[4].rank);
		onePairInfo.push_back(cardsInHand[3].rank);
		onePairInfo.push_back(cardsInHand[2].rank);
	}
	else if (cardsInHand[1].rank == cardsInHand[2].rank){
		onePairInfo.push_back(cardsInHand[1].rank);
		onePairInfo.push_back(cardsInHand[4].rank);
		onePairInfo.push_back(cardsInHand[3].rank);
		onePairInfo.push_back(cardsInHand[0].rank);
	}
	else if (cardsInHand[2].rank == cardsInHand[3].rank){
		onePairInfo.push_back(cardsInHand[2].rank);
		onePairInfo.push_back(cardsInHand[4].rank);
		onePairInfo.push_back(cardsInHand[1].rank);
		onePairInfo.push_back(cardsInHand[0].rank);
	}
	else{
		onePairInfo.push_back(cardsInHand[4].rank);
		onePairInfo.push_back(cardsInHand[2].rank);
		onePairInfo.push_back(cardsInHand[1].rank);
		onePairInfo.push_back(cardsInHand[0].rank);
	}
	return onePairInfo;
}

//compare two hands
bool poker_rank(const Hand &hand2, const Hand &hand1){
	//use hand rank to decide if two hand ranks are different
	if (hand1.getRank() != hand2.getRank()){
		return hand1.getRank() < hand2.getRank();
	}
	else{
		std::vector<Card> cardsInHand = hand1.getCards();
		std::vector<Card> cardsInHand2 = hand2.getCards();
		//get vectors that contain information in the case of two pairs and one pair
		std::vector<int> info1 = getTwoPairsInfo(cardsInHand);
		std::vector<int> info2 = getTwoPairsInfo(cardsInHand2);
		std::vector<int> info3 = getOnePairInfo(cardsInHand);
		std::vector<int> info4 = getOnePairInfo(cardsInHand2);

		switch (hand1.getRank()){
		case Rank::straight_flush:
			//sorted by highest card in each hand
			return cardsInHand[4].operator<(cardsInHand2[4]);

		case Rank::four_kind:
			//sorted by rank of 4 cards that have the same rank
			return cardsInHand[2].rank < cardsInHand2[2].rank;

		case Rank::full_house:
			//sorted by rank of 3 cards that have the same rank
			//then by rank of 2 cards that have the same rank
			if (cardsInHand[2].rank == cardsInHand2[2].rank){
				return 1;
			}
			else{
				return cardsInHand[2].rank < cardsInHand2[2].rank;
			}

		case Rank::flush:
			//sorted by highest ranking card, then by next highest ranking card, etc
			for (std::vector<Card>::size_type i = cardsInHand.size() - 1; i != 0; i--){
				if (cardsInHand[i].rank != cardsInHand2[i].rank){
					return cardsInHand[i].rank < cardsInHand2[i].rank;
				}
			}
			return cardsInHand[0].rank < cardsInHand2[0].rank;

		case Rank::straight:
			//sorted by highest card in each hand
			return cardsInHand[4].operator<(cardsInHand2[4]);

		case Rank::three_kind:
			//sorted by the rank of the 3 cards that have the same rank
			return cardsInHand[2].rank < cardsInHand2[2].rank;

		case Rank::two_pairs:
			//sorted by the rank of higher pair, then by lower pair, then  by 5th card
			if (info1[0] != info2[0]){
				return info1[0] < info2[0];
			}
			else{
				if (info1[1] != info2[1]){
					return info1[1] < info2[1];
				}
				else{
					return info1[2] < info2[2];
				}
			}


		case Rank::one_pair:
			//sorted by the rank of the pair, then by the highest unpaired card
			//then next highest card, etc
			if (info3[0] != info4[0]){
				return info3[0] < info4[0];
			}
			else{
				if (info3[1] != info4[1]){
					return info3[1] < info4[1];
				}
				else{
					if (info3[2] != info4[2]){
						return info3[2] < info4[2];
					}
					else{
						return info3[3] < info4[3];
					}
				}
			}

		case Rank::no_rank:
			//sorted by highest ranking card, then by next highest ranking card
			for (std::vector<Card>::size_type i = cardsInHand.size() - 1; i != 0; i--){
				if (cardsInHand[i].rank != cardsInHand2[i].rank){
					return cardsInHand[i].rank < cardsInHand2[i].rank;
				}
			}
			return cardsInHand[0].rank < cardsInHand2[0].rank;

		default:
			return false;

		}
	}
}




////////////////////////////////////////////////
// Class Method Implementation                //
///////////////////////////////////////////////

//default constructor
FiveCardDraw::FiveCardDraw(){
	//initialize dealer position to zero
	dealer_position = 0;

	//intialize common pot of chips
	chips_pot = 0;

	most_recent_bet_position = -1;

	//generate 52 combinations of cards and add them to main deck
	Card curr_card;
	for (int suitIdx = Card::Suit::clubs; suitIdx != Card::Suit::spades; ++suitIdx){
		for (int rankIdx = Card::Rank::two; rankIdx != Card::Rank::ace; ++rankIdx){
			curr_card.rank = static_cast<Card::Rank>(rankIdx);
			curr_card.suit = static_cast<Card::Suit>(suitIdx);
			main_deck.add_card(curr_card);
		}
	}
}


//Helper Function for extra credit
//generate positions to discard for auto_player. Note: position 0 is the counter

vector<int>	FiveCardDraw::auto_valid_positions(Player &player){

	enum hand_rank{
		no_rank,
		one_pair,
		two_pairs,
		three_kind,
		straight,
		flush,
		full_house,
		four_kind,
		straight_flush
	};

	enum card_Rank{
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		jack,
		queen,
		king,
		ace
	};


	player.player_hand.setHandRank();
	vector<int> valid_positions;
	valid_positions.push_back(0);


	//straight flush, full house, straight, or flush: do not discard or receive any cards;
	if ((player.getPlayerHand().getRank() == straight_flush) || (player.getPlayerHand().getRank() == full_house) || (player.getPlayerHand().getRank() == straight) || (player.getPlayerHand().getRank() == flush)) {

		return valid_positions;
	}
	//four of a kind or two pair: discard the unmatched card and receive one more card;

	else if (player.getPlayerHand().getRank() == four_kind){
		if (!(player.player_hand[0].rank == player.player_hand[1].rank)){

			valid_positions.push_back(0);
		}
		else{
			valid_positions.push_back(player.player_hand.size() - 1);
		}
		return valid_positions;
	}

	else if (player.getPlayerHand().getRank() == two_pairs){
		vector<int> two_pairs = getTwoPairsInfo(player.player_hand.getCards());
		vector<Card> myhand = player.player_hand.getCards();
		vector<int> vec_hand_rank;
		for (auto i : myhand){
			vec_hand_rank.push_back(i.rank);
		}
		int pos = find(vec_hand_rank.begin(), vec_hand_rank.end(), two_pairs[2]) - vec_hand_rank.begin();
		valid_positions.push_back(pos);

		return valid_positions;
	}
	//three of a kind: discard the two unmatched cards and receive two more cards;


	else if (player.getPlayerHand().getRank() == three_kind){

		vector<Card> myhand = player.player_hand.getCards();
		if (myhand[0].rank == myhand[1].rank && myhand[1].rank == myhand[2].rank){

			valid_positions.push_back(myhand.size() - 1);
			valid_positions.push_back(myhand.size() - 2);

		}
		else if (myhand[1].rank == myhand[2].rank && myhand[2].rank == myhand[3].rank){
			valid_positions.push_back(0);
			valid_positions.push_back(myhand.size() - 1);
		}
		else{
			valid_positions.push_back(0);
			valid_positions.push_back(1);
		}
		return valid_positions;
	}

	//one pair: discard the three unmatched cards and receive three more cards;
	else if (player.getPlayerHand().getRank() == one_pair){
		vector<int> one_pair = getOnePairInfo(player.player_hand.getCards());
		vector<Card> myhand = player.player_hand.getCards();
		vector<int> vec_hand_rank;
		for (auto i : myhand){
			vec_hand_rank.push_back(i.rank);
		}
		for (int i = 1; i <= 3; ++i){
			int pos = find(vec_hand_rank.begin(), vec_hand_rank.end(), one_pair[i]) - vec_hand_rank.begin();
			valid_positions.push_back(pos);
		}
		return valid_positions;
	}
	else{
		vector<Card> myhand = player.player_hand.getCards();
		bool aced = false;
		int aced_index;
		for (size_t i = 0; i < myhand.size(); ++i){
			if (myhand[i].rank == ace){
				aced = true;
				aced_index = i;
				break;
			}
		}
		if (aced){
			for (size_t i = 0; i < myhand.size(); ++i){
				if (aced_index != i){
					valid_positions.push_back(i);
				}
			}

		}
		else{
			for (size_t i = 0; i < 3; ++i){
				valid_positions.push_back(i);
			}
		}
		return valid_positions;
	}


}

//method called before the given player's turn
int FiveCardDraw::before_turn(Player &player){
	if (player.status == out_of_round || player.status == chip_run_out){
		return Success;
	}
	//print player's name and his hand
	bool is_autoPlayer = false;
	player.player_hand.setHandRank();
	string info = player.player_name + " " + player.player_hand.asString();
	cout << info << endl;

	vector<int> user_inputs;

	char last = player.player_name[player.player_name.length() - 1];

	if (last == '*'){
		cout << "Automated Player: " << info << " " << "is playing" << endl;

		user_inputs = auto_valid_positions(player);

	}
	else{
		//prompt the user to discard cards
		cout << "Please give positions of cards you want to discard" << endl;

		//get user response and parse it to get a vector of valid positions for discarding cards
		string response;
		getline(cin, response);

		unsigned int size = player.player_hand.size();
		user_inputs = valid_input_positions(response, size);

		//keep re-prompting if reponse is invalid
		while (user_inputs.size() == 1 && user_inputs[0] > 0){
			cout << "Please give positions of cards you want to discard" << endl;
			getline(cin, response);

			user_inputs = valid_input_positions(response, size);


		}

	}



	//discard the cards to discard deck
	try{
		for (unsigned int i = 1; i < user_inputs.size(); ++i){

			//add card to discard deck
			discard_deck.add_card(player.player_hand[user_inputs[i]]);
			//remove card from player's hand

			player.player_hand.remove_card(user_inputs[i]);


			//@updating the user_position vector

			for (unsigned int j = 1; j < user_inputs.size(); ++j){
				if (user_inputs[j] > user_inputs[i]){
					user_inputs[j]--;
				}

			}
		}
	}
	catch (Error error){
		return error;
	}


	return 0;

}


//method called for the given player's turn
int  FiveCardDraw::turn(Player &player){

	if (player.status == out_of_round || player.status == chip_run_out){
		return Success;
	}
	//compute number of replacement needed due to discarding cards
	int NofCards_needed = VALID_HAND_SIZE - (player.player_hand.size());

	//deal cards into player's hand until 5 cards in hand
	while (NofCards_needed > 0){
		//both decks have no cards
		if (main_deck.size() == 0 && discard_deck.size() == 0){
			return no_more_card_for_this_game_go_home;
		}
		//no cards in main deck, shuffle discard deck and deal card from it
		else if (main_deck.size() == 0){
			discard_deck.shuffle();
			player.player_hand << discard_deck;
		}
		//deal card from main deck
		else{
			player.player_hand << main_deck;
		}
		NofCards_needed--;

	}
	return 0;
}


//method called after the given player's turn
int  FiveCardDraw::after_turn(Player &player){
	//print player's name and his hand
	string info = player.player_name + " " + player.player_hand.asString();
	cout << info << endl;
	return 0;

}



//every player adds one chip to pot to participate betting
int FiveCardDraw::participate_betting(){
	//one chip deducted from each player and added to chips_pot
	for (size_t count = 0; count < num_players_in_game(); count++){
		chips_pot++;
		(*players[count]).decrease_chips(CHIP_UNIT);
		if ((*players[count]).get_num_chips() == 0){
			(*players[count]).status = chip_run_out;
		}
	}

	return 0;
}



//determine position of first bet
//if everyone checks, position is -1
int FiveCardDraw::before_betting(size_t  position) {
	//every player puts one chip to pot
	//participate_betting();

	string response;
	//betting starts with the player at the (dealer position + 1)
	for (size_t i = 1; i <= num_players_in_game(); ++i){

		if ((*players[(position + i) % num_players_in_game()]).status == out_of_round || (*players[(position + i) % num_players_in_game()]).status == chip_run_out){
			cout << (*players[(position + i) % num_players_in_game()]).player_name << ": folded or chip run out so Ignored " << endl;
			continue;
		}


		cout << "Here is your hand babe" << endl;
		cout << (*players[(position + i) % num_players_in_game()]).getPlayerHand().asString() << endl;
		cout << (*players[(position + i) % num_players_in_game()]).player_name << ": do you want to check or bet ? " << endl;
		getline(cin, response);

		
		if(response.compare("bet") != 0 && response.compare("check") != 0){
			
			before_betting((position + i-1) % num_players_in_game());
			
			return 0;
		}


		//player bets
		if (response.compare("bet") == 0){
			cout << "Do you want to bet 1 or 2 ? " << endl;
			getline(cin,response);

		

	        //can only bet 1 or 2
			while (    (!is_anumber(response)) || !(stoi(response) == 1 || stoi(response) == 2)){
				cout << "Sorry, you can only bet 1 or 2" << endl;
				cout << "Do you want to bet 1 or 2 ?" << endl;
				getline(cin, response);
			}

			//update current bet value
			//determine position of most recent bet
			current_bet_value = stoi(response);
			most_recent_bet_position = (position + i) % num_players_in_game();


			//update player's bet so far
			(*players[(position + i) % num_players_in_game()]).set_bet_so_far(current_bet_value);



			//////////////////////////////////////////
			cout << "---------- Someone bets ---------------" << endl;
			cout << "Chips in pot: " << chips_pot << endl;
			cout << "Current bet value " << current_bet_value << endl;
			/////////////////////////////////////////

			(*players[(position + i) % num_players_in_game()]).status = raise;
			return 0;
		}
	}


	cout << "------------ all players check -----------------" << endl;
	return 0;
}



//betting process
int FiveCardDraw::betting(){
	//every player checks, no need for betting phase

	all_player_check = true;
	for (size_t i = 0; i < num_players_in_game(); ++i){
		if ((*players[i]).status != chip_run_out && (*players[i]).status!= check) {
			all_player_check = false; 
			break;
		}
	}



	if (all_player_check){
		return 0;
	}

	//one player bets
	else{
		current_position = (most_recent_bet_position + 1)% num_players_in_game();
		string response;

		//every player decides to fold, call or raise
		while (!is_betting_end()){
			
			//player will not participate the betting phase
			//if he runs out of chips or he is already out of round
			if ((*players[current_position]).status != out_of_round || (*players[current_position]).status != chip_run_out){
				cout << "should be three" << endl;
				player_bet(players[current_position]);
			}
			current_position++;
			current_position %= num_players_in_game();
		}

		
	}


	return 0;
}


//award winner the chips in the pot
int FiveCardDraw::after_betting(){
	/*
	//if all players check, no winner and no award
	if (all_player_check){
		cout << "Result: all players check" << endl;

		return 0;
	}
	*/

	

	//put player's bet into pot
	for (size_t i = 0; i < num_players_in_game(); ++i){
		if ((*players[i]).status != out_of_round){
			unsigned int bet = (*players[i]).get_bet_so_far();
			chips_pot += bet;
			(*players[i]).decrease_chips(bet);
		}
	}

	//if all players except oen decide to fold, entire spot is awarded to the remaining player
	if (num_player_fold + 1 == num_players_in_game()){
		size_t i = 0;
		for (; i < num_players_in_game(); ++i){
			if ((*players[i]).status != out_of_round){
				break;
			}
		}

		//award entire pot to the player
		(*players[i]).increase_chips(chips_pot);
		chips_pot = 0;

		cout << "Result: all players except one decide to fold; entire pot is awarded to the remaining player" << endl;
		return 0;
	}

	//determine the number of players with equal highest rank
	unsigned int highest_rank_players = 0;
	for (size_t i = 0; i < num_players_in_game(); ++i){
		if ((*players[i]).getPlayerHand().getRank() == (*players[0]).getPlayerHand().getRank() && (*players[i]).status != out_of_round){
			highest_rank_players++;
		}
		else{
			break;
		}
	}


    //compute the number of chips to split
	unsigned int split = (unsigned int)floor(chips_pot / highest_rank_players);
	cout << "split value " << split << endl;
	cout << "chips in pot: " << chips_pot << endl;

	//split chips to winners
	for (size_t i = 0; i < highest_rank_players; ++i){
		if ((*players[i]).status != out_of_round){
			(*players[i]).increase_chips(split);
		}
	}

	chips_pot = 0;

	cout << "Result: standard" << endl;
	return 0;
}


//check if betting ends
bool FiveCardDraw::is_betting_end(){

	if (num_player_fold + 1 == num_players_in_game()){
		cout << "are you hereb bbbbbbbbbbbbbbbbbb?"<<endl;
		return true;
	}


	for (size_t i = 1; i < num_players_in_game(); ++i){
		//no need to consider when player is out of round or runs out of chips
		if ((*players[(most_recent_bet_position + i) % num_players_in_game()]).status == out_of_round || (*players[(most_recent_bet_position + i) % num_players_in_game()]).status == chip_run_out){
			continue;
		}

		//betting ends if most recent bet or raise is called by all remaining players
		if ((*players[(most_recent_bet_position + i) % num_players_in_game()]).status == raise || (*players[(most_recent_bet_position + i) % num_players_in_game()]).status == not_set){
			return false;
		}
	}

	return true;
}


//player bet
int FiveCardDraw::player_bet(std::shared_ptr<Player> &player){
	
	cout << "----------------- Player " << (*player).player_name << " Start--------------------" << endl;

	cout << "Current chips in the pot: " << chips_pot << endl;
	cout << "Current bet value: " << current_bet_value << endl;
	cout << "Player's bet so far:  " << (*player).get_bet_so_far() << endl;
	cout << "your hand is: " << endl;
	cout << (*player).getPlayerHand().asString() << endl;
	
	cout << "your status " << player->status << endl;
	


	//player runs out of chips, no obligation to call, bet, or raise
	if ((*player).get_bet_so_far() == (*player).get_num_chips()){
		cout << "NOTE: " << (*player).player_name << " runs out of chip, so no obligation to call, bet, or raise" << endl;
		return 0;

	}


	string response;
	unsigned int bet_sofar = (*player).get_bet_so_far();
	cout << (*player).player_name << ": Do you want to fold, call or raise ? " << endl;
	getline(cin, response);
	
	//player folds
	if (response.compare("fold") == 0){
		//player is out of round
		(*player).status = out_of_round;

		//push his bet so far to the bot
		chips_pot += bet_sofar;
		(*player).decrease_chips(bet_sofar);

		//update counter
		num_player_fold++;

	}

	//player calls
	else if (response.compare("call") == 0){
		//update player's bet so far
		(*player).set_bet_so_far(current_bet_value);
		(*player).status = call;
	}

	//player raises
	else if (response.compare("raise") == 0){
		cout << "Amount to raiase: " << endl;
		getline(cin, response);

		//can only raise 1 or 2
		while ((!is_anumber(response)) ||   !(stoi(response) == 1 || stoi(response) == 2) ){
			cout << "Sorry, you can only raise 1 or 2" << endl;
			cout << "Do you want to raise 1 or 2 ?" << endl;
			getline(cin, response);
		}

		//check if player has enough chips for the raise
		int remaining_chips = (*player).get_num_chips() - ((*player).get_bet_so_far() + stoi(response));
		if (remaining_chips < 0){
			cout << "Sorry, you do not have enough chips to raise" << endl;
			
			//not enough to raise 2, but OK to raise 1
			if (stoi(response) == 2 && remaining_chips==-1){
				cout << "TIP: You do not have enough chips to raise 2, but you can raise 1" << endl;
				cout << "Please choose again" << endl;
				return player_bet(player);
			}
		}


		//update player's bet so far
		(*player).set_bet_so_far(current_bet_value + stoi(response));
		current_bet_value += stoi(response);		
		(*player).status = raise;

		//updaate position of most recent bet/raise
		most_recent_bet_position = find(players.begin(), players.end(), player) - players.begin();
	
		//reset status of remaining players
		reset_betting_status(most_recent_bet_position);

	}

	//command not recognized
	else{
		cout << "Sorry, your command is not recognized" << endl;
		return player_bet(player);
	}




	cout << "---------------------------------------------" << endl;
	cout << "Current chips in the pot: " << chips_pot << endl;
	cout << "Current bet value: " << current_bet_value << endl;
	cout << "Player's bet so far:  " << (*player).get_bet_so_far() << endl;
	cout << "Player's chip count: " << (*player).get_num_chips() << endl;
	cout << "----------------- Player " << (*player).player_name << " End --------------------" << endl;

	cout << endl;

	return 0;
}


//reset other player's status if someone raises
void FiveCardDraw::reset_betting_status(size_t raise_index){
	for (size_t i = 1; i < num_players_in_game(); ++i){

		//skip invalid player
		if ((*players[(raise_index + i) % num_players_in_game()]).status == out_of_round || (*players[(raise_index + i) % num_players_in_game()]).status == chip_run_out){
			continue;
		}
		
		if (i != raise_index){
			(*players[(raise_index + i) % num_players_in_game()]).status = not_set;
		}
	}

}

int FiveCardDraw:: reset_afte_firstBetting(){




	


	for (size_t i = 0; i < num_players_in_game(); ++i){

		//skip invalid player
		if ((*players[i]).status == out_of_round || (*players[i]).status == chip_run_out){
			continue;
		}

		if ((*players[i]).status != out_of_round){
			unsigned int bet = (*players[i]).get_bet_so_far();
			chips_pot += bet;
			(*players[i]).decrease_chips(bet);
		}


		//reset player's bet so far and status
		(*players[i]).bet_so_far = 0;
		(*players[i]).status = not_set;
	}


	if (num_player_fold + 1 == num_players_in_game()){
		size_t i = 0;
		for (; i < num_players_in_game(); ++i){
			if ((*players[i]).status != out_of_round){
				break;
			}
		}

		//award entire pot to the player
		(*players[i]).increase_chips(chips_pot);
		chips_pot = 0;

		cout << "Result: all players except one decide to fold; entire pot is awarded to the remaining player" << endl;

		 return too_many_folds;
	}


	//reset bet value for the phase
	current_bet_value = 0;
	return Success;
}





//reset all player's status after a round
void FiveCardDraw::reset_all_status(){
	for (size_t i = 0; i < num_players_in_game(); ++i){
			(*players[i]).status = not_set;
			(*players[i]).bet_so_far = 0;
	}

	//reset game state
	current_bet_value = 0;
	current_position = 0;
	all_player_check = false;
	most_recent_bet_position = -1;
	num_player_fold = 0;
	
}


//after each round, print stats
void FiveCardDraw::print_betting_stats(){
	cout << "------------ Betting Stats ---------------" << endl;
	for (size_t i = 0; i < num_players_in_game(); ++i){
		cout << "----------------------" << endl;
		cout << "Player Name: " << (*players[i]).player_name << endl;
		cout << "Win: " << (*players[i]).hands_won << endl;
		cout << "Loss: " << (*players[i]).hands_lost << endl;
		cout << "Chip Count: " << (*players[i]).get_num_chips() << endl;


		cout << "Chip Bet: " << (*players[i]).get_bet_so_far() << endl;


		
		if ((*players[i]).status == out_of_round){
			cout << "Player Hand: player folded without showing down their hand" << endl;
		}
		else{

			/*
			cout << "Player Hand: " << (*players[i]).getPlayerHand().asString() << endl;
			*/

			cout << "Player Hand: something" << endl;
		}
		

		cout << "----------------------" << endl;
	}
}


//method called before game's round
int  FiveCardDraw::before_round() {
	//too many players to distribute 5 cards to each player
	if ((short)(VALID_HAND_SIZE * players.size()) > (main_deck.size() + discard_deck.size())){
		return too_many_players;
	}







	//shuffle main deck and distribute 5 cards to each player starting from dealer position
	for (int i = 0; i < VALID_HAND_SIZE; ++i){
		main_deck.shuffle();
		for (size_t count = 1; count <= num_players_in_game(); count++){
			(*players[(dealer_position + count) % num_players_in_game()]).player_hand << main_deck;
		}

	}





	//////////////////////////
	cout << "// First betting phase  //" << endl;
	//////////////////////////


	cout << "-------------- Betting Start -----------" << endl;
	participate_betting();
	before_betting(dealer_position);
	betting();
	int reset_after_FirstBetting_result = reset_afte_firstBetting();


	cout << "--------------------user stauts after first bet" << endl;
	for (int i= 0 ; i < num_players_in_game(); i++){
		cout << "player_sta: " << (*players[i]).status << endl;

	}
	if (reset_after_FirstBetting_result != Success){

		return too_many_folds;
	}



	//after_betting();
	//print_betting_stats();
	
	cout << "-------------- Betting End -----------" << endl;






	//call before_turn method on each player
	for (size_t count = 1; count <= num_players_in_game(); count++){
		//check for exception
		int check_before_turn = before_turn(*players[(dealer_position + count) % num_players_in_game()]);

		//return non-zero value to indicate failure
		if (check_before_turn != 0){
			return check_before_turn;
		}

	}



	return 0;

}

//method called for game's round
int FiveCardDraw::round(){
	//call turn and after_turn method on each player
	for (size_t count = 1; count <= num_players_in_game(); count++){
		//call turn on the player
		int check_turn = turn(*players[(dealer_position + count) % num_players_in_game()]);

		//immediately return non-zero value to indicate failure of calling turn method
		if (check_turn != 0){
			return check_turn;
		}

		//call after_turn on the player
		after_turn(*players[(dealer_position + count) % num_players_in_game()]);
	}


	//////////////////////////
	cout << "// second betting phase  //" << endl;
	//////////////////////////


	cout << "-------------- Betting Start -----------" << endl;

	before_betting(most_recent_bet_position - 1);

	betting();

	//after_betting();
	//print_betting_stats();

	cout << "-------------- Betting End -----------" << endl;
	return 0;
}


//method called after game's round
int FiveCardDraw::after_round(){
	//sort players based on their hand rank
	print_sorted_player();
	


	/////////////////////
	// After both Bettings    //
	////////////////////

	
	after_betting();
	print_betting_stats();
	reset_betting_status(most_recent_bet_position);


	//move all cards into main deck
	reset();




	//if a player's chip count is 0, ask him if reset or leave
	string choice;
	for (size_t i = 0; i < num_players_in_game(); i++){
		//find a player with 0 chip count
		if ((*players[i]).get_num_chips() == 0){
			cout << (*players[i]).player_name << ": your chip count is 0" << endl;
			cout << "Do you want to quit the game or reset chip count to 20 and keep playing" << endl;
			cout << "Please enter quit or reset" << endl;
			getline(cin, choice);

			//keep prompting if input is invalid
			while (!(choice.compare("quit") == 0 || choice.compare("reset") == 0)){
				cout << "Do you want to quit the game or reset chip count to 20 and keep playing" << endl;
				cout << "Please enter quit or reset" << endl;
				getline(cin, choice);
			}

			//player quits the game
			if (choice.compare("quit") == 0){
				string s = (*players[i]).player_name;
				ofstream player_file(s + ".txt");
				player_file << *players[i];
				players.erase(players.begin() + i);
				player_file.close();
				terminate();
			}
			//reset player's chip count
			else{
				(*players[i]).increase_chips(20);
			}
		
		}
	}




	//promt the user asking if anyone wants to leave
	string response;
	cout << "Anyone wants to leave?" << endl;

	//parse user response
	getline(cin, response);


	//keep promting the user until saying no
	while (response.compare("no") != 0){

		istringstream player_names(response);
		vector<string> names;
		string temp;
		while (player_names >> temp){
			names.push_back(temp);

		}

		for (size_t i = 0; i < num_players_in_game(); i++)
		{
			for (string s : names){
				//matching player found
				if ((*players[i]).player_name.compare(s) == 0){
					//output statistics to file
					ofstream player_file(s + ".txt");
					player_file << *players[i];
					players.erase(players.begin() + i);
					player_file.close();
					terminate();
				}
			}

		}

		//repromt
		cout << "Anyone wants to leave?" << endl;
		getline(cin, response);

	}

	//promt the user and ask if anyone wants to join
	cout << "Anyone wants to join?" << endl;
	string join_response;
	getline(cin, join_response);





	//keep repromting until saying no
	while (join_response.compare("no") != 0){
		//parse user response
		istringstream player_names_join(join_response);
		vector<string> join_names;
		string join_temp;
		while (player_names_join >> join_temp){
			join_names.push_back(join_temp);

		}

		for (string s : join_names){
			//add player to the game
			try{
				add_player(s);
				//player already in the game
			}
			catch (Error i) {
				cout << "player: " << s << " already playing" << endl;
				cout << "Error code: " << i << endl;
			}
		}

		//reprompt
		cout << "Anyone wants to join?" << endl;
		getline(cin, join_response);

	}

	//increment dealer position
	dealer_position = (dealer_position + 1) % num_players_in_game();
	return 0;
}



//compare player's rank
bool player_rank(const std::shared_ptr<Player> & p1, const std::shared_ptr<Player> &p2){
	//return false if first pointer is singluar
	if (p1 == 0){
		return false;
	}

	//return true if first pointer is non-singluar but second pointer is singular
	if (p1 != 0 && p2 == 0){
		return true;
	}

	//otherwise, return normal comparison result based on their hands
	return poker_rank((*p1).getPlayerHand(), (*p2).getPlayerHand());
}


//print information of sorted players bases on their hand ranks
void FiveCardDraw::print_sorted_player(){

	//make a copy of vector member variable
	vector<shared_ptr<Player>> players_copy = players;

	for (unsigned int i = 0; i < num_players_in_game(); ++i){
		(*players_copy[i]).player_hand.setHandRank();
	}

	//sort
	std::sort(players_copy.begin(), players_copy.end(), player_rank);

	//update game statistics
	for (unsigned int i = 0; i < num_players_in_game(); ++i){
		//increment hands_won for players with highest rank
		//NOTE: we assume it is possible for several players to have the same highest rank
		if (player_rank(players[0], players[i]) == player_rank(players[i], players[0])){
			(*players_copy[i]).hands_won++;
			cout << "winner: " << (*players_copy[i]).player_name << endl;
		}
		//increment hands_lost for players not with highest rank
		else{
			(*players_copy[i]).hands_lost++;
		}
	}

	//print each player's name, hands_won, hands_lost and current hand
	for (unsigned int i = 0; i < players.size(); ++i){
		Player current_player = *players_copy[i];
		cout << "------------" << endl;
		cout << current_player << endl;
		cout << current_player.player_hand.asString() << endl;
		cout << "------------" << endl;
	}

	//handle automated player's leaving
	unsigned int game_size = num_players_in_game();

	for (unsigned int i = 0; i < num_players_in_game() - 1; ++i){
		char last = (*players_copy[i]).player_name[(*players_copy[i]).player_name.length() - 1];
		if (last == '*'){
			if (player_rank(players[0], players[i]) == player_rank(players[i], players[0])){
				highest_automated_leave((*players_copy[i]).player_name);
			}
			else{
				other_automated_leave((*players_copy[i]).player_name);
			}
		}
	}

	//check if automated player with lowest rank will leave
	if (num_players_in_game() > 1){
		char last = (*players_copy[num_players_in_game() - 1]).player_name[(*players_copy[num_players_in_game() - 1]).player_name.length() - 1];
		if (last == '*' && player_rank(players[num_players_in_game() - 1], players[num_players_in_game() - 2]) != player_rank(players[num_players_in_game() - 2], players[num_players_in_game() - 1])){
			lowest_automated_leave((*players_copy[num_players_in_game() - 1]).player_name);
		}
	}
}


void FiveCardDraw::highest_automated_leave(string automated_name){
	unsigned int random_num = rand() % 100;

	if (random_num <= 9){
		for (size_t i = 0; i < num_players_in_game(); i++)
		{
			//matching player found
			if ((*players[i]).player_name.compare(automated_name) == 0){
				//output statistics to file
				ofstream player_file(automated_name.substr(0, automated_name.length() - 1) + "_automated.txt");
				player_file << *players[i];
				players.erase(players.begin() + i);
				player_file.close();


				cout << "Automated player " << automated_name << " leave the game with highest rank with 10%" << endl;
				terminate();
			}
		}
	}
	else{
		cout << "Automated player " << automated_name << " does not leave the game with highest rank with 90%" << endl;
	}
}

void FiveCardDraw::lowest_automated_leave(string automated_name){
	unsigned int random_num = rand() % 100;

	if (random_num <= 89){
		for (size_t i = 0; i < num_players_in_game(); i++)
		{
			//matching player found
			if ((*players[i]).player_name.compare(automated_name) == 0){
				//output statistics to file
				ofstream player_file(automated_name.substr(0, automated_name.length() - 1) + "_automated.txt");
				player_file << *players[i];
				players.erase(players.begin() + i);
				player_file.close();

				cout << "Automated player " << automated_name << " leave the game with lowest rank with 90%" << endl;
				terminate();
			}
		}
	}
	else{
		cout << "Automated player " << automated_name << " does not leave the game with lowest rank with 10%" << endl;
	}

}

void FiveCardDraw::other_automated_leave(string automated_name){
	unsigned int random_num = rand() % 100;
	if (random_num <= 49){
		for (size_t i = 0; i < num_players_in_game(); i++)
		{
			//matching player found
			if ((*players[i]).player_name.compare(automated_name) == 0){
				//output statistics to file
				ofstream player_file(automated_name.substr(0, automated_name.length() - 1) + "_automated.txt");
				player_file << *players[i];
				players.erase(players.begin() + i);
				player_file.close();

				cout << "Automated player " << automated_name << " leave the game with other rank with 50%" << endl;
				terminate();
			}
		}
	}
	else{
		cout << "Automated player " << automated_name << " does not leave the game with other rank with 50%" << endl;
	}

}




//move all cards from players or discard deck into main deck
void FiveCardDraw::reset(){

	//move all cards from players into main deck
	for (unsigned int i = 0; i < num_players_in_game(); ++i){
		int size = (*players[i]).player_hand.size();
		for (int j = 0; j < (size); ++j){
			main_deck.add_card((*players[i]).player_hand[0]);
			(*players[i]).player_hand.remove_card(0);
		}



	}

	//move all cards from discard deck into main deck
	while (discard_deck.size() != 0){
		main_deck.add_card(discard_deck.remove());
	}

}


void FiveCardDraw::terminate(){
	if (num_players_in_game() == 1){
		char last = (*players[0]).player_name[(*players[0]).player_name.length() - 1];
		if (last == '*'){
			ofstream player_file((*players[0]).player_name.substr(0, (*players[0]).player_name.length() - 1) + "_automated.txt");
			player_file << *players[0];
			players.erase(players.begin());
			player_file.close();
		}
		else{
			ofstream player_file((*players[0]).player_name + ".txt");
			player_file << *players[0];
			players.erase(players.begin());
			player_file.close();
		}

		cout << "Only One player left. Stop the game" << endl;
		throw Error::terminator;
	}
}
