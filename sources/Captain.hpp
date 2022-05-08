#include "Player.hpp"

using namespace std;
namespace coup
{
    class Captain : public Player
    {
    private:
    public:
        Player *stolenPlayer;
        bool stealSuccess;
        Captain(Game &board, string name);
        void block(Player &p);
        void steal(Player &p);
        string role();
        ~Captain();
    };

}