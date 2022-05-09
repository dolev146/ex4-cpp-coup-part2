#include "Captain.hpp"

namespace coup
{
    Captain::Captain(coup::Game &board, std::string name) : coup::Player(board, std::move(name))
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
        why_not = true;
        if (p.call_that_executed_end != Actions::steal)
        {
            throw "not steal";
        }
        p.blockme();
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

    void Captain::blockme()
    {
        switch (call_that_executed_end)
        {
        case Actions::foreign_aid:
            how_much_i_have -= 2;
            break;
        case Actions::steal:
            me_she_ani_rotze_laarog->how_much_i_have += ma_she_ganavti;
            how_much_i_have -= ma_she_ganavti;
            break;
        default:
            throw invalid_argument("you can't block my last action");
            break;
        }
        call_that_executed_end = Actions::nothing;
    }

} // namespace coup