#include "Player.hpp"
#include "Game.hpp"
#include <string>
#include <stdexcept>
#include <vector>
#include "Duke.hpp"

namespace coup
{
    Duke::Duke(coup::Game &board, std::string name) : coup::Player(board, std::move(name))
    {
    }

    std::string Duke::role()
    {
        return "Duke";
    }

    void Duke::block(Player &p)
    {
        why_not = false;
        if (p.call_that_executed_end != Actions::foreign_aid)
        {
            throw string("not foreign aid");
        }
        p.blockme();
    }

    void Duke::tax()
    {
        startTurn();
        this->how_much_i_have += 3;
        endTurn(Actions::tax);
    }

    Duke::~Duke()
    {
    }
}