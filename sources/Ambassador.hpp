#ifndef Ambassador_hpp
#define Ambassador_hpp
#include "Player.hpp"
#include "Game.hpp"
#include <string>
#include <stdexcept>
#include <vector>

namespace coup
{
    class Ambassador : public coup::Player
    {
    public:
        Ambassador(Game &, std::string );
        ~Ambassador();
        void block(Player &p);
        std::string role();
        void transfer(Player &, Player &);
    };
};

#endif /* Ambassador_hpp */