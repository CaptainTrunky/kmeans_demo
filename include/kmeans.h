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

    void initialize(const Types::Points& ps, const size_t cluster_num);

    // let's follow sklearn naming
    void fit(const Types::Points& ps, const size_t clusters_num, const size_t iters=1000);
    void transform(const Types::Points& ps) const;

    const Types::Points& mu() const {
      return _mu;
    }

    Types::Points& mu() {
      return _mu;
    }

  private:
    Types::Points _mu;

    void _initialize(const Types::Points& ps, const size_t clusters_num);
    Types::Vector _compute_weights(const size_t iter, const Types::Points& ps) const;
};

#endif /* INCLUDE_KMEANS_H_ */
