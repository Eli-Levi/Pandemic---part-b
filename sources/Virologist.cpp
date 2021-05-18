#include "Virologist.hpp"

namespace pandemic
{
    Player &Virologist::treat(City city_name)
    {
        if(city_name == current_pos)
        {
            Player::treat(city_name);
            return *this;
        }
        if(hand.count(city_name) == 0)
        {
            throw "you need to have the card at hand!";
        }
        Player::remove_disease_cubes(city_name);
        hand.erase(city_name);
        return *this;
    }
};