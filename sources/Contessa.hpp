#include "Player.hpp"
namespace coup
{
    class Contessa : public Player
    {
    private:
    public:
        Contessa(Game &board, string name);
        void block(Player p);
        void role();
        ~Contessa();
    };

}