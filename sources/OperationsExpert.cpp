#include "OperationsExpert.hpp"

namespace pandemic
{
    Player &OperationsExpert::build()
    {
        board_copy.research_stations.at(current_pos) = true;
        return *this;
    }
};