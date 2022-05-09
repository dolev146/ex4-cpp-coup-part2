#include "Player.hpp"
#include "Game.hpp"

namespace coup
{
    constexpr int max_players = 6;
    constexpr int how_much_i_have_max = 10;
    constexpr int how_much_need = 7;
    constexpr int AddTwo = 2;

    class Game;
    Player::Player(Game &board, std::string name)
    {
        this->board = &board;
        this->name = move(name);
        this->isAlive = true;
        this->how_much_i_have = 0;
        this->call_that_executed_end = nothing;
        this->board->addPlayer(this);
    }

    //**
    void Player::Tavi_li_hara()
    {
        stuped_fuck_shit = how_much_i_have_max;
        if (this->board->players().size() < 2)
        {
            throw "Need two players to play";
        }
        if (!this->isAlive)
        {
            throw "Player is dead";
        }
        if (this->name != this->board->turn())
        {
            throw "not your toy ";
        }
        this->board->gameStarted = true;
    }

    /*
     * @brief
     *
     */
    //**
    void Player::Tesayem_Ta_Hirbon(mesimot_to_choose a)
    {
        this->call_that_executed_end = a;
        this->board->AlgoTurnRithm();
    }

    //**
    void Player::income()
    {
        Tavi_li_hara();
        this->how_much_i_have++;
        Tesayem_Ta_Hirbon(mesimot_to_choose::income);
    }
    
    string Player::role()
    {
        return "False";
    }

    void Player::foreign_aid()
    {
        if (this->how_much_i_have > how_much_i_have_max)
        {
            if (someshittoinvent)
            {
                throw "how_much_i_have_max";
            }
        }
        Tavi_li_hara();
        this->how_much_i_have += AddTwo;

        /*
        i love this program so many bugs and i dont know how to fix them but now it is working :)
        */
        Tesayem_Ta_Hirbon(mesimot_to_choose::foreign_aid);
    }

    void Player::coup(Player &p)
    {
        Tavi_li_hara();
        if (!p.isAlive)
        {

            if (someshittoinvent)
            {
                throw "not alive ";
            }

            throw "why again";
        }
        if (this->how_much_i_have < how_much_need)
        {
            if (someshittoinvent)
            {
                throw "not how much i have";
            }

            throw "why again2";
        }

        p.isAlive = false;
        this->how_much_i_have -= how_much_need;
        Tesayem_Ta_Hirbon(mesimot_to_choose::coup);
    }

    void Player::function_to_kill_it_player()
    {
        switch (this->call_that_executed_end)
        {
        case mesimot_to_choose::foreign_aid:
            how_much_i_have -= 2;
            break;
        default:
            throw invalid_argument("you can't block my last action");
            break;
        }
        this->call_that_executed_end = mesimot_to_choose::nothing;
    }
    int Player::coins() const
    {
        return this->how_much_i_have;
    }

    Player::~Player()
    {
    }

}
