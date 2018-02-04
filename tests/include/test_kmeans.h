#include <boost/numeric/ublas/io.hpp>

#include <boost/test/unit_test.hpp>

#include "kmeans.h"
#include "types.h"

BOOST_AUTO_TEST_CASE( test_kmeans_initialization ) {
  KMeans kmeans;

  Types::Points ps(8, 2);
  // cluster 1
  ps(0,0) = 0; ps(0,1) = 0;
  ps(1,0) = 1; ps(1,1) = 1;
  ps(2,0) = 0.5; ps(2,1) = 0.5;
  ps(3,0) = -0.5; ps(3,1) = -0.5;

  // cluster 2
  ps(4,0) = 10; ps(4,1) = 10;
  ps(5,0) = 11; ps(5,1) = 11;
  ps(6,0) = 10.5; ps(6,1) = 10.5;
  ps(7,0) = -10.5; ps(7,1) = -10.5;

  kmeans.initialize(ps, 2);

  const auto mu = kmeans.mu();

  BOOST_CHECK_EQUAL(mu.size1(), 2);
  BOOST_CHECK_EQUAL(mu.size2(), 2);

  for(const auto val: mu.data()) {
    BOOST_CHECK_EQUAL(false, std::isnan(val));
  }
}
