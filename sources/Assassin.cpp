#include "Assassin.hpp"

namespace coup
{
    constexpr int coup_cost = 7;
    constexpr int kill_cost = 3;

    Assassin::Assassin(coup::Game &board, std::string name) : coup::Player(board, name)
    {
        this->player_to_kill = nullptr;
    }

    std::string Assassin::role()
    {
        return "Assassin";
    }

    void Assassin::coup(Player &p)
    {
        startTurn();
        if (!p.isAlive)
        {
            throw "player is dead";
        }
        // if not enaugh coins to kill
        if (this->how_much_i_have < 3)
        {
            throw "not enough coins";
        }
        // if this doesnt have enough coins to coup
        if (this->how_much_i_have >= 7)
        {
            p.isAlive = false;
            this->how_much_i_have -= 7;
            this->player_to_kill = &p;
            endTurn(Actions::coup);
        }
        else
        {
            // kill
            p.isAlive = false;
            this->player_to_kill = &p;
            this->how_much_i_have -= 3;
            endTurn(Actions::Acoup);
        }
    }

    void Assassin::blockme()
    {
        switch (this->call_that_executed_end)
        {
        case Actions::foreign_aid:
            this->how_much_i_have -= 2;
            break;
        case Actions::Acoup:
            this->player_to_kill->isAlive = true;

            break;
        default:
            throw "not good choice Assasing";
            break;
        }
        this->call_that_executed_end = Actions::nothing;
    };

    Assassin::~Assassin(){};

}