#include "Player.hpp"

namespace pandemic
{
    class Virologist : public Player
    {
        public:
        Virologist(Board board, City start): Player(board, start, "Virologist"){};
        virtual Player& treat(City city_name) override;
    };
};