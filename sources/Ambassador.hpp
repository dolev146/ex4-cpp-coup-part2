#ifndef Ambassador_hpp
#define Ambassador_hpp
#include "Player.hpp"

namespace coup
{
    class Ambassador : public coup::Player
    {
    public:
        Ambassador(coup::Game &board, std::string &name);
        ~Ambassador();
        void block(Player &p);
        std::string role();
        void transfer(Player &, Player &);
    };
};

#endif /* Ambassador_hpp */