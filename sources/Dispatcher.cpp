#include "Dispatcher.hpp"

namespace pandemic
{
    Player &Dispatcher::fly_direct(City city_name)
    {
        if (!board.get_research_station(current_pos))
        {
            Player::fly_direct(city_name);
        }
        else
        {
            move_to_city(city_name);
        }
        return *this;
    }
};