#include "Captain.hpp"
namespace coup
{
    Captain::Captain(Game &board, string name) : Player(board, name)
    {
        stealSuccess = false;
        stolenPlayer = NULL;
    }

    void Captain::block(Player &p)
    {
    }
    void Captain::steal(Player &p)
    {
        if (this->board->game_over == true && this->board->game_started == false && this->board->playersObj.size() < 2)
        {
            throw runtime_error("Game is not started yet");
        }
        if (this->board->current_player_turn != this)
        {
            throw runtime_error("It is not your turn");
        }
        // check if the player is in the same board
        if (this->board != p.board)
        {
            throw runtime_error("Player is not in the same board");
        }
        // check if the player is alive
        if (p.isAlive == false)
        {
            throw runtime_error("Player is not alive");
        }
        // check if this has 10 coins or more he must run coup
        if (this->money >= 10)
        {
            throw runtime_error("You must run coup");
        }
        if (p.money <= 0)
        {
            throw runtime_error("Player has no money");
        }
        if (p.money == 1)
        {
            p.money = 0;
            this->money += 1;
            this->stealSuccess = true;
            this->stolenPlayer = &p;
        }
        else
        {
            p.money -= 2;
            this->money += 2;
            this->stealSuccess = true;
            this->stolenPlayer = &p;
        }
    }

    string Captain::role()
    {
        return "Captain";
    }



    
}