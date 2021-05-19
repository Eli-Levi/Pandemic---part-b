#include "FieldDoctor.hpp"

namespace pandemic
{
   Player& FieldDoctor::treat(City city_name)
   {
      if(board_copy.disease_cube_num.at(city_name) == 0)
      {
         throw "you cant cure a city that has 0 disease cubes!";
      }
      if (current_pos != city_name && !board_copy.is_neighbors(this->current_pos,city_name))
      {
         throw "you cant cure a non connected city!";
      }

      if(board_copy.get_cured().at((unsigned long)board_copy.get_city_color(city_name)))
      {
         board_copy.disease_cube_num.at((unsigned long)city_name) = 0;
         return *this;
      }
      board_copy.disease_cube_num.at((unsigned long)city_name) -= 1;
      return *this;
   }

};