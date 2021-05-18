#include "FieldDoctor.hpp"

namespace pandemic
{
   Player& FieldDoctor::treat(City city_name)
   {
      if (current_pos != city_name && !board_copy.is_neighbors(this->current_pos,city_name))
      {
         throw std::__throw_invalid_argument;
      }

      if(board_copy.get_cured().at((unsigned long long)board_copy.get_city_color(city_name)))
      {
         board_copy.disease_cube_num.at((unsigned long)city_name) = 0;
      }
      board_copy.disease_cube_num.at((unsigned long)city_name) -= 1;
      return *this;
   }

};