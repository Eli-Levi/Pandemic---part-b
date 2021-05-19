#include "Dispatcher.hpp"

namespace pandemic
{
    Player& Dispatcher::fly_direct(City city_name)
    {
        if (current_pos == city_name)
        {
            throw " can't fly to same city";
        }
        
        if(board_copy.get_research_station(current_pos))
        {
            current_pos = city_name;
            return *this;
        }
        return Player::fly_direct(city_name);

    }
};