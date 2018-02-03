/*
 * geometry.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: crady
 */

#include "geometry.h"
#include <boost/numeric/ublas/io.hpp>

namespace Geometry {
  ublas::matrix_row<const Types::Points> pick_random_point(const Types::Points& ps) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long unsigned> dis(0, ps.size2());

    return get_point(dis(gen), ps);
  }

  ublas::matrix_row<const Types::Points> get_point(const size_t idx, const Types::Points& ps) {
    return ublas::matrix_row<const Types::Points>(ps, idx);
  }

  Types::CoordType distance_between_two_points(const Types::Point& p1, const Types::Point& p2) {
    return boost::numeric::ublas::norm_2(p1 - p2);
  }

  Types::CoordType distance_from_point(const Types::Point& p, const Types::Points& ps) {
    Types::CoordType total_distance = 0;

    for (size_t r = 0; r < ps.size1(); ++r) {
      const Types::Point p1 = get_point(r, ps);

      total_distance += distance_between_two_points(p, p1);
    }

    return total_distance;
  }
}
