#include "Duke.hpp"
namespace coup
{
    void Duke::block(Player p)
    {
    }
    void Duke::tax()
    {
        if (this != this->board->current_player_turn)
        {
            throw std::runtime_error("Not your turn");
        }
        if (this->money >= 10)
        {
            throw std::runtime_error("must coup!");
        }
        else
        {
            this->money = this->money + 3;
        }
    }
    string Duke::role()
    {
        return "Duke";
    }

    void Duke::block(Player p)
    {
        if (p.isAlive == false)
        {
            throw std::runtime_error("Player is already dead");
        }
        if (p.asking_for_foreign_aid == false)
        {
            throw std::runtime_error("Player is not asking for foreign aid");
        }
        p.money = p.money - 2;
    }
}
