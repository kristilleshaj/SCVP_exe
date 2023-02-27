#include <unistd.h>
#include <systemc.h>

#include "kpn.h"
void kpn :: ADD(){
    while (1)
        b.write(a.read()+c.read());
};
void kpn :: SPLIT(){
    int i=10;
    while(i){
        int b_val=b.read();
        a.write(b_val);
        d.write(b_val);
        std::cout<<"iter "<<std::abs(i-10)<<" e="<<b_val<<std::endl;
        i--;
    }
    sc_stop();
};
void kpn :: DELAY(){
    while (1)
        c.write(d.read());
};
// ADD THINGS HERE
