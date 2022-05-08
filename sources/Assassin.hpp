#ifndef Assassin_hpp
#define Assassin_hpp
#include "Player.hpp"

namespace coup
{

    class Assassin : public Player
    {
    public:
        Player *player_to_kill;
        Assassin(Game &board, std::string &name);
        ~Assassin();
        std::string role();
        void coup(Player &);
        void blockMe();
    }
}

#ifndef Assassin_hpp