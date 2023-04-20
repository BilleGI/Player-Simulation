#pragma once
#include <string>
#include <ctime>
#include <vector>
#include "track.h"

class Player
{
    private:
        std::vector<Track> music;
        int now;
    public:
        void getTrack();

        void play();

        void pause();

        void next();

        void stop();
};

void primary(const std::string& command);
