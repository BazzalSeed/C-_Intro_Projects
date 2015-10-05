// lab4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "Error.h"
#include"SevenCardStud.h"
#include "functions.h"
#include <algorithm>
using namespace std;

#define MIN_NUM_ARGS 4


vector<Hand> allhands;


/*

void helper(Hand &hand, Hand tempHand, int start, int end, int index, int r){
	if (index == r){
		allhands.push_back(tempHand);
		return;
	}

	for (int i = start; i <= end && end - i + 1 >= r - index; i++){
		tempHand[index] = hand[i];
		helper(hand, tempHand, i + 1, end, index + 1, r);
	}
}


void combination(Hand &hand, int n, int r){
	Hand tempHand;
	helper(hand, tempHand, 0, n - 1, 0, r);
}




Hand sortAllHands(Hand &hand){
	combination(hand, 7, 5);
	sort(allhands.begin(), allhands.end());
	return allhands[0];
}
*/


int main(int argc, char* argv[]){
	

	//number of arguments not enough
	if (argc < MIN_NUM_ARGS){
		cout << "Too few arguments" << endl;
		cout << "Usage: lab3 <Game name> <player1's name> <player2's name> ... " << endl;
		return Error::two_few_arguments;
	}


	shared_ptr<Game>game_holder;
	try{
		//start the game with the given name
		Game::start_game(argv[1]);
		//obtain a pointer to the game
		shared_ptr<Game> ptr_newg = Game::instance();
		game_holder = ptr_newg;


		//add players to the game
		for (int i = 2; i < argc; i++){
			string temp(argv[i]);

			(*ptr_newg).add_player(temp);
		
		}

		//continue the game if at least two players
		while ((*ptr_newg).num_players_in_game() >= 2){
		   



			int before_round_result= (*ptr_newg).before_round();
			(*ptr_newg).round();
			
			(*ptr_newg).after_round();

		}

	}
	//catch exception and stop the game
	catch (Error i){
		cout << "Exception caught, stop the game" << endl;
		try{
			(*game_holder).stop_game();
		}
		catch (Error j){
			return j;
		}
		return i;
	}

	//stop the game in the end
	try{
		(*game_holder).stop_game();
		return Error::Success;
	}
	catch (Error k){
		return k;

	}
	
}