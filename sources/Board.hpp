#pragma once
#include <array>
#include <map>
#include "City.hpp"
#include <ostream>
#include <set>
#include <algorithm>
#include "Color.hpp"

const unsigned int TOTAL_NUM_CITIES = 48;
const unsigned int NUM_OF_DISEASES = 4;

namespace pandemic
{
    class Board
    {
        void map_setup();

    protected:
        std::map<City, std::set<City>> neighbors_list;
        std::map<City, Color> city_color;
        std::array<bool, NUM_OF_DISEASES> cured;
        //std::map<City, bool> research_stations;
        std::array<bool, TOTAL_NUM_CITIES> research_stations;
        std::array<int, TOTAL_NUM_CITIES> disease_cube_num;

    public:
        Board() { map_setup(); };

        int operator[](City city_name) const;

        int &operator[](City city_name);

        friend std::ostream &operator<<(std::ostream &os, Board &map_state);

        bool is_clean();
        void remove_cures();
        void remove_stations();

        //assisters
        bool is_neighbors(City curr, City move_to);

        bool get_research_station(City name) { 
            return research_stations.at((unsigned long)name); }

        void add_research_station(City city){research_stations.at(city) = true;}

        Color get_city_color(City name) { return city_color[name]; }

        const bool get_cured(Color color) { return cured.at((unsigned long)color); }

        void cure_disease(Color color){ cured.at((unsigned long)color) = true;}
        
    };
};