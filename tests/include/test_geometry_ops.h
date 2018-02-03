/*
 * test_geometry_ops.h
 *
 *  Created on: Feb 2, 2018
 *      Author: crady
 */

#ifndef TESTS_INCLUDE_TEST_GEOMETRY_OPS_H_
#define TESTS_INCLUDE_TEST_GEOMETRY_OPS_H_

#include <boost/test/unit_test.hpp>

#include <iostream>

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

  expected = 1.732050;

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

  const auto& p1 = Geometry::get_point(0, ps);

  const auto actual = Geometry::distance_from_point(p1, ps);

  const auto expected = 5.196152;

  BOOST_CHECK_CLOSE(actual, expected, 1e-3);
}

#endif /* TESTS_INCLUDE_TEST_GEOMETRY_OPS_H_ */
