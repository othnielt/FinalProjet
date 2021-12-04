#include "TradeArea.h"

//Helper function
template <typename Container>
bool contains(Container const& c, typename Container::const_reference v) {
	return std::find(c.begin(), c.end(), v) != c.end();
}

template<class InputIterator, class T>
InputIterator findName(InputIterator first, InputIterator last, const T& val)
{
	while (first != last) {
		if ((*first)->getName().compare(val) == 0) return first;
		++first;
	}
	return last;
}


bool containsName(list<Card*> const& c, string& v) {
	list<Card*>::const_iterator first = c.begin();
	list<Card*>::const_iterator last = c.end();
	while (first != last) {
		if ((*first)->getName().compare(v) == 0) return true;
		++first;
	}
	return false;
}

TradeArea::TradeArea()
{
	cards = new list<Card*>;
	cardTypes = list<string>();
}

TradeArea::~TradeArea()
{/*
	//Make sure that each card is deleted.
	for (auto&& card : *cards){
		delete card;
	}
	cards->clear();
	cardTypes.clear();*/
}

TradeArea & TradeArea::operator+=(Card *card)
{
	
	(*cards).insert((*cards).begin(), card);
	if (!contains(cardTypes, card->getName())) {						
		cardTypes.emplace_front(card->getName());

	}

	return *this;
}

bool TradeArea::legal(Card *card)
{
	return (cards->size() < 3 || contains(cardTypes, card->getName()));
}

bool TradeArea::empty()
{
	return cards->empty();
}

Card * TradeArea::trade(string name)
{
	if (empty())
		return nullptr;
	list<Card*>::iterator it = cards->begin();
	while (it != cards->end()) {
		if (name.compare((**it).getName()) == 0) {
			Card* temp = *it;
			cards->erase(it);
			if (!containsName(*cards, name)) {					
				cardTypes.remove(name);
			}
			return temp;
		}
		it++;
	}
	//If there is no card of that type:
	return nullptr;
}

int TradeArea::numCards()
{
	return cards->size();
}

TradeArea::TradeArea(istream & in, CardFactory *cf)
{
	cards = new list<Card*>;
	cardTypes = list<string>();
	char cardType[256];
	in.getline(cardType, 256);
	int cnt = 0;
	while (cardType[cnt] != NULL) {
		cnt++;
	}
	cnt--;
	for (int i = cnt ; i >= 0; i--) {
			Card* cardToAdd = ((*cf).getCard(cardType[i]));
			(*this) += cardToAdd;
		}



}

string TradeArea::getCardType(int i)
{
	//if i < 0 return first, and if i > size return last.
	list<string>::iterator it = cardTypes.begin();
	while (i > 0 && it != cardTypes.end()) {
		it++;
		i--;
		
	}
	return *it;
}

/*
Text File Format:
Line 1: Char for each card
*/

ostream & operator<<(ostream & out, TradeArea ta)
{
	for (list<Card*>::iterator it = ta.cards->begin(); it != ta.cards->end(); it++) {
		out << (*it);
	}
	return out;

}
