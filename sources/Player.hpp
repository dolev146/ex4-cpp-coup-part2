
#pragma once
#include "Game.hpp"
#include <string>

using namespace std;
namespace coup
{

    class Player
    {
    public:
        string name;
        int money;
        int id;
        bool isAlive;
        bool asking_for_foreign_aid;
        Game *board;
        Game *board;
        Player(Game &board, string name);
        void income();
        void foreign_aid();
        void coup(Player p);
        string role();
        int coins();
        ~Player();
    };

}