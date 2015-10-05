#include "stdafx.h"
#include "Player.h"
#include "Error.h"

//read values from input file
//NOTE: require three arguments in the file with correct order
Player::Player(char *name): hands_won (0) , hands_lost(0)
{
	player_name = std::string(name);
	std::string storage;
	std::ifstream ifs;
	ifs.open(name);

	if (ifs.is_open()){
		int count = 0;
		
		while (ifs >> storage && count < num_args_in_player_file){

			if (storage.size == 0){
				count++;
				continue;
			}

			std::istringstream reader(storage);
			switch (count){
			   case 0:
				   reader >> player_name;
				   count++;
				   break;
			   case 1:
				   if (is_number(storage)){
					   reader >> hands_won;
				   }
				   count++;
				   break;
			   case 2:
				   if (is_number(storage)){
					   reader >> hands_lost;
				   }
				   count++;
				   break;
			   default:
				   break;
		    }
		}
	}
	else{
		throw Error::file_not_open;
	}

}


std::string Player::get_player_name() const{
	return player_name;
}


std::ostream& operator<< (std::ostream &os, const Player &player){
	os << player.player_name << " " << player.hands_won << " " << player.hands_lost << std::endl;
	return os;
}



bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

