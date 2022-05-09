
#include "Contessa.hpp"

namespace coup
{
    Contessa::Contessa(coup::Game &board, std::string name) : coup::Player(board, std::move(name))
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
        why_not = true;
        if (p.call_that_executed_end != Actions::Acoup)
        {
            throw "throw";
        }
        p.blockme();
    }
}