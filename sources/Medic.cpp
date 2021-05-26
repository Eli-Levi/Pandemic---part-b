#include "Medic.hpp"

namespace pandemic
{

   void Medic::treat_by_move()
   {
      if (board.get_cured(board.get_city_color(current_pos)))
      {
         board[current_pos] = 0;
      }
   }
   Player &Medic::treat(City city_name)
   {
      Player::treat(city_name);
      board[current_pos] = 0;
      return *this;
   }

   Player &Medic::drive(City city_name)
   {
      Player::drive(city_name);
      treat_by_move();
      return *this;
   }

   Player &Medic::fly_direct(City city_name)
   {
      Player::fly_direct(city_name);
      treat_by_move();
      return *this;
   }

   Player &Medic::fly_charter(City city_name)
   {
      Player::fly_charter(city_name);
      treat_by_move();
      return *this;
   }

   Player &Medic::fly_shuttle(City city_name)
   {
      Player::fly_shuttle(city_name);
      treat_by_move();
      return *this;
   }
};