#include "Player.hpp"
#include "Game.hpp"
#include <string>
#include <stdexcept>
#include <vector>
#include "Captain.hpp"

namespace coup
{
    Captain::Captain(coup::Game &board, std::string name) : coup::Player(board, name)
    {
        this->me_she_ani_rotze_laarog = nullptr;
        this->ma_she_ganavti = 0;
    }

    Captain::~Captain()
    {
    }

    std::string Captain::role()
    {
        return "Captain";
    }

    void Captain::block(Player &p)
    {
        if (p.call_that_executed_end != Actions::steal)
        {
            throw "not steal";
        }
        p.BlockMe();
    }

    void Captain::steal(Player &p)
    {
        startTurn();
        if (p.how_much_i_have <= 0)
        {
            throw "not enough ";
        }
        if (p.how_much_i_have < 2)
        {
            this->how_much_i_have += p.how_much_i_have;
            this->ma_she_ganavti = p.how_much_i_have;
            p.how_much_i_have = 0;
            this->me_she_ani_rotze_laarog = &p;
        }
        else
        {
            this->how_much_i_have += 2;
            this->ma_she_ganavti = 2;
            p.how_much_i_have -= 2;
            this->me_she_ani_rotze_laarog = &p;
        }
        endTurn(Actions::steal);
    }

    void Captain::blockMe()
    {
        switch (this->call_that_executed_end)
        {
        case Actions::foreign_aid:
            this->how_much_i_have -= 2;
            break;
        case Actions::steal:
            this->me_she_ani_rotze_laarog->how_much_i_have += this->ma_she_ganavti;
            this->how_much_i_have -= this->ma_she_ganavti;
        default:
            throw "not good choice";
            break;
        }
        this->call_that_executed_end = Actions::nothing;
    }

} // namespace coup