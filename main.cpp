#include <iostream>
#include <string>
using namespace std;

#include "Interface.hpp"

string get_status_str(bool status)
{
    return status ? "Pass" : "Fail";
}

int main()
{
    TroubleBoardGame start_game;

	start_game.buildgameboard();

    system("pause");
}
