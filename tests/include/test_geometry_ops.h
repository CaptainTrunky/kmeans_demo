/*
 * test_geometry_ops.h
 *
 *  Created on: Feb 2, 2018
 *      Author: crady
 */

#ifndef TESTS_INCLUDE_TEST_GEOMETRY_OPS_H_
#define TESTS_INCLUDE_TEST_GEOMETRY_OPS_H_

#include <boost/test/unit_test.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <iostream>

#include "types.h"
#include "kmeans.h"

BOOST_AUTO_TEST_CASE( test_compute_distance_between_two_points ) {
  Types::Point p1(2);
  p1(0) = 0;
  p1(1) = 0;

  Types::Point p2(2);
  p2(0) = 1;
  p2(1) = 1;

  KMeans kmeans;

  const auto actual = kmeans._distance_between_two_points(p1, p2);

  const auto expected = 1.4142;

  BOOST_CHECK_CLOSE(actual, expected, 1e-3);
}

#endif /* TESTS_INCLUDE_TEST_GEOMETRY_OPS_H_ */
