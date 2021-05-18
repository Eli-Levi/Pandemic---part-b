#include "Scientist.hpp"

namespace pandemic
{
    Player& Scientist::discover_cure(Color color_name)
    {
        if (hand.size() < cure_with_num_cards)
        {
            throw "not enough cards at hand";
        }
        if(!board_copy.get_research_station(current_pos))
        {
            throw "you need a research station to discover a cure";
        }
        int num_of_color_at_hand = 0;
        std::set<City> cards_to_del;
        unsigned long index = 0;
        for (City city : hand)
        {
            if (board_copy.city_color[city] == color_name)
            {
                ++num_of_color_at_hand;
                cards_to_del.insert(city);
                ++index;
            }
        }
        if (num_of_color_at_hand >= cure_with_num_cards)
        {
            board_copy.cured.at((unsigned long)color_name) = true;
            std::set<City>::iterator curr = cards_to_del.begin();
            while(curr != cards_to_del.end())
            {
                hand.erase(*curr);
            }
        }
        return *this;
        }
};