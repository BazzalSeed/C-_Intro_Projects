#ifndef FiveCardDraw_H
#define FiveCardDraw_H

#include <algorithm>
#include "Game.h"

using namespace std;

class PokerGame :public Game{

protected:
	//variables related to betting
	unsigned int most_recent_bet_position;
	unsigned int chips_pot;     //common pot of chips that winner wins
	unsigned int current_bet_value;
	unsigned int current_position;
	bool all_player_check = false;
	unsigned int num_player_fold = 0;

	size_t dealer_position;    //current dealer position, rotating during the game
	Deck discard_deck = Deck();         //deck to store discarded cards

public:
	PokerGame();     //constructor
	virtual 



public:
	FiveCardDraw();            //default constructor

	//player's turn
	virtual int before_turn(Player &player);
	virtual int turn(Player &player);
	virtual int after_turn(Player &player);

	//game's round
	virtual int before_round();
	virtual int round();
	virtual int after_round();

	//betting phase
	int participate_betting();
	int before_betting();
	int betting();
	int after_betting();

	//betting for each player
	int player_bet(std::shared_ptr<Player> &player);

	//utility function for betting
	bool is_betting_end();
	void reset_betting_status(size_t);
	void reset_all_status();
	void print_betting_stats();


	//helper methods for after_round()
protected:
	void print_sorted_player();
	void reset();


	//-------------------------------------------------------------------------------------
	//Helper Function for extra credit
	vector<int> auto_valid_positions(Player &player);
	void highest_automated_leave(string automated_name);
	void lowest_automated_leave(string automated_name);
	void other_automated_leave(string automated_name);
	void terminate();

};



#endif