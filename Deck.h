#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"
#ifndef Deck_h
#define Deck_h
using namespace std;

class Deck : public vector<Card*> {

public : 
// constructor 
    Deck ();
    Deck (istream&,CardFactory* );

 // fonctions    
     Card* draw () ;
     // insertion operator 
  friend ostream& operator +=(istream&, Deck card);

};

//friend ostream& operator<<(ostream& COUT ,const Card& card)

#endif