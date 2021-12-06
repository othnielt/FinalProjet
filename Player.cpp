#include "Player.h"

Player:: Player(string &playerName) {											
	name = playerName;
	numCoins = 0;
	maxNumChains = 2;
	hand = new Hand();
}


string Player :: getName() {
	return name;
}

int Player:: getNumCoins() {
	return numCoins;
}

Player& Player:: operator +=(int i) {
	numCoins = numCoins + i;
	return(*this);
}

Player & Player::operator+=(Card *card)
{
	*hand += card;
	return *this;
}

int Player:: getMaxNumChains() {
	return maxNumChains;
}

int Player::getNumChains() {
	return chains.size();

}


 ChainBase& Player:: operator[](int i) {	
	 if (i < getNumChains())
		 return chains[i];
	 else
		 throw ChainDoesntExist();
}

//On assume que seulement un joueur a besoin d'acheter une troisième chaine 1 fois.
void Player:: buyThirdChain() {
	if (numCoins < 3)
		throw NotEnoughCoins();
	else {
		numCoins = numCoins - 3;
																
		maxNumChains++;
	}

}

void Player::printHand(ostream& out, bool notTopCard) {
	if (notTopCard) {
		out << *hand;
	}
	else {

		out << hand->top();
	}
																					

}// on imprime la carte du dessus de la main du joueur (avec
// argument false) ou toute la main du joueur (avec
// argument true) à l'ostream fourni.


Player:: Player(istream& in, CardFactory* cf) {
	getline(in,name, '\t');

	in >> numCoins;
	in >> maxNumChains;
	hand = new Hand(in, cf);
	char type;
	int size;
	string chainInfo;
	string tmp;
	for (int i = 0; i < 3; i++) {
		getline(in, chainInfo);
		if (chainInfo.compare("NULL") != 0) {
			type = chainInfo.at(0);
			size = atoi(chainInfo.substr(2).c_str());
			addChain(type);
			for (int i = 0; i < size; i++) {
				addToChain(cf->getCard(type));
			}

		}

	}
	

}


template<class T>
bool Player::addChain() {
	static_assert(std::is_base_of<Card, T>::value, "T is not derived from Card");
	if (chains.size() <= maxNumChains) {
		T temp;
		addChain(temp.getName()[0]);
		return true;
	}
	//else
	return false;
}


bool Player::addToChain(Card * card)
{
	if (card == nullptr)
		return false;
	for (int i = 0; i < chains.size(); i++) {
		if ((*this)[i].legal(card)) {
			(*this)[i] += card;
			return true;
		}
	}
	//else
	if (chains.size() < maxNumChains) {
		addChain(card->getName()[0]);
		chains.back() += card;
		return true;
	}
	//else
	return false;
}

void Player::sellChain(int i){
	numCoins += chains[i].sell();
	chains.removeChain(i);
}

void Player::addChain(char type)
{
	if (type == 'B') {
		ChainBase* newChain = new Chain<Blue>;
		chains.addChain(newChain);
	}
	else if (type == 'C') {
		ChainBase* newChain = new Chain<Chili>;
		chains.addChain(newChain);
	}
	else if (type == 'S') {
		ChainBase* newChain = new Chain<Stink>;
		chains.addChain(newChain);
	}
	else if (type == 'G') {
		ChainBase* newChain = new Chain<Green>;
		chains.addChain(newChain);
	}
	else if (type == 'So') {
		ChainBase* newChain = new Chain<Soy>;
		chains.addChain(newChain);
	}
	else if (type == 'Bk') {
		ChainBase* newChain = new Chain<Black>;
		chains.addChain(newChain);
	}
	else if (type == 'R') {
		ChainBase* newChain = new Chain<Red>;
		chains.addChain(newChain);
	}
	else if (type == 'Ga') {
		ChainBase* newChain = new Chain<Garden>;
		chains.addChain(newChain);
	}
}



ostream & operator<<(ostream & out, Player p)
{
	out << p.getName() << '\t' << p.getNumCoins() << " coins\n";
	for (int i = 0; i < p.getNumChains(); i++)
		out << p[i] << "\n";
	return out;
}

void Player::print(ostream & out)				//on imprime toutes les cartes
{	
	//addChain<Quartz>();
	//addToChain(new Quartz());
	out << getName() << '\t' << getNumCoins() << ' ' << getMaxNumChains() << "\n";
	out << *hand << "\n";
	for (int i = 0; i < 3; i++){
		if (i < getNumChains())
			out << chains[i].getType().at(0) << " " << chains[i].getSize() << "\n";
		else
			out << "NULL" << "\n";
	}
		
}
