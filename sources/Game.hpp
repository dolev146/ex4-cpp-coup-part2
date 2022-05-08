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
        // init a static variable to keep track of the number of players
        int num_players;
        int turn_counter;
        int num_players_alive;
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
