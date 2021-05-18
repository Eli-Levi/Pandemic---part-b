#include "Player.hpp"
#include "Board.hpp"


namespace pandemic
{
    class Medic : public Player
    {
        public:

        Medic(Board board, City start): Player(board, start, "Medic"){};

        virtual Player& drive(City city_name) override;

        virtual Player& treat(City city_name) override;
    };
};