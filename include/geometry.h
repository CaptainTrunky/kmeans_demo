/*
 * geometry.h
 *
 *  Created on: Feb 3, 2018
 *      Author: crady
 */

#ifndef INCLUDE_GEOMETRY_H_
#define INCLUDE_GEOMETRY_H_

#include "types.h"

#include <random>

namespace ublas = boost::numeric::ublas;

namespace Geometry {
  //! Introduces directions for 2D matrices
  enum AXIS {
    ROW = 0,
    COLUMN = 1,
    AXIS_NUM = 2
  };

  //! Returns a random point represented by a row from a matrix.
  /*!
    \param [in] ps A set of points.
    \return A point.
  */
  Types::RowConst pick_random_point(const Types::Points& ps);

  //! Returns a random point represented by a row from a matrix.
  /*!
    \param [in] ps A set of points.
    \param [in] weights Defines probabilities distribution for picking a point.
    \return A point.
  */
  Types::RowConst pick_random_point_with_discrete_distr(const Types::Points& ps, const Types::Vector& weights);

  //! Gets a point from a matrix
  /*!
    \param [in] idx A point's index.
    \param [in] ps A set of points
    \return A point.
  */
  Types::RowConst get_point(const size_t idx, const Types::Points& ps);

  //! Computes L2-norm along specified axis.
  /*!
    \param [in] m An input matrix.
    \param [in] axis Axis for computing norm (default = AXIS::ROW).
    \return A vector of norms.
  */
  Types::Vector compute_norm_along_axis(const Types::Matrix& m, const AXIS axis = AXIS::ROW);

  //! Computes Euclidian distance between two points.
  /*!
    \param [in] p1 First point.
    \param [in] p2 Second point.
    \return Distance between two points of type CoordType.
  */
  Types::CoordType distance_between_two_points(const Types::Point& p1, const Types::Point& p2);

  //! Computes Euclidian distance between single point and set of points.
  /*!
    \param [in] p1 A point.
    \param [in] ps A set of points.
    \return A vector of distances.
  */
  Types::Vector compute_distance_to_points(const Types::Point& p, const Types::Points& ps);

  //! Computes total Euclidian distance between single point and set of points.
  /*!
    \param [in] p1 A point.
    \param [in] ps A set of points.
    \return Total distance.
  */
  Types::CoordType total_distance_from_point(const Types::Point& p, const Types::Points& ps);
}

#endif /* INCLUDE_GEOMETRY_H_ */
