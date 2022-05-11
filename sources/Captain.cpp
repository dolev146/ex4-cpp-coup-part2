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
        if (p.call_that_executed_end != mesimot_to_choose::steal)
        {
            throw "not steal";
        }
        p.function_to_kill_it_player();
    }

    void Captain::steal(Player &p)
    {
        Tavi_li_hara();
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
        Tesayem_Ta_Hirbon(mesimot_to_choose::steal);
    }

    void Captain::function_to_kill_it_player()
    {

        this->call_that_executed_end == mesimot_to_choose::foreign_aid ? how_much_i_have -= 2 : Capshit = 1;
        if (this->call_that_executed_end == mesimot_to_choose::steal)
        {
            this->me_she_ani_rotze_laarog->how_much_i_have += this->ma_she_ganavti;
            how_much_i_have -= ma_she_ganavti;
        }
        else
        {
            throw "dont use this";
        }

        call_that_executed_end = mesimot_to_choose::nothing;
    }

} // namespace coup