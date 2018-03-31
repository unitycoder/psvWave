//
// Created by lars on 26/03/18.
//

#ifndef HMC_FORWARD_FD_SHOT_H
#define HMC_FORWARD_FD_SHOT_H


#include <armadillo>
#include "model.h"

class shot {
public:
    // Fields
    arma::irowvec source;
    arma::imat receivers;
    arma::vec sourceFunction;
    arma::mat seismogramSyn_ux;
    arma::mat seismogramSyn_uz;
    double dt;
    int nt;
    int ishot;
    int snapshotInterval;

    arma::cube txxSnapshots;
    arma::cube tzzSnapshots;
    arma::cube txzSnapshots;
    arma::cube vxSnapshots;
    arma::cube vzSnapshots;

    arma::mat seismogramObs_ux;
    arma::mat seismogramObs_uz;

    arma::mat vxAdjointSource;
    arma::mat vzAdjointSource;

    // Constructor
    shot(arma::irowvec _source, arma::imat &_receivers, arma::vec &_sourceFunction, int _nt, double _dt,
         model &_model, int ishot, int _snapshotInterval);

    // Methods
    void writeShot(arma::file_type type);

    void calculateAdjointSources();
};


#endif //HMC_FORWARD_FD_SHOT_H
