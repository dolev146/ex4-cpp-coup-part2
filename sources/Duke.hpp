#ifndef Duke_hpp
#define Duke_hpp
#include "Player.hpp"

namespace coup
{
    class Duke : public coup::Player
    {
    public:
        bool why_not = true;
        int stuiped_make_tidy = 0;
        Duke(coup::Game &board, std::string name);
        ~Duke();
        void block(Player &);
        void tax();
        std::string role();
    };
}

#endif /* Duke_hpp */
