#include "Board.hpp"
#include <string>
#include <fstream>
using namespace std;

namespace pandemic
{
    int& Board::operator[](City city_name) { return Board::disease_cube_num[city_name]; }
    ostream &operator<<(ostream &os, const Board &map_state)
    {
        return os;
    }
    bool Board::is_clean(){return false;}
    void remove_cures(){}
    void Board::map_setup()
    {
        ifstream file{"cities_map.txt"};
        while(!file.eof())
        {
            City name;
            Color city_color;
            std::list<City> send_neighbors;

        }
    }
};