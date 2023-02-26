#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>

SC_MODULE(stateMachine){
    sc_in<char> input;
    sc_in<bool> clk;
    enum base {Start, G, GA, GAA, GAAG};
    base states;
    unsigned int count;
    unsigned int pos;
    SC_CTOR(stateMachine) : input("input"), clk("clk"), states(Start), count(0), pos(0){
        SC_METHOD(run_fsm);
        sensitive<<clk;
        dont_initialize();
    }
    void run_fsm();
};

#endif // STATE_MACHINE_H


