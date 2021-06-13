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
        if (!board.is_neighbors(current_pos, city_name))
        {
            throw "can't drive to unconnected cities";
        }
        move_to_city(city_name);
        return *this;
    }

    Player &Player::fly_direct(City city_name)
    {
        if (hand.count(city_name) != 1)
        {
            throw "can't fly without proper card at hand";
        }
        move_to_city(city_name);
        hand.erase(city_name);
        return *this;
    }

    Player &Player::fly_charter(City city_name)
    {
        if (hand.count(current_pos) != 1)
        {
            throw "can't fly without card in hand";
        }
        auto temp = current_pos;
        move_to_city(city_name);
        hand.erase(temp);
        return *this;
    }

    Player &Player::fly_shuttle(City city_name)
    {
        if (!board.get_research_station(current_pos) || !board.get_research_station(city_name))
        {
            throw "need a research station";
        }
        move_to_city(city_name);
        return *this;
    }

    void Player::move_to_city(City city)
    {
        if (current_pos == city)
        {
            throw "can't move to same city";
        }
        current_pos = city;
    }

    Player &Player::build()
    {
        if (hand.count(this->current_pos) != 1)
        {
            throw "you need the corrosponding card at hand!";
        }
        if (!board.get_research_station(current_pos) && hand.count(current_pos) == 1)
        {
            board.add_research_station(current_pos);
            hand.erase(current_pos);
        }
        return *this;
    }

    Player &Player::discover_cure(Color color_name)
    {
        if (hand.size() < NUM_OF_CARDS_CURE)
        {
            throw "not enough cards at hand";
        }
        if (!board.get_research_station(current_pos))
        {
            throw "you need a research station to discover a cure";
        }
        making_the_cure(color_name, NUM_OF_CARDS_CURE);
        return *this;
    }

    void Player::making_the_cure(Color color_name, int num_of_cards_used)
    {
        std::set<City> cards_to_del;
        for (City city : hand)
        {
            if (board.get_city_color(city) == color_name)
            {
                cards_to_del.insert(city);
            }
        }
        if (cards_to_del.size() >= num_of_cards_used)
        {
            board.cure_disease(color_name);
            int count = num_of_cards_used;
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
        if (board[city_name] == 0)
        {
            throw "can't reduce disease cubes below 0!";
        }
        if (board.get_cured(board.get_city_color(city_name)))
        {
            board[city_name] = 0;
            return;
        }
        board[city_name] -= 1;
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