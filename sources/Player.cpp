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
        this->name = name;
        this->isAlive = true;
        this->how_much_i_have = 0;
        this->call_that_executed_end = nothing;
        if (this->board->players_Pointers_array.size() >= max_players)
        {
            throw "Too many players";
        }
        if (this->board->gameStarted)
        {
            throw "Game already started";
        }
        this->board->players_Pointers_array.push_back(this);
    }

    //**
    void Player::startTurn()
    {
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
    void Player::endTurn(Actions a)
    {
        this->call_that_executed_end = a;
        this->board->AlgoTurnRithm();
    }

    //**
    void Player::income()
    {

        startTurn();
        this->how_much_i_have++;
        endTurn(Actions::income);
    }

    void Player::foreign_aid()
    {
        if (this->how_much_i_have > how_much_i_have_max)
        {
            throw "how_much_i_have_max";
        }
        startTurn();
        this->how_much_i_have += 2;
        endTurn(Actions::foreign_aid);
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
        endTurn(Actions::coup);
    }
    string Player::role()
    {
        return "Player";
    }
    int Player::coins() const
    {
        return this->how_much_i_have;
    }

    void Player::BlockMe()
    {
        switch (this->call_that_executed_end)
        {
        case Actions::foreign_aid:
            this->how_much_i_have -= 2;
            break;
        default:
            throw "not supported";
            break;
        }
        this->call_that_executed_end = Actions::nothing;
    }

    Player::~Player()
    {
    }

}
