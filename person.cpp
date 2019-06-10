#include "person.h"

Person::Person(QString f, QString l, QString c, QString r){
    //check for empty strings
    if(!f.isEmpty() && !l.isEmpty() && !c.isEmpty() && !r.isEmpty()) {
        firstName   = f;
        lastName    = l;
        catchphrase = c;
    }
}
