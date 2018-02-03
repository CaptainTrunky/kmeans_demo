/*
 * KMeans.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: crady
 */
#include <boost/numeric/ublas/matrix_proxy.hpp>

#include "geometry.h"
#include "kmeans.h"

void KMeans::fit(const Types::Points& ps, const size_t clusters_num, const size_t iters) {
  for (size_t idx = 0; idx <= iters; ++idx) {
    (void)ps;
    (void) clusters_num;
  }
}

void KMeans::_initialize(const Types::Points& ps, const size_t clusters_num, const size_t iters) {
  centroids().resize(0, ps.size2());

  (void)iters;

  const auto init = Geometry::pick_random_point(ps);

  while (true) {
    if (centroids().size1() == clusters_num) {
      break;
    }

  }
}

void KMeans::transform(const Types::Points& ps) const {
  (void)ps;
}


