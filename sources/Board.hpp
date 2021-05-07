#pragma once
#include <array>
#include <map>
#include "City.hpp"
#include <ostream>
#include <set>
#include "Color.hpp"
#include "City Helper.hpp"

const unsigned int TOTAL_NUM_CITIES = 48;
const unsigned int NUM_OF_DISEASES = 4;

namespace pandemic
{
    class Board
    {
        uint NUM_ON_DISEASE_CUBES;
        map<City, set<City>> neighbors_list;
        map<City, Color> city_color;
        array<bool, NUM_OF_DISEASES> cured;
        map<City, bool> research_stations;
        array<int, TOTAL_NUM_CITIES> disease_cube_num;

        //map<City, City_Helper> the_board;
        void map_setup();

    public:
        Board() : NUM_ON_DISEASE_CUBES(0)
        {
            // black cities
            city_color.insert({City::Algiers, Color::Black});
            neighbors_list.insert({City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo}});
            city_color.insert({City::Baghdad, Color::Black});
            neighbors_list.insert({City::Baghdad, {City::Tehran, City::Riyadh, City::Istanbul, City::Cairo, City::Karachi}});
            city_color.insert({City::Cairo, Color::Black});
            neighbors_list.insert({City::Cairo, {City::Baghdad, City::Riyadh, City::Istanbul, City::Khartoum, City::Algiers}});
            city_color.insert({City::Chennai, Color::Black});
            neighbors_list.insert({City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}});
            city_color.insert({City::Delhi, Color::Black});
            neighbors_list.insert({City::Delhi, {City::Mumbai, City::Tehran, City::Kolkata, City::Karachi, City::Chennai}});
            city_color.insert({City::Istanbul, Color::Black});
            neighbors_list.insert({City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}});
            city_color.insert({City::Karachi, Color::Black});
            neighbors_list.insert({City::Karachi, {City::Tehran, City::Riyadh, City::Delhi, City::Mumbai, City::Baghdad}});
            city_color.insert({City::Kolkata, Color::Black});
            neighbors_list.insert({City::Kolkata, {City::Chennai, City::Bangkok, City::Delhi, City::HongKong}});
            city_color.insert({City::Moscow, Color::Black});
            neighbors_list.insert({City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran}});
            city_color.insert({City::Mumbai, Color::Black});
            neighbors_list.insert({City::Mumbai, {City::Karachi, City::Delhi, City::Chennai}});
            city_color.insert({City::Riyadh, Color::Black});
            neighbors_list.insert({City::Riyadh, {City::Karachi, City::Baghdad, City::Cairo}});
            city_color.insert({City::Tehran, Color::Black});
            neighbors_list.insert({City::Tehran, {City::Karachi, City::Baghdad, City::Moscow, City::Delhi}});

            // blue cities
            city_color.insert({City::Atlanta, Color::Blue});
            neighbors_list.insert({City::Atlanta, {City::Chicago, City::Miami, City::Washington}});
            city_color.insert({City::Chicago, Color::Blue});
            neighbors_list.insert({City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}});
            city_color.insert({City::Essen, Color::Blue});
            neighbors_list.insert({City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg}});
            city_color.insert({City::London, Color::Blue});
            neighbors_list.insert({City::London, {City::NewYork, City::Paris, City::Madrid, City::Essen}});
            city_color.insert({City::Madrid, Color::Blue});
            neighbors_list.insert({City::Madrid, {City::NewYork, City::Paris, City::London, City::SaoPaulo, City::Algiers}});
            city_color.insert({City::Milan, Color::Blue});
            neighbors_list.insert({City::Milan, {City::Essen, City::Paris, City::Istanbul}});
            city_color.insert({City::Montreal, Color::Blue});
            neighbors_list.insert({City::Montreal, {City::Chicago, City::Washington, City::NewYork}});
            city_color.insert({City::NewYork, Color::Blue});
            neighbors_list.insert({City::NewYork, {City::London, City::Washington, City::Montreal, City::Madrid}});
            city_color.insert({City::Paris, Color::Blue});
            neighbors_list.insert({City::Paris, {City::London, City::Essen, City::Algiers, City::Milan, City::Madrid}});
            city_color.insert({City::SanFrancisco, Color::Blue});
            neighbors_list.insert({City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}});
            city_color.insert({City::StPetersburg, Color::Blue});
            neighbors_list.insert({City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow}});
            city_color.insert({City::Washington, Color::Blue});
            neighbors_list.insert({City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami}});

            // red cities
            city_color.insert({City::Bangkok, Color::Red});
            neighbors_list.insert({City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}});
            city_color.insert({City::Beijing, Color::Red});
            neighbors_list.insert({City::Beijing, {City::Shanghai, City::Seoul}});
            city_color.insert({City::HoChiMinhCity, Color::Red});
            neighbors_list.insert({City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila}});
            city_color.insert({City::HongKong, Color::Red});
            neighbors_list.insert({City::HongKong, {City::Kolkata, City::Bangkok, City::HoChiMinhCity, City::Manila, City::Shanghai, City::Taipei}});
            city_color.insert({City::Jakarta, Color::Red});
            neighbors_list.insert({City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}});
            city_color.insert({City::Manila, Color::Red});
            neighbors_list.insert({City::Manila, {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney, City::HongKong}});
            city_color.insert({City::Osaka, Color::Red});
            neighbors_list.insert({City::Osaka, {City::Taipei, City::Tokyo}});
            city_color.insert({City::Seoul, Color::Red});
            neighbors_list.insert({City::Seoul, {City::Beijing, City::Tokyo, City::Shanghai}});
            city_color.insert({City::Shanghai, Color::Red});
            neighbors_list.insert({City::Shanghai, {City::Beijing, City::Tokyo, City::Seoul, City::HongKong, City::Taipei}});
            city_color.insert({City::Sydney, Color::Red});
            neighbors_list.insert({City::Sydney, {City::Manila, City::Jakarta, City::LosAngeles}});
            city_color.insert({City::Taipei, Color::Red});
            neighbors_list.insert({City::Taipei, {City::Manila, City::Shanghai, City::HongKong, City::Osaka}});
            city_color.insert({City::Tokyo, Color::Red});
            neighbors_list.insert({City::Tokyo, {City::Seoul, City::Shanghai, City::SanFrancisco, City::Osaka}});

            //yellow cities
            city_color.insert({City::Bogota, Color::Yellow});
            neighbors_list.insert({City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}});
            city_color.insert({City::BuenosAires, Color::Yellow});
            neighbors_list.insert({City::BuenosAires, {City::Bogota, City::SaoPaulo}});
            city_color.insert({City::Johannesburg, Color::Yellow});
            neighbors_list.insert({City::Johannesburg, {City::Kinshasa, City::Khartoum}});
            city_color.insert({City::Khartoum, Color::Yellow});
            neighbors_list.insert({City::Khartoum, {City::Kinshasa, City::Cairo, City::Lagos, City::Johannesburg}});
            city_color.insert({City::Kinshasa, Color::Yellow});
            neighbors_list.insert({City::Kinshasa, {City::Khartoum, City::Lagos, City::Johannesburg}});
            city_color.insert({City::Lagos, Color::Yellow});
            neighbors_list.insert({City::Lagos, {City::Khartoum, City::Kinshasa, City::SaoPaulo}});
            city_color.insert({City::Lima, Color::Yellow});
            neighbors_list.insert({City::Lima, {City::MexicoCity, City::Bogota, City::Santiago}});
            city_color.insert({City::LosAngeles, Color::Yellow});
            neighbors_list.insert({City::LosAngeles, {City::MexicoCity, City::SanFrancisco, City::Chicago, City::Sydney}});
            city_color.insert({City::MexicoCity, Color::Yellow});
            neighbors_list.insert({City::MexicoCity, {City::LosAngeles, City::Miami, City::Chicago, City::Lima, City::Bogota}});
            city_color.insert({City::Miami, Color::Yellow});
            neighbors_list.insert({City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}});
            city_color.insert({City::Santiago, Color::Yellow});
            neighbors_list.insert({City::Santiago, {City::Lima}});
            city_color.insert({City::SaoPaulo, Color::Yellow});
            neighbors_list.insert({City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}});
            for(int i = 0; i <TOTAL_NUM_CITIES; i++ )
            {
                if(i < NUM_OF_DISEASES)
                {
                    cured[i] = false;
                }
                research_stations[(City)i] = false;
                disease_cube_num[i] = 0;
            }
        };
        int operator[](City city_name) const;
        int &operator[](City city_name);
        friend std::ostream &operator<<(std::ostream &os, const Board &map_state);
        bool is_clean();
        void remove_cures();
        const array<bool, NUM_OF_DISEASES>& get_cured() { return cured; };
        friend class Player;
    };
};