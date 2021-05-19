#include "Medic.hpp"

namespace pandemic
{
   Player &Medic::treat(City city_name)
   {
      Player::treat(city_name);
      board_copy.disease_cube_num.at((unsigned long)city_name) = 0;
      return *this;
   }

   Player &Medic::drive(City city_name)
   {
      Player::drive(city_name);
      if (board_copy.get_cured().at((unsigned long)board_copy.get_city_color(current_pos)))
      {
         board_copy.disease_cube_num.at((unsigned long)city_name) = 0;
      }
      return *this;
   }

   Player &Medic::fly_direct(City city_name)
   {
      Player::fly_direct(city_name);
      if (board_copy.get_cured().at((unsigned long)board_copy.get_city_color(current_pos)))
      {
         board_copy.disease_cube_num.at((unsigned long)city_name) = 0;
      }
      return *this;
   }

   Player& Medic::fly_charter(City city_name)
   {
      Player::fly_charter(city_name);
      if (board_copy.get_cured().at((unsigned long)board_copy.get_city_color(current_pos)))
      {
         board_copy.disease_cube_num.at((unsigned long)city_name) = 0;
      }
      return *this;
   }

   Player& Medic::fly_shuttle(City city_name)
   {
      Player::fly_shuttle(city_name);
      if (board_copy.get_cured().at((unsigned long)board_copy.get_city_color(current_pos)))
      {
         board_copy.disease_cube_num.at((unsigned long)city_name) = 0;
      }
      return *this;
   }
};