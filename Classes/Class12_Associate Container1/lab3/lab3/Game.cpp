#include "stdafx.h"
#include "Game.h"
#include "Error.h"
#include "Player.h"
#include "FiveCardDraw.h"


std::shared_ptr<Game> Game::staPtr_to_game = 0;


std::shared_ptr<Game> Game::instance(){
	if (staPtr_to_game == NULL){
		throw Error::instance_not_available;
	}
	else{
		return std::shared_ptr<Game>(staPtr_to_game);
	}
}

void Game::start_game(const std::string &str){
	if (Game::staPtr_to_game != NULL){
		throw Error::game_already_started;
	}
	if (str.find(std::string("FiveCardDraw")) == std::string::npos){
		throw Error::unknown_game;
	}
	Game::staPtr_to_game = std::make_shared<FiveCardDraw>(FiveCardDraw());
}


void Game::stop_game(){
	if (Game::staPtr_to_game == NULL){
		throw Error::no_game_in_progress;
	}
	Game::staPtr_to_game = NULL;
}


void Game::add_player(const std::string &player_name){
	for (std::vector<std::shared_ptr<Player>>::iterator it = players.begin(); it != players.end(); ++it){
		Player current_player = **it;
		if (current_player.get_player_name.compare(player_name) == 0){
			throw Error::already_playing;
		}
	}
	std::shared_ptr<Player> new_player = std::make_shared<Player>(new Player(player_name.c_str()));
	players.push_back(new_player);
}



std::shared_ptr<Player> Game::find_player(const std::string &player_name){
	for (std::vector<std::shared_ptr<Player>>::iterator it = players.begin(); it != players.end(); ++it){
		Player current_player = **it;
		if (current_player.get_player_name.compare(player_name) == 0){
			return *it;
		}
	}
	return 0;
}



