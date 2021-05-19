#include "Player.hpp"
#include "Board.hpp"


namespace pandemic
{
    class GeneSplicer : public Player
    {
        public:
        GeneSplicer(Board& board, City start): Player(board, start, "GeneSplicer"){};
        virtual Player& discover_cure(Color color_name) override;
    };
};