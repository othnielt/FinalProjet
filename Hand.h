#pragma once
#include "CardFactory.h"

class Hand : public vector<Card*> {
private:


public:
	Hand() = default;						//constructeur par défaut
	Hand& operator+=(Card*);				//a joute une carte derričre la derničre carte de la main.
	Card* play();							//renvoie et supprime la première carte de la main du joueur .
	Card* top();							//renvoie mais ne supprime pas la première carte de la main du joueur.
	Card* operator[](int);					//renvoie et supprime une carte ŕ une position donnée.
	Hand(istream&, CardFactory*);		//constructeur qui accepte fichier
	friend ostream & operator << (ostream &, Hand);
};
