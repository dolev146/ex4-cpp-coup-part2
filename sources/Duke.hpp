#include "Player.hpp"
// #include "Game.hpp"
using namespace std;
namespace coup
{
    class Duke : public Player
    {
    private:
    public:
        using Player::Player;
        Duke(Game &board, string name);
        void block(Player p);
        string role();
        void tax();
        ~Duke();
    };
}