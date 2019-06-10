#ifndef PLAYER_H
#define PLAYER_H
#include "person.h"
#include <QString>
#include "house.h"

/**
 * @brief The Player class - user and each computer player is a Player object
 */
class Player : public Person
{
    static constexpr long double STARTING_CASH = 50000;
public:
    /** @brief Player - default constructor */
    Player() : cash{STARTING_CASH}, bac{0.0}, hand{nullptr} {}

    /**
     * @brief Player - alt constructor - all values set
     * @param c: the starting cash
     * @param b: the starting blood alcohol content
     * @param h: the starting hand - should be nullptr
     */
    Player(long double c = STARTING_CASH, float b = 0, Hand *h = nullptr);

    ~Player() {delete hand;}

    inline void drinkWhiskey()  { bac += .03; }
    inline void drinkBeer()     { bac += .02; }
    inline void decrementBAC()  { bac -= -01; }
    inline void getHand(Hand *h) { if(h != nullptr) hand = new Hand(*h); }
private:
    long double cash; /** @brief Money player currently has */
    float bac;        /** @brief blood alcohol content */
    Hand *hand;       /** @brief two Cards in the players hand */
};

#endif // PLAYER_H
