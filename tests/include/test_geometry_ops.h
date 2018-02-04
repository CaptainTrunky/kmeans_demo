/*
 * test_geometry_ops.h
 *
 *  Created on: Feb 2, 2018
 *      Author: crady
 */

#ifndef TESTS_INCLUDE_TEST_GEOMETRY_OPS_H_
#define TESTS_INCLUDE_TEST_GEOMETRY_OPS_H_

#include <boost/numeric/ublas/io.hpp>
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <math.h>

#include "geometry.h"
#include "kmeans.h"
#include "types.h"


BOOST_AUTO_TEST_CASE( test_compute_distance_between_two_points ) {
  Types::Point p1(2);
  p1(0) = 0;
  p1(1) = 0;

  Types::Point p2(2);
  p2(0) = 1;
  p2(1) = 1;

  KMeans kmeans;

  auto actual = Geometry::distance_between_two_points(p1, p2);

  auto expected = 1.414213;

  BOOST_CHECK_CLOSE(actual, expected, 1e-3);

  const bool preserve = false;

  p1.resize(3, preserve);
  p1(0) = 0;
  p1(1) = 0;
  p1(2) = 0;

  p2.resize(3, preserve);

  p2(0) = 1;
  p2(1) = 1;
  p2(2) = 1;

  actual = Geometry::distance_between_two_points(p1, p2);

  expected = std::sqrt(3);

  BOOST_CHECK_CLOSE(actual, expected, 1e-3);
}

BOOST_AUTO_TEST_CASE( test_compute_total_distance_from_point_to_points) {
  Types::Points ps(3, 3);

  ps(0, 0) = 0;
  ps(0, 1) = 0;
  ps(0, 2) = 0;

  ps(1, 0) = 1;
  ps(1, 1) = 1;
  ps(1, 2) = 1;

  ps(2, 0) = 2;
  ps(2, 1) = 2;
  ps(2, 2) = 2;

  const auto& p1 = Geometry::get_point(0, ps);

  const auto actual = Geometry::total_distance_from_point(p1, ps);

  const auto expected = 3 * std::sqrt(3);

  BOOST_CHECK_CLOSE(actual, expected, 1e-3);
}

BOOST_AUTO_TEST_CASE( test_compute_distance_from_point_to_points) {
  Types::Points ps(3, 3);

  ps(0, 0) = 0;
  ps(0, 1) = 0;
  ps(0, 2) = 0;

  ps(1, 0) = 1;
  ps(1, 1) = 1;
  ps(1, 2) = 1;

  ps(2, 0) = 2;
  ps(2, 1) = 2;
  ps(2, 2) = 2;

  const auto& p1 = Geometry::get_point(1, ps);

  const auto actual = std::move(Geometry::compute_distance_to_points(p1, ps));

  BOOST_CHECK_EQUAL(actual.size(), 3);

  BOOST_CHECK_CLOSE(actual(0), std::sqrt(3), 1e-3);
  BOOST_CHECK_CLOSE(actual(1), 0 , 1e-3);
  BOOST_CHECK_CLOSE(actual(2), std::sqrt(3), 1e-3);
}

BOOST_AUTO_TEST_CASE( test_get_random_point_with_distribution) {
  Types::Points ps(2, 3);

  ps(0, 0) = 0;
  ps(0, 1) = 0;
  ps(0, 2) = 0;

  ps(1, 0) = 1;
  ps(1, 1) = 1;
  ps(1, 2) = 1;

  Types::Vector weights(2);

  // roughly 33% and 66%
  weights(0) = std::sqrt(3);
  weights(1) = 2 * std::sqrt(3);

  size_t count1 = 0;
  size_t count2 = 0;

  for (size_t idx = 0; idx < 1000; ++idx) {
    const auto p = Geometry::pick_random_point_with_discrete_distr(ps, weights);

    if (boost::numeric::ublas::norm_2(p - Geometry::get_point(0, ps)) < 1e-3) {
      ++count1;
    } else {
      ++count2;
    }
  }

  // count1 ~ 330, count2 ~660
  BOOST_CHECK_EQUAL(true, count2 - count1 > 200);
}

BOOST_AUTO_TEST_CASE( test_compute_norms_along_axis) {
  Types::Points ps(2, 3);

  ps(0, 0) = 0;
  ps(0, 1) = 0;
  ps(0, 2) = 0;

  ps(1, 0) = 1;
  ps(1, 1) = 1;
  ps(1, 2) = 1;

  auto ps_norms = std::move(Geometry::compute_norm_along_axis(ps, Geometry::AXIS::ROW));

  BOOST_CHECK_CLOSE(ps_norms(0), 0.00000, 1e-3);
  BOOST_CHECK_CLOSE(ps_norms(1), std::sqrt(3), 1e-3);

  ps_norms = std::move(Geometry::compute_norm_along_axis(ps, Geometry::AXIS::COLUMN));

  BOOST_CHECK_CLOSE(ps_norms(0), std::sqrt(1), 1e-3);
  BOOST_CHECK_CLOSE(ps_norms(1), std::sqrt(1), 1e-3);
  BOOST_CHECK_CLOSE(ps_norms(2), std::sqrt(1), 1e-3);
}

#endif /* TESTS_INCLUDE_TEST_GEOMETRY_OPS_H_ */
