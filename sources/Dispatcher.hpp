#include "Player.hpp"
#include "Board.hpp"

namespace pandemic
{
    class Dispatcher : public Player
    {
        public:
        Dispatcher(Board board, City start): Player(board, start,"Dispatcher"){};
        virtual Player& fly_direct(City city_name) override;
    };
};