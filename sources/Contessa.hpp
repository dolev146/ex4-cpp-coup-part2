#ifndef Contessa_hpp
#define Contessa_hpp

#include "Player.hpp"
#include "Game.hpp"
#include <string>
#include <stdexcept>
#include <vector>


namespace coup
{
    class Contessa : public coup::Player
    {
    public:
        Contessa(coup::Game &board, std::string name);
        ~Contessa();
        std::string role();
        void block(Player &p);
    };
}

#endif /* Contessa_hpp */