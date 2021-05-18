#include "Dispatcher.hpp"

namespace pandemic
{
    Player& Dispatcher::fly_direct(City city_name)
    {
        if(board_copy.get_research_station(current_pos))
        {
            current_pos = city_name;
        }
        return *this;
    }
};