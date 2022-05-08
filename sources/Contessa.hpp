#include "Player.hpp"
#include "Game.hpp"
namespace coup
{
    class Contessa : public Player
    {
    private:
    public:
        using Player::Player;

        Contessa(Game &board, string name);
        void block(Player &p);
        string role();
        ~Contessa();
    };

}