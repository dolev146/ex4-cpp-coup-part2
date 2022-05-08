#ifndef Duke_hpp
#define Duke_hpp
#include "Player.hpp"
#include <string>

namespace
{
    class Duke : public Player
    {
    public:
        Duke(Game &board, std::string &name);
        ~Duke();
        void block();
        void tax();
        std::string role();
    }
}

#endif /* Duke_hpp */
