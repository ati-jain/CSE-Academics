`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:43:16 11/04/2022
// Design Name:   InstrMem
// Module Name:   C:/Users/Student/Downloads/RI/test_instrMem.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: InstrMem
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_instrMem;

	// Inputs
	reg [31:0] pc;
	reg clk;
	reg reset;

	// Outputs
	wire [31:0] instruction;

	// Instantiate the Unit Under Test (UUT)
	InstrMem uut (
		.pc(pc), 
		.clk(clk), 
		.reset(reset), 
		.instruction(instruction)
	);

	always #10 clk <= ~clk;
	initial begin
		// Initialize Inputs
		pc = 0;
		clk = 0;
		reset = 0;
		#100;
		pc = 1;
		#100;
		pc = 2;
	
		// Wait 100 ns for global reset to finish
		//#100;
		//clk = 1;
		//pc = 0;
		//#10;
		//reset = 0;
		//#10;
		//pc = 32'd2;
		//#10;
		//pc = 32'd3;
		//#10;
		
        
		// Add stimulus here

	end
      
endmodule

