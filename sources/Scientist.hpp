#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        int cure_with_num_cards;
        
        public:
        Scientist(Board& board, City start, int cure_with_n_cards = 4): Player(board, start, "Scientist"), cure_with_num_cards(cure_with_n_cards){};

        virtual Player& discover_cure(Color color_name) override;
    };
};