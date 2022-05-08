#include "Contessa.hpp"
#include "Assassin.hpp"
namespace coup
{
    void Contessa::block(Player &p)
    {
        if (p.isAlive == false)
        {
            throw std::runtime_error("Player is already dead");
        }
        if (p.role() != "Assassin")
        {
            throw std::runtime_error("Player is not an assassin");
        }

        // use dynamic_cast to check if p is an assassin
        Assassin *a = dynamic_cast<Assassin *>(&p);
        if (a == nullptr)
        {
            throw std::runtime_error("Player is not an assassin");
        }
        if (a->isAlive == false)
        {
            throw std::runtime_error("the blocked player didnt steal!");
        }
        this->board.revivePlater(a.coupedPlayer);
        a.resetPlayer();
    }

    string Contessa::role()
    {
        return "Contessa";
    }
}