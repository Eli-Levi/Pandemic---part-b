#include "Color.hpp"
#include <list>

class City_Helper
{
    protected:
    pandemic::City city;
    pandemic::Color city_color;
    unsigned int num_of_disease_cubes;
    std::list<pandemic::City> neighbors;
    bool has_research_station;
    friend class Board;
    City_Helper(pandemic::City city_name, pandemic::Color color, list<pandemic::City> list, int disease_cube_num = 0): city(city_name), city_color(color), num_of_disease_cubes(disease_cube_num), neighbors(list), has_research_station(false){};
};