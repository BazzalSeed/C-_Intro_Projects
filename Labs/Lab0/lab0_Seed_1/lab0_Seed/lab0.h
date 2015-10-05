#ifndef LAB0_H
#define LAB0_H
#include <vector>

using namespace std;
enum Rank{ two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
enum Suite{ clubs=11, diamonds, hearts, spades };
enum names{
	Program_name,

};

enum Result{
	SUCCESS,
	FAILURE_OPENING_FILE,
	WRONG_NUMBER_ARGUMENTS,
	NULL_DECK
};

struct Card
{

	Rank rank_;
	Suite suit_;

};

int ParseFile(vector<Card>& deck, char * name);
int usage_message(char* filename);
int print_vector(const vector<Card> & deck);
#endif