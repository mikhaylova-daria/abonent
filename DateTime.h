
    #ifndef LIBR_H
        #include "libr.h"
        #define LIBR_H
    #endif

namespace my {

class TimeSpan;
class DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    bool unixTimeFlag;
    time_t unixTime;
    int w_day;    // 0, если воскресенье, остальные от 1 до 6
public:
    DateTime();
    DateTime(time_t _unixTime);
    DateTime(int _year, int _month, int _day, int h, int m, int s);
    DateTime(int _year, int _month, int _day);
    int day_of_week();   // 0, если воскресенье, остальные от 1 до 6
    static DateTime now();
    time_t unixT();
    std::string str();
    my::TimeSpan Dif(DateTime);
    DateTime & operator = (DateTime);
    bool operator < (DateTime);
    bool operator > (DateTime);
    bool operator <= (DateTime);
    bool operator >= (DateTime);
    bool operator != (DateTime);
    bool operator == (DateTime);
    TimeSpan operator - (DateTime);
    DateTime operator + (TimeSpan);
    DateTime operator - (TimeSpan);

    friend std::ostream& operator << (std::ostream& ostr, my::DateTime x);
    friend std::istream& operator>> (std::istream&, my::DateTime &);
};


class TimeSpan
{
public:
    DateTime span;
  public:
    TimeSpan & operator = (const TimeSpan &other){
        this->span = other.span;
        return *this;
    }
    friend class DateTime;
    friend std::ostream& operator << (std::ostream& ostr, my::TimeSpan x);
    friend std::istream& operator>> (std::istream&, my::TimeSpan &);
};


std::istream& operator>> (std::istream& istr, my::DateTime & x)
{
    int _year, _month, _day, _hour, _minute, _second;
    istr >> _year;
    istr >> _month;
    istr >> _day;
    istr >> _hour;
    istr >> _minute;
    istr >> _second;
    my::DateTime answer(_year, _month, _day, _hour, _minute, _second);
    x = answer;
    return (istr);
}


std::ostream& operator << (std::ostream& ostr, my::DateTime x)
{
    ostr<<x.str();
    return (ostr);
}

std::istream& operator>> (std::istream& istr, my::TimeSpan & x)
{
    int _year, _month, _day, _hour, _minute, _second;
    istr >> _year;
    istr >> _month;
    istr >> _day;
    istr >> _hour;
    istr >> _minute;
    istr >> _second;
    my::DateTime answer(_year, _month, _day, _hour, _minute, _second);
    x.span = answer;
    return (istr);
}


std::ostream& operator << (std::ostream& ostr, my::TimeSpan x)
{
    ostr<<x.span.str();
    return (ostr);
}
}

//-- КОНСТРУКТОР ПО УМОЛЧАНИЮ--
my::DateTime::DateTime():unixTimeFlag(false){;}

//-- КОНСТРУКТОР ПО UNIXTIME--

my::DateTime::DateTime(time_t _unixTime): unixTime(_unixTime){
    unixTimeFlag = true;
    struct tm * timeinfo;
    timeinfo = localtime (& _unixTime);
    year = 1900 + timeinfo->tm_year;
    month = 1 + timeinfo->tm_mon; //номер месяца
    day = timeinfo->tm_mday;
    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
    second = timeinfo->tm_sec;
    w_day = timeinfo->tm_wday;
}

//-- КОНСТРУКТОР ПО ВРЕМЕНИ--

my::DateTime::DateTime(int _year, int _month, int _day, int h, int m, int s): year(_year), month(_month), day(_day), hour(h), minute(m), second(s){
    unixTimeFlag = false;
}

//-- КОНСТРУКТОР ПО ДАТЕ--

my::DateTime::DateTime(int _year, int _month, int _day): year(_year), month(_month), day(_day), hour(0), minute(0), second(0){
    unixTimeFlag = false;
}




