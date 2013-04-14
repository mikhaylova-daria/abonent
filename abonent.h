#ifndef ABONENT_H
#define ABONENT_H
#ifndef LIBR_H
    #include "libr.h"
    #define LIBR_H
#endif

struct ringing {
    my::DateTime date;
    my::TimeSpan duration;
    string number;
};

class Abonent
{
    int tariff;
    int balance;
    my::List<ringing> list_of_ringing;
public:
    Abonent (float _tariff): tariff((int)(_tariff * 100)) {;}
    ~Abonent(){;}

    void top_up_balance(float _fee){
        balance = balance + _fee * 100;
        return;
    }

    float balance_inquiry () const {
        return (float)balance / 100;
    }


    void new_ringing (ringing _new) {
        list_of_ringing.push(_new);
    }

};


#endif // ABONENT_H
