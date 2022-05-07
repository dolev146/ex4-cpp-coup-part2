#include "Player.hpp"

using namespace std;
namespace coup
{
    class Ambassador : public Player
    {
    private:
    public:
        Ambassador(Game &board, string name);
        void transfer(Player p1, Player p2);
        void role();
        ~Ambassador();
    };

}