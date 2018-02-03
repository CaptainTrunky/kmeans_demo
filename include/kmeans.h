/*
 * KMeans.h
 *
 *  Created on: Jan 30, 2018
 *      Author: crady
 */

#ifndef INCLUDE_KMEANS_H_
#define INCLUDE_KMEANS_H_

#include "types.h"

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
};

#endif /* INCLUDE_KMEANS_H_ */
