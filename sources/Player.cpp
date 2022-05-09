#include "Player.hpp"
#include "Game.hpp"

namespace coup
{
    constexpr int max_players = 6;
    constexpr int how_much_i_have_max = 10;
    constexpr int how_much_need = 7;

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
    void Player::startTurn()
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
    void Player::endTurn(mesimot_to_choose a)
    {
        this->call_that_executed_end = a;
        this->board->AlgoTurnRithm();
    }

    //**
    void Player::income()
    {

        startTurn();
        this->how_much_i_have++;
        endTurn(mesimot_to_choose::income);
    }

    void Player::foreign_aid()
    {
        if (this->how_much_i_have > how_much_i_have_max)
        {
            throw "how_much_i_have_max";
        }
        startTurn();
        this->how_much_i_have += 2;
        endTurn(mesimot_to_choose::foreign_aid);
    }

    void Player::coup(Player &p)
    {
        startTurn();
        if (!p.isAlive)
        {
            throw "not alive ";
        }
        if (this->how_much_i_have < how_much_need)
        {
            throw "not how much i have";
        }
        p.isAlive = false;
        this->how_much_i_have -= how_much_need;
        endTurn(mesimot_to_choose::coup);
    }
    string Player::role()
    {
        return "Player";
    }
    int Player::coins() const
    {
        return this->how_much_i_have;
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

    Player::~Player()
    {
    }

}
