#include "Game.hpp"

namespace coup
{
    constexpr int ONE = 1;
    constexpr int  limited_player_number = 6;
    std::vector<std::string> Game::players()
    {
        std::vector<std::string> players_return_value;
        for (auto *player : players_Pointers_array)
        {
            if (player->isAlive)
            {
                players_return_value.push_back(player->name);
            }
        }
        return players_return_value;
    };
    std::string Game::turn()
    {
        // check if players pointer array is empty
        if (players_Pointers_array.empty())
        {
            throw "No players";
        }
        return players_Pointers_array[this->counter]->name;
    };

    void Game::addPlayer(Player *p)
    {
        if (players().size() >= limited_player_number)
        {
            throw runtime_error("Need up to six players to play");
        }
        if (this->gameStarted)
        {
            throw runtime_error("Add Player In Middle Of Game");
        }

        this->players_Pointers_array.push_back(p);
    }

    std::string Game::winner()
    {
        // check if players pointer array doesnt have less than 1 player in it and if the game not started yet then throw
        // bool temp_check1 =  ? true : false;
        // bool temp_check2 =  ? true : false;
        if (players().size() != 1 || !gameStarted)
        {
            throw runtime_error("their is no winner in this game");
        }
        return this->players_Pointers_array[this->counter]->name;
    };

    void Game::AlgoTurnRithm()
    {
        // replace do while with for loop
        do
        {
            this->counter = (this->counter + 1) % players_Pointers_array.size();
        } while (!players_Pointers_array[this->counter]->isAlive);
        // maybe need to fix this
        // for (size_t i = 0; i < players_Pointers_array.size(); i++)
        // {
        //     if (players_Pointers_array[i]->isAlive)
        //     {
        //         this->counter = (this->counter + 1) % players_Pointers_array.size();
        //     }
        // }
        // return;
    };

    Game::Game()
    {
        this->gameOver = false;
        this->gameStarted = false;
        this->counter = 0;
    };

}