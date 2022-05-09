#ifndef Player_hpp
#define Player_hpp

#include "Game.hpp"
#include <string>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include <string>

using namespace std;
namespace coup
{
    class Game;
    enum mesimot_to_choose
    {
        nothing,
        income,
        foreign_aid,
        coup,
        Acoup,
        transfer,
        block,
        steal,
        tax
    };

    class Player
    {
    public:
        int stuped_fuck_shit = 0;
        Game *board;
        std::string name;
        Player(Game &, std::string);
        ~Player();
        mesimot_to_choose call_that_executed_end;
        bool isAlive;
        int how_much_i_have;

        void income();
        void foreign_aid();
        void coup(Player &);

        //**
        virtual void function_to_kill_it_player();
        virtual std::string role();
        void startTurn();
        void endTurn(mesimot_to_choose a);
        int coins() const;
    };
}

#endif