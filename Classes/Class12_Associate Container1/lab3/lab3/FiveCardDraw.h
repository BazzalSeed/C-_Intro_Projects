
#ifndef FiveCardDraw_H

#define FiveCardDraw_H
#include "Game.h"
#include "Card.h"
#include <vector>
#include "Error.h" 
using namespace std;

class FiveCardDraw: public Game{
protected:
	size_t dealer_position;
	Deck discard_deck;
public:
	FiveCardDraw();
	virtual int before_turn(Player &player);
	virtual int turn(Player &player);
	virtual int after_turn(Player &player);
	virtual int before_round();
	virtual int round();
	virtual int after_round();

//methods for after_round()
protected:
	bool player_rank(shared_ptr<Player> &p1, shared_ptr<Player> &p2);
	void print_sorted_player();
	void reset();


};

//Functions used for this FiveCardDraw Class

//Method to take in response from cin and size of valid hand. return a vector containing all valid positions
//!! the 0 position of the vecotr count how many invalid position user has entered
vector<int> valid_input_positions (string response , unsigned int hand_size){

	stringstream ss(response);
	vector<int> user_inputs;
	user_inputs.push_back(0);
	string temp;
	while (ss >> temp){
		int check = stoi(temp);
		if (check >= 0 && check < hand_size){
			user_inputs.push_back(check);
		}
		else{
			cout << "detecting invliad position from user" << ": " << check << endl;
			++user_inputs[0];
		}
	}

	return user_inputs;
	
}

int notfull(vector<shared_ptr<Player>> players){
	for (unsigned int i = 0; i < players.size(); ++i){
		if ((*players[i]).HandnotFull()) { return i; }
	}
	return -1;
}




#endif