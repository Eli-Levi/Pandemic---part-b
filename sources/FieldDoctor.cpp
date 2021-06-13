#include "FieldDoctor.hpp"
using namespace std;

namespace pandemic
{
   Player& FieldDoctor::treat(City city_name)
   {
      if(board[city_name] == 0)
      {
         string explain = "you cant cure a city that has 0 disease cubes!";
         throw invalid_argument(explain);
      }
      
      if (current_pos != city_name && !board.is_neighbors(current_pos,city_name))
      {
         string explain = "you cant cure a non connected city!";
         throw invalid_argument(explain);
      }

      if(board.get_cured(board.get_city_color(city_name)))
      {
         board[city_name] = 0;
         return *this;
      }
      board[city_name] -= 1;
      return *this;
   }

};