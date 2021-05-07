#include "Player.hpp"
#include "Board.hpp"


namespace pandemic
{
    class Medic : public Player
    {
        public:
        Medic(Board board, City start): Player(board, start){};
        virtual Player& treat(City city_name);
    };
};