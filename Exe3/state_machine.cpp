#include <iostream>

#include "state_machine.h"

void stateMachine::run_fsm(){
    pos++;
    switch (states) {
        case Start:
            if(input.read()=='G'){
                states=G;
            }
            break;
        case G:
            if(input.read()=='A'){
                states=GA;
            }
            else if(input.read()=='C' | input.read()=='T'){
                states=Start;
            }
            break;
        case GA:
            if(input.read()=='A'){
                states=GAA;
            }
            else if(input.read()=='G'){
                states=G;
            }
            else if(input.read()=='C' | input.read()=='T'){
                states=Start;
            }
            break;
        case GAA:
            if(input.read()=='G'){
                states=GAAG;
            }
            else if(input.read()=='A' | input.read()=='C' | input.read()=='T'){
                states=Start;
            }
            break;
        case GAAG:
            count++;
            std::cout<<"Match nr "<< count <<" was found at position "<<(pos-4)<< std::endl;
            if(input.read()=='G'){
                states=G;
            }
            else if(input.read()=='A' | input.read()=='C' | input.read()=='T'){
                states=Start;
            }
            break;
    }
}