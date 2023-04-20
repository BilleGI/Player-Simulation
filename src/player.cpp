#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include "track.h"
#include "player.h"

void initial(std::string& name, const int& i, std::tm& dt, std::time_t& t)
{
    name = "Track " + std::to_string(i);
    dt.tm_year = rand() % 44 + 80;
    dt.tm_mon = rand() % 11;
    dt.tm_mday = rand() % 31;
    t = rand() % 720 + 120;
}

void Player::getTrack()
{
    if(music.empty())
    {
        int16_t num = 0;
        std::cout << "Enter the number of tracks: ";
        while(true)
        {
            std::cin >> num;
            std::cin.get();
            if(num >= 3 && num <= 1000)
                break;
            std::cout << "Enter the correct mean: ";
        }

        std::string name;
        std::tm dt;
        std::time_t t;
        srand(time(nullptr));
        for(int i = 0; i < num; i++)
        {
            initial(name, i, dt, t);
            Track my_Track(name, dt, t);
            music.push_back(my_Track);
        }
    }
}


void Player::play()
{
    std::string name;

    std::cout << "Enter the name of the track: ";
    getline(std::cin, name);
    for (int i = 0; i < music.size(); ++i)
    {
        if(name == music[i].str())
        {
            now = i;
            std::cout << "Track " << music[now].str();
            std::cout << " date " << music[i].date_track().tm_mday << "." << music[i].date_track().tm_mon << "." << music[i].date_track().tm_year;
            std::cout << " time " << music[i].time_track();
        }
    }
}

void Player::pause()
{
    std::cout << "Track " << music[now].str() << " is paused." << std::endl;
}

void Player::next()
{
    srand(time(nullptr));
    int i = rand() % music.size();
    now = i;
    std::cout << "Track " << music[now].str();
    std::cout << " date " << music[i].date_track().tm_mday << "." << music[i].date_track().tm_mon << "." << music[i].date_track().tm_year;
    std::cout << " time " << music[i].time_track();
}

void Player::stop()
{
    std::cout << "Track " << music[now].str() << " is stoped." << std::endl;
}

void primary (const std::string& command)
{
    static std::string lastCommand;
    static Player player;

    player.getTrack();
    if(command != lastCommand)
    {
        if(command == "play" && lastCommand != "next")
            player.play();

        else if (command == "pause" && !lastCommand.empty())
            player.pause();

        else if (command == "next" && !lastCommand.empty())
            player.next();

        else if(command == "stop" && !lastCommand.empty())
            player.stop();

        if(command == "play" && lastCommand.empty())
            lastCommand = command;
        else if (!lastCommand.empty())
            lastCommand = command;
    }

}
