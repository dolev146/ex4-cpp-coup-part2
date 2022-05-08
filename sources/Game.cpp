#include "Game.hpp"
const expr int ONE = 1;
namespace coup
{
    std::vector<std::string> players()
    {
        std::vector<std::string> players_return_value;
        for (auto player : players_Pointers_array)
        {
            players_return_value.push_back(player->name);
        }
        return players_return_value;
    };
    std::string turn()
    {
        // check if players pointer array is empty
        if (players_Pointers_array.empty())
        {
            throw "No players";
        }
        return players_Pointers_array[this->counter]->name;
    };

    std::string winner()
    {
        // check if players pointer array doesnt have less than 1 player in it and if the game not started yet then throw
        bool temp_check1 = (players_Pointers_array.size() < ONE) ? true : false;
        bool temp_check2 = (this->gameStarted == false) ? true : false;
        if (temp_check1 || temp_check2)
        {
            throw "No winner";
        }
    };

    void AlgoTurnRithm()
    {
        // replace do while with for loop
        // do
        // {
        //     i = (i + 1) % playersList.size();
        // } while (!playersList[i]->isAlive);
        // maybe need to fix this
        for (int i = 0; i < players_Pointers_array.size(); i++)
        {
            if (players_Pointers_array[i]->isAlive)
            {
                this->counter = (this->counter + 1) % players_Pointers_array.size();
            }
        }
    };

    Game::Game()
    {
        this->gameOver = false;
        this->gameStarted = false;
        this->counter = 0;
    };

}