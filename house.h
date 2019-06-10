#ifndef HOUSE_H
#define HOUSE_H
#include <QString>
#include <QVector>
#include <utility>
#include <ctime>
#include <QDebug>

using namespace std;

enum Value {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
const QVector<QString> value_names = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

enum Suit {CLUBS, DIAMONDS, SPADES, HEARTS};
const QVector<QString> suit_names = {"Clubs", "Diamonds", "Spades", "Hearts"};

class Card
{
public:
    Card() : value{ACE}, suit{SPADES} {}
    Card(Suit s, Value v) : value{v}, suit{s} {}
    void setAll(int s, int v);

private:
    Value value{ACE};
    Suit  suit{SPADES};
};

typedef pair<Card, Card> Hand;
const int DEFAULT_DECK_SIZE = 52;

class Deck
{
public:
    Deck();
    Deck(Card * d, int s);
    ~Deck();

    Hand dealHand();
    short getSize() {return size;}
private:
    Card *deck;
    short size{DEFAULT_DECK_SIZE};
};

class House
{
public:
    House() : theDeck(), cardsInPlay() {}

    void showFlop();
    void showTurn();
    void showRiver();

    void reset();
    //void dealAll(QVector<*Player> players);

private:
    QVector<Card> cardsInPlay;
    Deck theDeck;
};

#endif // HOUSE_H
