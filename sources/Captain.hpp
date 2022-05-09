#ifndef Captian_hpp
#define Captian_hpp
#include "Player.hpp"

namespace coup{
    class Captain : public coup::Player
    {
        public:
            Captain(coup::Game &board, std::string name);
            ~Captain();
            void block(Player &p);
            std::string role();
            void blockMe();
            void steal(Player &p);
            Player *me_she_ani_rotze_laarog;
            int ma_she_ganavti;
    };
}




#endif /* Captian_hpp */