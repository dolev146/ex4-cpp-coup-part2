#ifndef Player_hpp
#define Player_hpp
#include <string>

using namespace std;
namespace coup
{
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

    class Game;
    class Player
    {
    public:
        Game *board;
        std::string name;
        Player(Game &, std::string &);
        ~Player();
        Actions call_that_executed_end;
        bool isAlive;
        int how_much_i_have;

        void income();
        void foreign_aid();
        void coup(Player &);

        //**
        virtual void BlockMe();
        virtual std::string role();
        void startTurn(Actions);
        int coins() const;
    };
}

#endif