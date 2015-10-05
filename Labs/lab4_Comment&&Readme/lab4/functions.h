#include <iostream>
#include <string>
#include <istream>
#include "Game.h"
#include "Deck.h"
#include <Math.h>
#include<vector>
using namespace std;
bool is_anumber(const std::string& s);
vector<int> valid_input_positions(string response, unsigned int hand_size);
std::vector<int> getTwoPairsInfo(const std::vector<Card> &cardsInHand);
std::vector<int> getOnePairInfo(const std::vector<Card> &cardsInHand);
bool poker_rank(const Hand &hand2, const Hand &hand1);
bool player_rank(const std::shared_ptr<Player> & p1, const std::shared_ptr<Player> &p2);
