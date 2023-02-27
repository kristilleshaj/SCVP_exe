#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
// TODO
template<unsigned int N = 1, unsigned int M = 1, unsigned int L=0>
SC_MODULE(transition){
    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;
public:
    SC_CTOR(transition){};

    void fire(){
    /*    if(in->testTokens()>0){
            std::cout << this->name() << ": Fired" << std::endl;
            in->removeTokens(1);
            out->addTokens(1);
        }
        else{
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }*/
        bool has_token=0;
        for(int i=0; i<N; i++){
            if(in[i]->testTokens()==0) {
                has_token=1;
            }
        }
        for(int i=0; i<L; i++){
            if(inhibitors[i]->testTokens()!=0) {
                has_token=1;
            }
        }
        if(has_token){
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }
        else{
            std::cout << this->name() << ": Fired" << std::endl;
            for(int i=0; i<N; i++){
                in[i]->removeTokens();
            }
            for(int i=0; i<M; i++){
                out[i]->addTokens();
            }
        }
    }
};

#endif // TRANSITION_H
