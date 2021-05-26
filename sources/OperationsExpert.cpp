#include "OperationsExpert.hpp"

namespace pandemic
{
    Player &OperationsExpert::build()
    {
        board.add_research_station(current_pos);
        return *this;
    }
};