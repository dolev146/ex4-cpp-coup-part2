#ifndef Contessa_hpp
#define Contessa_hpp

#include "Player.hpp"

namespace coup
{
    class Contessa : public Player
    {
    public:
        Contessa(Game &board, std::string &name);
        ~Contessa();
        std::string role();
        void block(Player &p);
    };
}

#endif /* Contessa_hpp */