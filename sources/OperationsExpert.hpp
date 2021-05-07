#include "Player.hpp"
#include "Board.hpp"


namespace pandemic
{
    class OperationsExpert : public Player
    {
        public:
        OperationsExpert(Board board, City start): Player(board, start){};
        virtual Player& build();
        Player& take_cards(City city_name){return *this;};
    };
};