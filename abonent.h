
#ifndef LIBR_H
    #include "libr.h"
    #define LIBR_H
#endif
namespace my{

class ringing {
public:
    my::DateTime date;
    my::TimeSpan duration;
    std::string number;
    ringing(){;}
    ringing (my::DateTime _date, my::TimeSpan _duration,std::string  _number): date(_date), duration(_duration), number(_number){;}
    ringing & operator = (const ringing &other) {

        this->date = other.date;
        this->duration = other.duration;

        ///////////////////////////////////
        ////////// ПРОБЛЕМА ///////////////
        ///////////////////////////////////

        //std::cout<<other.number<<std::endl;  //это выводит
        (this->number) = other.number;  // не работает :(
        //this->number = "2314321";   //и даже так не работает :'(
        //std::cout<<this->number<<std::endl; //ничего не пишет
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
        float min_dur = _new.duration.span.unixT() / 60;
        this->top_up_balance(-min_dur * (float)((float)this->tariff / 100));
        return;
    }


};
}


