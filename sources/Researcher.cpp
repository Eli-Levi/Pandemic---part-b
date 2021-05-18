#include "Researcher.hpp"

const int NUM_OF_CARDS_CURE = 5;

namespace pandemic
{
    Player &Researcher::discover_cure(Color color_name)
    {
        if (hand.size() < NUM_OF_CARDS_CURE)
        {
            throw "not enough cards at hand";
        }
        making_the_cure(color_name);
        return *this;
    }
};