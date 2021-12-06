#ifndef CardFactory_h
#define CardFactory_h

#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include "Deck.h"
#include "Card.h"
#include "Blue.cpp"
#include "Chili.cpp"
#include "Stink.cpp"
#include "Green.cpp"
#include "Soy.cpp"
#include "Black.cpp"
#include "Red.cpp"
#include "Garden.cpp"

class Deck;

class CardFactory {
private:
	Deck *deck;
	CardFactory(const CardFactory&);
	CardFactory();

public:
	static CardFactory* getFactory();
	Deck getDeck();
	Card* getCard(char);
	Deck setDeck (istream &);
};
#endif
