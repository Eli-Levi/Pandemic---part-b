#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        int cure_with_num_cards;
        public:
        Scientist(Board board, City start, int cure_with_n_cards): Player(board, start), cure_with_num_cards(cure_with_n_cards){};
        Player& discover_cure(Color color_name);
    };
};