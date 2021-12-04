#include "DiscardPile.h"


DiscardPile::DiscardPile()
{
	//la DiscardPile est vide
}

DiscardPile::~DiscardPile()
{
}

DiscardPile & DiscardPile::operator+=(Card *card)
{
	(*this).push_back(card);
	return *this;
}

Card * DiscardPile::pickUp()
{
	if (this->empty()) {
		throw domain_error("The discard pile is empty");
		return nullptr;
	}
	else {
		Card* temp = (*this).back();
		(*this).pop_back();
		return temp;
	}
}

Card * DiscardPile::top()
{
	return this->back();
}

bool DiscardPile::isEmpty()
{
	if ((*this).size() == 0)
		return true;
	return false;
}



void DiscardPile::print(ostream & out)				//on imprime toutes les cartes
{
	if (!isEmpty()) {
		for (vector<Card*>::iterator it = this->begin(); it != this->end(); it++) {
			out << (**it);
		}
	}
	/*else
		out << "Discard pile is empty";*/
}

DiscardPile::DiscardPile(istream & in, CardFactory *cf)		// sinon supprimé la méthode const adapt
{
	char cardType[256];
	in.getline(cardType, 256);
	int cnt = 0;
	while (cardType[cnt] != NULL) {
		cnt++;
	}
	cnt--;
	for (int i = cnt ; i >= 0; i--) {
		Card* cardToAdd = ((*cf).getCard(cardType[i]));
		(*this).push_back(cardToAdd);
	}

}



ostream & operator<<(ostream & out, DiscardPile dp)
{
	if (!dp.isEmpty()) {
		out << dp.back();
	}
	
	return out;
}
