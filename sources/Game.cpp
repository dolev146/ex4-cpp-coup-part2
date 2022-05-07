#include "Game.hpp"

namespace coup
{
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
        Game::turn_counter = Game::turn_counter % this->playersObj.size();
        for (Player *player : this->playersObj)
        {
            if (player->id == Game::turn_counter)
            {
                // check if palyer is alive
                if (player->isAlive)
                {
                    this->current_player_turn = player;
                    Game::turn_counter++;
                    return player->name;
                }
                else
                {
                    // if player is dead, then go to the next player
                    Game::turn_counter++;
                    continue;
                }
            }
        }
        return this->current_player_turn->name;
    }

    string Game::winner()
    {
        // see which player is still alive and return the name of the player
        // if there is more than one player allive then the game is not over
        // if there is only one player alive then the game is over and the winner is alive
        if (Player::num_players_alive == 1)
        {
            return this->current_player_turn->name;
        }
        else
        {
            return "";
        }
    }
}