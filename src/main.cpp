#include <iostream>
#include <algorithm>
#include "player.h"

void check(std::string& command)
{
    while(true)
    {
        auto it = std::find_if(command.begin(), command.end(), [](const char &c)
        {
            return !std::isalpha(c);
        });

        if(it==command.end())
            break;

        std::cout << "Enter the correct command: ";
        getline(std::cin, command);
    }
}

int main()
{
    std::string command;
    std::cout << "The program simulates the operation of the player." << std::endl;
    std::cout << "List of available commands: " << std::endl;
    std::cout << "play - requests a recording to be played," << std::endl;
    std::cout << "pause - puts on pause," << std::endl;
    std::cout << "next - play the next track," << std::endl;
    std::cout << "stop - stop the record," << std::endl;
    while(true)
    {
        std::cout << "Enter the command: ";
        getline(std::cin, command);

        check(command);

        if(command == "end")
            break;

        if (command == "play" || command == "pause" || command == "next" || command == "stop")
            primary(command);
    }

    return 0;
}
