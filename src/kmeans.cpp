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

  }
}

void KMeans::_initialize(const Types::Points& ps, const size_t clusters_num, const size_t iters=1000) {
  centroids().resize(0, ps.columns());

  while (true) {
    if (centroids().rows() == clusters_num) {
      break;
    }

  }
}

ublas::matrix_row<ublas::matrix<double>> KMeans::_pick_random_point(const Types::Points& ps) const {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, ps.columns());

  return ublas::matrix_row<ublas::matrix<double>>(ps, dis(gen));
}

void KMeans::transform(const Types::Points& ps) const {

}


