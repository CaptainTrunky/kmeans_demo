/*
 * geometry.h
 *
 *  Created on: Feb 3, 2018
 *      Author: crady
 */

#ifndef INCLUDE_GEOMETRY_H_
#define INCLUDE_GEOMETRY_H_

#include "types.h"

#include <random>

namespace ublas = boost::numeric::ublas;

namespace Geometry {
  ublas::matrix_row<const Types::Points> pick_random_point(const Types::Points& ps);
  ublas::matrix_row<const Types::Points> get_point(const size_t idx, const Types::Points& ps);

  Types::CoordType distance_between_two_points(const Types::Point& p1, const Types::Point& p2);
  Types::CoordType distance_from_point(const Types::Point& p1, const Types::Points& p);
}

#endif /* INCLUDE_GEOMETRY_H_ */