// ПЕРЕВОД В СТРОКУ
std::string my::DateTime:: str()
{
    char c;
    std::string answer;
    //answer.push_back(c);
    int a;
    a = day;
    for (int i = 0;  i < 2; ++i){
        int x;
        if (i == 0) {x = a / 10;} else {x = a %10;}
        switch (x)
          {
          case 0: c = '0';
              break;
          case 1: c = '1';
              break;
          case 2: c = '2';
              break;
          case 3: c = '3';
              break;
          case 4: c = '4';
              break;
          case 5: c = '5';
              break;
          case 6: c = '6';
              break;
          case 7: c = '7';
              break;
          case 8: c = '8';
              break;
          case 9: c = '9';
              break;
          }
        a = a % 10;
        answer.push_back(c);
    }
    answer.push_back('.');

    a = month;
    for (int i = 0;  i < 2; ++i){
        int x;
        if (i == 0) {x = a / 10;} else {x = a %10;}
        switch (x)
          {
          case 0: c = '0';
              break;
          case 1: c = '1';
              break;
          case 2: c = '2';
              break;
          case 3: c = '3';
              break;
          case 4: c = '4';
              break;
          case 5: c = '5';
              break;
          case 6: c = '6';
              break;
          case 7: c = '7';
              break;
          case 8: c = '8';
              break;
          case 9: c = '9';
              break;
          }
        a = a % 10;
        answer.push_back(c);
    }
    answer.push_back('.');

    a = year;
    int X;
    X = 1000;
    for (int i = 0;  i < 4; ++i){

        switch (a / X)
          {
          case 0: c = '0';
              break;
          case 1: c = '1';
              break;
          case 2: c = '2';
              break;
          case 3: c = '3';
              break;
          case 4: c = '4';
              break;
          case 5: c = '5';
              break;
          case 6: c = '6';
              break;
          case 7: c = '7';
              break;
          case 8: c = '8';
              break;
          case 9: c = '9';
              break;
          }
        a = a % X;
        X /= 10;
        answer.push_back(c);
    }
    answer.push_back(' ');

    a = hour;
    X = 10;
    for (int i = 0;  i < 2; ++i){
        switch (a / X)
          {
          case 0: c = '0';
              break;
          case 1: c = '1';
              break;
          case 2: c = '2';
              break;
          case 3: c = '3';
              break;
          case 4: c = '4';
              break;
          case 5: c = '5';
              break;
          case 6: c = '6';
              break;
          case 7: c = '7';
              break;
          case 8: c = '8';
              break;
          case 9: c = '9';
              break;
          }
        a = a % X;
        X /= 10;
        answer.push_back(c);
    }
    answer.push_back(':');

    a = minute;
    X = 10;
    for (int i = 0;  i < 2; ++i){

        switch (a / X)
          {
          case 0: c = '0';
              break;
          case 1: c = '1';
              break;
          case 2: c = '2';
              break;
          case 3: c = '3';
              break;
          case 4: c = '4';
              break;
          case 5: c = '5';
              break;
          case 6: c = '6';
              break;
          case 7: c = '7';
              break;
          case 8: c = '8';
              break;
          case 9: c = '9';
              break;
          }
        a = a % X;
        X /= 10;
        answer.push_back(c);
    }
    answer.push_back(':');

    a = second;
    X = 10;
    for (int i = 0;  i < 2; ++i){

        switch (a / X)
          {
          case 0: c = '0';
              break;
          case 1: c = '1';
              break;
          case 2: c = '2';
              break;
          case 3: c = '3';
              break;
          case 4: c = '4';
              break;
          case 5: c = '5';
              break;
          case 6: c = '6';
              break;
          case 7: c = '7';
              break;
          case 8: c = '8';
              break;
          case 9: c = '9';
              break;
          }
        a = a % X;
        X /= 10;
        answer.push_back(c);
    }
    return answer;
}

//  СТАТИЧЕСКИЙ МЕТОД, ВОЗВРАЩАЮЩИЙ ТЕКУЩЕЕ ВРЕМЯ

my::DateTime my::DateTime::now()
{
      time_t rawtime;
      time (&rawtime);
      localtime (&rawtime);
      my::DateTime t(rawtime);
      return t;
}




