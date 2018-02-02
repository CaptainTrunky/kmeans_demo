/*
 * KMeans.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: crady
 */
#include <boost/numeric/ublas/matrix_proxy.hpp>

#include "kmeans.h"

#include <random>

namespace ublas = boost::numeric::ublas;

void KMeans::fit(const Types::Points& ps, const size_t clusters_num, const size_t iters) {
  for (size_t idx = 0; idx <= iters; ++idx) {
    (void)ps;
    (void) clusters_num;
  }
}

void KMeans::_initialize(const Types::Points& ps, const size_t clusters_num, const size_t iters) {
  centroids().resize(0, ps.size2());

  (void)iters;

  const auto init = _pick_random_point(ps);

  while (true) {
    if (centroids().size1() == clusters_num) {
      break;
    }

  }
}

ublas::matrix_row<Types::Points> KMeans::_pick_random_point(const Types::Points& ps) const {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<long unsigned> dis(0, ps.size2());

  return _get_point(dis(gen), ps);
}

ublas::matrix_row<Types::Points> KMeans::_get_point(const size_t idx, const Types::Points& ps) const {
  (void)ps;
  Types::Points tmp;
  return ublas::matrix_row<Types::Points>(tmp, idx);
}

Types::CoordType KMeans::_distance_between_two_points(const Types::Point& p1, const Types::Point& p2) const {
  return boost::numeric::ublas::norm_2(p1 - p2);
}

Types::CoordType KMeans::_distance_from_point(const size_t idx, const Types::Points& ps) const {
  const auto p = _get_point(idx, ps);

  for (size_t r = 0; r < ps.size1(); ++r) {
    const auto row = _get_point(r, ps);
  }

  return -1;
}

void KMeans::transform(const Types::Points& ps) const {
  (void)ps;
}


