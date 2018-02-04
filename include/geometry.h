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
  enum AXIS {
    ROW = 0,
    COLUMN = 1,
    AXIS_NUM = 2
  };

  Types::RowConst pick_random_point(const Types::Points& ps);
  Types::RowConst pick_random_point_with_discrete_distr(const Types::Points& ps, const Types::Vector& weights);

  Types::RowConst get_point(const size_t idx, const Types::Points& ps);

  // 0 - rows, 1 - columns
  Types::Vector compute_norm_along_axis(const Types::Matrix& m, const AXIS axis = AXIS::ROW);

  Types::CoordType distance_between_two_points(const Types::Point& p1, const Types::Point& p2);
  Types::Vector compute_distance_to_points(const Types::Point& p, const Types::Points& ps);
  Types::CoordType total_distance_from_point(const Types::Point& p, const Types::Points& ps);
}

#endif /* INCLUDE_GEOMETRY_H_ */
