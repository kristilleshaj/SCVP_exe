#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
// TODO
SC_MODULE(subnet){
    transition<1,1,1> ACT;
    transition<1,1,0> RD;
    transition<1,1,0> PRE;
    transition<1,1,0> WR;
    place<3,3> ACTIVE=0;
public:
    SC_CTOR(subnet) : ACT("ACT"),RD("RD"),WR("WR"),PRE("PRE") {
        ACT.out.bind(ACTIVE);
        ACT.inhibitors.bind(ACTIVE);
        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);
        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);
        PRE.in.bind(ACTIVE);
    }
};
#endif // SUBNET_H