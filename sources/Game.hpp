#ifndef Game_hpp
#define Game_hpp
#include "Player.hpp"
#include <vector>
#include <string>

using namespace coup;
using namespace std;

namespace coup
{

    class Game
    {
    public:
        bool gameOver;
        bool gameStarted;
        std::vector<Player *> players_Pointers_array;
        size_t counter;
        std::vector<std::string> players();
        std::string turn();
        std::string winner();
        void AlgoTurnRithm();
        Game();
        ~Game(){};
    };
}

#endif