#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include <house.h>
#include <player.h>
#include <database.h>

class Game : public QGraphicsView
{

public:
    Game(QWidget * device = nullptr);

    /** @brief addRandomPlayers - adds n random players
     * @param n: the number of players for the game
     */
    void addRandomPlayers(int n);

    /**
     * @brief removePlayer - removes the player from the game
     * @param p: the player to be removed
     * @return: bool - true if found and removed successfully, else false
     */
    bool removePlayer(Player * p);

    /** @brief startRound - starts the round of betting */
    void startRound();

    /** @brief editPlayer1Info - used for entering in the basic Person information for the user */
    void editPlayer1Info();

    /** @brief selectOpponents - allows user to select the opponents for the game */
    void selectOpponents();


public slots:
private:
    QGraphicsScene * scene;
    House          * house;   /** @brief house: object in charge of the deck, pot, rounds, etc */
    QVector<Player*> players; /** @brief players: vector of all players, including the user */
    Database       * data;    /** @brief data: the SQLite database in charge of the loading and saving data */
};

#endif // GAME_H
