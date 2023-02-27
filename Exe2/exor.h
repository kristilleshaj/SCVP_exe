#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

SC_MODULE(exor) {

    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;

    nand nand_a, nand_b, nand_c, nand_d;

    sc_signal<bool> h1, h2, h3;

    SC_CTOR(exor) : A("A"), B("B"), Z("Z"), nand_a("nand_a"), nand_b("nand_b"), nand_c("nand_c"), nand_d("nand_d") {

        sensitive << A << B;
        nand_a.A.bind(A);
        nand_a.B.bind(B);
        nand_a.Z.bind(h1);
        nand_b.A.bind(A);
        nand_b.B.bind(h1);
        nand_b.Z.bind(h2);
        nand_c.A.bind(B);
        nand_c.B.bind(h1);
        nand_c.Z.bind(h3);
        nand_d.A.bind(h2);
        nand_d.B.bind(h3);
        nand_d.Z.bind(Z);

    }
};

#endif // EXOR_H
