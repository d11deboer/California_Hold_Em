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
    static short currentID;
public:
    /** @brief Player - default constructor */
    Player() : cash{STARTING_CASH}, bac{0.0}, hand{nullptr}, id{0} { currentID = 0; }

    /**
     * @brief Player - alt constructor - all values set
     * @param c: the starting cash
     * @param b: the starting blood alcohol content
     * @param h: the starting hand - should be nullptr
     */
    Player(long double c = STARTING_CASH, float b = 0, Hand *h = nullptr);

    /** @brief copy constructor */
    Player(const Player & p);

    /** @brief move constructor */
    Player(Player && p);

    ~Player() override { delete hand; }

    bool operator==(const Player & p);
    bool operator!=(const Player & p);
    bool operator>(const Player & p);

    /** @brief drinkWhiskey - adds to the player's BAC .03 */
    inline void drinkWhiskey()  { bac += .03; }

    /** @brief drinkBeer - adds to the player's BAC .02 */
    inline void drinkBeer()     { bac += .02; }

    /** @brief decrementBAC - lowers the players BAC by .01 (used to sober up Player) */
    inline void decrementBAC()  { bac -= .01; }

    /** @brief setHand - sets the players hand to h if h exists */
    inline void setHand(Hand *h) { if(h != nullptr) hand = new Hand(*h); }

    /** @brief getRole - returns "Player" */
    inline QString getRole() override { return "Player"; }

    /** @brief setInfo - sets all of the Person info as well as the Player specific info - error checked */
    void setInfo() override;
private:
    short id;
    long double cash; /** @brief Money player currently has */
    float bac;        /** @brief blood alcohol content */
    Hand *hand;       /** @brief two Cards in the players hand */
};

#endif // PLAYER_H
