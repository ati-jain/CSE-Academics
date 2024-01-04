`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:53:15 10/26/2022
// Design Name:   RISC
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab6/RISC/RISC_test.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: RISC
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module RISC_test;

	// Inputs
	reg clk;
	reg rst;

	// Outputs
	wire [31:0] Return;
	//wire [31:0] instr;

	// Instantiate the Unit Under Test (UUT)
	RISC uut (
		.clk(clk), 
		.rst(rst), 
		.Return(Return)
		//.instr(instr)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		
		// Wait 100 ns for global reset to finish
		#100;
		rst = 0;
		forever #100 clk = ~clk;
		$display("The result is : %d", Return);
	end
	initial begin
		
	end
      
endmodule

