
#ifndef LIBR_H
    #include "libr.h"
    #define LIBR_H
#endif
namespace my{

struct ringing {
    my::DateTime date;
    my::TimeSpan duration;
    std::string number;
    ringing(){;}
    ringing (my::DateTime _date, my::TimeSpan _duration,std::string  _number): date(_date), duration(_duration), number(_number){;}
    ringing & operator = (const ringing &other) {

        this->date = other.date;
        this->duration = other.duration;
        std::cout<<other.number<<std::endl;
        (this->number) = other.number;
        std::cout<<this->number<<std::endl;
        return *this;
    }

    friend std::istream& operator>> (std::istream& istr, my::ringing & x)
    {
        my::DateTime _date;
        my::TimeSpan _duration;
        std::string _number;
        istr >> _date;
        istr >> _duration;
        istr >> _number;
        my::ringing answer(_date, _duration, _number);
        x = answer;
        return (istr);
    }


    friend std::ostream& operator << (std::ostream& ostr, my::ringing x)
    {
        ostr<<" Время вызова: "<<x.date<<" Продолжительность: "<<x.duration<<" Номер абонента: "<<x.number;
        return (ostr);
    }
};

class Abonent
{
    int tariff;
    int balance;
    my::List<ringing> list_of_ringing;
public:
    Abonent (float _tariff): tariff((int)(_tariff * 100)), balance(0) {;}
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
}


