#include "Game.hpp"

namespace coup
{

    Game::Game()
    {
        this->num_players = 0;
        this->turn_counter = 0;
        this->num_players_alive = 0;
        this->game_over = false;
        this->game_started = false;
        
    }

    vector<string> Game::players()
    {
        vector<string> names;
        for (auto &player : this->playersObj)
        {
            names.push_back(player->name);
        }
        return names;
    }

    string Game::turn()
    {
        // loop over the number of players and increase the turn counter by 1 each time
        // use module the playarObj.size() to loop over the number of players in the game with modulus
        // if the turn counter is equal to the number of players, then reset the turn counter to 0
        // return the name of the player with the current turn counter
        this->game_started = true;
        // loop al players and if only one alive then game is over
        int temp_alive = 0;
        for (Player *player : this->playersObj)
        {
            if (player->isAlive)
            {
                temp_alive++;
            }
        }
        if (temp_alive == 1)
        {
            this->game_over = true;
        }
        this->turn_counter = this->turn_counter % this->playersObj.size();
        for (Player *player : this->playersObj)
        {
            if (player->id == this->turn_counter)
            {
                // check if palyer is alive
                if (player->isAlive)
                {
                    this->current_player_turn = player;
                    this->turn_counter++;
                    return player->name;
                }
                else
                {
                    // if player is dead, then go to the next player
                    this->turn_counter++;
                    continue;
                }
            }
        }
        // return this->current_player_turn->name;
    }

    string Game::winner()
    {
        // see which player is still alive and return the name of the player
        // if there is more than one player allive then the game is not over
        // if there is only one player alive then the game is over and the winner is alive
        if (game_over == false)
        {
            throw std::runtime_error("Game is not over");
        }
        // loop over players and check if they are alive
        for (Player *player : this->playersObj)
        {
            if (player->isAlive)
            {
                return player->name;
            }
        }
    }

}