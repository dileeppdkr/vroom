#ifndef SOLOMON_H
#define SOLOMON_H

/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "structures/vroom/input/input.h"
#include "structures/vroom/tw_route.h"

using tw_solution = std::vector<tw_route>;

// Initialization types.
enum class INIT_T { NONE, HIGHER_AMOUNT, EARLIEST_DEADLINE, FURTHEST };

// Implementation of a variant of the Solomon I1 heuristic.
tw_solution basic_heuristic(const input& input, INIT_T init, float lambda);

// Adjusting the above for situation with heterogeneous fleet.
tw_solution dynamic_vehicle_choice_heuristic(const input& input,
                                             INIT_T init,
                                             float lambda);

// Re-build single route using initial state. Jobs are inserted based
// on time windows length or deadline.
tw_route single_route_heuristic(const input& input,
                                const tw_route& init_tw_r,
                                bool tw_length);

#endif
