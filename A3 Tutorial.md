# Assignment 3 Tutorial  
  
*Pretty good to use lecture 3 to understand instruction formats*  
  
*f d x m w* --> 6 times in a row, not consecutively  
  
int Reg[10];                              // array of 10  
Reg[1] = 100; Reg[3] = 200; Reg[5] = 300; // only initializes 3 of them  
  
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
        D_Out2 = Reg[arg2];             // l.d  r2  f6  [-24] <-- D_Out2 = immediate    
        dest = arg3;                    // destination register (l.d    r2  __f6__  [-24])  
        break;  
    // need to add more cases for load and store  
}  
  
## x-box --> do the addition/multipication  
int X_Out;  
switch( opc ) {  
    //...  
    case 'l':  
        // add 100 + 4  
}  
  
## m-box  
int M_Out;  
switch( opc ) {  
    //...  
    case 'l':  
        // go to memory location 104 and set M_Out to that (17)  
}  
  
## w-box  
switch( opc ){  
    //...  
    case 'l':  
        // write 17 to Reg[2]  
    case 'm':  
        // what is in f6 to destination register  
}  
  
__What the loop values will look like__  <br>
  
__PC      0      1       2       3       4       5__  <br>
_head_    l     l       m       a       s       s<br>
_tail_    124   348     246     468     368     584<br>
_opc_     l     l       m       a       s       s<br>
_arg3_    4     8       6       8       8       4<br>
_arg2_    2     4       4       6       6       8<br>
_arg1_    1     3       2       4       3       5<br>
_D_Out1_  100   200     17      41      200     300<br>
_D_Out2_  4     8       41      697     8       4<br>
_dest_    2     4       6       8       .       .<br>
_X_out_   104   208     697     738     208     304<br>
_M_out_   17    41      no-op   no-op           <br>
_vlStored_                              697     738<br>
  
  
__for 'm' or 'a'__: opcode rs rt rd (operand 1, operand 2, destination) <br>
__for 's'__ s.d r2 f6 24 (s.d f6,24(r2)) <br>