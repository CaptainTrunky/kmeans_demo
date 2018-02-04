/*
 * Types.h
 *
 *  Created on: Jan 30, 2018
 *      Author: crady
 */

#ifndef INCLUDE_TYPES_H_
#define INCLUDE_TYPES_H_

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/vector.hpp>

namespace Types {
  using CoordType = double;

  using Vector = boost::numeric::ublas::vector<CoordType>;
  using Point = Vector;

  using Matrix = boost::numeric::ublas::matrix<CoordType>;
  using Points = Matrix;

  using Row = boost::numeric::ublas::matrix_row<Types::Points>;
  using RowConst = boost::numeric::ublas::matrix_row<const Types::Points>;

  using Column = boost::numeric::ublas::matrix_column<Types::Points>;
  using ColumnConst = boost::numeric::ublas::matrix_column<const Types::Points>;
}

#endif /* INCLUDE_TYPES_H_ */