//ВРЕМЯ В UNIXTIME

time_t my::DateTime::unixT(){
    if (unixTimeFlag){
        return unixTime;
    } else {
        unixTimeFlag = true;
        int day_month;
        switch (month)
        {
            case 1: day_month = day - 1; //целые дни!
                break;
            case 2: day_month = day - 1 + 31;
                break;
            case 3:
                if (year % 4 ==  0 )//год високосный
                {
                    day_month = day - 1 + 31 + 29;
                } else {
                    day_month = day - 1 + 31 + 28;
                }
                break;
            case 4:
                 if (year % 4 ==  0 )//год високосный
                 {
                    day_month = day - 1 + 31 * 2 + 29;
                 } else {
                    day_month = day - 1 + 31 * 2 + 28;
                 }
                break;
            case 5:
                if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                {
                    day_month = day - 1 + 31 * 2 + 29 + 30;
                 } else {
                     day_month = day - 1 + 31 * 2 + 28 + 30;
                 }
                break;
            case 6:
                  if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                  {
                       day_month = day - 1 + 31 * 3 + 29 + 30;
                  } else {
                      day_month = day - 1 + 31 * 3 + 28 + 30;
                  }
                break;
            case 7:
                 if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                 {
                        day_month = day - 1 + 31 * 3 + 29 + 30 * 2;
                  } else {
                        day_month = day - 1 + 31 * 3 + 28 + 30 * 2;
                  }
                break;
            case 8:
             if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                {
                     day_month = day - 1 + 31 * 4 + 29 + 30 * 2;
                 } else {
                     day_month = day - 1 + 31 * 4 + 28 + 30 * 2;
                }
                break;
            case 9:
              if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                 {
                       day_month = day - 1 + 31 * 5 + 29 + 30 * 2;
                  } else {
                       day_month = day - 1 + 31 * 5 + 28 + 30 * 2;
                  }
                break;
            case 10:
            if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                {
                   day_month = day - 1 + 31 * 5 + 29 + 30 * 3;
                } else {
                   day_month = day - 1 + 31 * 5 + 28 + 30 * 3;
                }
                break;
            case 11:
            if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                {
                    day_month = day - 1 + 31 * 6 + 29 + 30 * 3;
                } else {
                     day_month = day - 1 + 31 * 6 + 28 + 30 * 3;
                }
                break;
            case 12:
            if (((year % 4 ==  0) && (year % 100 != 0)) ||(year % 400 == 0))//год високосный
                 {
                      day_month = day - 1 + 31 * 6 + 29 + 30 * 4;
                 } else {
                         day_month = day - 1 + 31 * 6 + 28 + 30 * 4;
                 }
                 break;

        }
        int year_366 = (year - 1970) / 4 - (year - 1970) / 100 + (year - 1970) / 400; //количество високосных лет (c 1972) ( 2000 вычеркнули)
        int year_365 = year - 1970 - year_366; //количество невисокосных лет
        unixTime = (year_366 * 366 + year_365 * 365 + day_month) * 86400  + 3600 * hour + 60 * minute + second + 72000; //без этих двух часов не сходится((( мб часовой пояс?
        struct tm * timeinfo;
         timeinfo = localtime (& unixTime);
         w_day = timeinfo->tm_wday;
         return unixTime;
    }

}

//1 Январь	31
//2	Февраль	28 (в високосном году — 29)
//3	Март	31
//4	Апрель	30
//5	Май	31
//6	Июнь	30
//7	Июль	31
//8	Август	31
//9	Сентябрь	30
//10	Октябрь	31
//11	Ноябрь	30
//12	Декабрь	31

//    1 минута	60 секунд
//    1 час	3600 секунд
//    1 день	86400 секунд
//    1 неделя	604800 секунд
//    1 месяц (30.44 дней) 	2629743 секунд
//    1 год (365.24 дней) 	 31556926 секунд



// ДЕНЬ НЕДЕЛИ

