#ifndef LIBR_H
    #define LIBR_H
    #include "libr.h"
#endif


int main()
{
    my::Abonent first(1.0);
    first.top_up_balance(10.3);

    my::ringing ring;
    ring.date = my::DateTime::now();
    my::DateTime other_time (my::DateTime::now().unixT() + 3600);
    ring.duration = other_time.operator -(ring.date);
    ring.number = "+792600000000";
    my::List<my::ringing> ls;
    //std::cout << first.balance_inquiry();

    ls.push(ring);
//ls.output();
    //first.new_ringing(ring);
    return 0;
}

