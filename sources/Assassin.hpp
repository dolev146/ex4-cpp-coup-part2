#include "Player.hpp"
using namespace std;
namespace coup
{
    class Assassin : public Player
    {
    private:
    public:
        Assassin(Game &board, string name);
        void block(Player p);
        void role();
        ~Assassin();
    };
}