int my::DateTime::day_of_week()
{
    if (unixTimeFlag) {
        return w_day;
    } else {
        unixTime = unixT();
        std::cout<<unixTime<<"\n";
        return w_day;
    }
}


// РАЗНИЦА

my::TimeSpan my::DateTime::Dif (DateTime a)
{
    if (!unixTimeFlag){
        this->unixT();
    }
    if(!a.unixTimeFlag){
        a.unixT();
    }
    size_t x;
    if (a.unixTime > this->unixTime) {

        x = a.unixTime - this->unixTime;
    } else {
       x = this->unixTime - a.unixTime;
    }
    DateTime _answer(x);
    _answer.year = _answer.year - 1970;
    _answer.day -= 1;
    _answer.month -=1;
    _answer.hour -= 3; //+часовой пояс
    TimeSpan answer;
    answer.span = _answer;
    return answer;
}

// СЛОЖЕНИЕ
my::DateTime  my::DateTime::operator + (my::TimeSpan a){
    if (!unixTimeFlag){
        this->unixT();
    }
    if(!a.span.unixTimeFlag){
        a.span.unixT();
    }
    DateTime answer(unixTime + a.span.unixTime);
    return answer;
}

my::DateTime  my::DateTime::operator - (my::TimeSpan a){
    if (!unixTimeFlag){
        this->unixT();
    }
    if(!a.span.unixTimeFlag){
        a.span.unixT();
    }
    size_t x;
    if (unixTime - a.span.unixTime < 0) {
        std::cout<< "Дата меньше начала эпохи"<<'\n';
        x = 0;
    } else {
        x = unixTime - a.span.unixTime;
    }
    DateTime answer(x);
    return answer;
}


//промежуток между датами
my::TimeSpan  my::DateTime::operator - (my::DateTime a){
    if (!unixTimeFlag){
        this->unixT();
    }
    if(!a.unixTimeFlag){
        a.unixT();
    }
    size_t x;
    if (unixTime - a.unixTime < 0) {
         x = a.unixTime - unixTime;
    } else {
        x = unixTime - a.unixTime;
    }
    my::TimeSpan answer;
    DateTime y(x);
    answer.span = y;
    return answer;
}

// ОПЕРАТОР ПРИСВАИВАНИЯ
my::DateTime & my::DateTime::operator = (DateTime a){
     year = a.year;
     month = a.month;
     day = a.day;
     hour = a.hour;
     minute = a.minute;
     second = a.second;
     unixTimeFlag = a.unixTimeFlag;
     unixTime = a.unixTime;
     w_day = a.w_day;
    return *this;
}


// ОПЕРАОТРЫ СРАВНЕНИЯ
bool my::DateTime:: operator < (my::DateTime a){
    if (!unixTimeFlag){
        this->unixT();
    }
    if(!a.unixTimeFlag){
        a.unixT();
    }
    return (unixTime < a.unixTime);
}

bool my::DateTime:: operator > (my::DateTime a){
    if (!unixTimeFlag){
        this->unixT();
    }
    if(!a.unixTimeFlag){
        a.unixT();
    }
    return (unixTime > a.unixTime);
}

bool my::DateTime:: operator <= (my::DateTime a){
    if (!unixTimeFlag){
        this->unixT();
    }
    if(!a.unixTimeFlag){
        a.unixT();
    }
    return (unixTime <= a.unixTime);
}

bool my::DateTime:: operator >= (my::DateTime a){
    if (!unixTimeFlag){
        this->unixT();
    }
    if(!a.unixTimeFlag){
        a.unixT();
    }
    return (unixTime >= a.unixTime);
}

bool my::DateTime:: operator == (my::DateTime a){
    if (!unixTimeFlag){
        this->unixT();
    }
    if(!a.unixTimeFlag){
        a.unixT();
    }
    return (unixTime == a.unixTime);
}

bool my::DateTime:: operator != (my::DateTime a){
    if (!unixTimeFlag){
        this->unixT();
    }
    if(!a.unixTimeFlag){
        a.unixT();
    }
    return (unixTime != a.unixTime);
}


