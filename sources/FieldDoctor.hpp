#include "Player.hpp"
#include "Board.hpp"


namespace pandemic
{
    class FieldDoctor : public Player
    {
        public:
        FieldDoctor(Board& board, City start): Player(board, start, "FieldDoctor"){};

        virtual Player& treat(City city_name) override;
    };
};