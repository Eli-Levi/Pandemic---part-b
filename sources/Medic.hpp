#include "Player.hpp"
#include "Board.hpp"


namespace pandemic
{
    class Medic : public Player
    {
        void treat_by_move();

        public:

        Medic(Board& board, City start): Player(board, start, "Medic"){};

        virtual Player& drive(City city_name) override;

        virtual Player& treat(City city_name) override;

        virtual Player &fly_direct(City city_name) override;

        virtual Player& fly_charter(City city_name) override;
        
        virtual Player& fly_shuttle(City city_name) override;
    };
};