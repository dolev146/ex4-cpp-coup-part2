#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "Player.hpp"
#pragma once

using namespace std;

namespace coup
{

    class Game
    {
    public:
        static int turn_counter;
        static int num_players_alive;
        vector<Player *> playersObj;
        Player *current_player_turn;
        bool game_over;
        bool game_started;
        vector<string> players();
        string turn();
        string winner();
        ~Game();
        Game();
    };
}
