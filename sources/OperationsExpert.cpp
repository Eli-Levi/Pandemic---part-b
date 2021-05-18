#include "OperationsExpert.hpp"

namespace pandemic
{
    Player &OperationsExpert::build()
    {
        board_copy.research_stations[current_pos] = true;
        return *this;
    }
};