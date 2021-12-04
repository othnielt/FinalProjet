#include "Table.h"

Table::Table(string & name1, string & name2)
{
	Player player1(name1);
	Player player2(name2);
	players.push_back(player1);
	players.push_back(player2);
	discard = new DiscardPile();
	ta= new TradeArea();
	CardFactory *cf = CardFactory::getFactory();
	deck = new Deck(cf);
}

Table::~Table()
{
}

bool Table::win(string & name)
{
	//If there is no player, returns the player in the lead.
	if (players[0].getNumCoins() > players[1].getNumCoins())
		name = players[0].getName();
	else
		name = players[1].getName();
	return deck->empty();
}

Table::Table(istream & in, CardFactory* cf)
{
	Player *player1 = new Player(in, cf);
	Player *player2 = new Player(in, cf);

	players.push_back(*player1);
	players.push_back(*player2);

	discard = new DiscardPile(in, cf);
	ta = new TradeArea(in, cf);
	deck = new Deck(in, cf);

}


/*
Text File Format:
Line 1: player 1 info
Line 2: player 2 info
Line 3: discard pile info
Line 4: trading area info
*/

ostream & operator<<(ostream & out, Table t)
{
	out << "------Table------\n" ;
	for (Player player : t.players) {
		out << player << "\n";
	}
	out << "Top of discard pile:\n" << *t.discard << "\n" << "Trading area:\n" << *t.ta <<"\n";
	out << "-----------------\n";

	return out;
}
