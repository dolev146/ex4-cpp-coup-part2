#ifndef Assassin_hpp
#define Assassin_hpp

#include "Player.hpp"
using namespace std;
namespace coup
{

    class Assassin : public coup::Player
    {
    public:
        bool why_not = false;
        Player *player_to_kill;
        Assassin(coup::Game &board, std::string name);
        ~Assassin();
        std::string role();
        void coup(Player &);
        void blockme();
    };
}

#endif /* Assassin_hpp */