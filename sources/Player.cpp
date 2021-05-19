#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
#include "Color.hpp"

using namespace std;

const int NUM_OF_CARDS_CURE = 5;

namespace pandemic
{
    Player &Player::drive(City city_name)
    {
        if (city_name == current_pos)
        {
            throw "must move to a new city!";
        }
        if (!board_copy.is_neighbors(current_pos, city_name))
        {
            throw "can't drive to unconnected cities";
        }
        current_pos = city_name;
        return *this;
    }

    Player &Player::fly_direct(City city_name)
    {
        if (hand.count(city_name) != 1)
        {
            throw "can't fly without proper card at hand";
        }
        current_pos = city_name;
        hand.erase(city_name);
        return *this;
    }

    Player &Player::fly_charter(City city_name)
    {
        if (hand.count(current_pos) != 1)
        {
            throw __throw_invalid_argument;
        }
        hand.erase(current_pos);
        current_pos = city_name;
        return *this;
    }

    Player &Player::fly_shuttle(City city_name)
    {
        if (current_pos == city_name)
        {
            throw "cant fly to same city!";
        }
        if (board_copy.get_research_station(current_pos) && board_copy.get_research_station(city_name))
        {
            current_pos = city_name;
            return *this;
        }
        throw "need a research station";
    }

    Player &Player::build()
    {
        if (!board_copy.get_research_station(this->current_pos) && hand.count(this->current_pos) == 1)
        {
            board_copy.research_stations.at(current_pos) = true;
            hand.erase(current_pos);
        }
        else if (hand.count(this->current_pos) != 1)
        {
            throw "you need the corrosponding card at hand!";
        }
        return *this;
    }

    Player &Player::discover_cure(Color color_name)
    {
        if (hand.size() < NUM_OF_CARDS_CURE)
        {
            throw "not enough cards at hand";
        }
        if (!board_copy.get_research_station(current_pos))
        {
            throw "you need a research station to discover a cure";
        }
        making_the_cure(color_name, NUM_OF_CARDS_CURE);
        return *this;
    }

    void Player::making_the_cure(Color color_name, int num_of_cards_used)
    {
        int num_of_color_at_hand = 0;
        std::set<City> cards_to_del;
        for (City city : hand)
        {
            if (board_copy.city_color[city] == color_name)
            {
                ++num_of_color_at_hand;
                cards_to_del.insert(city);
            }
        }
        if (num_of_color_at_hand >= num_of_cards_used)
        {
            board_copy.cured.at((unsigned long)color_name) = true;
            int count = NUM_OF_CARDS_CURE;
            for (auto city : cards_to_del)
            {
                if (count == 0)
                {
                    break;
                }
                hand.erase(city);
                --count;
            }
        }
    }

    Player &Player::treat(City city_name)
    {
        if (current_pos != city_name)
        {
            throw "treat needs to be in your current city!";
        }
        remove_disease_cubes(city_name);
        return *this;
    }

    void Player::remove_disease_cubes(City city_name)
    {
        if (board_copy.disease_cube_num.at((unsigned long)city_name) == 0)
        {
            throw "can't reduce disease cubes below 0!";
        }
        if (board_copy.cured.at((unsigned long)board_copy.city_color[city_name]))
        {
            board_copy.disease_cube_num.at((unsigned long)city_name) = 0;
            return;
        }
        board_copy.disease_cube_num.at((unsigned long)city_name) -= 1;
    }

    std::string Player::role() const
    {
        return this->player_role;
    }

    Player &Player::take_card(City city_name)
    {
        hand.insert(city_name);
        return *this;
    }

    Player &Player::remove_cards()
    {
        this->hand.clear();
        return *this;
    }

}