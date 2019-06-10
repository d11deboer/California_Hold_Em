#include "house.h"

Deck::Deck() {
    srand(time(NULL));
    deck = new Card[DEFAULT_DECK_SIZE];
    int i = 0;
    for(int v = 0; v < value_names.size(); v++) {
        for(int s = 0; s < suit_names.size(); s++) {
            deck[i].setAll(s, v);
        }
    }
    size = DEFAULT_DECK_SIZE;
}

Deck::Deck(Card * d, int s) {
    deck = d;
    size = s;
}

Hand Deck::dealHand() {
//    while(deck[rand() % size] == nullptr){

//    }
}

Deck::~Deck(){
    delete [] deck;
    size = 0;
}

void Card::setAll(int s, int v) {
    if(s < suit_names.size() && s >= 0 && v < value_names.size() && v >= 0) {
        suit  = Suit(s);
        value = Value(v);
    }
    else {
        qDebug() << "Error: setAll value out of range.";
    }
}

void House::showFlop() {

}
