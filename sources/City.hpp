#pragma once
#include <string>
namespace pandemic
{
    enum class City
    {
        // blue cities
        SanFrancisco,
        Chicago,
        Montreal,
        Atlanta,
        Washington,
        NewYork,
        Madrid,
        London,
        Paris,
        Essen,
        Milan,
        StPetersburg,
        // yellow cities
        LosAngeles,
        MexicoCity,
        Miami,
        Bogota,
        Lima,
        SaoPaulo,
        BuenosAires,
        Santiago,
        Lagos,
        Khartoum,
        Kinshasa,
        Johannesburg,
        // black cities
        Algiers,
        Cairo,
        Istanbul,
        Moscow,
        Tehran,
        Baghdad,
        Riyadh,
        Karachi,
        Delhi,
        Mumbai,
        Chennai,
        Kolkata,
        // red cities
        Beijing,
        Shanghai,
        Seoul,
        HongKong,
        Taipei,
        Tokyo,
        Osaka,
        Manila,
        Bangkok,
        HoChiMinhCity,
        Jakarta,
        Sydney
    };

    class enum_assistant
    {
        public:
        static std::string enum_to_string(City city)
        {
            switch (city)
            {
            case City::SanFrancisco:
                return "SanFrancisco";
                break;
            case City::Chicago:
                return "Chicago";
                break;
            case City::Montreal:
                return "Montreal";
                break;
            case City::Atlanta:
                return "Atlanta";
                break;
            case City::Washington:
                return "Washington";
                break;
            case City::NewYork:
                return "NewYork";
                break;
            case City::Madrid:
                return "Madrid";
                break;
            case City::London:
                return "London";
                break;
            case City::Paris:
                return "Paris";
                break;
            case City::Essen:
                return "Essen";
                break;
            case City::Milan:
                return "Milan";
                break;
            case City::StPetersburg:
                return "StPetersburg";
                break;
            case City::LosAngeles:
                return "LosAngeles";
                break;
            case City::MexicoCity:
                return "MexicoCity";
                break;
            case City::Miami:
                return "Miami";
                break;
            case City::Bogota:
                return "Bogota";
                break;
            case City::Lima:
                return "Lima";
                break;
            case City::SaoPaulo:
                return "SaoPaulo";
                break;
            case City::BuenosAires:
                return "BuenosAires";
                break;
            case City::Santiago:
                return "Santiago";
                break;
            case City::Lagos:
                return "Lagos";
                break;
            case City::Khartoum:
                return "Khartoum";
                break;
            case City::Kinshasa:
                return "Kinshasa";
                break;
            case City::Johannesburg:
                return "Johannesburg";
                break;
            case City::Algiers:
                return "Algiers";
                break;
            case City::Cairo:
                return "Cairo";
                break;
            case City::Istanbul:
                return "Istanbul";
                break;
            case City::Moscow:
                return "Moscow";
                break;
            case City::Tehran:
                return "Tehran";
                break;
            case City::Baghdad:
                return "Baghdad";
                break;
            case City::Riyadh:
                return "Riyadh";
                break;
            case City::Karachi:
                return "Karachi";
                break;
            case City::Delhi:
                return "Delhi";
                break;
            case City::Mumbai:
                return "Mumbai";
                break;
            case City::Chennai:
                return "Chennai";
                break;
            case City::Kolkata:
                return "Kolkata";
                break;
            case City::Beijing:
                return "Beijing";
                break;
            case City::Shanghai:
                return "Shanghai";
                break;
            case City::Seoul:
                return "Seoul";
                break;
            case City::HongKong:
                return "HongKong";
                break;
            case City::Taipei:
                return "Taipei";
                break;
            case City::Tokyo:
                return "Tokyo";
                break;
            case City::Osaka:
                return "Osaka";
                break;
            case City::Manila:
                return "Manila";
                break;
            case City::Bangkok:
                return "Bangkok";
                break;
            case City::HoChiMinhCity:
                return "HoChiMinhCity";
                break;
            case City::Jakarta:
                return "Jakarta";
                break;
            case City::Sydney:
                return "Sydney";
                break;
            default:
                return "";
                break;
            }
        }
    };
};