#include "Deck.h"

Deck::Deck(istream &in, CardFactory *cf)
{
	*this = ( cf->setDeck(in) );

	
}

Card * Deck::draw()
{
	if (this->empty()) {
		throw DeckEmpty();
		return nullptr;
	}
	else {
		Card* temp = (*this).back();
		(*this).pop_back();
		return temp;
	}
}

Deck::Deck(CardFactory* cf)
{
	*this = (*cf).getDeck();
}



ostream & operator<<(ostream & out, Deck d) {
	for (vector<Card*>::iterator it = d.begin(); it != d.end(); it++) {
		out << (*it);
	}
	return out;
}
