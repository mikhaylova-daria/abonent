#ifndef LIBR_H
    #define LIBR_H
    #include "libr.h"
#endif


int main()
{
    my::Abonent first(1.0);
    first.top_up_balance(1000);
    float x = first.balance_inquiry();
    std::cout << x;
    return 0;
}

