
#include "Player.hpp"

using namespace std;
namespace coup
{
    class Ambassador : public coup::Player
    {
    public:
        Ambassador(Game &board, std::string name);
        void block(Player &p);
        std::string role();
        void transfer(Player &, Player &);
        ~Ambassador();
    };
}

