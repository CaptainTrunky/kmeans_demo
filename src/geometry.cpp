/*
 * geometry.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: crady
 */

#include "geometry.h"

#include <exception>

#include <boost/numeric/ublas/io.hpp>

namespace Geometry {
  Types::RowConst pick_random_point(const Types::Points& ps) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long unsigned> dis(0, ps.size2());

    return get_point(dis(gen), ps);
  }

  Types::RowConst pick_random_point_with_discrete_distr(const Types::Points& ps, const Types::Vector& weights) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<long unsigned int> distr(weights.begin(), weights.end());

    return Types::RowConst(ps, distr(gen));
  }

  Types::RowConst get_point(const size_t idx, const Types::Points& ps) {
    return ublas::matrix_row<const Types::Points>(ps, idx);
  }

  Types::Vector compute_norm_along_axis(const Types::Matrix& m, AXIS axis) {
    Types::Vector res;
    if (axis == AXIS::ROW) {
      res.resize(m.size1());

      for (size_t i = 0; i < m.size1(); ++i) {
        Types::RowConst r(m, i);

        res(i) = boost::numeric::ublas::norm_2(r);
      }
    } else if (axis == AXIS::COLUMN) {
      res.resize(m.size2());

      for (size_t i = 0; i < m.size2(); ++i) {
        Types::ColumnConst c(m, i);

        res(i) = boost::numeric::ublas::norm_2(c);
      }
    } else {
      throw std::runtime_error("Unknown axis type");
    }

    return res;
  }

  Types::CoordType distance_between_two_points(const Types::Point& p1, const Types::Point& p2) {
    return boost::numeric::ublas::norm_2(p1 - p2);
  }

  Types::Vector compute_distance_to_points(const Types::Point& p, const Types::Points& ps) {
    Types::Vector res(ps.size1());

    for (size_t r = 0; r < ps.size1(); ++r) {
      const Types::Point p1 = get_point(r, ps);

      res(r) = distance_between_two_points(p, p1);
    }

    return res;
  }

  // FIXME: could be implemented with compute_distance_to_points. check additional memory allocation vs raw looping over elements
  Types::CoordType total_distance_from_point(const Types::Point& p, const Types::Points& ps) {
    Types::CoordType total_distance = 0;

    for (size_t r = 0; r < ps.size1(); ++r) {
      const Types::Point p1 = get_point(r, ps);

      total_distance += distance_between_two_points(p, p1);
    }

    return total_distance;
  }
}
