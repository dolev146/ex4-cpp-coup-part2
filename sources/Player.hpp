
#pragma once
#include "Game.hpp"
#include <string>


using namespace std;
namespace coup
{

    class Player
    {
    public:
        // init a static variable to keep track of the number of players
        static int num_players;
        // init a static variable to keep track of the number of players
        static int num_players_alive;
        // init a static variable to keep track of the number of players
        static int num_players_dead;
        // init a static variable to keep track of the number of players
        static int num_players_in_game;
        // init a static variable to keep track of the number of players
        static int num_players_in_game_alive;

        string name;
        int money;
        int id;
        bool isAlive;
        Game *board;
        Player(Game &board, string name);
        void income();
        void foreign_aid();
        void coup(Player p);
        void role();
        int coins();
        ~Player();
    };

}