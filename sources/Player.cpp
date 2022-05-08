#include "Player.hpp"
#include "Game.hpp"
#pragma once
using namespace std;
#define MAX_PLAYERS 6
#define INCOME 1
#define FOREIGN_AID 2
#define ONE 1

namespace coup
{

    void Player::income()
    {
        this->money = this->money + INCOME;
    }
    void Player::foreign_aid()
    {
        this->money = this->money + FOREIGN_AID;
    }
    void Player::coup(Player p)
    {
        p.isAlive = false;
        // update the number of players alive
        this->board->num_players_alive--;
    }
    string Player::role()
    {
        return "";
    }
    int Player::coins()
    {
        return this->money;
    }
    Player::Player(Game &board, string name)
    {
        this->name = name;
        this->isAlive = true;
        this->board = &board;
        this->money = 0;
        this->id = this->board->playersObj.size();
        this->asking_for_foreign_aid = false;

        // if the game is over then throw an error or the game started then throw an error
        if (this->board->game_over)
        {
            throw std::runtime_error("Game is over");
        }
        if (this->board->game_started)
        {
            throw std::runtime_error("Game already started");
        }

        // if the number of players is less than 6, then add 1 to the number of players
        if (this->board->playersObj.size() < MAX_PLAYERS)
        {
            // add player to playersObj
            this->board->playersObj.push_back(this);
        }
        else
        {
            // if the number of players is more than 6 then throw an error
            throw std::runtime_error("Too many players");
        }

        // if this->board->num_players = 0 then set this->board->current_player_turn to this player
        if (this->board->playersObj.size() == 0)
        {
            this->board->current_player_turn = this;
        }
    }

    Player::~Player()
    {
    }
}