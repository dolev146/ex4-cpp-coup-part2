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
        Player::num_players_alive--;
        // update the number of players dead
        Player::num_players_dead++;
        // update the number of players in game
        Player::num_players_in_game--;
    }
    void Player::role()
    {
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
        this->id = Player::num_players;

        // if the number of players is less than 6, then add 1 to the number of players
        if (Player::num_players < MAX_PLAYERS)
        {
            Player::num_players = Player::num_players + ONE;
            // add player to playersObj
            this->board->playersObj.push_back(this);
        }
        else
        {
            // if the number of players is more than 6 then throw an error
            throw std::runtime_error("Too many players");
        }
    }

    Player::~Player()
    {
    }
}