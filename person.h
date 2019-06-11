#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:
    inline Person() : firstName{"John"}, lastName{"Doe"}, catchphrase{"Something generic"}, role{"Nobody"} {}
    Person(QString f, QString l, QString c, QString r);

    inline virtual QString getFullName()    {return firstName + " " + lastName;}
    inline virtual QString getCatchPhrase() {return catchphrase;}
    virtual QString getRole() = 0;
    virtual void    setInfo() = 0;
protected:
    QString firstName;
    QString lastName;
    QString catchphrase;
    QString role;
};

#endif // PERSON_H
