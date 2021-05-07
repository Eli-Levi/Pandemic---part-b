#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Color.hpp"

using namespace std;
namespace pandemic
{
    Player& Player::drive(City city_name)
    { 
        
        return *this;
    }
    Player& Player::fly_direct(City city_name) {return *this;};
    Player& Player::fly_charter(City city_name){return *this;};
    Player& Player::fly_shuttle(City city_name){return *this;};
    Player& Player::build(){return *this;};
    Player& Player::discover_cure(Color color_name){return *this;};
    Player& Player::treat(City city_name){return *this;};
    std::string Player::role() const{ return "to be done. dun dun DUN!!!!";} ;
    Player& Player::take_card(City city_name){return *this;};
}