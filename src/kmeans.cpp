/*
 * KMeans.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: crady
 */

#include "geometry.h"
#include "kmeans.h"

#include <algorithm>

#include <math.h>

#include <boost/numeric/ublas/io.hpp>

void KMeans::fit(const Types::Points& ps, const size_t clusters_num, const size_t iters) {
  for (size_t idx = 0; idx <= iters; ++idx) {
    (void)ps;
    (void) clusters_num;
  }
}

void KMeans::initialize(const Types::Points& ps, const size_t clusters_num) {
  _initialize(ps, clusters_num);
}

void KMeans::_initialize(const Types::Points& ps, const size_t clusters_num) {
  mu().resize(clusters_num, ps.size2());

  Types::Row(mu(), 0) = Geometry::pick_random_point(ps);

  for (size_t c_idx = 1; c_idx < clusters_num; ++c_idx) {
    const auto weights = _compute_weights(c_idx, ps);

    Types::Row(mu(), c_idx) = Geometry::pick_random_point_with_discrete_distr(ps, weights);
  }
}

Types::Vector KMeans::_compute_weights(const size_t iter, const Types::Points& ps) const {
  Types::Matrix d2(ps.size1(), iter);

  const auto ps_norms = std::move(Geometry::compute_norm_along_axis(ps, Geometry::AXIS::ROW));

  for (size_t idx = 0; idx < iter; ++idx) {
    Types::Vector c_norm(ps_norms.size());

    Types::RowConst c(mu(), iter);

    std::fill(
        std::begin(c_norm),
        std::end(c_norm),
        boost::numeric::ublas::norm_2(c)
    );

    Types::Vector diff = ps_norms - c_norm;

    std::transform(
        std::begin(diff),
        std::end(diff),
        std::begin(diff),
        [](const Types::CoordType v) { return std::pow(v,2); }
    );

    Types::Column col(d2, idx);
    col = diff;
  }

  Types::Vector res(d2.size1());

  for(size_t idx = 0; idx < d2.size1(); ++idx) {
    Types::RowConst r(d2, idx);

    res(idx) = *std::min_element(std::begin(r), std::end(r));
  }

  const auto total = boost::numeric::ublas::sum(res);

  std::transform(
      std::begin(res),
      std::end(res),
      std::begin(res),
      [=](const Types::CoordType v) { return v / total; }
  );

  return Types::Column(d2, 0);
}

void KMeans::transform(const Types::Points& ps) const {
  (void)ps;
}


