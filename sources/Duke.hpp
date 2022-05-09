#ifndef Duke_hpp
#define Duke_hpp
#include "Player.hpp"

namespace coup
{
    class Duke : public coup::Player
    {
    public:
        Duke(coup::Game &board, std::string name);
        ~Duke();
        void block(Player &);
        void tax();
        std::string role();
    };
}



#endif /* Duke_hpp */
