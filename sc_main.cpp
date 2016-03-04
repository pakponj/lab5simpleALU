//------------------------------------------------------------------
// Simple Testbench for 4-bits adder file
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>

#include "alu.h"

sc_uint<4> ADD = "0b0000";
sc_uint<4> SUB = "0b0001";
sc_uint<4> XOR = "0b0010";
sc_uint<4> AND = "0b0011";
sc_uint<4> OR = "0b0100";
sc_uint<4> NOTA = "0b0101";
sc_uint<4> STL = "0b0110";

sc_signal<sc_uint<16> > ain, bin, sum;
sc_signal<bool> ci, co, oflag, zflag, ltflag/*, op*/;
sc_signal<sc_uint<4> > opALU;

alu DUT("ALU"); 	//Instantiate Device Under .

void printResult()
{
	cout << "OPERATION: " << opALU << endl;
	cout << endl;
	cout << "A: " << ain.read() << endl;
	cout << "B: " << bin.read() << endl;
	cout << "Result: " << DUT.sum << endl;
	cout << "Zero flag: " << DUT.zflag << endl;
	cout << "Overflow flag: " << DUT.oflag << endl;
	cout << "Less Than flag: " << DUT.ltflag << endl;
	cout << "END OPERATION" << endl;
	cout << endl;
}

int sc_main(int argc, char* argv[])
{
	sc_clock clk("clk", 10, SC_NS, 0.5);   // Create a clock signal

	sc_trace_file *ar;
	ar = sc_create_vcd_trace_file("SimpleALU");
	sc_trace(ar, ain, "ain");
	sc_trace(ar, bin, "bi2n");
	sc_trace(ar, sum, "sum");
	sc_trace(ar, ci, "ci");
	sc_trace(ar, co, "co");
	sc_trace(ar, clk, "clk");
	sc_trace(ar, oflag, "oflag");
	sc_trace(ar, zflag, "zflag");
	sc_trace(ar, ltflag, "ltflag");
	//sc_trace(ar, op, "op");
	sc_trace(ar, opALU, "opALU");

	DUT.ain(ain);                       // Connect ports
	DUT.bin(bin);
	DUT.ci(ci);
	DUT.sum(sum);
	DUT.co(co);
	DUT.oflag(oflag);
	DUT.zflag(zflag);
	DUT.ltflag(ltflag);
	//DUT.op(op);
	DUT.opALU(opALU);
	
	////////////////////Start test cases///////////////////////////

	cout << "DUMMY TEST CASE FOR sc_trace TO START." << endl;
	ain.write("0b0000000000000000");
	bin.write("0b0000000000000000");
	ci.write(false);
	opALU.write(ADD);
	sc_start(100, SC_NS);
	printResult();

	cout << "ADD_ALU" << endl;
	ain.write("0b0000000000000100");
	bin.write("0b0000000000000011");
	ci.write(false);
	opALU.write(ADD);
	sc_start(100, SC_NS);
	printResult();
	
	cout << "SUB_ALU" << endl;
	ain.write("0b0000000000000100");
	bin.write("0b0000000000000011");
	ci.write(false);
	opALU.write(SUB);
	sc_start(100, SC_NS);
	printResult();

	cout << "XOR_ALU" << endl;
	ain.write("0b0000000000000100");
	bin.write("0b0000000000000011");
	ci.write(false);
	opALU.write(XOR);
	sc_start(100, SC_NS);
	printResult();

	cout << "AND_ALU" << endl;
	ain.write("0b0000000000000100");
	bin.write("0b0000000000000011");
	ci.write(false);
	opALU.write(AND);
	sc_start(100, SC_NS);
	printResult();

	cout << "OR_ALU" << endl;
	ain.write("0b0000000000000100");
	bin.write("0b0000000000000011");
	ci.write(false);
	opALU.write(OR);
	sc_start(100, SC_NS);
	printResult();

	cout << "NOTA_ALU" << endl;
	ain.write("0b0000000000000100");
	bin.write("0b0000000000000011");
	ci.write(false);
	opALU.write(NOTA);
	sc_start(100, SC_NS);
	printResult();

	cout << "STL_ALU" << endl;
	ain.write("0b0000000000000100");
	bin.write("0b0000000000000011");
	ci.write(false);
	opALU.write(STL);
	sc_start(100, SC_NS);
	printResult();

	sc_close_vcd_trace_file(ar);

	return 0;                           // Return OK, no errors.
}

