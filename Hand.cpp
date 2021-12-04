#include "hand.h"
#include <string>
#include <iostream>

//back est la première carte 
//size - pour avoir la position

Hand& Hand ::operator+=(Card*cardToAdd) {  
	(*this).insert(begin(), cardToAdd);
	return *this;

}//ici on ajoute une carte derrière la dernière carte de la main.

Card* Hand :: play() {

	Card* temp = (*this).back();
	(*this).pop_back();
	return temp;

}//on renvoie et on supprime la première carte de la main du joueur .

Card* Hand ::top() {
	return (*this).back();
}//on renvoie mais on ne supprime pas la première carte de la main du joueur.

Card* Hand ::operator[](int position) {
	Card* temp = (*this).at((*this).size() - position);
	(*this).erase( (*this).begin() + ((*this).size()-position) );
	return temp;
}//on renvoie et on supprime une carte à une position donnée.


Hand:: Hand(std::istream& in, CardFactory* cf) {
	char cardType[256];
	in.getline(cardType, 256); 
	in.getline(cardType, 256);

	int cnt = 0;
	while (cardType[cnt] != NULL) {
		cnt++;
	}
	cnt--;
	for (int i = cnt; i >= 0; i--) {
		Card* cardToAdd = ((*cf).getCard(cardType[i]));
		(*this).push_back(cardToAdd);
	}

}													


ostream & operator<<(ostream & out, Hand h)
{
	// TODO: make sure cards are in order
	for (vector<Card*>::reverse_iterator it = h.rbegin(); it != h.rend(); it++) {
		out << (*it);
	}
	return out;
}
