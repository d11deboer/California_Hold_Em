#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QVector>
#include <player.h>

class Database
{
public:
    Database();
    ~Database();

    bool createTables();
    bool isOpen();
    bool addPlayer();
    bool removePlayer(Player*);
    bool removePlayer(QString name);
    QVector<Player*> & fetchAllPlayers();
    inline bool saveUserInfo(Player * info) { delete userInfo; userInfo = new Player(*info);}

private:
    QSqlDatabase  * db;
    QVector<Player*> allPlayers;
    Player        * userInfo;
};

#endif // DATABASE_H
