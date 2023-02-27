#ifndef KPN_H
#define KPN_H

#include <systemc.h>

SC_MODULE(kpn)
{
private:
    // ADD THINGS HERE
    sc_fifo<int> a,b,c,d;
public:
    SC_CTOR(kpn) : a(10), b(10), c(10), d(10) // : ADD THINGS HERE
    {
        b.write(1);
        c.write(0);
        SC_THREAD(ADD);
        SC_THREAD(SPLIT);
        SC_THREAD(DELAY);
    }
    void ADD();
    void SPLIT();
    void DELAY();
};

#endif // KPN_H
