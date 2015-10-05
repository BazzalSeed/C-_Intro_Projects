#ifndef GAME_H

#define GAME_H

#include <memory>
#include <vector>
#include "Deck.h"
#include "Player.h"

class Game{
protected:
	static std::shared_ptr<Game> staPtr_to_game;
	Deck main_deck = Deck();
	std::vector <std::shared_ptr<Player>> players;
public:
	static std::shared_ptr<Game>instance();
	static void start_game(const std::string &);
	static void stop_game();
	void add_player(const std::string &);
	std::shared_ptr<Player> find_player(const std::string &);

	virtual int before_turn(Player &) = 0;
	virtual int turn(Player &) = 0;
	virtual int after_turn(Player &) = 0;
	virtual int before_round() = 0;
	virtual int round() = 0;
	virtual int after_round() = 0;
};



#endif