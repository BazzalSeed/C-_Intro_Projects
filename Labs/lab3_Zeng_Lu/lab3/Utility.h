
#include <vector>
#include "Hand.h"
static const std::string handRanks[] = { "no_rank", "one_pair", "two_pairs", "three_kind", "straight", "flush", "full_house", "four_kind", "straight_flush" };

std::vector<int> getTwoPairsInfo(const std::vector<Card> &);
std::vector<int> getOnePairInfo(const std::vector<Card> &);
bool poker_rank(const Hand &hand1, const Hand &hand2);