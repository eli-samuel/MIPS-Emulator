# Assignment 3 Tutorial

*Pretty good to use lecture 3 to understand instruction formats*

*f d x m w* --> 6 times in a row, not consecutively

int Reg[10];                              // array of 10
Reg[1] = 100; Reg[3] = 200; Reg[5] = 300; // only initializes 3 of themc

int  Mem[400];                            // array of 400
char XMem[] = "llmass";                   // six opcodes in XMem
Mem[0] = 124; Mem[1] = 348; Mem[2] = 246; // initializes only 6
Mem[3] = 468; Mem[4] = 368; Mem[5] = 584; 
Mem[104] = 17; Mem[208] = 41;

// Starts a loop

__We will go over the first iteration of the loop__

# f-box
char head = XMem[PC];   // The first value of head wil b 'l' (from XMem)
int  tail = Mem[PC];    // the first value of head will be Mem[0] = 124, it can be thought of as [_1, 2, 4_]
std::cout << "f: Fetched " << head << "#" << tail << ".\n";

# d-box
char opc = head;                        // see what your instruction is (opcode)
int arg3 = tail % 10;                   // find the 3 arguments (124) --> arg3 = 4
tail = tail / 10;                       // tail = 12 
int arg2 = tail % 10;                   // arg2 = 2
tail = tail / 10;                       // tail = 1
int arg1 = tail;                        // arg1 = 1

*l.d --> 'l',   r2 --> 1 (register file),  f6 --> 2 (destination),  [-24] --> 4 (immediate)_*

int D_Out1 = Reg[arg1];                 // Reg[1] = 100

# switch-case statement
switch( opc ){                          // opcode will be 'l' in this case
    case 'a':                           // case for addition (same as multiplication)
    case 'm':                           // case for multiplication
        D_Out2 = Reg[arg2];             // l.d    __r2__  f6  [-24]
        dest = arg3;                    // destination register (l.d    r2  __f6__  [-24])
        break;
    // need to add more cases for load and store
}

// x-box --> do the addition/multipication
int X_Out;
switch( opc ) {
    //...
    case 'l':
        // add 100 + 4
}

// m-box
int M_Out;
switch( opc ) {
    //...
    case 'l':
        // go to memory location 104 and set M_Out to that (17)
}

// w-box
switch( opc ){
    //...
    case 'l':
        // write 17 to Reg[2]
}

__What the loop values will look like__
_PC      0   1   2   3   4   5   6_ \n
_head_    l   l\n
_tail_    124 348\n
_opc_     l   l\n
_arg3_    4   8\n
_arg2_    2   4\n
_arg1_    1   3\n
_D_Out1_  100 200\n
_D_Out2_  4   8\n
_dest_    2   4\n
_X_out_   104 208\n
_M_out_   17  41\n
