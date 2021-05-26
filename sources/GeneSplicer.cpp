#include "GeneSplicer.hpp"

const int NUM_OF_CARDS_CURE = 5;

namespace pandemic
{
    Player &GeneSplicer::discover_cure(Color color_name)
    {
        if (hand.size() < NUM_OF_CARDS_CURE)
        {
            throw "not enough cards at hand";
        }
        if (!board.get_research_station(current_pos))
        {
            throw "you need a research station to discover a cure";
        }
        board.cure_disease(color_name);
        for (unsigned long i = 0; i < NUM_OF_CARDS_CURE; i++)
        {
            hand.erase(*(hand.begin()));
        }
        return *this;
    }
};