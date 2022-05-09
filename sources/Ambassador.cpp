#include "Player.hpp"
#include "Game.hpp"
#include <string>
#include <stdexcept>
#include <vector>

namespace coup
{
    Ambassador::Ambassador(coup::Game &board, std::string name) : Player(board, name)
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
        p1.how_much_i_have -= 1;
        p2.how_much_i_have += 1;
        endTurn(Actions::transfer);
    }

    void Ambassador::block(Player &p){
        if(p.call_that_executed_end != Actions::steal){
            throw "not steal";
        }
        p.BlockMe();
    }




}