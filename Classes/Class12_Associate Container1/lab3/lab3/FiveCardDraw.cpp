#include "stdafx.h"
#include "FiveCardDraw.h"
#include "Utility.cpp"
#include <algorithm>

using  namespace std;

FiveCardDraw::FiveCardDraw(){
	dealer_position = 0;
	Card curr_card;
	for (int suitIdx = Card::Suit::clubs; suitIdx != Card::Suit::spades; ++suitIdx){
		for (int rankIdx = Card::Rank::two; rankIdx != Card::Rank::ace; ++rankIdx){
			curr_card.rank = static_cast<Card::Rank>(rankIdx);
			curr_card.suit = static_cast<Card::Suit>(suitIdx);
			main_deck.add_card(curr_card);
		}
	}
}

 int FiveCardDraw::before_turn(Player &player){
	 string info = player.player_name + " " + player.player_hand.asString;
	 cout << info << endl;
	 cout << "Please give positions of cards you want to discard" << endl;
	 string response;
	 cin >> response;
	 unsigned int size = player.player_hand.size;
	 vector<int> user_inputs;
	 user_inputs = valid_input_positions(response, size);

	 while (user_inputs.size() == 1 && user_inputs[0] > 0){
		 cout << "Please give positions of cards you want to discard" << endl;
		 cin >> response;
		 user_inputs = valid_input_positions(response, size);
	 }


	 try
	 {

		 for (unsigned int i = 1; i < user_inputs.size(); ++i){

			 discard_deck.add_card(player.player_hand[user_inputs[i]]);
			 player.player_hand.remove_card(i);


		 }
	 }
	 catch (int error){
		 return before_turn_remove_fail;
	 }
	return 0;
	
}


 int  FiveCardDraw:: turn(Player &player){

	 int NofCards_needed = valid_hand_size - (player.player_hand.size);
	 while (NofCards_needed > 0){
		 if (main_deck.size == 0 && discard_deck.size == 0){
			 return no_more_card_for_this_game_go_home;
		 }
		 else if (main_deck.size == 0){
			 discard_deck.shuffle();
			 player.player_hand << discard_deck;
		 }
		 else{
			 player.player_hand << main_deck;
		 }

	 }
	 return 0;
 }

 int  FiveCardDraw::after_turn(Player &player){

	 string info = player.player_name + " " + player.player_hand.asString;
	 cout << info << endl;
	 return 0;

 }
 
 int  FiveCardDraw::before_round() { 
	 if (valid_hand_size * players.size > (main_deck.size + discard_deck.size)){
		 return too_many_players; 
	 }
	 for (int i = 0; i < valid_hand_size; ++i){
		 main_deck.shuffle();
		 for (int count = 1; count <= players.size; count++){
			 players[(dealer_position + count) % players.size].player_hand << main_deck;
		 }

	 }
	 
	 for (int count = 1; count <= players.size; count++){
		 int check_before_turn = before_turn(players[(dealer_position + count) % players.size]);
		 if (check_before_turn != 0){
			 return check_before_turn;
		 }
			 
	 }
	 return 0;

 }


 int FiveCardDraw::round(){
	 for (int count = 1; count <= players.size; count++){
		 int check_turn = turn(players[(dealer_position + count) % players.size]);
		 if (check_turn != 0){
			 return check_turn;
		 }
		 after_turn(players[(dealer_position + count) % players.size]);
	 }
	 return 0;
 }
 


 int FiveCardDraw::after_round(){

 }


 bool FiveCardDraw::player_rank(shared_ptr<Player> &p1, shared_ptr<Player> &p2){
	 return poker_rank((*p1).player_hand, (*p2).player_hand);
 }

 void FiveCardDraw::print_sorted_player(){
	 vector<shared_ptr<Player>> players_copy = players;
	 sort(players_copy.begin(), players_copy.end(), player_rank);
	 int  highestHandRank = (*players_copy[0]).player_hand.getRank();

	 for (unsigned int i = 0; i < players.size; ++i){
		 if ((*players_copy[i]).player_hand.getRank() == highestHandRank){
			 (*players_copy[i]).hands_won++;
		 }
		 else{
			 (*players_copy[i]).hands_lost++;
		 }
	 }

	 for (unsigned int i = 0; i < players.size; ++i){
		 Player current_player = *players_copy[i];
		 cout << current_player << endl;
		 cout << current_player.player_hand.asString() << endl;
	 }
 }


 void FiveCardDraw::reset(){

	 for (unsigned int i = 0; i < players.size; ++i){
		 for (unsigned int j = 0; j < (*players[i]).player_hand.size; ++j){
			 main_deck.add_card((*players[i]).player_hand[i]);
			 (*players[i]).player_hand.remove_card(i);
		 }
	 }

	 while (discard_deck.size != 0){
		 main_deck.add_card(discard_deck.remove());
	 }

 }