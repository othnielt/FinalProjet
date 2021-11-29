
#ifndef Card_h
#include <iostream>
#include <string>
 using namespace std;
 class Card {
public:
    //    get number of coin per card 
    virtual int getCardsPerCoin(int coins) = 0  ; 

    // return the name of the card 

    virtual string getName() = 0 ; 


    virtual void print(ostream& out) = 0 ; 

    // print the objet 
    friend ostream& operator<<(ostream& COUT ,const Card& card){

        COUT << card; 
     return COUT ; 
 }
}; 
#endif

  // operator to print the objet
   