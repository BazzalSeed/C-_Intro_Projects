#include "stdafx.h"
#include "Player.h"

//check if the given string is numerical value
bool is_number_for_player(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}


//read values from input file
//NOTE: require three arguments in the file with correct order

//constructor
Player::Player(const char *name) : hands_won(0), hands_lost(0), num_chips(20), status(not_set), bet_so_far(0)
{
	player_name = std::string(name);
	
	//open a file with the given name
	std::string storage;
	std::ifstream ifs;
	ifs.open(player_name + ".txt");

	if (ifs.is_open()){
		int count = 0;

		while (ifs >> storage && count < NUM_ARGS_INPUT_FILE){
			//argument is empty, go on to next argument
			if (storage.size() == 0){
				count++;
				continue;
			}

			std::istringstream reader(storage);
			switch (count){
				//update player name
			    case 0:
				   reader >> player_name;
				   count++;
				   break;
				//update hands_won
			    case 1:
				  if (is_number_for_player(storage)){
					  reader >> hands_won;
				  }
				  count++;
				  break;
				//update hands_lost
			    case 2:
				   if (is_number_for_player(storage)){
					   reader >> hands_lost;
				   }
				   count++;
				   break;
				//update num_chips
				case 3:
					if (is_number_for_player(storage)){
						reader >> num_chips;
					}
					count++;
					break;
			    default:
				    break;
			    }
		    }
	}

}

//get player's name
std::string Player::get_player_name() const{
	return player_name;
}

//get player's hand
Hand Player::getPlayerHand() const{
	return player_hand;
}


//get num_chips
unsigned int Player::get_num_chips(){
	return num_chips;
}


//increase num_chips by given amount
void Player::increase_chips(unsigned int increase){
	num_chips += increase;
}

//decrease num_chips by given amount
void Player::decrease_chips(unsigned int decrease){
	num_chips -= decrease;
}


//reset num_chips
void Player::reset_chips(){
	num_chips = DEFAULT_NUM_CHIPS;
}


//update current chip bet
void Player::set_bet_so_far(unsigned int new_bet){
	bet_so_far = new_bet;
}


//get bet so far
unsigned int Player::get_bet_so_far(){
	return bet_so_far;
}


//non-member insertion operator
//print player's information
std::ostream& operator<< (std::ostream &os, const Player &player){
	os << player.player_name << " " << player.hands_won << " " << player.hands_lost << " " << player.num_chips << std::endl;
	return os;
}
