/*
 * KMeans.h
 *
 *  Created on: Jan 30, 2018
 *      Author: crady
 */

#ifndef INCLUDE_KMEANS_H_
#define INCLUDE_KMEANS_H_

#include "types.h"

//!  A class implements kmeans algorithm.
/*!
  It relies on using kmeans++ initialization. Interface more or less consistent
  with scikit approach. Some functions are parallelized in case of larger datasets:
  more than 1000 elements.
*/

class KMeans {
  public:
    KMeans() = default;
    ~KMeans() = default;

    //! Initializes centroids using kmeans++.
    /*!
      \param [in] ps Training set of N-dimensional points.
      \param [in] cluster_num Number of clusters to identify.
    */
    void initialize(const Types::Points& ps, const size_t cluster_num);

    //! Searches for optimal centroids locations. Calls initialize() at first.
    /*!
      \param [in] ps Training set of N-dimensional points.
      \param [in] cluster_num Number of clusters to identify.
      \param [in] iters Number of steps for training (default = 1000).
    */
    void fit(const Types::Points& ps, const size_t clusters_num, const size_t iters=1000);

    //! Assigns clusters to each of input points.
    /*!
      \param [in] ps A set of N-dimensional points.
    */
    void transform(const Types::Points& ps) const;

    //! Centroids' accessor.
    /*!
      \return A set of centroids.
    */
    const Types::Points& mu() const {
      return mu_;
    }

    //! Centroids' accessor.
    /*!
      \return A set of centroids.
    */
    Types::Points& mu() {
      return mu_;
    }

  private:
    Types::Points mu_;

    Types::Vector compute_weights(const size_t iter, const Types::Points& ps) const;
};

#endif /* INCLUDE_KMEANS_H_ */
