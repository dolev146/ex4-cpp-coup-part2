#include "Player.hpp"
// #include "Game.hpp"
using namespace std;
namespace coup
{
    class Duke : public Player
    {
    private:
    public:
        Duke(Game &board, string name);
        void block(Player p);
        void role();
        void tax();
        ~Duke();
    };
}