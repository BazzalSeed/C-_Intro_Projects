#ifndef PLAYER_H

#define PLAYER_H

#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "Hand.h"

enum{
	num_args_in_player_file = 3
};


struct Player{
	friend class FiveCardDraw;
private:
	std::string player_name;
	Hand player_hand;
	unsigned int hands_won;
	unsigned int hands_lost;
public:
	
	Player(char *);      //constructor
	std::string get_player_name() const;
	bool HandnotFull(){
		return (player_hand.size != valid_hand_size);
	}
	friend std::ostream& operator<< (std::ostream &, const Player &);
};


#endif