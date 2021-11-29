#include "Card.h"
#include "iostream"
using namespace std;


class Chain_Base {
protected:
    virtual void addCard(Card* card)  = 0 ; 
    virtual void print(ostream&) const = 0;

 public:   
    virtual int getSize() = 0;
    virtual string getType() = 0;
    virtual int sell() = 0;
    virtual bool legal(Card*) = 0;
     
     // operator to print the objet
    friend ostream& operator << (ostream& COUT, const Card* card) {
		    COUT << (*card);
		    return COUT;
	};

    // add to card 
    Chain_Base& operator += (Card* card){

        this->addCard(card);
        return *this;
    }
};