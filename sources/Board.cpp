#include "Board.hpp"
#include <string>
#include <fstream>
using namespace std;

namespace pandemic
{
    int &Board::operator[](City city_name)
    {
        return disease_cube_num.at((unsigned long)city_name);
    }

    int Board::operator[](City city_name) const
    {
        return disease_cube_num.at((unsigned long)city_name);
    }

    ostream &operator<<(ostream &os, Board &map_state)
    {
        for (int i = 0; i < TOTAL_NUM_CITIES; i++)
        {
            City city = (City)i;
            os << enum_assistant::enum_to_string(city) << ": has "
               << map_state[city] << "disease cubes ";
            if (map_state.get_research_station(city))
            {
                os << " and has a research station";
            }
            os << endl;
        }
        return os;
    }

    void Board::remove_cures()
    {
        for (unsigned long i = 0; i < NUM_OF_DISEASES; i++)
        {
            this->cured.at(i) = false;
        }
    }

    bool Board::is_neighbors(City curr, City move_to)
    {
        return neighbors_list[curr].find(move_to) != neighbors_list[curr].end();
    }

    bool Board::is_clean()
    {
        for (int city : disease_cube_num)
        {
            if (disease_cube_num.at((unsigned long)city) != 0)
            {
                return false;
            }
        }
        return true;
    }

    void Board::map_setup()
    {
        // black cities
        city_color.insert({City::Algiers, Color::Black});
        neighbors_list.insert({City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo}});
        research_stations.at(City::Algiers) = false;

        city_color.insert({City::Baghdad, Color::Black});
        neighbors_list.insert({City::Baghdad, {City::Tehran, City::Riyadh, City::Istanbul, City::Cairo, City::Karachi}});
        research_stations.at(City::Baghdad) = false;

        city_color.insert({City::Cairo, Color::Black});
        neighbors_list.insert({City::Cairo, {City::Baghdad, City::Riyadh, City::Istanbul, City::Khartoum, City::Algiers}});
        research_stations.at(City::Cairo) = false;

