#include "track.h"
#include <ctime>
#include <string>

std::string Track::str()
{
    return title;
}

std::tm Track::date_track()
{
    return date;
}

std::time_t Track::time_track()
{
    return time;
}
