#include<iostream> 
#ifndef Card_h
#define Card_h

#include <iostream>
#include <string>
 
 class card {

//    get number of coin per card 
virtual int getCardsPerCoin(int coins) = 0  ; 

// return the name of the card 

virtual string getName() = 0 ; 


virtual void print(ostream& out) = 0 ; 

 // print the objet 
 friend ostream& operator<<(ostream& COUT ,Card* card){

     COUT << *(card); 
     return COUT ; 
 }
}; 
#endif