#include "doctest.h"
#include "Test.hpp"

using namespace std;
using namespace pandemic;

TEST_CASE("good input for drive")
{
    Board b;
    Player player(b, City::Atlanta);
    player.drive(City::Washington);
    CHECK_EQ(player.get_pos(), City::Washington);
}

TEST_CASE("bad drive input")
{
    Board b;
    Player player(b, City::Atlanta);
    CHECK_THROWS(player.drive(City::Beijing));
}

TEST_CASE("good input for fly direct")
{
    Board b;
    Player player(b, City::Atlanta);
    player.build();
    player.fly_direct(City::Madrid);
    CHECK_EQ(player.get_pos(), City::Madrid);
    CHECK_EQ(player.get_num_cards(), 3);

    Dispatcher dispatch(b, City::Atlanta);
    dispatch.fly_direct(City::Sydney);
    CHECK_EQ(dispatch.get_pos(), City::Sydney);
    CHECK_EQ(dispatch.get_num_cards(), 4);
}

TEST_CASE("good input for fly charter")
{
    Board b;
    Player player(b, City::Atlanta);
    player.fly_charter(City::Beijing);
    CHECK_EQ(player.get_pos(), City::Beijing);
    CHECK_EQ(player.get_num_cards(), 3);
}

TEST_CASE("good input for fly shuttle")
{
    Board b;
    Player player(b, City::Atlanta);
    Virologist viro(b, City::Essen);
    viro.build();
    player.build();
    player.fly_shuttle(City::Essen);
    CHECK_EQ(player.get_pos(), City::Essen);
    CHECK(!(player.get_pos() == City::Essen));
}

TEST_CASE("good input for build")
{
    Board b;
    Player player(b, City::Atlanta);
    player.build();
    CHECK(player.has_research_station(City::Atlanta));
    CHECK_FALSE(player.has_research_station(City::Paris));
    CHECK_EQ(player.get_pos(), City::Essen);
}

TEST_CASE("good input for discover cure")
{
    Board b;
    Player player(b, City::Atlanta);
    player.take_card(City::Sydney)
        .take_card(City::HoChiMinhCity)
        .take_card(City::HongKong)
        .take_card(City::Bangkok)
        .take_card(City::Minila)
        .take_card(City::Atlanta);
    CHECK_EQ(player.get_num_cards(), 6);
    player.build();
    CHECK_EQ(player.get_num_cards(), 5);
    player.discover_cure(Color::Red);
    CHECK_EQ(player.get_num_cards(), 0);
    player.take_card(City::Sydney)
        .take_card(City::HoChiMinhCity)
        .take_card(City::HongKong)
        .take_card(City::Bangkok)
        .take_card(City::Minila);
    CHECK(player.get_board().get_is_cured().at(size_t(Color::Red)));
    player.discover_cure(Color::Red);
}

TEST_CASE("treat works properly")
{
    Board b;
    CHECK(b.is_clean());
    b[City::Atlanta] = 3;
    CHECK_FALSE(b.is_clean());
    Player player(b, City::Atlanta);
    player.treat(City::Atlanta);
    CHECK_EQ(b[City::Atlanta] , 2);
    
    Medic medic(b,City::Atlanta);
    medic.treat(City::Atlanta);
    CHECK_EQ(b[City::Atlanta] , 0);
}
