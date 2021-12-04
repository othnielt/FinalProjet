
#ifndef Card_h
#include <iostream>
#include <string>
 using namespace std;
 class Card {
public:
    //  on obtient le nombre de pièces par carte
    virtual int getCardsPerCoin(int coins) = 0  ; 

    // on retourne le nom de la carte 

    virtual string getName() = 0 ; 


    virtual void print(ostream& out) = 0 ; 

    // on imprime l'objet
    friend ostream& operator<<(ostream& COUT ,const Card& card){

        COUT << card; 
     return COUT ; 
 }
}; 
#endif

   
