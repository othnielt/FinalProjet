#include <vector>
#include "Card.h"
#include "CardFactory.h"
#ifndef DiscardPile_h
#define DiscardPile_h
using namespace std;

class DiscardPile : public vector<Card*>{

      public:
       // constructors
    
         DiscardPile() ; 
         DiscardPile(istream&, const CardFactory* );
         ~ DiscardPile();

       // focntions
        DiscardPile& operator+= (Card*);
        Card* pickUp();
        Card* top();
        void print( std::ostream& );

};
#endif