        city_color.insert({City::Chennai, Color::Black});
        neighbors_list.insert({City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}});
        research_stations.at(City::Chennai) = false;

        city_color.insert({City::Delhi, Color::Black});
        neighbors_list.insert({City::Delhi, {City::Mumbai, City::Tehran, City::Kolkata, City::Karachi, City::Chennai}});
        research_stations.at(City::Delhi) = false;

        city_color.insert({City::Istanbul, Color::Black});
        neighbors_list.insert({City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}});
        research_stations.at(City::Istanbul) = false;

        city_color.insert({City::Karachi, Color::Black});
        neighbors_list.insert({City::Karachi, {City::Tehran, City::Riyadh, City::Delhi, City::Mumbai, City::Baghdad}});
        research_stations.at(City::Karachi) = false;

        city_color.insert({City::Kolkata, Color::Black});
        neighbors_list.insert({City::Kolkata, {City::Chennai, City::Bangkok, City::Delhi, City::HongKong}});
        research_stations.at(City::Kolkata) = false;

        city_color.insert({City::Moscow, Color::Black});
        neighbors_list.insert({City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran}});
        research_stations.at(City::Moscow) = false;

        city_color.insert({City::Mumbai, Color::Black});
        neighbors_list.insert({City::Mumbai, {City::Karachi, City::Delhi, City::Chennai}});
        research_stations.at(City::Mumbai) = false;

        city_color.insert({City::Riyadh, Color::Black});
        neighbors_list.insert({City::Riyadh, {City::Karachi, City::Baghdad, City::Cairo}});
        research_stations.at(City::Riyadh) = false;

        city_color.insert({City::Tehran, Color::Black});
        neighbors_list.insert({City::Tehran, {City::Karachi, City::Baghdad, City::Moscow, City::Delhi}});
        research_stations.at(City::Tehran) = false;

        // blue cities
        city_color.insert({City::Atlanta, Color::Blue});
        neighbors_list.insert({City::Atlanta, {City::Chicago, City::Miami, City::Washington}});
        research_stations.at(City::Atlanta) = false;

        city_color.insert({City::Chicago, Color::Blue});
        neighbors_list.insert({City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}});
        research_stations.at(City::Chicago) = false;

        city_color.insert({City::Essen, Color::Blue});
        neighbors_list.insert({City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg}});
        research_stations.at(City::Essen) = false;

        city_color.insert({City::London, Color::Blue});
        neighbors_list.insert({City::London, {City::NewYork, City::Paris, City::Madrid, City::Essen}});
        research_stations.at(City::London) = false;

        city_color.insert({City::Madrid, Color::Blue});
        neighbors_list.insert({City::Madrid, {City::NewYork, City::Paris, City::London, City::SaoPaulo, City::Algiers}});
        research_stations.at(City::Madrid) = false;

        city_color.insert({City::Milan, Color::Blue});
        neighbors_list.insert({City::Milan, {City::Essen, City::Paris, City::Istanbul}});
        research_stations.at(City::Milan) = false;

        city_color.insert({City::Montreal, Color::Blue});
        neighbors_list.insert({City::Montreal, {City::Chicago, City::Washington, City::NewYork}});
        research_stations.at(City::Montreal) = false;

        city_color.insert({City::NewYork, Color::Blue});
        neighbors_list.insert({City::NewYork, {City::London, City::Washington, City::Montreal, City::Madrid}});
        research_stations.at(City::NewYork) = false;

        city_color.insert({City::Paris, Color::Blue});
        neighbors_list.insert({City::Paris, {City::London, City::Essen, City::Algiers, City::Milan, City::Madrid}});
        research_stations.at(City::Paris) = false;

        city_color.insert({City::SanFrancisco, Color::Blue});
        neighbors_list.insert({City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}});
        research_stations.at(City::SanFrancisco) = false;

        city_color.insert({City::StPetersburg, Color::Blue});
        neighbors_list.insert({City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow}});
        research_stations.at(City::StPetersburg) = false;

        city_color.insert({City::Washington, Color::Blue});
        neighbors_list.insert({City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami}});
        research_stations.at(City::Washington) = false;

        // red cities
        city_color.insert({City::Bangkok, Color::Red});
        neighbors_list.insert({City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}});
        research_stations.at(City::Bangkok) = false;

        city_color.insert({City::Beijing, Color::Red});
        neighbors_list.insert({City::Beijing, {City::Shanghai, City::Seoul}});
        research_stations.at(City::Beijing) = false;

        city_color.insert({City::HoChiMinhCity, Color::Red});
        neighbors_list.insert({City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila}});
        research_stations.at(City::HoChiMinhCity) = false;

        city_color.insert({City::HongKong, Color::Red});
        neighbors_list.insert({City::HongKong, {City::Kolkata, City::Bangkok, City::HoChiMinhCity, City::Manila, City::Shanghai, City::Taipei}});
        research_stations.at(City::HongKong) = false;

        city_color.insert({City::Jakarta, Color::Red});
        neighbors_list.insert({City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}});
        research_stations.at(City::Jakarta) = false;

        city_color.insert({City::Manila, Color::Red});
        neighbors_list.insert({City::Manila, {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney, City::HongKong}});
        research_stations.at(City::Manila) = false;

        city_color.insert({City::Osaka, Color::Red});
        neighbors_list.insert({City::Osaka, {City::Taipei, City::Tokyo}});
        research_stations.at(City::Osaka) = false;

        city_color.insert({City::Seoul, Color::Red});
        neighbors_list.insert({City::Seoul, {City::Beijing, City::Tokyo, City::Shanghai}});
        research_stations.at(City::Seoul) = false;

        city_color.insert({City::Shanghai, Color::Red});
        neighbors_list.insert({City::Shanghai, {City::Beijing, City::Tokyo, City::Seoul, City::HongKong, City::Taipei}});
        research_stations.at(City::Shanghai) = false;

        city_color.insert({City::Sydney, Color::Red});
        neighbors_list.insert({City::Sydney, {City::Manila, City::Jakarta, City::LosAngeles}});
        research_stations.at(City::Sydney) = false;

        city_color.insert({City::Taipei, Color::Red});
        neighbors_list.insert({City::Taipei, {City::Manila, City::Shanghai, City::HongKong, City::Osaka}});
        research_stations.at(City::Taipei) = false;

        city_color.insert({City::Tokyo, Color::Red});
        neighbors_list.insert({City::Tokyo, {City::Seoul, City::Shanghai, City::SanFrancisco, City::Osaka}});
        research_stations.at(City::Tokyo) = false;

        //yellow cities
        city_color.insert({City::Bogota, Color::Yellow});
        neighbors_list.insert({City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}});
        research_stations.at(City::Bogota) = false;

        city_color.insert({City::BuenosAires, Color::Yellow});
        neighbors_list.insert({City::BuenosAires, {City::Bogota, City::SaoPaulo}});
        research_stations.at(City::BuenosAires) = false;

        city_color.insert({City::Johannesburg, Color::Yellow});
        neighbors_list.insert({City::Johannesburg, {City::Kinshasa, City::Khartoum}});
        research_stations.at(City::Johannesburg) = false;

        city_color.insert({City::Khartoum, Color::Yellow});
        neighbors_list.insert({City::Khartoum, {City::Kinshasa, City::Cairo, City::Lagos, City::Johannesburg}});
        research_stations.at(City::Khartoum) = false;

        city_color.insert({City::Kinshasa, Color::Yellow});
        neighbors_list.insert({City::Kinshasa, {City::Khartoum, City::Lagos, City::Johannesburg}});
        research_stations.at(City::Kinshasa) = false;

        city_color.insert({City::Lagos, Color::Yellow});
        neighbors_list.insert({City::Lagos, {City::Khartoum, City::Kinshasa, City::SaoPaulo}});
        research_stations.at(City::Lagos) = false;

        city_color.insert({City::Lima, Color::Yellow});
        neighbors_list.insert({City::Lima, {City::MexicoCity, City::Bogota, City::Santiago}});
        research_stations.at(City::Lima) = false;

        city_color.insert({City::LosAngeles, Color::Yellow});
        neighbors_list.insert({City::LosAngeles, {City::MexicoCity, City::SanFrancisco, City::Chicago, City::Sydney}});
        research_stations.at(City::LosAngeles) = false;

        city_color.insert({City::MexicoCity, Color::Yellow});
        neighbors_list.insert({City::MexicoCity, {City::LosAngeles, City::Miami, City::Chicago, City::Lima, City::Bogota}});
        research_stations.at(City::MexicoCity) = false;

        city_color.insert({City::Miami, Color::Yellow});
        neighbors_list.insert({City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}});
        research_stations.at(City::Miami) = false;

        city_color.insert({City::Santiago, Color::Yellow});
        neighbors_list.insert({City::Santiago, {City::Lima}});
        research_stations.at(City::Santiago) = false;

        city_color.insert({City::SaoPaulo, Color::Yellow});
        neighbors_list.insert({City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}});
        research_stations.at(City::SaoPaulo) = false;

        for (unsigned long i = 0; i < TOTAL_NUM_CITIES; i++)
        {
            if (i < NUM_OF_DISEASES)
            {
                cured.at(i) = false;
            }
            disease_cube_num.at(i) = 0;
        }
    }
};