#include "Player.hpp"

using namespace std;
namespace coup
{
    class Captain : public Player
    {
    private:
    public:
        Captain(Game &board, string name);
        void block(Player p);
        void steal(Player p);
        void role();
        ~Captain();
    };

}