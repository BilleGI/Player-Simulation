#pragma once
#include<string>
#include <ctime>

class Track
{
private:
    std::string title;
    std::tm date;
    std::time_t time;
public:
    // конструктор
    Track() : title(""), date(), time(0)
        {};
    Track(const std::string& tite, const std::tm& dt, const std::time_t& t) :
        title(tite), date(dt), time(t)
    { }

//    std::string str(Track& track);
    std::string str();

    std::tm date_track();

    std::time_t time_track();
};
