#include "Player.hpp"
#include "Game.hpp"
#include <string>
#include <stdexcept>
#include <vector>
#include "Contessa.hpp"

namespace coup{
    Contessa::Contessa(coup::Game &board, std::string name) : coup::Player(board, name)
    {
    }

    Contessa::~Contessa()
    {
    }

    std::string Contessa::role()
    {
        return "Contessa";
    }

    void Contessa::block(Player &p)
    {
        if (p.call_that_executed_end != Actions::Acoup)
        {
            throw "throw";
        }
        p.BlockMe();
    }
}