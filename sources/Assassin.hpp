#ifndef Assassin_hpp
#define Assassin_hpp

#include "Player.hpp"
#include "Game.hpp"
#include <string>
#include <stdexcept>
#include <vector>

namespace coup
{

    class Assassin : public coup::Player
    {
    public:
        Player *player_to_kill;
        Assassin(coup::Game &board, std::string name);
        ~Assassin();
        std::string role();
        void coup(Player &);
        void blockMe();
    };
};

#endif /* Assassin_hpp */