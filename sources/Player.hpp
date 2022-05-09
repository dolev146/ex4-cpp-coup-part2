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
    enum Actions
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
        Game *board;
        std::string name;
        Player(Game &, std::string);
        ~Player();
        Actions call_that_executed_end;
        bool isAlive;
        int how_much_i_have;

        void income();
        void foreign_aid();
        void coup(Player &);

        //**
        virtual void blockme();
        virtual std::string role();
        void startTurn();
        void endTurn(Actions a);
        int coins() const;
    };
}

#endif