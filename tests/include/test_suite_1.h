#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( my_test ) {
  const int z = 4 + 5;
  BOOST_CHECK_EQUAL(z, 9);
}
