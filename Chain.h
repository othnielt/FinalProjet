#include "Chain_Base.h"
#include <vector>
#include <vector>
#include "CardFactory.h"
using namespace std;


template<class T> class Chain : public Chain_Base, public vector<T>{

/////// // constructors/////////
public:
    Chain();
    Chain(istream&, const  CardFactory*);

    // add cart to the chaine 
    Chain<T>& operator+=( Card* card ) ; 
    // return the number of card in the current chain 
    int sell (); 
    //   add card to the current chain
    void addCard(Card* );
    //get the current chain size 
    int getSize();
    // get the current card type 
    string getType();
    string types ; 
     
     void print(ostream& COUT) const {
		COUT << (*this);
	};

    // throw Error 

    class IllegalType : public exception {

       const  string erreur () const throw (){

           return "the type of the card does not match  with the chaine ";
       }
    }; 








};