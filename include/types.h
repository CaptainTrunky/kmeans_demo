/*
 * Types.h
 *
 *  Created on: Jan 30, 2018
 *      Author: crady
 */

#ifndef INCLUDE_TYPES_H_
#define INCLUDE_TYPES_H_

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

namespace Types {
  using CoordType = double;

  using Point = boost::numeric::ublas::vector<CoordType>;
  using Points = boost::numeric::ublas::matrix<CoordType>;
}

#endif /* INCLUDE_TYPES_H_ */
