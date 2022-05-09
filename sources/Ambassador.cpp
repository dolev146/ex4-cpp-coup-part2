#include "Ambassador.hpp"

namespace coup
{
    constexpr int ONEAGAIN = 1;
    Ambassador::Ambassador(coup::Game &board, std::string name) : Player(board, std::move(name))
    {
    }

    Ambassador::~Ambassador()
    {
    }

    std::string Ambassador::role()
    {
        return "Ambassador";
    }

    void Ambassador::transfer(Player &p1, Player &p2)
    {
        startTurn();
        if (p1.how_much_i_have < 1)
        {
            throw "not enough money";
        }
        p1.how_much_i_have -= ONEAGAIN;
        p2.how_much_i_have += ONEAGAIN;
        endTurn(Actions::transfer);
    }

    void Ambassador::block(Player &p)
    {
        why_not = true; 
        if (p.call_that_executed_end != Actions::steal)
        {
            throw invalid_argument("you can't block " + p.name + " now");
        }
        p.blockme();
    }

}