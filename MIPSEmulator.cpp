/*
// mandatory:
l.d   f2,4(r1)                            // test program to be
l.d   f4,8(r3)                            // simulated;
mul.d f6,f2,f4                            // straight-line code;
add.d f8,f4,f6                            // no pipelining
s.d   f6,8(r3)
s.d   f8,4(r5)

*/

#include <iostream>  // for std::cout

int main () {
    // all submissions _must_ contain this prelude or equivalent

    int Reg[10];                              // register file
    Reg[1] = 100; Reg[3] = 200; Reg[5] = 300; // r-register values

    int  Mem[400];                            // main memory
    char XMem[] = "llmass";                   // six opcodes in XMem
    Mem[0] = 124; Mem[1] = 348; Mem[2] = 246; // six argument lists
    Mem[3] = 468; Mem[4] = 368; Mem[5] = 584; // in main memory
    Mem[104] = 17; Mem[208] = 41;             // memory data values

    // loop over instructions
    for(int PC = 0; PC < 6; PC++) {         // fetch-execute cycle

        // f-box
        char head = XMem[PC];
        int  tail = Mem[PC];
        std::cout << "f: Fetched " << head << "#" << tail << ".\n";

        // d-box
        char opc = head;                        // decompose instruction
        std::cout << "d: Set opc to '" << opc << "'.\n";
        int arg3 = tail % 10;                   // into its opcode and
        tail = tail / 10;                       // its three arguments
        int arg2 = tail % 10;                   // inst = {opc,arg1,...}
        tail = tail / 10;
        int arg1 = tail;

        // all code or equivalent above this line is mandatory

        int D_Out1 = Reg[arg1];                 // You may imitate this style.
        std::cout << "d: Set D_Out1 to " << D_Out1 << ".\n";
        int D_Out2, dest, value_to_store;
        switch( opc ){
            case 'a':
            case 'm':
                D_Out2 = Reg[arg2];
                std::cout << "d: Set D_Out2 to " << D_Out2 << ".\n";
                dest = arg3;
                std::cout << "d: Set dest to f" << dest << ".\n";
                break;
            case 'l':
                // find D_Out2 and dest
                D_Out2 = arg3;
                std::cout << "d: Set D_Out2 to " << D_Out2 << ".\n";
                dest = arg2;
                std::cout << "d: Set dest to f" << dest << ".\n";
                break;
            case 's':
                // find D_Out2 and dest
                D_Out2 = arg3;
                std::cout << "d: Set D_Out2 to " << D_Out2 << ".\n";
                std::cout << "d: Did not set dest.\n";
                break;
        }

        // x-box
        int X_Out;
        switch( opc ) {
            case 'a':
            case 'l':
            case 's':
                X_Out = D_Out1 + D_Out2;
                std::cout << "x: Set X_Out to " << X_Out << ".\n";
                break;
            case 'm':
                X_Out = D_Out1 * D_Out2;
                std::cout << "x: Set X_Out to " << X_Out << ".\n";
                break;
        }

        // m-box
        int M_Out;
        switch( opc ) {
            case 'a':
            case 'm':
                std::cout << "m: M-box does no-op. \n";
                break;
            case 'l':
                M_Out = Mem[X_Out];
                std::cout << "m: Set M_Out to " << M_Out << ".\n";
                break;
            case 's':
                //M_Out = value to store; this is what im confuzzled abt
                //aaaaaa
                //aaaaaa
                M_Out = Reg[arg2];
                value_to_store = M_Out;
                // or just value_to_store = Reg[arg2];
                std::cout << "m: Set value_to_store to " << value_to_store << ".\n";
                break;
        }

        // w-box
        switch( opc ){
            case 'a':
            case 'm':
                Reg[dest] = X_Out;
                std::cout << "w. Set f" << dest << " to " << Reg[dest] << ".\n";
                break;
            case 'l':
                Reg[dest] = M_Out;
                std::cout << "w. Set f" << dest << " to " << Reg[dest] << ".\n";
                break;
            case 's':
                std::cout << "w: W-box does no-op. \n";
                break;
        }

        std::cout << "\n";
    }                                         // end 'for' loop
}
/*

f: Fetched l#124.
d: Set opc to 'l'.
d: Set D_Out1 to 100.
d: Set D_Out2 to 4.
d: Set dest to f2.
x: Set X_Out to 104.
m: Set M_Out to 17.
w. Set f2 to 17.

f: Fetched l#348.
d: Set opc to 'l'.
d: Set D_Out1 to 200.
d: Set D_Out2 to 8.
d: Set dest to f4.
x: Set X_Out to 208.
m: Set M_Out to 41.
w. Set f4 to 41.

f: Fetched m#246.
d: Set opc to 'm'.
d: Set D_Out1 to 17.
d: Set D_Out2 to 41.
d: Set dest to f6.
x: Set X_Out to 697.
m: M-box does no-op.
w. Set f6 to 697.

f: Fetched a#468.
d: Set opc to 'a'.
d: Set D_Out1 to 41.
d: Set D_Out2 to 697.
d: Set dest to f8.
x: Set X_Out to 738.
m: M-box does no-op.
w. Set f8 to 738.

f: Fetched s#368.
d: Set opc to 's'.
d: Set D_Out1 to 200.
d: Set D_Out2 to 8.
d: Did not set dest.
x: Set X_Out to 208.
m: Set value_to_store to 697.
w: W-box does no-op.

f: Fetched s#584.
d: Set opc to 's'.
d: Set D_Out1 to 300.
d: Set D_Out2 to 4.
d: Did not set dest.
x: Set X_Out to 304.
m: Set value_to_store to 738.
w: W-box does no-op.

*/
