#include "Assassin.hpp"

namespace coup
{
    constexpr int coup_cost = 7;
    constexpr int kill_cost = 3;

    Assassin::Assassin(coup::Game &board, std::string name) : coup::Player(board, std::move(name))
    {
        this->player_to_kill = nullptr;
    }

    std::string Assassin::role()
    {
        return "Assassin";
    }

    void Assassin::coup(Player &p)
    {
        Tavi_li_hara();
        if (!p.isAlive)
        {
            throw "player is dead";
        }
        // if not enaugh coins to kill
        if (this->how_much_i_have < kill_cost)
        {
            throw "not enough coins";
        }
        // if this doesnt have enough coins to coup
        if (this->how_much_i_have >= coup_cost)
        {
            p.isAlive = false;
            this->how_much_i_have -= coup_cost;
            this->player_to_kill = &p;
            Tesayem_Ta_Hirbon(mesimot_to_choose::coup);
        }
        else
        {
            // kill
            p.isAlive = false;
            this->player_to_kill = &p;
            this->how_much_i_have -= kill_cost;
            Tesayem_Ta_Hirbon(mesimot_to_choose::Acoup);
        }
    }

    void Assassin::function_to_kill_it_player()
    {
        why_not = true;
        switch (this->call_that_executed_end)
        {
        case mesimot_to_choose::foreign_aid:
            this->how_much_i_have -= 2;
            break;
        case mesimot_to_choose::Acoup:
            this->player_to_kill->isAlive = true;

            break;
        default:
            throw "not good choice Assasing";
            break;
        }
        this->call_that_executed_end = mesimot_to_choose::nothing;
    };

    Assassin::~Assassin(){};

}