#include "Scientist.hpp"
#include <iostream>

namespace pandemic
{
    Player& Scientist::discover_cure(Color color_name)
    {
        if (hand.size() < cure_with_num_cards)
        {
            throw "not enough cards at hand";
        }
        if(!board.get_research_station(current_pos))
        {
            throw "you need a research station to discover a cure";
        }
        making_the_cure(color_name, cure_with_num_cards);
        return *this;
        }
};