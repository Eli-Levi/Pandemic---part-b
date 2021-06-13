#include "GeneSplicer.hpp"
using namespace std;

const int NUM_OF_CARDS_CURE = 5;

namespace pandemic
{
    Player &GeneSplicer::discover_cure(Color color_name)
    {
        if (hand.size() < NUM_OF_CARDS_CURE)
        {
            string explain = "not enough cards at hand";
            throw invalid_argument(explain);
        }
        if (!board.get_research_station(current_pos))
        {
            string explain = "Need a research station at current city!";
            throw invalid_argument(explain);
        }
        board.cure_disease(color_name);
        set<City> discard ;
        auto it = hand.begin();
        for (int i = 0; i < NUM_OF_CARDS_CURE; ++i) {
            discard.insert(discard.end(),(*it));
            it++;
        }
        for (auto c: discard)
        {
            hand.erase(c);
        }
        return *this;
    }
};