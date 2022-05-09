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
        if (p.call_that_executed_end != mesimot_to_choose::foreign_aid)
        {
            throw string("not foreign aid");
        }
        p.function_to_kill_it_player();
    }

    void Duke::tax()
    {
        startTurn();
        this->how_much_i_have += 3;
        endTurn(mesimot_to_choose::tax);
    }

    Duke::~Duke()
    {
    }
}