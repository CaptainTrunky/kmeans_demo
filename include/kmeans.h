/*
 * KMeans.h
 *
 *  Created on: Jan 30, 2018
 *      Author: crady
 */

#ifndef INCLUDE_KMEANS_H_
#define INCLUDE_KMEANS_H_

#include "types.h"

namespace ublas = boost::numeric::ublas;

#include <boost/numeric/ublas/io.hpp>

class KMeans {
  public:
    KMeans() = default;
    ~KMeans() = default;

    void initialize(const Types::Points& ps);

    // let's follow sklearn naming
    void fit(const Types::Points& ps, const size_t clusters_num, const size_t iters=1000);
    void transform(const Types::Points& ps) const;

    const Types::Points& centroids() const {
      return _centroids;
    }

    Types::Points& centroids() {
      return _centroids;
    }

  private:
    Types::Points _centroids;

    void _initialize(const Types::Points& ps, const size_t clusters_num, const size_t iters=1000);

  public:
    ublas::matrix_row<Types::Points> _pick_random_point(const Types::Points& ps) const;
    ublas::matrix_row<Types::Points> _get_point(const size_t idx, const Types::Points& ps) const;

    Types::CoordType _distance_between_two_points(const Types::Point& p1, const Types::Point& p2) const;
    Types::CoordType _distance_from_point(const size_t idx, const Types::Points& p) const;
};

#endif /* INCLUDE_KMEANS_H_ */
