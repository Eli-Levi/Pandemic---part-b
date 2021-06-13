#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <string>
#include <vector>
#include "Board.hpp"

namespace pandemic
{
    class Player
    {
        protected:
        Board& board;

        City& current_pos;

        std::string player_role;

        std::set<City> hand;
        
        void making_the_cure(Color color_name, int num_of_cards_used);

        void remove_disease_cubes(City city_name);

        void move_to_city(City city);

    public:
        Player(Board& board, City city_start = City::Atlanta, std::string role = "Player"): board(board), current_pos(city_start), player_role(role){};

        virtual Player& drive(City city_name);

        virtual Player &fly_direct(City city_name);

        virtual Player& fly_charter(City city_name);

        virtual Player& fly_shuttle(City city_name);

        virtual Player& build();

        virtual Player& discover_cure(Color color_name);

        virtual Player& treat(City city_name);


        std::string role() const;

        Player& take_card(City city_name);

        City& get_pos(){ return current_pos;};

        Board& get_board(){return board;};

        virtual Player& remove_cards();
    };
};